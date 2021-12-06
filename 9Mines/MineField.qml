import QtQuick 2.0

Rectangle {
    property int mineFieldSize: 6
    color: "lightgray"
    anchors.fill: parent

    Grid {
        anchors.centerIn: parent
        columns: mineFieldSize
        spacing: 3

        Repeater {
            model: mineFieldSize*mineFieldSize

            MineTile {
                tileIndex: index
            }
        }
    }

}
