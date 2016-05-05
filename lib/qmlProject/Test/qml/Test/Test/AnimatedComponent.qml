import QtQuick 1.1

Rectangle{
    id: one
    x:200
    width: 10
    height: 10
    color: "red"
    radius: 45
    anchors.verticalCenter: parent.verticalCenter
    property int interval: 10
    state: 'show'

    states: [
        State {
            name: "show"

            PropertyChanges {
                target: one
                x:200
                opacity: 1.0
            }
        },

        State {
            name: "hide"

            PropertyChanges {
                target: one
                x: 100
                opacity: 0
            }
        }
    ]

    transitions: [
        Transition {
            from: "show"
            to: "hide"
           SequentialAnimation {
               ParallelAnimation {
                   PropertyAnimation{
                       target: one
                       properties: "x"
                       easing.type: Easing.OutBounce
                       duration: 1000
                   }

                   PropertyAnimation{
                       target: one
                       properties: "opacity"
                       easing.type: Easing.OutBounce
                       duration: 1000
                   }
               }
           }
        }
    ]

    Timer{
        running: false
        repeat: true
        interval: parent.interval

        onTriggered: {
            if(parent.state == 'show')
            {
                parent.state = 'hide'
            }
            else
            {
                parent.state = 'show'
            }

            console.log("=========",parent.interval)
        }
    }
}
