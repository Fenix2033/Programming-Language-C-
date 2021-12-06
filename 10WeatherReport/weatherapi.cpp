#include "weatherapi.h"

WeatherApi::WeatherApi(QObject *parent) : QObject(parent)
{

}

void WeatherApi::parseTemperature(QNetworkReply* reply){
    QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
    QJsonObject rootObject = document.object();

    if (rootObject.contains("currently") && rootObject["currently"].isObject()){
        QJsonObject currObject = rootObject["currently"].toObject();
        if (currObject.contains("temperature") and currObject["temperature"].isDouble()){
            double temperature = currObject["temperature"].toDouble();
            emit newTemperature("Currently "+QString::number(temperature));
        } else {
            qDebug() << "No temperature";
        }
    } else {
        qDebug() << "No currently";
    }
}

void WeatherApi::getTemperature(float lat, float lon){
    QNetworkAccessManager* m_manager = new QNetworkAccessManager(this);
    connect(m_manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(parseTemperature(QNetworkReply*)));
    qDebug() << lat << ":::" << lon;
    QString address = "https://api.forecast.io/forecast/3c6670ca22466eadc48988aa696094c9/"+QString::number(lat)+","+QString::number(lon);
    m_manager->get(QNetworkRequest(address));
}
