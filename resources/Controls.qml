import QtQuick 2.0

Item {
    property int height_: 6 * button0.width
    property int width_: button0.width
    property alias text: controlsText
    property var button0CppClass
    property var button1CppClass
    property var button2CppClass

    Text {
        id: controlsText
        width: button0.width
        height: width / 2
        font.family: "Helvetica"
        font.pointSize: 14
        color: "#ececec"
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
    }


    Rectangle {
        property bool borderEnabled: false
        id: button0
        color: "#828282"
        width: 100
        height: width
        radius: width / 2
        border.width: 7
        border.color: "transparent"
        x: 0
        y: 5 * width

        Text {
            id: number0
            x: (button0.width - width) / 2
            y: (button0.height - height) / 2
            font.family: "Helvetica"
            font.pointSize: 20
            color: "#ececec"
            font.bold: true
            text: "0"
        }

        function turnOnBacklight() {
            button0.border.color = "red"
            number0.color = "red"
        }

        function turnOffBacklight() {
            button0.border.color = "transparent"
            number0.color = "#ececec"
        }

        Connections {
            target: button0CppClass
            function onTurnOnBacklight() {
                button0.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                button0.turnOffBacklight()
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                button0CppClass.buttonPressed()
            }
        }
    }


    Rectangle {
        property bool borderEnabled: false
        id: button1
        color: "#828282"
        width: button0.width
        height: width
        radius: width / 2
        border.width: 7
        border.color: "transparent"
        x: 0
        y: 3 * width

        Text {
            id: number1
            x: (button0.width - width) / 2
            y: (button0.height - height) / 2
            font.family: "Helvetica"
            font.pointSize: 20
            color: "#ececec"
            font.bold: true
            text: "1"
        }

        function turnOnBacklight() {
            button1.border.color = "red"
            number1.color = "red"
        }

        function turnOffBacklight() {
            button1.border.color = "transparent"
            number1.color = "#ececec"
        }

        Connections {
            target: button1CppClass
            function onTurnOnBacklight() {
                button1.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                button1.turnOffBacklight()
            }
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                button1CppClass.buttonPressed()
            }
        }
    }


    Rectangle {
        property bool borderEnabled: false
        id: button2
        color: "#828282"
        width: button0.width
        height: width
        radius: width / 2
        border.width: 7
        border.color: "transparent"
        x: 0
        y: width

        Text {
            id: number2
            x: (button0.width - width) / 2
            y: (button0.height - height) / 2
            font.family: "Helvetica"
            font.pointSize: 20
            color: "#ececec"
            font.bold: true
            text: "2"
        }

        function turnOnBacklight() {
            button2.border.color = "red"
            number2.color = "red"
        }

        function turnOffBacklight() {
            button2.border.color = "transparent"
            number2.color = "#ececec"
        }

        Connections {
            target: button2CppClass
            function onTurnOnBacklight() {
                button2.turnOnBacklight()
            }
            function onTurnOffBacklight() {
                button2.turnOffBacklight()
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                button2CppClass.buttonPressed()
            }
        }
    }
}
