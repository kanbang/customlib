import QtQuick 2.2


Rectangle {
    x: 0
    y: 0
    width: parent.width
    height: 300*divscale
    color: "lightgray"
    property variant items: [ portrait, nameText, numberText, durationText, stateText, hideText];

    Rectangle {
        id: portrait
        anchors.left: parent.left
        anchors.leftMargin: 20 *divscale
        anchors.top: parent.top
        anchors.topMargin: 20 *divscale
        width: 200*divscale
        height: 200*divscale
        radius: 40

        function layoutForState(statesText)
        {
            if( statesText == 'hideFlags')
            {
                portrait.visible = false;
            }

            if(statesText == 'harassment')
            {
                portrait.color = "blue"
            } else
            {
                portrait.color = 'white'
            }
        }
    }

    Text {
        id: nameText
        anchors.top: portrait.top
        anchors.left: portrait.right
        anchors.leftMargin: 20 *divscale
        font.pixelSize: 70 *divscale

        text: "xingkongdao"

        function layoutForState(statesText)
        {
            if(statesText == 'hideFlags')
            {
                nameText.visible = false;
            }
            else if (statesText == 'contact')
            {
                nameText.text = '15120077642'
            }
        }
    }

    Text {
        id: numberText
        anchors.top: nameText.bottom
        anchors.topMargin: 20* divscale
        anchors.left: portrait.right
        anchors.leftMargin: 20 *divscale
        font.pixelSize: 30 *divscale
        text: "15120077642 | china mobile"

        function layoutForState(statesText)
        {
            if(statesText == 'hideFlags')
            {
                numberText.visible = false;
            }
            else if (statesText == 'contact')
            {
                numberText.text  = ' china mobile'
            }

        }
    }

    Text {
        id: durationText
        property string temp: "39: 45 | It is "
        anchors.top: numberText.bottom
        anchors.topMargin: 20* divscale
        anchors.left: portrait.right
        anchors.leftMargin: 20*divscale
        font.pixelSize: 30*divscale

        text: temp

        function layoutForState(statesText)
        {
            if(statesText != 'hideFlags')
            {
                durationText.text = temp + statesText;
            }
            else
            {
                durationText.visible = false;
            }

        }
    }

    Text {
        id: stateText
        anchors.left: parent.left
        anchors.leftMargin: 20 *divscale
        anchors.top: parent.top
        anchors.topMargin: 20 *divscale

        font.pixelSize: 70*divscale

        text: "INCOMING ..."
        visible: false

        function layoutForState(statesText)
        {
            if( statesText == 'hideFlags')
            {
                stateText.visible = true;
            }
        }
    }

    Text {
        id: hideText
        anchors.left: parent.left
        anchors.leftMargin: 20 *divscale
        anchors.top: stateText.bottom
        anchors.topMargin: 20 *divscale

        font.pixelSize: 50*divscale

        text: "Hide all icons , Press to show the icons."
        visible: false

        function layoutForState(statesText)
        {
            if( statesText == 'hideFlags')
            {
                hideText.visible = true;
            }
        }
    }

    function layoutForState(statesText)
    {
        for(var i = 0; i<items.length; i++)
        {
            items [i].layoutForState(statesText);
        }
    }
}
