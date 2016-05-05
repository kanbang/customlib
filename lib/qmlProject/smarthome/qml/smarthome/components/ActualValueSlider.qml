/** This file is part of Home Control Qt Quick Embedded Widgets Demo**
*
* Copyright © 2010 Nokia Corporation and/or its subsidiary(-ies).*
* All rights reserved.
*
* Contact:  Nokia Corporation (qt-info@nokia.com)
*
* You may use this file under the terms of the BSD license as follows:
*
* “Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
* Neither the name of Nokia Corporation and its Subsidiary(-ies) nor the
* names of its contributors may be used to endorse or promote products
* derived from this software without specific prior written permission.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.”
*/

import Qt 4.7

/**
* This element represents a slider with a scale and a knob that sets a value
* on that scale. It also features an optional speechbubble hovering over the
* knob to display the value that is currently set. The the distance covered
* by the knob in pixels to change the real value of the slider can be
* modified by the user. The slider also features an optional needle that can
* be used to show another value that is currently set. There also is a high-
* light that can used to hightlight the value that currently is set (in case
* of the value being images above the actual slider for example). The other
* visual elements can also be customized by user specific images.
*
* int pixelPerValue:           Sets how many pixels the knob has to be slid to
*                              change the value
* real value:                  The value that the knob is set to from the
*                              outside
* real actualValue:            The value that sets the position of the needle
* alias needleVisible:         Can be used to hide/show the needle
* int valueSliderHeight:       The height of the slider
* int balloonHeight:           The height of the balloon
* int balloonTriangleHeight:   The height of the triangle below the balloon
* string backgroundImage:      The image of the background
* string balloonImage:         The image of the balloon
* string balloonTriangleImage: The image of the triangle below the balloon
* string knobImagePressed:     The image of the pressed knob
* string knobImageNormal:      The image of the knob when not pressed
* string needleImage:          The image of the needle
* string focusImage:           The image of the highlight
* alias focusVisible:          Can be used to hide/show the focus
*
*/
Item {
    id: actualValueSlider

    property string balloonText: ""
    property int pixelPerValue: 8
    property real value: 0
    property real actualValue: 0
    property alias needleVisible: actualNeedle.visible

    // this value sets the height of the background
    property int valueSliderHeight
    property int balloonHeight
    property int balloonTriangleHeight

    property string backgroundImage
    property string balloonImage
    property string balloonTriangleImage
    property string knobImagePressed
    property string knobImageNormal
    property string needleImage
    property alias focusVisible: focus.visible
    property string focusImage
    property real maxSliderValue: width / pixelPerValue - knob.offset

    // the overall height of the item must be determined by its components
    height: background.height + balloonBackground.height + triangle.height

    /**
    * This Image draws the slider background
    */
    Image {
        id: background
        y: 100
        width: parent.width
        height: valueSliderHeight
        source: backgroundImage
        smooth: true
    }

    /**
    * This Image draws the current value of the outside world e.g. current temperature
    */
    Image {
        id: actualNeedle
        // since value can be set from outside the actual position of the slider
        // has to be determined with an offset
        x: background.x - actualNeedle.width / 2 + 22 + actualValue * pixelPerValue
        anchors.top: background.top
        source: needleImage
        smooth:  true
    }

    /**
    * This Image draws the user value (can be dragged)
    */
    Image {
        id: knob

        property bool pressed: false
        property int offset: 6

        source: knob.pressed ? knobImagePressed : knobImageNormal
        // since value can be set from outside the actual position of the slider
        // has to be determined with an offset
        x: background.x - knob.width / 2 + 22 + value * pixelPerValue
        anchors.top: background.top
        anchors.topMargin: 2
        smooth: true

        /**
        * This area makes it dragable
        */
        MouseArea {
            anchors.fill: parent
            drag {
                target: parent
                axis: Drag.XAxis
                minimumX: -knob.offset
                maximumX: background.width - knob.width + knob.offset
            }

            onPressed: knob.pressed = true
            onReleased: knob.pressed = false

            onPositionChanged: {
                value = (knob.x + knob.offset) / pixelPerValue
            }
        }
    }

    Image {
        id: focus
        source: (visible == true) ? focusImage : ""
        anchors {
            bottom: background.top
            horizontalCenter: knob.horizontalCenter
        }
    }

    /**
    * A Borderimage is used to surround the ballon texts.
    */
    BorderImage {
        id: balloonBackground
        source: visible ? balloonImage : ""
        width: balloon.width + 60
        height: balloonHeight
        border { left: 25; right: 25; top: 26; bottom: 26 }
        smooth: true
        visible: balloonText.length > 0
        anchors.horizontalCenter: triangle.horizontalCenter
        anchors.bottom: triangle.top
        anchors.bottomMargin: -4

        Text {
            id: balloon
            anchors.centerIn: parent
            font {
                pointSize: 14
                bold: true
            }
            text: balloonText
        }

        Behavior on width {
            NumberAnimation {
                duration: 200
            }
        }
    }

    Image {
        id: triangle
        visible: balloonBackground.visible
        source: visible ? balloonTriangleImage : ""
        height: balloonTriangleHeight
        smooth: true
        anchors.bottom: knob.top
        anchors.bottomMargin: 10
        anchors.horizontalCenter: knob.horizontalCenter
    }
}
