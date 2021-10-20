#include <QApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPushButton>
#include "backend.h"
#include "debug_window.h"

/* TODO:
 * - Audio für signalviewengine
 * - Serial standard
 *      - Values get:
 *          - Speed
 *          - Distance
 *          - If break
 *          - Battery
 *          - Lap trigger
 *      - Values send:
 *          - Gas
 *          - Light
 *
 *
 * - Gucken wie man das mit input bei raspi machen könnte
 *      - Hardware trigger:
 *          - Tempomat on/off
 *          - Tempomat higher/lower
 *          - Switch menu
 *          - Ignore
 *          - If brakes
 *          - Gas
 *
 * X q proberty für alle anderen werte
 * - zweites menu mit allen daten
 * - laptime engine
 * - tempomat
 *
 *
 *
 *
 *
 */

int main(int argc, char *argv[]){   
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    BackEnd *backend = new BackEnd("COM1");
    engine.rootContext()->setContextProperty("backend", backend);
    engine.load(url);

    Debug debug_window(backend);
    debug_window.show();
    


    return app.exec();
}
