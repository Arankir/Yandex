#include "requestdata.h"

RequestData::RequestData(QString a_url, bool a_parallel, QObject *parent) : QObject(parent){
    _manager = new QNetworkAccessManager();
    _socket = new QTcpSocket();
    _answer="";
    _url=a_url;
    _parallel=a_parallel;
    Get(a_url,a_parallel);
}

RequestData::RequestData(){
    _manager = new QNetworkAccessManager();
    _socket = new QTcpSocket();
    _answer="";
}

void RequestData::Get(QString a_url, bool a_parallel){
    _manager->get(QNetworkRequest(QUrl(a_url)));
    connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultGet);
    if(!a_parallel){
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

void RequestData::Get(QNetworkRequest a_request, bool a_parallel){
    _manager->get(a_request);
    qDebug()<<"Запрос:"<<a_request.url();
    connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultPost);
    if(!a_parallel){
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

void RequestData::Post(QString a_url, QUrlQuery a_post, bool a_parallel){
    _manager->post(QNetworkRequest(QUrl(a_url)), a_post.query(QUrl::FullyEncoded).toUtf8());
    connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultPost);
    if(!a_parallel){
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

void RequestData::Post(QString a_url, QHttpMultiPart a_post, bool a_parallel){
_manager->post(QNetworkRequest(QUrl(a_url)),&a_post);
connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultPost);
    QEventLoop loop;
    connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    loop.exec();
    disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
}

void RequestData::Post(QNetworkRequest a_request, QString a_post, bool a_parallel){
    _manager->post(a_request, a_post.toUtf8());
    qDebug()<<"Запрос:"<<a_post.toUtf8();
    connect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultPost);
    if(!a_parallel){
        QEventLoop loop;
        connect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
        loop.exec();
        disconnect(_manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);
    }
}

void RequestData::OnResultGet(QNetworkReply *a_reply){
    _code=a_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if(!a_reply->error()){
        _answer=a_reply->readAll();
    }
    emit s_finished(this);
}

void RequestData::OnResultPost(QNetworkReply *a_reply){
    qDebug()<<"Ошибка:"<< a_reply->error();
    _code=a_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    if(true){
        _answer=a_reply->readAll();
        _authorization=a_reply->rawHeader("Authorization");
        //QString::fromUtf8(a_reply->readAll())
    }
    emit s_finished(this);
}

RequestData::~RequestData(){
    disconnect(_manager,&QNetworkAccessManager::finished,this,&RequestData::OnResultGet);
    delete _manager;
}
