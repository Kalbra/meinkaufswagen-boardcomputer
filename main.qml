import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 1.6



Window {
    visible: true
    width: 800
    height: 480
    color: "#000000"
    title: qsTr("Board Computer")
    //flags: Qt.FramelessWindowHint | Qt.Window

    Item {
        id: gird
        x: 0
        y: 0
        width: 800
        height: 480

        Rectangle {
            id: rectangle
            x: 0
            y: 0
            width: 401
            height: 67
            color: "#00000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle1
            x: 400
            y: 0
            width: 400
            height: 67
            color: "#00000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle2
            x: 0
            y: 413
            width: 401
            height: 67
            color: "#00000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle3
            x: 400
            y: 413
            width: 400
            height: 67
            color: "#00000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle4
            x: 799
            y: 66
            width: 1
            height: 348
            color: "#00000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle6
            x: 0
            y: 66
            width: 1
            height: 348
            color: "#00000000"
            border.color: "#ffffff"
        }
    }


    Item {
        id: main_display
        x: 0
        y: 0
        width: 800
        height: 480

        Connections {
            target: qml_bridge
            onSetting_displayChanged: {
                if(qml_bridge.display_id === 0)
                    main_display.visible = true
                else
                    main_display.visible = false
            }
        }

        Item {
            id: lap_time
            x: 0
            y: 66
            width: 176
            height: 348

            Text {
                id: lap_time_1
                x: 0
                y: 26
                width: 176
                height: 47
                color: qml_bridge.delta1_color
                text: qml_bridge.delta1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                font.pixelSize: 41
            }

            Text {
                id: lap_time_2
                x: 0
                y: 73
                width: 176
                height: 47
                color: qml_bridge.delta2_color
                text: qml_bridge.delta2
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                font.pixelSize: 41
            }

            Text {
                id: lap_time_3
                x: 0
                y: 120
                width: 176
                height: 47
                color: qml_bridge.delta3_color
                text: qml_bridge.delta3
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                font.pixelSize: 41
            }

            Text {
                id: lap_time_4
                x: 0
                y: 168
                width: 176
                height: 47
                color: qml_bridge.delta4_color
                text: qml_bridge.delta4
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                font.pixelSize: 41
            }

            Text {
                id: lap_time_5
                x: 0
                y: 216
                width: 176
                height: 47
                color: qml_bridge.delta5_color
                text: qml_bridge.delta5
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                font.pixelSize: 41
            }

            Text {
                id: lap_time_6
                x: 0
                y: 264
                width: 176
                height: 47
                color: qml_bridge.delta6_color
                text: qml_bridge.delta6
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Arial"
                font.pixelSize: 41
            }
        }

        Item {
            id: signal_control
            x: 176
            y: 66
            width: 129
            height: 348

            Rectangle {
                id: engine_temp
                objectName: "engine_temp"
                x: 1
                y: 1
                width: 127
                height: 49
                color: qml_bridge.engine_temp_color

                Text {
                    id: engine_temp_text
                    x: 1
                    y: 1
                    width: 127
                    height: 49
                    color: "#ffffff"
                    text: qsTr("ENTP")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Arial"
                    font.pixelSize: 30
                }
            }

            Rectangle {
                id: ignore
                objectName: "ignore"
                x: 1
                y: 298
                width: 127
                height: 49
                color: qml_bridge.light_color

                Text {
                    id: light_text
                    x: 0
                    y: 0
                    width: 127
                    height: 49
                    color: "#ffffff"
                    text: qsTr("LIGT")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Arial"
                    font.pixelSize: 30
                }
            }

            Rectangle {
                id: oil_temp
                objectName: "oil_temp"
                x: 1
                y: 50
                width: 127
                height: 49
                color: qml_bridge.oil_temp_color
                Text {
                    id: oil_temp_text
                    x: 1
                    y: 1
                    width: 127
                    height: 49
                    color: "#ffffff"
                    text: qsTr("OLTP")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Arial"
                    font.pixelSize: 30
                }
            }

            Rectangle {
                id: battery_status
                objectName: "battery_status"
                x: 1
                y: 99
                width: 127
                height: 49
                color: qml_bridge.battery_status_color
                Text {
                    id: battery_status_text
                    x: 1
                    y: 1
                    width: 127
                    height: 49
                    color: "#ffffff"
                    text: qsTr("BAST")
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.family: "Arial"
                    font.pixelSize: 30
                }
            }

            Rectangle {
                id: serial_status
                objectName: "serial_status"
                x: 1
                y: 148
                width: 127
                height: 49
                color: qml_bridge.serial_status_color
                Text {
                    id: serial_status_text
                    x: 1
                    y: 1
                    width: 127
                    height: 49
                    color: "#ffffff"
                    text: qsTr("SLST")
                    font.pixelSize: 30
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.family: "Arial"
                }
            }


        }

        Text {
            id: total_distance_display
            x: 400
            y: 413
            width: 400
            height: 67
            color: "#ffffff"
            text: qml_bridge.total_distance
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Arial"
            font.pixelSize: 53
        }

        Text {
            id: lap_time_display
            x: 0
            y: 413
            width: 400
            height: 67
            color: "#ffffff"
            text: qml_bridge.lap_time
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Arial"
            font.pixelSize: 53
        }

        Text {
            id: average_speed_display
            x: 0
            y: 0
            width: 400
            height: 67
            color: "#ffffff"
            text: qml_bridge.average_speed
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Arial"
            font.pixelSize: 53
        }

        Text {
            id: cruise_control_display
            x: 400
            y: 0
            width: 400
            height: 67
            color: "#ffffff"
            text: qml_bridge.cruise_control
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.family: "Arial"
            font.pixelSize: 53
        }

        Item {
            id: speed_display
            x: 345
            y: 92
            width: 446
            height: 259

            Text {
                id: speed
                x: 8
                y: 45
                width: 387
                height: 222
                color: "#ffffff"
                text: qml_bridge.speed_string
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Arial"
                font.pixelSize: 199
            }

            Text {
                id: unit
                x: 322
                y: 8
                width: 129
                height: 48
                color: "#ffffff"
                text: qsTr("km/h")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.family: "Arial"
                font.pixelSize: 54
            }
        }

        Rectangle {
            id: rpm
            x: 535
            y: 148
            width: 35
            height: 494
            rotation: 90
            gradient: Gradient {
                GradientStop {
                    position: 0.99
                    color: "#0aff4b"
                }

                GradientStop {
                    position: 0.519
                    color: "#ffce00"
                }

                GradientStop {
                    position: 0
                    color: "#ff0000"
                }

            }
            border.width: 0
            border.color: "#00000000"
        }

        Rectangle {
            id: rpmoverlay
            x: qml_bridge.rpm_progressbar - 189
            y: 377
            width: qml_bridge.rpm_progressbar
            height: 36
            color: "#000000"
            rotation: 0
        }

        Rectangle {
            id: signal_grid
            x: 176
            y: 66
            width: 129
            height: 348
            color: "#00000000"
            border.color: "#ffffff"
        }
    }

    Item {
        id: info_display
        x: 1
        y: 1
        width: 800
        height: 480
        visible: {
            if(qml_bridge.display_id === 1)
                visible = true
            else
                visible = false

        }
        Connections {
            target: qml_bridge
            onSetting_displayChanged: {
                if(qml_bridge.display_id === 1)
                    info_display.visible = true
                else
                    info_display.visible = false
            }
        }


        Rectangle {
            id: middle_line
            x: 399
            y: 66
            width: 1
            height: 348
            color: "#00000000"
            border.color: "#ffffff"
        }

        Rectangle {
            id: rectangle7
            x: 0
            y: 136
            width: 800
            height: 1
            color: "#00000000"
            border.color: "#ffffff"
            border.width: 1
        }

        Rectangle {
            id: rectangle8
            x: 0
            y: 205
            width: 800
            height: 1
            color: "#00000000"
            border.color: "#ffffff"
            border.width: 1
        }

        Rectangle {
            id: rectangle9
            x: 0
            y: 274
            width: 800
            height: 1
            color: "#00000000"
            border.color: "#ffffff"
            border.width: 1
        }

        Rectangle {
            id: rectangle10
            x: 0
            y: 343
            width: 800
            height: 1
            color: "#00000000"
            border.color: "#ffffff"
            border.width: 1
        }

        Text {
            id: total_distance_display1
            x: 400
            y: 413
            width: 400
            height: 67
            color: "#ffffff"
            text: qml_bridge.total_distance
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: lap_time_display1
            x: 0
            y: 413
            width: 400
            height: 67
            color: "#ffffff"
            text: qml_bridge.lap_time
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: average_speed_display1
            x: 0
            y: 0
            width: 400
            height: 67
            color: "#ffffff"
            text: qml_bridge.average_speed
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: cruise_control_display1
            x: 400
            y: 0
            width: 400
            height: 67
            color: "#ffffff"
            text: qml_bridge.cruise_control
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: engine_temp_display
            x: 0
            y: 66
            width: 400
            height: 71
            color: "#ffffff"
            text: qml_bridge.engine_temp
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: oil_temp_display
            x: 0
            y: 136
            width: 400
            height: 71
            color: "#ffffff"
            text: qml_bridge.oil_temp
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: battery_charge_display
            x: 0
            y: 205
            width: 400
            height: 71
            color: "#ffffff"
            text: qml_bridge.battery_charge
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: total_time_display
            x: 0
            y: 274
            width: 400
            height: 70
            color: "#ffffff"
            text: qml_bridge.total_time
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: rpm_display
            x: 0
            y: 344
            width: 400
            height: 70
            color: "#ffffff"
            text: qml_bridge.rpm
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }

        Text {
            id: speed_small_display
            x: 400
            y: 66
            width: 400
            height: 71
            color: "#ffffff"
            text: qml_bridge.speed_string
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 53
            font.family: "Arial"
            horizontalAlignment: Text.AlignHCenter
        }
    }
}

/*##^##
Designer {
    D{i:8;invisible:true}
}
##^##*/
