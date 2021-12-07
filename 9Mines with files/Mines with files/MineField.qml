import QtQuick 2.0

Rectangle {
    id: mineField
    property int mineSideCount: 5
    property alias mineSpacing: mineGrid.spacing
    color: "lightgray"

    Grid{
        x: mineSpacing
        y: mineSpacing
        id: mineGrid
        columns: mineSideCount
        spacing: 10

        Repeater{
            model: mineSideCount*mineSideCount

            MineTile{
                tileIndex: index
                width: (mineField.width/mineSideCount)-(mineSpacing/(mineSideCount-1)*mineSideCount)
                height: (mineField.height/mineSideCount)-(mineSpacing/(mineSideCount-1)*mineSideCount)
            }
        }
    }
}
