#include "LearnQml.h"

LearnQml::LearnQml()
{
    /**
      锚描述：
    anchors.top : AnchorLine
    anchors.bottom : AnchorLine
    anchors.left : AnchorLine
    anchors.right : AnchorLine

    anchors.horizontalCenter : AnchorLine
    anchors.verticalCenter : AnchorLine
    anchors.baseline : AnchorLine

    anchors.margins : real
    anchors.topMargin : real        当前Item的位置加上旁白值
    anchors.bottomMargin : real     当前Item的位置减去旁白值
    anchors.leftMargin : real       当前Item的位置加上旁白值
    anchors.rightMargin : real      当前Item的位置减去旁白值

    当前Item的中心坐标加上偏移值
    anchors.horizontalCenterOffset : real
    anchors.verticalCenterOffset : real
    anchors.baselineOffset : real

    anchors.centerIn : Item
    anchors.fill : Item

    anchors.mirrored : bool

    ***************************************************
    action                  The action type has all the properties of QAction.
    bool                    A boolean is a binary true/false value.
    color                   A color is a standard color name in quotes.
    date                    A date is specified as "YYYY-MM-DD".
    double                  A double number has a decimal point and is stored in double precision.
    enumeration             An enumeration type consists of a set of named values.
    font                    A font type has the properties of a QFont.
    int                     An integer is a whole number, e.g. 0, 10, or -20.
    list                    A list of objects.
    point                   A point type has x and y attributes.
    real                    A real number has a decimal point, e.g. 1.2 or -29.8.
    rect                    A rect type has x, y, width and height attributes.
    size                    A size type has width and height attributes
    string                  A string is a free form text in quotes, e.g. "Hello world!".
    time                    A time is specified as "hh:mm:ss".
    url                     A URL is a resource locator, like a file name.
    variant                 A variant type is a generic property type.
    vector3d                A vector3d type has x, y, and z attributes.
    ****************************************************************
      */

    variant();
}


void LearnQml::Item()
{
    /**
      所有对象的基类，在QML中，所有的可视化的项都继承它
      它定义了所有可视化项的一般属性，像： x、y的位置，以及width、height，和锚。
      锚提供了一种通过指定该项与其他项的关系来定位一个项
      */
}

