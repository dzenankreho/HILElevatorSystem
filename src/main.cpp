#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <string>
#include <iostream>
#include "ClientComModule.h"

int main(int argc, char *argv[]) {
    QGuiApplication a(argc, argv);

    QQmlApplicationEngine engine;

    ClientComModule::initializeComModule();

    Elevator elevator1(1), elevator2(2);
    ClientComModule::getAccess().registerElevator(elevator1);
    ClientComModule::getAccess().registerElevator(elevator2);

    CallButton callButton0(0), callButton1(1), callButton2(2);
    ClientComModule::getAccess().registerCallButton(callButton0);
    ClientComModule::getAccess().registerCallButton(callButton1);
    ClientComModule::getAccess().registerCallButton(callButton2);

    FloorButton elevator1FloorButton0(0), elevator1FloorButton1(1), elevator1FloorButton2(2),
                elevator2FloorButton0(0), elevator2FloorButton1(1), elevator2FloorButton2(2);
    ClientComModule::getAccess().registerFloorButton(elevator1, elevator1FloorButton0);
    ClientComModule::getAccess().registerFloorButton(elevator1, elevator1FloorButton1);
    ClientComModule::getAccess().registerFloorButton(elevator1, elevator1FloorButton2);
    ClientComModule::getAccess().registerFloorButton(elevator2, elevator1FloorButton0);
    ClientComModule::getAccess().registerFloorButton(elevator2, elevator1FloorButton1);
    ClientComModule::getAccess().registerFloorButton(elevator2, elevator1FloorButton2);


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
