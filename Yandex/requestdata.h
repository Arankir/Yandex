#ifndef IMAGEREQUEST_H
#define IMAGEREQUEST_H

#include <QMainWindow>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTextCodec>
#include <QTcpSocket>
#include <QEventLoop>
#include <QDir>
#include <QHttpMultiPart>
#include <QUrl>
#include <QUrlQuery>

class RequestData : public QObject
{
    Q_OBJECT
public:
    explicit RequestData(QString url, bool parallel=false, QObject *parent = nullptr);
    RequestData();
    ~RequestData();
    void Get(QString str, bool parallel = false);
    void Get(QNetworkRequest request, bool parallel = false);
    void Post(QString url, QUrlQuery post, bool parallel = false);
    void Post(QString url, QHttpMultiPart post, bool parallel = false);
    void Post(QNetworkRequest request, QString post, bool parallel = false);
    QByteArray GetAnswer() {return _answer;}
    QByteArray GetAuthorization() {return _authorization;}
    int GetCode() {return _code;}

signals:
    void s_finished(RequestData *imgr);

private:
    QNetworkAccessManager *_manager;
    QTcpSocket *_socket;
    QByteArray _answer;
    int _code;
    QByteArray _authorization;
    QString _url;
    bool _parallel;

public slots:
    void OnResultGet(QNetworkReply *reply);
    void OnResultPost(QNetworkReply *reply);
};

#endif // IMAGEREQUEST_H
