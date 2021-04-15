#include "partnerapi.h"

PartnerAPI::PartnerAPI(QObject *parent) : QObject(parent), reestr_("RegionPostavka", "Partners") {
    connect(&timerOrders_, &QTimer::timeout, this, &PartnerAPI::checkOrders);
}

PartnerAPI::~PartnerAPI() {
    disconnect(&timerOrders_, &QTimer::timeout, this, &PartnerAPI::checkOrders);
    if (request_ != nullptr) {
        disconnect(request_);
        delete request_;
    }
}

int &PartnerAPI::fixInterval(int &interval) {
    if (interval <= 0) {
        interval = 3000;
    }
    if (interval > 60000) {
        interval = 60000;
    }
    return interval;
}

void PartnerAPI::start(int interval) {
    timerInterval_ = fixInterval(interval);
    timerOrders_.start(timerInterval_);
}

QNetworkRequest PartnerAPI::createNetworkRequest(QUrl aUrl, QString aContentType, QString aAuth) {
    QNetworkRequest request(aUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, aContentType.toUtf8());
    if (aAuth != "") {
        request.setRawHeader("Authorization", aAuth.toUtf8());
    }
    return request;
}

RequestData *PartnerAPI::createRequestData() {
    auto request = new RequestData(this);
    QObject::connect(request, &RequestData::s_finished, this, &PartnerAPI::checkAuth);
    QObject::connect(request, &RequestData::s_request, this, &PartnerAPI::logNetwork);
    return request;
}

void PartnerAPI::logNetwork(QNetworkAccessManager::Operation operation, QString request, QString post, int code) {
    switch (operation) {
    case QNetworkAccessManager::Operation::GetOperation: {
        qInfo(logRequest) << "GET " << code << agent().leftJustified(10) << request;
        break;
    }
    case QNetworkAccessManager::Operation::PostOperation: {
        qInfo(logRequest) << "POST" << code << agent().leftJustified(10) << request << "(" + post + ")";
        break;
    }
    default: {

    }
    }
}
