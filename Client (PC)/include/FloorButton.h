#pragma once
#include "Button.h"


class FloorButton : public Button {
    Q_OBJECT

public:
    FloorButton(int floorNumber);
    Q_INVOKABLE void buttonPressed() override;
};
