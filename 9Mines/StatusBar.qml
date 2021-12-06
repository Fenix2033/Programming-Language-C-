import QtQuick 2.0

Rectangle {
    width: parent.width
    height: 30
    color: "white"

    Text {
        id: label
        text: "Score: " + generator.score
        font {
            pixelSize: 15
            bold: true
        }

        anchors {
            left: parent.left
            leftMargin: 10
            verticalCenter: parent.verticalCenter
        }
    }
}