void LearnQml::Item_example()
{
    /**
    Item {
         Image {
             source: "tile.png"
         }
         Image {
             x: 80
             width: 100
             height: 100
             source: "tile.png"
         }
         Image {
             x: 190
             width: 100
             height: 100
             fillMode: Image.Tile
             source: "tile.png"
         }
     }
     ************************************
    当键盘按下的适合，或者按下事件，当是按下左方向键的时候
    Item {
         focus: true
         Keys.onPressed: {
             if (event.key == Qt.Key_Left) {
                 console.log("move left");
                 event.accepted = true;
             }
         }
         Keys.onSelectPressed: console.log("Selected");
     }

     *******************************
    输入窗口获得焦点
    Rectangle {
         FocusScope {
             focus: true
             TextInput {
                 id: input
                 focus: true
             }
         }
     }
     ********************************
    文本显示在图片的下面，两个Item的中心位置的x坐标相等
    文本距离图片底部 有5个像素的距离，如果anchors.topMargins: -5
    则位置重复了
    Item {
         Image {
             id: pic
             // ...
         }
         Text {
             id: label
             anchors.horizontalCenter: pic.horizontalCenter
             anchors.top: pic.bottom
             anchors.topMargin: 5
             // ...
         }
     }

    *************************************
     Item {
         Image {
             id: pic
             // ...
         }
         Text {
             id: label
             anchors.left: pic.right
             anchors.leftMargin: 5
             // ...
         }
     }

    ************************************

     Item {
         children: [
             Text {},
             Rectangle {}
         ]
         resources: [
             Component {
                 id: myComponent
                 Text {}
             }
         ]
     }
     ***********************************
     Item {
         children: [
             Text {},
             Rectangle {}
         ]
         resources: [
             Timer {}
         ]
     }
    ************************************
    // Label.qml
     import QtQuick 1.1

     Item {
         property alias icon: image.source
         property alias label: text.text
         implicitWidth: text.implicitWidth + image.implicitWidth
         implicitHeight: Math.max(text.implicitHeight, image.implicitHeight)
         Image { id: image }
         Text {
             id: text
             wrapMode: Text.Wrap
             anchors.left: image.right; anchors.right: parent.right
             anchors.verticalCenter: parent.verticalCenter
         }
     }

    *****************************************
    矩形透明，由于父类的opacity： 0.5,所以，由于父类和所有的子类的透明都是一个值。
    Item {
         Rectangle {
             opacity: 0.5
             color: "red"
             width: 100; height: 100
             Rectangle {
                 color: "blue"
                 x: 50; y: 50; width: 100; height: 100
             }
         }
     }
    *********************************************************
    // 旋转角度
    Rectangle {
         color: "blue"
         width: 100; height: 100
         Rectangle {
             color: "red"
             x: 25; y: 25; width: 50; height: 50
             rotation: 30
         }
     }

    **********************************************************
    伸缩
    Rectangle {
         color: "blue"
         width: 100; height: 100
         Rectangle {
             color: "green"
             width: 25; height: 25
         }
         Rectangle {
             color: "red"
             x: 25; y: 25; width: 50; height: 50
             scale: 1.4
         }
     }

    function toggle() {
         if (button.state == 'On')
             button.state = 'Off';
         else
             button.state = 'On';
     }
    ****************
    状态，需要和transitions 一起用，达到动画的效果
    Item {
         states: [
             State {
                 // ...
             },
             State {
                 // ...
             }
             // ...
         ]
     }
    *************************

    Image {
         source: "myimage.png"
         transformOrigin: Item.BottomRight
         rotation: 45
     }

    ***********************************************

    Item {
         transitions: [
             Transition {
                 // ...
             },
             Transition {
                 // ...
             }
             // ...
         ]
     }

    *****************
     图层的概念
    Item {
         Rectangle {
             z: 1
             color: "red"
             width: 100; height: 100
         }
         Rectangle {
             color: "blue"
             x: 50; y: 50; width: 100; height: 100
         }
     }


**/
}

void LearnQml::Flipable_example()
{
    /**
        Rectangle {
            id: rect
            width: 360
            height: 360

            Flipable {
            id: flipable
            width: 240
            height: 240
            property int angle: 0
            property bool flipped: false
            front: Image { source: "/home/xkd1/share/ebook/learn/program/qmlProject/Test/qml/Test/SmartHome/pics/icons/jalousie_down.png" } // 前面
            back: Image { source: "/home/xkd1/share/ebook/learn/program/qmlProject/Test/qml/Test/SmartHome/pics/icons/jalousie_up.png" } // 后面
            // 旋转动画 前后面交换
            transform: Rotation {
            origin.x: flipable.width/2; origin.y: flipable.height/2
            axis.x: 0; axis.y: 1; axis.z: 0 // rotate around y-axis
            angle: flipable.angle
            }
            states: State {
            name: "back"
            PropertyChanges { target: flipable; angle: 180 }
            when: flipable.flipped
            }
            transitions: Transition {
            NumberAnimation { properties: "angle"; duration: 1000 }
            }
            MouseArea {
            anchors.fill: parent
            onClicked: flipable.flipped = !flipable.flipped
            }
        }
      */
}

void LearnQml::variant()
{
    /**
    property variant items:[1,2,3,"Four","Five"]
    function changeItem()
    {
        var cur = items;
        cur[0] ="xkd";
        只有这样才能改变items里面的值，通过items[index] = "**"这样的方式不能改变值
        items = cur;
        for(var i = 0; i< items.length; i++)
            console.log(items[i]);
    }
      */
}
