import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3


Window {
    width: 900
    height: 720
    id: mainWindow
    visible: true
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    color: "#cecece"


    Floor {
        id:floor3
        floorNumber: 2
        buttonCppClass: elevatorCallButton2
        x: 0
        y: 0
        elevator1Number: "2"
        elevator2Number: "2"
        Connections {
            target: elevatorCallButton2
            function onTurnOnBacklight() {
                floor3.elevatorCallButton.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                floor3.elevatorCallButton.turnOffBacklight()
            }
        }
    }


    Floor {
        id:floor2
        floorNumber: 1
        buttonCppClass: elevatorCallButton1
        x: 0
        y: mainWindow.height / 3
        elevator1Number: "1"
        elevator2Number: "1"
        Connections {
            target: elevatorCallButton1
            function onTurnOnBacklight() {
                floor2.elevatorCallButton.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                floor2.elevatorCallButton.turnOffBacklight()
            }
        }
    }


    Floor {
        id:floor1
        floorNumber: 0
        buttonCppClass: elevatorCallButton0
        x: 0
        y: 2 * mainWindow.height / 3
        elevator1Number: "0"
        elevator2Number: "0"
        Connections {
            target: elevatorCallButton0
            function onTurnOnBacklight() {
                floor1.elevatorCallButton.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                floor1.elevatorCallButton.turnOffBacklight()
            }
        }
    }


    Controls {
        id: controls1
        enabled: false
        button0CppClass: elevator1FloorButton0
        button1CppClass: elevator1FloorButton1
        button2CppClass: elevator1FloorButton2
        x: 564 + (mainWindow.width - 564 - 2 * controls1.width_) / 3
        y: (mainWindow.height - controls1.height_) / 2
        text.text: "LEFT\nELEVATOR"

        Connections {
            target: elevator1
            function onEnableElevatorButtons() {
                controls1.enabled = true
            }
            function onDisableElevatorButtons() {
                controls1.enabled = false
            }
            function onOpenDoor(floor) {
                switch (floor) {
                case 0:
                    floor1.openElevator1Door()
                    break;
                case 1:
                    floor2.openElevator1Door()
                    break;
                case 2:
                    floor3.openElevator1Door()
                    break;
                default:
                    break;
                }
            }
            function onCloseDoor(floor) {
                switch (floor) {
                case 0:
                    floor1.closeElevator1Door()
                    break;
                case 1:
                    floor2.closeElevator1Door()
                    break;
                case 2:
                    floor3.closeElevator1Door()
                    break;
                default:
                    break;
                }
            }
        }
    }

    Rectangle {
        id: disabledRect1
        color: "#cecece"
        opacity: 0.85
        width: controls1.width_ + 10
        height: controls1.height_ - 60
        x: 564 + (mainWindow.width - 564 - 2 * controls1.width_) / 3 - 5
        y: (mainWindow.height - controls1.height_) / 2 + 70
        visible: !controls1.enabled
    }

    Controls {
        id: controls2
        enabled: false
        button0CppClass: elevator2FloorButton0
        button1CppClass: elevator2FloorButton1
        button2CppClass: elevator2FloorButton2
        x: 564 + controls1.width_ + 2 * (mainWindow.width - 564 - 2 * controls1.width_) / 3
        y: (mainWindow.height - controls2.height_) / 2
        text.text: "RIGHT\nELEVATOR"

        Connections {
            target: elevator2
            function onEnableElevatorButtons() {
                controls2.enabled = true
            }
            function onDisableElevatorButtons() {
                controls2.enabled = false
            }
            function onOpenDoor(floor) {
                switch (floor) {
                case 0:
                    floor1.openElevator2Door()
                    break;
                case 1:
                    floor2.openElevator2Door()
                    break;
                case 2:
                    floor3.openElevator2Door()
                    break;
                default:
                    break;
                }
            }
            function onCloseDoor(floor) {
                switch (floor) {
                case 0:
                    floor1.closeElevator2Door()
                    break;
                case 1:
                    floor2.closeElevator2Door()
                    break;
                case 2:
                    floor3.closeElevator2Door()
                    break;
                default:
                    break;
                }
            }
        }
    }

    Rectangle {
        id: disabledRect2
        color: "#cecece"
        opacity: 0.85
        width: controls1.width_ + 10
        height: controls1.height_ - 60
        x: 564 + controls1.width_ + 2 * (mainWindow.width - 564 - 2 * controls1.width_) / 3 - 5
        y: (mainWindow.height - controls1.height_) / 2 + 70
        visible: !controls2.enabled
    }
}
