import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 1024
    height: 768
    visible: true
    title: qsTr("Hello World")

    MineField{
        height: parent.height-60
        width: height
        anchors.centerIn: parent
        mineSpacing: 8
        mineSideCount: 6
    }

}
