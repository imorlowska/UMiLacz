import QtQuick 1.1

Rectangle {

    id: draggable

    width: 100
    height: 100

    onXChanged: {
        if (mouseArea.drag.active) {
            console.log("x=" + x)
        }
    }
    onYChanged: {
        if (mouseArea.drag.active) {
          console.log("y=" + y)
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        drag {
            target: draggable
            axis: Drag.XandYAxis
        }
    }
}
