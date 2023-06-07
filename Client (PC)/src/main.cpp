#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <string>
#include <iostream>
#include "LocalController.h"


int main(int argc, char *argv[]) {
    QGuiApplication a(argc, argv);

    QQmlApplicationEngine engine;

    LocalController localController;
    GuiElevator elevator1, elevator2;
    localController.registerElevator(elevator1);
    localController.registerElevator(elevator2);

    CallButton callButton0(0), callButton1(1), callButton2(2);
    localController.registerCallButton(callButton0);
    localController.registerCallButton(callButton1);
    localController.registerCallButton(callButton2);

    FloorButton elevator1FloorButton0(0), elevator1FloorButton1(1), elevator1FloorButton2(2),
                elevator2FloorButton0(0), elevator2FloorButton1(1), elevator2FloorButton2(2);
    localController.registerFloorButton(elevator1, elevator1FloorButton0);
    localController.registerFloorButton(elevator1, elevator1FloorButton1);
    localController.registerFloorButton(elevator1, elevator1FloorButton2);
    localController.registerFloorButton(elevator2, elevator2FloorButton0);
    localController.registerFloorButton(elevator2, elevator2FloorButton1);
    localController.registerFloorButton(elevator2, elevator2FloorButton2);


    engine.rootContext()->setContextProperty("elevator1", &elevator1);
    engine.rootContext()->setContextProperty("elevator2", &elevator2);

    engine.rootContext()->setContextProperty("elevatorCallButton0", &callButton0);
    engine.rootContext()->setContextProperty("elevatorCallButton1", &callButton1);
    engine.rootContext()->setContextProperty("elevatorCallButton2", &callButton2);

    engine.rootContext()->setContextProperty("elevator1FloorButton0", &elevator1FloorButton0);
    engine.rootContext()->setContextProperty("elevator1FloorButton1", &elevator1FloorButton1);
    engine.rootContext()->setContextProperty("elevator1FloorButton2", &elevator1FloorButton2);

    engine.rootContext()->setContextProperty("elevator2FloorButton0", &elevator2FloorButton0);
    engine.rootContext()->setContextProperty("elevator2FloorButton1", &elevator2FloorButton1);
    engine.rootContext()->setContextProperty("elevator2FloorButton2", &elevator2FloorButton2);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return a.exec();
}
