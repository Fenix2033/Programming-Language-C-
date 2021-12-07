import QtQuick 2.0

Rectangle{
    property alias tileIndex: label.text
    property string previousState: ""
    id: mineTile
    width: 60
    height: 60
    border.width: 3
    border.color: "steelblue"
    color: "steelblue"
    radius: 4
    states: [
        State {
            name: "hovered"
            PropertyChanges {
                target: mineTile
                border.color: "lightblue"
            }
        },
        State {
            name: "boom"
            PropertyChanges {
                target: mineImg
                opacity: 100
            }
            PropertyChanges {
                target: label
                opacity: 0
            }
        }
    ]

    Image {
        id: mineImg
        opacity: 0
        source: "images/mine.png"
        width: parent.width-4
        height: parent.height-4
        anchors.centerIn: parent
        //anchors.fill: parent
    }

    Text {
        id: label
        text: "0"
        font {
            pixelSize: 24
            bold: true
        }
        color: "white"
        anchors.centerIn: parent
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked: {

            var mineCount = game.getMineCount(tileIndex)
            if (mineCount == 9){
                mineTile.state = "boom"
                mineTile.previousState = mineTile.state
            } else {
                label.text = mineCount
            }
        }

        onEntered: {
            mineTile.state = "hovered"
            mineTile.previousState = mineTile.state
        }

        onExited: {
            mineTile.state = mineTile.previousState
        }
    }
}
