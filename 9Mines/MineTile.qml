import QtQuick 2.0

Rectangle {
    property int tileIndex: 0

    id: mineTile
    width: 64
    height: 64

    Image {
        id: tileImage
        source: "images/target.png"
        anchors.fill: parent
    }

    Text {
        id:tileText
        anchors.centerIn: parent
        color: "white"
        text: tileIndex
        font.bold: true
    }

    MouseArea{
        anchors.fill: parent

        onClicked: {
            var mineCount = generator.getMineCount(tileIndex)

            if (mineCount === 9){
                mineTile.state = "boom";
                endBanner.visible = true;
                parent.parent.enabled = false; // prevent further clicking
            } else if (parent.state == ''){
                mineTile.state = "revealed";
                tileText.text = mineCount;
                generator.increaseScore(1);
            }
        }
    }

    states: [
        State {
            name: "boom"
            PropertyChanges {
                target: tileImage
                source: "images/mine.jpg"
            }
            PropertyChanges {
                target: tileText
                visible: false
            }
        },
        State {
            name: "revealed"
            PropertyChanges {
                target: tileImage
                visible: false
            }
            PropertyChanges {
                target: tileText
                color: "black"
            }
        }
    ]
}
