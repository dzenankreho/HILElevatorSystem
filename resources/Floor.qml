import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    property alias lift1Number: lift1.number
    property alias lift2Number: lift2.number
    property var closeLift1Door: lift1.closeDoor
    property var openLift1Door: lift1.openDoor
    property var closeLift2Door: lift2.closeDoor
    property var openLift2Door: lift2.openDoor
    property var liftCallButton: button
    property int spratNumber
    property var buttonCppClass

    ColumnLayout {
        spacing: 0
        Rectangle {
            color: "#cecece"
            width: 564
            height: mainWindow.height / 3 - pod.height
        }
        Rectangle {
            id: pod
            color: "#a3a3a3"
            width: 564
            height: 10
        }
    }


    Elevator {
        id: lift1
        x: 50
        y: mainWindow.height / 3 - frameHeight - pod.height
    }


    Elevator {
        id: lift2
        x: 50 + lift1.frameWidth + 100
        y: mainWindow.height / 3 - frameHeight - pod.height
    }


    Rectangle {
        id: button
        color: "#828282"
        width: 30
        height: width
        radius: width / 2
        border.width: 3
        border.color: "transparent"
        x: 50 + lift1.frameWidth + 50 - width / 2
        y: mainWindow.height / 3 - lift1.frameHeight / 2 - pod.height - height / 2

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
