import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 480
    height: 480
    title: qsTr("Hello World")

    MineField {
        id: mineField
    }

    StatusBar {
        anchors {
            top: parent.top
            right: parent.right
        }
    }

    GameEnd {
        id: endBanner
        gameText: "You Lost!"
        visible: false
    }
}
