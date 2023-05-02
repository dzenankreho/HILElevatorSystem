#pragma once
#include <QObject>

class Button : public QObject {
    Q_OBJECT
    int floorNumber;

public:
    Button(int floorNumber);
    virtual Q_INVOKABLE void buttonPressed() = 0;
    int getFloorNumber() const;
signals:
    void turnOnBacklight();
    void turnOffBacklight();
    void notifyController(int floorNumber);
};
