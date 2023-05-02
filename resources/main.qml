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
        id:sprat3
        spratNumber: 2
        buttonCppClass: elevatorCallButton2
        x: 0
        y: 0
        lift1Number: "2"
        lift2Number: "2"
        Connections {
            target: elevatorCallButton2
            function onTurnOnBacklight() {
                sprat3.liftCallButton.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                sprat3.liftCallButton.turnOffBacklight()
            }
        }
    }


    Floor {
        id:sprat2
        spratNumber: 1
        buttonCppClass: elevatorCallButton1
        x: 0
        y: mainWindow.height / 3
        lift1Number: "1"
        lift2Number: "1"
        Connections {
            target: elevatorCallButton1
            function onTurnOnBacklight() {
                sprat2.liftCallButton.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                sprat2.liftCallButton.turnOffBacklight()
            }
        }
    }


    Floor {
        id:sprat1
        spratNumber: 0
        buttonCppClass: elevatorCallButton0
        x: 0
        y: 2 * mainWindow.height / 3
        lift1Number: "0"
        lift2Number: "0"
        Connections {
            target: elevatorCallButton0
            function onTurnOnBacklight() {
                sprat1.liftCallButton.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                sprat1.liftCallButton.turnOffBacklight()
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
                    sprat1.openLift1Door()
                    break;
                case 1:
                    sprat2.openLift1Door()
                    break;
                case 2:
                    sprat3.openLift1Door()
                    break;
                default:
                    break;
                }
            }
            function onCloseDoor(floor) {
                switch (floor) {
                case 0:
                    sprat1.closeLift1Door()
                    break;
                case 1:
                    sprat2.closeLift1Door()
                    break;
                case 2:
                    sprat3.closeLift1Door()
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
                    sprat1.openLift2Door()
                    break;
                case 1:
                    sprat2.openLift2Door()
                    break;
                case 2:
                    sprat3.openLift2Door()
                    break;
                default:
                    break;
                }
            }
            function onCloseDoor(floor) {
                switch (floor) {
                case 0:
                    sprat1.closeLift2Door()
                    break;
                case 1:
                    sprat2.closeLift2Door()
                    break;
                case 2:
                    sprat3.closeLift2Door()
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
