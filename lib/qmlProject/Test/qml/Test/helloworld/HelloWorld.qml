import QtQuick 1.1

Rectangle {
    id: page
    width:500;height:200
    color:"lightgray"

    //声明属性变量
    property bool isYes: false

    /**
      Gradient GradientStop 分别在总高度的0 颜色红色 总高度的1/3 黄色 总高度的1是绿色
      */
    gradient: Gradient {
        GradientStop {
            position: 0.0; color: "red"
        }
        GradientStop {
            position: 0.33;color: "yellow";
        }
        GradientStop{
            position:0.66; color: "black";
        }
        GradientStop{
            position:1;color:"green";
        }
    }

    Image {
        id: background
//        width:32;height: 32
//        smooth:true
//        anchors.fill:  parent
//        sourceSize.width: 32
//        sourceSize.height: 32
//        anchors.left: page.left; anchors.leftMargin: 15
//        anchors.top: page.top; anchors.topMargin: 10
        source: "App/PanelBackGround(11).png"

    }
    Image {
        id: psv
        width:32;height: 32
        smooth:true
//        anchors.fill:  parent
        sourceSize.width: 32
        sourceSize.height: 32
        anchors.left: page.left; anchors.leftMargin: 15
        anchors.top: page.top; anchors.topMargin: 10
        source: "App/Psv.png"

        MouseArea{
            anchors.fill: parent
            onMousePositionChanged:{
//            psv.source= "App/Psv48.png"
            psv.sourceSize.width=48
            psv.sourceSize.height=32
            }
        }
    }

    Image {
        id: ades
        width:32;height: 32
        smooth:true
//        anchors.fill:  parent
        sourceSize.width: 32
        sourceSize.height: 32
        anchors.left: psv.right; anchors.leftMargin: 15
        anchors.top: page.top; anchors.topMargin: 10
        source: "App/Ades.png"
    }

    Image {
        id: basemap
        width:32;height: 32
        smooth:true
//        anchors.fill:  parent
        sourceSize.width: 32
        sourceSize.height: 32
        anchors.left: ades.right; anchors.leftMargin: 15
        anchors.top: page.top; anchors.topMargin: 10
        source: "App/Basemap.png"
    }

    Image {
        id: geointerpret
        width:32;height: 32
        smooth:true
//        anchors.fill:  parent
        sourceSize.width: 32
        sourceSize.height: 32
        anchors.left: basemap.right; anchors.leftMargin: 15
        anchors.top: page.top; anchors.topMargin: 10
        source: "App/GeoInterpret.png"
    }
    Image {
        id: epoffice
        width:32;height: 32
        smooth:true
//        anchors.fill:  parent
        sourceSize.width: 32
        sourceSize.height: 32
        anchors.left: geointerpret.right; anchors.leftMargin: 15
        anchors.top: page.top; anchors.topMargin: 10
        source: "App/epoffice.png"
    }
    Image {
        id: fracAnaly
        width:32;height: 32
        smooth:true
//        anchors.fill:  parent
        sourceSize.width: 32
        sourceSize.height: 32
        anchors.left: epoffice.right; anchors.leftMargin: 15
        anchors.top: page.top; anchors.topMargin: 10
        source: "App/FracAnaly.png"
    }

    Text {
        id: helloText
        anchors.centerIn: parent
        text: "Hello World"
        font.pointSize: 24; font.bold: true
        y:30;anchors.horizontalCenter: page.horizontalCenter

        function changeColor()
        {
            if(page.isYes)
                helloText.color="white";
            else
                helloText.color="red";
//            if(hellotext.color=="#ff0000")
//                hellotext.color = "#ffffff";
//            else
//                hellotext.color = "#ff0000";
        }
        MouseArea{
            id:mouseArea
            anchors.fill: parent
        }

        /**
          states 内嵌于Text之中，可以为Text元素添加多个状态，现在的这个例子只增加了一个状态，
          该状态的名为“down”，然后由 “when”指定了什么时候触发这个状态
          */
        states: State{
            name:"down";when:mouseArea.pressed==true
            /**
              PropertyChanges则指定了哪个元素的哪些属性会发生怎么样的变化，例子中，PropertyChanges
              利用了“target”指定了id为“hellotext”的元素会发生变化，包括其y，rotation，color等属性
              */
            PropertyChanges{
                target:helloText;
                y:1;
                rotation: 180;
                color:"red"
            }
        }
        /**
          transitions是用于增加动画效果的（如果把transitions这个代码删去，Hello，World的文字也会发生变化，
          但是看不到中间动画渐变的效果）。同样可以看到transitions的复数形式，意味着可以添加多个动画过程。
          “from” 和 “to” 指明了当前的动画作用于哪两个状态变化之间。
          “from” 和 “to” 的参数名来自于 State中的 “name” 属性。
          */
        transitions: Transition
        {
            from: "down"
            to: ""
            reversible: true
            /**
              ParalleAnimation 则指定了由多个动画并行发生。NumberAnimation用于qreal类型的属性变化，
              ColorAnimation则用于颜色变化。
              */
            ParallelAnimation{
                NumberAnimation{
                    properties: "y,rotation";
                    duration:5000;
                    easing.type: Easing.InOutQuad;
                }
                ColorAnimation {duration: 5000 }
            }
        }
    }
    Grid {
        id:colorPicker
        x:4; anchors.bottom: page.bottom;anchors.bottomMargin: 4
        rows:2;columns:3;spacing: 3

        function changeColor(){
            helloText.color=xxx.cellColor;
            ades.source="App/FracAnaly.png";
            console.debug("  console.log: ")
        }

        ColorPicker{
            id:xxx
            cellColor: "white"
            onCLicked1: {
                colorPicker.changeColor();
            }
        }
        ColorPicker{
            cellColor: "green"
            onCLicked1: helloText.color = cellColor
        }
        ColorPicker{
            cellColor: "blue"
            onCLicked1: helloText.color = cellColor
        }
        ColorPicker{cellColor: "yellow"
            onCLicked1: helloText.color = cellColor
        }
        ColorPicker{cellColor: "steelblue"
            onCLicked1: helloText.color = cellColor
        }
        ColorPicker{cellColor: "black"
            onCLicked1: helloText.color = cellColor
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            helloText.changeColor();
            page.isYes = !page.isYes;
        }
    }
}
