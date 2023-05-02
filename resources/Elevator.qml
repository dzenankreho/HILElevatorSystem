import QtQuick 2.0

Item {
    property bool doorsClosed: true
    property alias frameWidth: frame.width
    property alias frameHeight: frame.height
    property alias number: number.text

    Rectangle {
        id: frame
        height: mainWindow.height / 5
        width: 182
        color: "#8c8c8c"
        x: 0
        y: 0
    }
    Rectangle {
        id: doors
        height: mainWindow.height / 5 - 30
        width: 162
        color: "#cdcdcd"
        x: (frame.width - width) / 2
        y: frame.height - height
        visible: doorsClosed
    }
    Rectangle {
        id: doorLine
        height: mainWindow.height / 5 - 30
        width: 2
        color: "#000000"
        x: frame.width / 2 - 1
        y: frame.height - height
        visible: doorsClosed
    }
    Rectangle {
        id: numberFrame
        height: 20
        width: 40
        color: "#000000"
        x: (frame.width - width) / 2
        y: (frame.height - doors.height - height) / 2
    }
    Text {
        id: number
        x: frame.width / 2 - width / 2
        y: (frame.height - doors.height - numberFrame.height) / 2
        font.family: "Helvetica"
        font.pointSize: 10
        color: "#0cf21b"
        font.bold: true
    }
    Rectangle {
        id: interiorWall
        height: mainWindow.height / 5 - 30
        width: 162
        color: "#ececec"
        x: (frame.width - width) / 2
        y: frame.height - height
        visible: !doorsClosed
    }
    Rectangle {
        id: handrest
        height: 20
        width: 122
        color: "#954520"
        x: (frame.width - width) / 2
        y: frame.height - height - 20
        visible: !doorsClosed
    }
    Rectangle {
        id: mirror
        height: 60
        width: 60
        color: "#d4e1ec"
        x: (frame.width - width) / 2
        y: frame.height - height - 40 - (doors.height - 100) / 2
        visible: !doorsClosed
    }
    Rectangle {
        id: door1Opened
        height: mainWindow.height / 5 - 30
        width: 10
        color: "#cdcdcd"
        x: (frame.width - doors.width) / 2
        y: frame.height - height
        visible: !doorsClosed
    }
    Rectangle {
        id: door2Opened
        height: mainWindow.height / 5 - 30
        width: 10
        color: "#cdcdcd"
        x: frame.width - 20
        y: frame.height - height
        visible: !doorsClosed
    }

    function closeDoor() {
        doorsClosed = true
    }

    function openDoor() {
        doorsClosed = false
    }
}
