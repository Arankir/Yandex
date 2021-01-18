#include "citymobileapi.h"

CityMobileAPI::CityMobileAPI(QObject *parent):
QObject(parent),
reestr_("RegionPostavka", "Partners"),
apiKey_(reestr_.value("CityMobile Token", "").toString()),
c_baseUrl(reestr_.value("isTest").toBool() ? c_baseTest : c_baseRelease) {

    qDebug() << "CityMobile Token =" << apiKey_;
    qDebug() << "isTest =" << reestr_.value("isTest").toString();

}

CityMobileAPI::~CityMobileAPI() {

}

void CityMobileAPI::updateConfigurationAGZS(QJsonDocument aPost) {
    auto req = createRequest();
    req->post(createNetworkRequest("api/station", "application/json", true), QString(aPost.toJson(QJsonDocument::Compact)).toUtf8());
    delete req;
}

void CityMobileAPI::updatePriceList(QString aPost) {
    auto req = createRequest();
    req->post(createNetworkRequest("api/price"), aPost.toUtf8());
    delete req;
}

void CityMobileAPI::checkOrders() {
    auto req = createRequest();
    req->get(createNetworkRequest("api/orders/items"));
    QJsonDocument jsonRequest = QJsonDocument::fromJson(req->getAnswer());
    delete req;
    emit s_gotOrders(jsonRequest);
    //qDebug() << "Ситимобил заказы:" << req->getAnswer();
    //connect(req, &RequestData::s_finished, this, &CityMobileAPI::checkOrders);
}

void CityMobileAPI::setStatusAccept(QString aOrderId, int aVCode) {
    auto req = createRequest();
    req->get(createNetworkRequest("api/orders/accept?orderId=" + aOrderId));
    if ((req->getCode() != 200) && (req->getCode() != 401)) {
        qWarning(logError) << "setStatusAccept" << aOrderId << req->getCode();
        emit s_error("setStatusAccept", aOrderId, req->getCode());
        setStatusCanceled(aOrderId, "Неизвестная ошибка.", QString::number(aVCode), QDateTime::currentDateTime());
    }
    delete req;
}

void CityMobileAPI::setStatusFueling(QString aOrderId, int aVCode) {
    Q_UNUSED(aVCode);
    auto req = createRequest();
    req->get(createNetworkRequest("api/orders/fueling?orderId=" + aOrderId));
    if ((req->getCode() != 200) && (req->getCode() != 401)) {
        qWarning(logError) << "setStatusFueling" << aOrderId << req->getCode();
        emit s_error("setStatusFueling", aOrderId, req->getCode());
        //setStatusCanceled(orderId, "Неизвестная ошибка.", QString::number(vCode), QDateTime::currentDateTime());
    }
    delete req;
}

void CityMobileAPI::setStatusCanceled(QString aOrderId, QString aReason, QString aExtendedOrderId, QDateTime aExtendedDate) {
    auto req = createRequest();
    req->get(createNetworkRequest("api/orders/canceled?orderId=" + aOrderId +
                           "&reason=\"" + aReason.replace(" ","%20") + "\""
                           "&extendedOrderId=" + aExtendedOrderId +
                           "&extendedDate=" + aExtendedDate.toString("dd.MM.yyyy HH:mm:ss")));
    delete req;
}

void CityMobileAPI::setStatusCompleted(QString aOrderId, double aLitre, QString aExtendedOrderId, QDateTime aExtendedDate) {
    auto req = createRequest();
    req->get(createNetworkRequest(QString("api/orders/completed?orderId=%1&litre=%2&extendedOrderId=%3&extendedDate=%4").arg(
                               aOrderId,
                               QString::number(aLitre).replace(",","."),
                               aExtendedOrderId,
                               aExtendedDate.toString("dd.MM.yyyy HH:mm:ss"))));
    delete req;
}

void CityMobileAPI::setStatusFuelNow(QString aOrderId, double aLitre) {
    auto req = createRequest();
    req->post(createNetworkRequest("api/orders/volume"), QString("orderId=" + aOrderId + "&litre=" + QString::number(aLitre).replace(",",".")).toUtf8());
    delete req;
}

void CityMobileAPI::setStatusMessage(QString aOrderId, QString aMessage) {
    auto req = createRequest();
    req->post(createNetworkRequest("api/orders/message"), QString("orderId=" + aOrderId + "&msg=" + aMessage).toUtf8());
    delete req;
}

RequestData *CityMobileAPI::createRequest() {
    auto request = new RequestData(this);
    QObject::connect(request, &RequestData::s_request, this,
                     [=](QNetworkAccessManager::Operation operation, QString request, QString post, int code) {
                        switch (operation) {
                        case QNetworkAccessManager::Operation::GetOperation: {
                            qInfo(logRequest) << "GET " << code << "CityMobile" << request;
                            break;
                        }
                        case QNetworkAccessManager::Operation::PostOperation: {
                            qInfo(logRequest) << "POST" << code << "CityMobile" << request << "(" + post + ")";
                            break;
                        }
                        default: {

                        }
                        }
                     });
    return request;
}

QNetworkRequest CityMobileAPI::createNetworkRequest(QString aUrl, QString aContentType, bool aAuth) {
    QNetworkRequest request;
    request.setUrl(QUrl(c_baseUrl + aUrl));
    request.setHeader(QNetworkRequest::ContentTypeHeader, aContentType);
    if (aAuth) {
        request.setRawHeader("Authorization", apiKey_.toUtf8());
    }
    return request;
}
