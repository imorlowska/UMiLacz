import QtQuick 1.1









        Column
        {
			property alias scrollbarWidth:scrollbar.width

            Item
            {

            clip: true
            id:fieldsContainer
            width:mainRectangle.width;
            height:fieldsPart.height-addField.height
            ListView
            {
                id:fieldsView
                anchors.fill: parent

                spacing: 3
                boundsBehavior: Flickable.DragOverBounds
                flickableDirection: Flickable.VerticalFlick




//                    onHeightChanged:
//                    {
//                        if(height > (fieldsPart.height-addField.height))
//                                mainRectangle.height = mainRectangle.height+23/0.4;
//                    }











    }

            ScrollBar
            {
				id:scrollbar
                target: fieldsView
            }
            }
    Rectangle
    {
        id:addField
        property color hoverColor: "#599EFF"
        property color buttonColor: "#CEFFE7"
        width:mainRectangle.width
        height:20
        Text
        {

            text:"+"


        }
        MouseArea
        {
            id:addMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: parent.color=parent.hoverColor
            onExited: parent.color = parent.buttonColor

        }
    }
            property alias mouseArea:addMouseArea
            property alias listModel : fieldsView.model
            property alias listDelegate: fieldsView.delegate
            property alias listView: fieldsView
           // property alias addButtonClicked: addMouseArea.onClicked
}


