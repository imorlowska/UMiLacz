import QtQuick 1.1
Rectangle
{
    id: sizeGrip
    property variant target
    width: 15
    height: 15
    radius: 3
//    anchors.right: mainRectangle.right
//    anchors.rightMargin: 0
//    anchors.bottom: mainRectangle.bottom
//    anchors.bottomMargin: 0
    x:mainRectangle.target-10
    y:mainRectangle.target-10

    states:
    [
        State
        {
            name: "nodrag"
//            AnchorChanges
//            {
//                target: sizeGrip
//                anchors.right: mainRectangle.right
//                anchors.bottom: mainRectangle.bottom
//            }
            PropertyChanges
            {

                target: sizeGrip
                x:target.width-10
                y:target.height-10
            }
        },
        State
        {
            name: "drag"
//            AnchorChanges
//            {
//                target: sizeGrip
//                anchors.right: undefined
//                anchors.bottom: undefined

//            }
            PropertyChanges
            {

                target: sizeGrip
                x:x
                y:y
            }
        }
    ]
    transitions: [
        Transition { to: "nodrag";
            ParallelAnimation {
                NumberAnimation { target: sizeGrip; property: "opacity"; to: 0.2; duration: 500; }
                //PropertyAction { target: sizeGrip; property: "visible"; value: false; }
                AnchorAnimation{}

            }
        },
        Transition { to: "drag";
            //PropertyAction { target: sizeGrip; property: "visible"; value: true; }
            ParallelAnimation
            {
                NumberAnimation { target: sizeGrip; property: "opacity"; to: 1; duration: 500; }
                AnchorAnimation{}
            }
        }
    ]
    state:"nodrag"
    color:"red"
    opacity:0.2

    onXChanged:
    {
        if(maDrag.drag.active)
        {

            //console.log(mouse.x+":"+mouse.y)
            //console.log(x+":"+y)
            target.width = x + 10
        }

    }
    onYChanged:
    {
        if(maDrag.drag.active)
        {

            //console.log(mouse.x+":"+mouse.y)
            //console.log(x+":"+y)
            target.height = y +10
        }
    }

    MouseArea
    {
        id:maDrag
        anchors.fill: parent
        onPressed:
        {
            sizeGrip.state="drag"
        }
        onReleased:
        {
            sizeGrip.state="nodrag"
        }
        //                onMousePositionChanged:
        //                {
        //                    if(sizeGrip.state=="drag")
        //                    //console.log(mouse.x+":"+mouse.y)
        //                    {
        //                        mainRectangle.width++
        //                    }
        //                }

        drag {
            target: sizeGrip
            axis: Drag.XandYAxis
            //minimumX: mainRectangle.minWidth
            //minimumY: mainRectangle.minHeight
            minimumX: 0
            minimumY: 0
        }

    }

}
