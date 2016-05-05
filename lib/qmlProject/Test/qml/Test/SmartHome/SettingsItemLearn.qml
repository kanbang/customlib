import QtQuick 1.1

Rectangle {
    property int currentMinute: 0
    property int currentHour: 0
    property int currentRain: 0
    property int currentWindForce: 0
    property int currentLux: 0
    property int currentTemperature: 0

    property real childOpacity: 0

    smooth: true
    radius: 15
    color: "#DA111316"
    //设置矩形拐角的颜色，线宽
    border {
        width: 3
        color: "lightgray"
    }

//    onChildOpacityChanged:
}
