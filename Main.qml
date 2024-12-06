import QtQuick 2.15
import QtQuick.Controls 2.15
import Traffic_light 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 500
    height: 800
    title: qsTr("Traffic Light Control")

    Column {
        anchors.centerIn: parent
        spacing: 20 // Space between the traffic light and the button

        // Traffic Light with the bar
        Column {
            id: trafficSignal
            anchors.horizontalCenter: parent

            Rectangle {
                id: trafficLight
                width: 150
                height: 400
                radius: 20
                color: "#333"

                Column {
                    spacing: 10
                    anchors.centerIn: parent

                    Rectangle {
                        id: redLight
                        width: 100
                        height: 100
                        radius: 75
                        color: "gray"
                        border.color: "black"
                        border.width: 2
                    }

                    Rectangle {
                        id: yellowLight
                        width: 100
                        height: 100
                        radius: 75
                        color: "gray"
                        border.color: "black"
                        border.width: 2
                    }

                    Rectangle {
                        id: greenLight
                        width: 100
                        height: 100
                        radius: 75
                        color: "gray"
                        border.color: "black"
                        border.width: 2
                    }
                }
            }

            Rectangle {
                id: bar
                width: 30
                height: 50
                anchors.horizontalCenter: trafficLight.horizontalCenter
                color: "#333"
            }
        }

        // Button positioned below the traffic light
        Button {
            id: triggerButton
            text: "Trigger Traffic Light"
            anchors.horizontalCenter: trafficSignal.horizontalCenter
            onClicked: trafficLightController.Button()
        }
    }

    Connections {
        target: trafficLightController

        function onRedLight() {
            redLight.color = "red"
            yellowLight.color = "gray"
            greenLight.color = "gray"
        }
        function onYellowLight() {
            redLight.color = "gray"
            yellowLight.color = "yellow"
            greenLight.color = "gray"
        }
        function onGreenLight() {
            redLight.color = "gray"
            yellowLight.color = "gray"
            greenLight.color = "green"
        }
    }
}
