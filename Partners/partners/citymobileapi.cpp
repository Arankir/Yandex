#include "citymobileapi.h"

CityMobileAPI::CityMobileAPI(QObject *parent) : QObject(parent), request_(new RequestData()), reestr_("RegionPostavka", "Partners"),
apiKey_(reestr_.value("CityMobile Token", "").toString()), c_baseUrl(reestr_.value("isTest").toBool() ? c_baseTest : c_baseRelease) {

    qDebug() << "CityMobile Token =" << apiKey_;
    qDebug() << "isTest =" << reestr_.value("isTest").toString();

    QObject::connect(request_, &RequestData::s_request, this,   [=](RequestType type, QString request, QString post, int code) {
                                                                    if (type == RequestType::get) {
                                                                        qInfo(logRequest) << "CityMobile" << "GET " << code << request;
                                                                    } else {
                                                                        qInfo(logRequest) << "CityMobile" << "POST" << code << request << "(" + post + ")";
                                                                    }
                                                                    //emit s_networkRequestInfo("CityMobile", type, request, post, code);
                                                                });
}

CityMobileAPI::~CityMobileAPI() {
    delete request_;
}

void CityMobileAPI::updateConfigurationAGZS(QJsonDocument aPost) {
    QNetworkRequest request = createRequest("api/station", "application/json", true);
    request_->post(request,QString(aPost.toJson(QJsonDocument::Compact)).toUtf8());
}

void CityMobileAPI::updatePriceList(QString aPost) {
    QNetworkRequest request = createRequest("api/price", "application/x-www-form-urlencoded", true);
    request_->post(request,aPost.toUtf8());
}

void CityMobileAPI::checkOrders() {
    QNetworkRequest request = createRequest("api/orders/items", "application/x-www-form-urlencoded", true);
    request_->get(request);
    QJsonDocument jsonRequest = QJsonDocument::fromJson(request_->getAnswer());
    emit s_gotOrders(jsonRequest);
    //qDebug() << "Ситимобил заказы:" << _request->getAnswer();
    //connect(_request, &RequestData::s_finished, this, &CityMobileAPI::checkOrders);
}

void CityMobileAPI::setStatusAccept(QString aOrderId, int aVCode) {
    QNetworkRequest request = createRequest("api/orders/accept?orderId=" + aOrderId, "application/x-www-form-urlencoded", true);
    request_->get(request);
    if ((request_->getCode() != 200) && (request_->getCode() != 401)) {
        qWarning(logError) << "setStatusAccept" << aOrderId << request_->getCode();
        emit s_error("setStatusAccept", aOrderId, request_->getCode());
        setStatusCanceled(aOrderId, "Неизвестная ошибка.", QString::number(aVCode), QDateTime::currentDateTime());
    }
}

void CityMobileAPI::setStatusFueling(QString aOrderId, int aVCode) {
    Q_UNUSED(aVCode);
    QNetworkRequest request = createRequest("api/orders/fueling?orderId=" + aOrderId, "application/x-www-form-urlencoded", true);
    request_->get(request);
    if ((request_->getCode() != 200) && (request_->getCode() != 401)) {
        qWarning(logError) << "setStatusFueling" << aOrderId << request_->getCode();
        emit s_error("setStatusFueling", aOrderId, request_->getCode());
        //setStatusCanceled(orderId, "Неизвестная ошибка.", QString::number(vCode), QDateTime::currentDateTime());
    }
}

void CityMobileAPI::setStatusCanceled(QString aOrderId, QString aReason, QString aExtendedOrderId, QDateTime aExtendedDate) {
    QNetworkRequest request = createRequest("api/orders/canceled?orderId=" + aOrderId +
                                                    "&reason=\"" + aReason.replace(" ","%20") + "\""
                                                    "&extendedOrderId=" + aExtendedOrderId +
                                                    "&extendedDate=" + aExtendedDate.toString("dd.MM.yyyy HH:mm:ss")
                                            , "application/x-www-form-urlencoded", true);
    request_->get(request);
}

void CityMobileAPI::setStatusCompleted(QString aOrderId, double aLitre, QString aExtendedOrderId, QDateTime aExtendedDate) {
    QNetworkRequest request = createRequest(QString("api/orders/completed?orderId=%1&litre=%2&extendedOrderId=%3&extendedDate=%4").arg(
                                                aOrderId,
                                                QString::number(aLitre).replace(",","."),
                                                aExtendedOrderId,
                                                aExtendedDate.toString("dd.MM.yyyy HH:mm:ss")), "application/x-www-form-urlencoded", true);
    request_->get(request);
}

void CityMobileAPI::setStatusFuelNow(QString aOrderId, double aLitre) {
    QNetworkRequest request = createRequest("api/orders/volume", "application/x-www-form-urlencoded", true);
    request_->post(request,QString("orderId=" + aOrderId + "&litre=" + QString::number(aLitre).replace(",",".")).toUtf8());
}

void CityMobileAPI::setStatusMessage(QString aOrderId, QString aMessage) {
    QNetworkRequest request = createRequest("api/orders/message", "application/x-www-form-urlencoded", true);
    request_->post(request,QString("orderId=" + aOrderId + "&msg=" + aMessage).toUtf8());
}

QNetworkRequest CityMobileAPI::createRequest(QString aUrl, QString aContentType, bool aAuth) {
    QNetworkRequest request;
    request.setUrl(QUrl(c_baseUrl + aUrl));
    request.setHeader(QNetworkRequest::ContentTypeHeader, aContentType);
    if (aAuth) {
        request.setRawHeader("Authorization", apiKey_.toUtf8());
    }
    return request;
}
