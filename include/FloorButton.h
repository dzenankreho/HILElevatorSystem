#pragma once
#include "Button.h"


class FloorButton : public Button {
public:
    FloorButton(int floorNumber);
    Q_INVOKABLE void buttonPressed() override;
};
