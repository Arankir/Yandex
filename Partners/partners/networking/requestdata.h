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
#include <QDebug>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(logAgzs)
Q_DECLARE_LOGGING_CATEGORY(logPrice)
Q_DECLARE_LOGGING_CATEGORY(logOrders)
Q_DECLARE_LOGGING_CATEGORY(logRequest)
Q_DECLARE_LOGGING_CATEGORY(logError)

class RequestData : public QObject {
    Q_OBJECT

public:
    RequestData(QObject *parent = nullptr);//: RequestData("", false, parent) {;}
    ~RequestData();
    void get(QString url, bool parallel = false);
    void get(QUrl url, bool parallel = false);
    void get(QNetworkRequest request, bool parallel = false);
    void post(QNetworkRequest request, QString post, bool parallel = false);
    QByteArray getAnswer() {return answer_;}
    QByteArray getAuthorization() {return authorization_;}
    int getCode() {return code_;}

signals:
    void s_finished(RequestData *request);
    void s_request(QNetworkAccessManager::Operation type, QString request, QString post, int code);

private slots:
    void completeRequest(QNetworkAccessManager::Operation type, QNetworkRequest request, QString post, bool parallel);
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager_;
    QByteArray answer_;

    QString post_;

    int code_;
    QByteArray authorization_;

};

#endif // IMAGEREQUEST_H
