#include "GuiElevator.h"

bool operator<(std::reference_wrapper<GuiElevator> el1, std::reference_wrapper<GuiElevator> el2) {
    return el1.get().getElevatorNumber() < el2.get().getElevatorNumber();
}
