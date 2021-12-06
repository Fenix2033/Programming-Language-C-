import QtQuick 2.0

Rectangle {
    id: button
    property string title: "" // vlastni atribut tlacitka, pouziva se jako obsah vnoreneho textu

    color: "red"
    width: parent.width * 0.3
    height: parent.height * 0.1

    Text {
        text: button.title
        color: "white"
        font.bold: true
        font.pixelSize: 30
        anchors.centerIn: parent
    }

    states: [
        State {
            name: "pressed"
            PropertyChanges {
                target: button
                color: "blue"
            }
        },
        State {
            name: "hover"
            PropertyChanges {
                target: button
                color: "orange"
            }
        }
    ]

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onClicked:
            if (button.state == "pressed") {
                button.state = "hover"
            } else {
                button.state = "pressed"
            }
        onEntered:
            if (button.state != "pressed") {
                button.state = "hover"
            }
        onExited:
            if (button.state != "pressed") {
                button.state = ""
            }
    }

    transitions: Transition {
        ColorAnimation {
            duration: 200 // ms
        }
    }
}
