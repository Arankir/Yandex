#include "requestdata.h"

//Q_LOGGING_CATEGORY(logAgzs,     "AGZS")
//Q_LOGGING_CATEGORY(logPrice,    "Price")
//Q_LOGGING_CATEGORY(logOrders,   "Orders")
Q_LOGGING_CATEGORY(logRequest,  "Request")
Q_LOGGING_CATEGORY(logError,    "Error")

RequestData::RequestData(QString aUrl, bool aParallel, QObject *aParent): QObject(aParent), manager_(new QNetworkAccessManager()), answer_(""),
authorization_(""), url_(aUrl), parallel_(aParallel) {
    connect(manager_, &QNetworkAccessManager::finished, this, &RequestData::onResult);
    manager_->setTransferTimeout(3000);
}

RequestData::RequestData(QObject *aParent): RequestData("", false, aParent) {

}

void RequestData::get(QString aUrl, bool aParallel) {
    url_  = aUrl;
    post_ = "";
    get(QNetworkRequest(QUrl(url_)), aParallel);
}

void RequestData::get(QNetworkRequest aRequest, bool aParallel) {
    completeRequest(RequestType::get, aRequest, "", aParallel);
}

void RequestData::post(QNetworkRequest aRequest, QString aPost, bool aParallel) {
    completeRequest(RequestType::post, aRequest, aPost, aParallel);
}

QByteArray RequestData::getAnswer() {
    return answer_;
}

QByteArray RequestData::getAuthorization() {
    return authorization_;
}

int RequestData::getCode() {
    return code_;
}

void RequestData::completeRequest(RequestType aType, QNetworkRequest aRequest, QString aPost, bool aParallel) {
    url_ = aRequest.url().toString();
    post_ = aPost.toUtf8();
    type_ = aType;
    switch (type_) {
    case RequestType::get: {
        manager_->get(aRequest);
        break;
    }
    case RequestType::post: {
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
    emit s_request(type_, url_, type_ == RequestType::post ? post_ : "", code_);
//    if (type_ == "GET") {
//        //qDebug()<< "GET(" << _url << ") Код:" << _code;
//        emit s_request(RequestType::get, url_, "", code_);
//    } else if (type_ == "POST") {
//        //qDebug()<< "POST(" << _url << _post << ") Код:" << _code;
//        emit s_request(RequestType::post, url_, post_, code_);
//    }
    answer_ = aReply->readAll();
    if (code_ != 200) {
        qWarning() << code_ << url_ << answer_;
    }
    if (aReply->rawHeaderList().indexOf("Authorization") > -1) {
        authorization_ = aReply->rawHeader("Authorization");
    }
    type_ = RequestType::unknown;
    emit s_finished(this);
}

RequestData::~RequestData() {
    disconnect(manager_);
    delete manager_;
}
