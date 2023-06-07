#include "Button.h"
#include <stdexcept>


Button::Button(int floorNumber) {
    if (floorNumber < 0) {
        throw std::invalid_argument("Floor number must be >= 0");
    }

    this->floorNumber = floorNumber;
}


int Button::getFloorNumber() const {
    return floorNumber;
}
