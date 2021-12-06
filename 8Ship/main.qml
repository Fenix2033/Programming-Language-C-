import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hra lode")

    Text {
        text: "Ahoj"

        // absolutni pozice
//        x: 10
//        y: 10

        // relativni pozice
        anchors.centerIn: parent

        // poradi elementu nad sebou smerem k uzivateli, vetsi hodnota znamena blize
//        z: 10
    }

    Button {
        id: buttonGame
        title: "HRA"
        anchors {
            left: parent.left
            top: parent.top
            leftMargin: 10
            topMargin: 10
        }
    }

    Button {
        id: buttonHelp
        title: "NAPOVEDA"
        anchors {
            left: buttonGame.right
            top: parent.top
            leftMargin: 10
            topMargin: 10
        }
    }

    Grid {
        id: grid
        columns: 2
        rows: 2
        spacing: 10

        anchors {
            top: buttonGame.bottom
            topMargin: 10
            left: parent.left
            leftMargin: 10
            right: parent.right
            rightMargin: 10
            bottom: parent.bottom
            bottomMargin: 10
        }
        
        Repeater {
            // misto ListModel{} muze byt jen cislo, napr. model: 25
            model: ListModel {
                ListElement {
                    tileColor: "navy"
                }
                ListElement {
                    tileColor: "brown"
                }
                ListElement {
                    tileColor: "orange"
                }
                ListElement {
                    tileColor: "yellow"
                }
            }

            // delegat, vola se opakovane pro kazdy ListElement
            // tileColor je vlastni atribut z ListElementu
            // pozor na konflikty s atributy QML, napr. nepouzivat color jako vlastni atribut
            Field {
                color: tileColor
                width: (parent.width / grid.columns) - grid.spacing * (grid.columns - 1) / grid.columns // nebo proste jen 5
                height: (parent.height / grid.columns) - grid.rows * (grid.rows - 1) / grid.rows // nebo proste jen 5
            }
        }
    }

}










