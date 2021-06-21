#include "citymobileapi.h"

CityMobileAPI::CityMobileAPI(QObject *parent): PartnerAPI(parent), apiKey_(reestr_.value("CityMobile Token", "").toString()) {
    qDebug() << "CityMobile Token =" << apiKey_;
    request_ = createRequestData();
}

CityMobileAPI::~CityMobileAPI() {

}

QString CityMobileAPI::baseUrl() {
    return reestr_.value("isTest").toBool() ? c_baseTest : c_baseRelease;
}

void CityMobileAPI::updateConfigurationAGZS(QJsonObject aConfiguration) {
//    auto req = createRequestData();
    QNetworkRequest request = createNetworkRequest(baseUrl() + "api/station", "application/json", true);
    request_->post(request, QString(QJsonDocument(aConfiguration).toJson(QJsonDocument::Compact)).toUtf8());
    if (request_->code() == 200) {
        isLastConfigurationUpdated_ = true;
    }
//    delete req;
}

void CityMobileAPI::updatePriceList(QString aPost) {
//    auto req = createRequestData();
    request_->post(createNetworkRequest(baseUrl() + "api/price"), aPost.toUtf8());
    if (request_->code() == 200) {
        isLastPriceUpdated_ = true;
    }
//    delete req;
}

int CityMobileAPI::checkOrders() {
//    auto req = createRequestData();
    request_->get(createNetworkRequest(baseUrl() + "api/orders/items"));
    QJsonDocument jsonRequest = QJsonDocument::fromJson(request_->answer());
//    delete req;
    emit s_gotOrders(jsonRequest);
    timerInterval_ = jsonRequest.object().value("nextRetryMs").toInt();
    timerOrders_.setInterval(fixInterval(timerInterval_));
    return timerInterval_;
}

int CityMobileAPI::setStatusAccept(QString aOrderId, int aVCode) {
//    auto req = createRequestData();
    request_->get(createNetworkRequest(baseUrl() + "api/orders/accept?orderId=" + aOrderId));
    if ((request_->code() != 200) && (request_->code() != 401)) {
        qWarning(logError) << "setStatusAccept" << aOrderId << request_->code();
        emit s_error("setStatusAccept", aOrderId, request_->code());
        setStatusCanceled(aOrderId, "Неизвестная ошибка.", QString::number(aVCode), QDateTime::currentDateTime());
    }
//    delete req;
    return request_->code();
}

int CityMobileAPI::setStatusFueling(QString aOrderId, int aVCode) {
    Q_UNUSED(aVCode);
//    auto req = createRequestData();
    request_->get(createNetworkRequest(baseUrl() + "api/orders/fueling?orderId=" + aOrderId));
    if ((request_->code() != 200) && (request_->code() != 401)) {
        qWarning(logError) << "setStatusFueling" << aOrderId << request_->code();
        emit s_error("setStatusFueling", aOrderId, request_->code());
        //setStatusCanceled(orderId, "Неизвестная ошибка.", QString::number(vCode), QDateTime::currentDateTime());
    }
//    delete req;
    return request_->code();
}

int CityMobileAPI::setStatusCanceled(QString aOrderId, QString aReason, QString aExtendedOrderId, QDateTime aExtendedDate) {
//    auto req = createRequestData();
    QUrl url(QString("%1api/orders/canceled").arg(baseUrl()));
    QUrlQuery query;
    query.addQueryItem("orderId", aOrderId);
    query.addQueryItem("reason", aReason.replace(" ","%20"));
    query.addQueryItem("extendedOrderId", aExtendedOrderId);
    query.addQueryItem("extendedDate", aExtendedDate.toString("dd.MM.yyyy HH:mm:ss"));
    url.setQuery(query);
    request_->get(createNetworkRequest(url));
//    req->get(createNetworkRequest(baseUrl() + "api/orders/canceled?orderId=" + aOrderId +
//                           "&reason=\"" + aReason.replace(" ","%20") + "\""
//                           "&extendedOrderId=" + aExtendedOrderId +
//                           "&extendedDate=" + aExtendedDate.toString("dd.MM.yyyy HH:mm:ss")));
//    delete req;
    return request_->code();
}

int CityMobileAPI::setStatusCompleted(QString aOrderId, double aLitre, QString aExtendedOrderId, QDateTime aExtendedDate) {
//    auto req = createRequestData();
    QUrl url(QString("%1api/orders/completed").arg(baseUrl()));
    QUrlQuery query;
    query.addQueryItem("orderId", aOrderId);
    query.addQueryItem("litre", QString::number(aLitre).replace(",","."));
    query.addQueryItem("extendedOrderId", aExtendedOrderId);
    query.addQueryItem("extendedDate", aExtendedDate.toString("dd.MM.yyyy HH:mm:ss"));
    url.setQuery(query);
    request_->get(createNetworkRequest(url));
//    req->get(createNetworkRequest(QString(baseUrl() + "api/orders/completed?orderId=%1&litre=%2&extendedOrderId=%3&extendedDate=%4").arg(
//                               aOrderId,
//                               QString::number(aLitre).replace(",","."),
//                               aExtendedOrderId,
//                               aExtendedDate.toString("dd.MM.yyyy HH:mm:ss"))));
//    delete req;
    return request_->code();
}

int CityMobileAPI::setStatusFuelNow(QString aOrderId, double aLitre) {
//    auto req = createRequestData();
    request_->post(createNetworkRequest(baseUrl() + "api/orders/volume"), QString("orderId=" + aOrderId + "&litre=" + QString::number(aLitre).replace(",",".")).toUtf8());
//    delete req;
    return request_->code();
}

void CityMobileAPI::setStatusMessage(QString aOrderId, QString aMessage) {
//    auto req = createRequestData();
    request_->post(createNetworkRequest(baseUrl() + "api/orders/message"), QString("orderId=" + aOrderId + "&msg=" + aMessage).toUtf8());
//    delete req;
}

//void CityMobileAPI::logNetwork(QNetworkAccessManager::Operation operation, QString request, QString post, int code) {
//    switch (operation) {
//    case QNetworkAccessManager::Operation::GetOperation: {
//        qInfo(logRequest) << "GET " << code << "CityMobile" << request;
//        break;
//    }
//    case QNetworkAccessManager::Operation::PostOperation: {
//        qInfo(logRequest) << "POST" << code << "CityMobile" << request << "(" + post + ")";
//        break;
//    }
//    default: {

//    }
//    }
//}

QNetworkRequest CityMobileAPI::createNetworkRequest(QUrl aUrl, QString aContentType, bool aAuth) {
    reestr_.sync();
    return PartnerAPI::createNetworkRequest(aUrl, aContentType, aAuth ? apiKey_.toUtf8() : "");
}
