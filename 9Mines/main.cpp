#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "minegenerator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();

    // inject your object into QML
    MineGenerator* generator = new MineGenerator();
    context->setContextProperty("generator", generator);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
