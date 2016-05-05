import QtQuick 1.1

Rectangle {
    id: tabBar

    //存放基本类型，问题时如果修改他们的值
    property variant tabs: []
    property variant icons: []
    property variant indices
    property bool showOnTop: true
    property int currentIndex: 0

    signal currentChanged(int index)
    function setCurrentIndex(cur) {
        currentIndex = cur
        if(indices)  //判断容器是否为空
            currentChanged(indices[currentIndex])
    }

    visible: false
    color: "transparent"
    onIndicesChanged: { visible = true; height = 36; }

    Row {
        id: header

        Repeater {
            model: tabBar.tabs.length

        }
    }
}
