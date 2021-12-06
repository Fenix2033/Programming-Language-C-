import QtQuick 2.11
import QtQuick.Window 2.11
import QtLocation 5.11
import QtPositioning 5.11

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Weather Forecast")

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        plugin: mapPlugin
        anchors.fill: parent
        zoomLevel: (maximumZoomLevel - minimumZoomLevel)/2
        center {
            // The Qt Company in Oslo
            latitude: 49.9485
            longitude: 17.7686
        }

        MouseArea{
            anchors.fill: parent

            onDoubleClicked: {
                map.zoomLevel += 1
            }

            onClicked: {
                temperatureLabel.text = "Temperature is: "+"YYY"
                markerText.text = "..."

                // convert screen coordinates to world coordinates
                const coordinates = map.toCoordinate(Qt.point(mouse.x,mouse.y))

                // request weather download
                weather.getTemperature(coordinates.latitude, coordinates.longitude)

                // position the marker
                marker.coordinate = coordinates
                marker.visible = true
            }
        }

        MapQuickItem {
                id:marker
                visible: false
                sourceItem: Item {
                    id: markerContent
                    height: 45
                    width: 30
                    Text {
                        id: markerText
                        text: "..."
                        font.pixelSize: 20
                        font.bold: true
                        anchors {
                            top: parent.top
                        }
                    }
                    Image {
                        id: markerImage
                        source: "marker.webp"
                        width: 20
                        anchors {
                            top: markerText.bottom
                            bottom: parent.bottom
                        }
                    }
                }
                coordinate: map.center
                anchorPoint.x: markerContent.width / 2
                anchorPoint.y: markerContent.height / 2
            }

        Text {
            id: temperatureLabel
            text: qsTr("Temperature is: XXX")
            font {
                bold: true
                pixelSize: 15
            }

            Connections {
                target: weather
                function onNewTemperature(temperature) {
                    temperatureLabel.text = temperature
                    markerText.text = temperature
                }
            }
        }
    }
}
