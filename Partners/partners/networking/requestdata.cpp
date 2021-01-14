#include "requestdata.h"

Q_LOGGING_CATEGORY(logAgzs,     "AGZS")
Q_LOGGING_CATEGORY(logPrice,    "Price")
Q_LOGGING_CATEGORY(logOrders,   "Orders")
Q_LOGGING_CATEGORY(logRequest,  "Request")
Q_LOGGING_CATEGORY(logError,    "Error")

RequestData::RequestData(QObject *aParent):
QObject(aParent),
manager_(new QNetworkAccessManager()),
answer_(""),
authorization_("") {
    connect(manager_, &QNetworkAccessManager::finished, this, &RequestData::onResult);
}

void RequestData::get(QString aUrl, bool aParallel) {
    get(QNetworkRequest(QUrl(aUrl)), aParallel);
}

void RequestData::get(QUrl aUrl, bool aParallel) {
    get(QNetworkRequest(aUrl), aParallel);
}

void RequestData::get(QNetworkRequest aRequest, bool aParallel) {
    completeRequest(QNetworkAccessManager::Operation::GetOperation, aRequest, "", aParallel);
}

void RequestData::post(QNetworkRequest aRequest, QString aPost, bool aParallel) {
    completeRequest(QNetworkAccessManager::Operation::PostOperation, aRequest, aPost, aParallel);
}

void RequestData::completeRequest(QNetworkAccessManager::Operation aType, QNetworkRequest aRequest, QString aPost, bool aParallel) {
    post_ = aPost.toUtf8();
    switch (aType) {
    case QNetworkAccessManager::Operation::GetOperation: {
        manager_->get(aRequest);
        break;
    }
    case QNetworkAccessManager::Operation::PostOperation: {
        manager_->post(aRequest, aPost.toUtf8());
        break;
    }
    default: ;
    }
    if (!aParallel) {
        QEventLoop loop;
        connect(manager_, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(manager_, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

void RequestData::onResult(QNetworkReply *aReply) {
    code_ = aReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    emit s_request(aReply->operation(),
                   aReply->url().url(),
                   aReply->operation() == QNetworkAccessManager::Operation::PostOperation ? post_ : "",
                   code_);

    answer_ = aReply->readAll();
    if (aReply->rawHeaderList().indexOf("Authorization") > -1) {
        authorization_ = aReply->rawHeader("Authorization");
    }
    emit s_finished(this);
}

RequestData::~RequestData() {
    disconnect(manager_);
    delete manager_;
}
