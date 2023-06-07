import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    property alias elevator1Number: elevator1.number
    property alias elevator2Number: elevator2.number
    property var closeElevator1Door: elevator1.closeDoor
    property var openElevator1Door: elevator1.openDoor
    property var closeElevator2Door: elevator2.closeDoor
    property var openElevator2Door: elevator2.openDoor
    property var elevatorCallButton: button
    property int floorNumber
    property var buttonCppClass

    ColumnLayout {
        spacing: 0
        Rectangle {
            color: "#cecece"
            width: 564
            height: mainWindow.height / 3 - ground.height
        }
        Rectangle {
            id: ground
            color: "#a3a3a3"
            width: 564
            height: 10
        }
    }


    Elevator {
        id: elevator1
        x: 50
        y: mainWindow.height / 3 - frameHeight - ground.height
    }


    Elevator {
        id: elevator2
        x: 50 + elevator1.frameWidth + 100
        y: mainWindow.height / 3 - frameHeight - ground.height
    }


    Rectangle {
        id: button
        color: "#828282"
        width: 30
        height: width
        radius: width / 2
        border.width: 3
        border.color: "transparent"
        x: 50 + elevator1.frameWidth + 50 - width / 2
        y: mainWindow.height / 3 - elevator1.frameHeight / 2 - ground.height - height / 2

        function turnOnBacklight() {
            button.border.color = "yellow"
        }

        function turnOffBacklight() {
            button.border.color = "transparent"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                buttonCppClass.buttonPressed()
            }
        }
    }
}
