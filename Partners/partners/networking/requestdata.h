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

//Q_DECLARE_LOGGING_CATEGORY(logAgzs)
//Q_DECLARE_LOGGING_CATEGORY(logPrice)
//Q_DECLARE_LOGGING_CATEGORY(logOrders)
Q_DECLARE_LOGGING_CATEGORY(logRequest)
Q_DECLARE_LOGGING_CATEGORY(logError)

enum class RequestType {
    get,
    post,
    unknown
};

class RequestData : public QObject {
    Q_OBJECT

public:
    explicit RequestData(QString url, bool parallel = false, QObject *parent = nullptr);
    RequestData(QObject *parent = nullptr);
    ~RequestData();
    void get(QString str, bool parallel = false);
    void get(QNetworkRequest request, bool parallel = false);
    void post(QNetworkRequest request, QString post, bool parallel = false);
    QByteArray getAnswer();
    QByteArray getAuthorization();
    int getCode();

signals:
    void s_finished(RequestData *request);
    void s_request(RequestType type, QString request, QString post, int code);

private slots:
    void completeRequest(RequestType type, QNetworkRequest request, QString post, bool parallel);
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager_;
    QByteArray answer_;
    RequestType type_;
    int code_;
    QByteArray authorization_;
    QString url_;
    QString post_;
    bool parallel_;

};

#endif // IMAGEREQUEST_H
