#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <QObject>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WeatherApi : public QObject
{
    Q_OBJECT

public:
    explicit WeatherApi(QObject *parent = nullptr);

    Q_INVOKABLE void getTemperature(float lat, float lon);

signals:
    void newTemperature(const QString temperature);

public slots:
    void parseTemperature(QNetworkReply* reply);

};

#endif // WEATHERAPI_H
