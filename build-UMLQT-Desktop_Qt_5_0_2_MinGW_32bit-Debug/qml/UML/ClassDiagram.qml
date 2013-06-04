import QtQuick 1.1

Rectangle
{
    id: mainRectangle
    width: 150
    height: 200
	color: "#13adbb"
    property int minWidth:100
    property int minHeight:50
    radius: 16

	//property variant classDummy: myClass
	//color:myClass.backgroundColor

    onWidthChanged:
    {
        if(width<minWidth)
            width=minWidth
    }

    onHeightChanged:
    {
        if(height<minHeight)
            height=minHeight
    }

    MouseArea
    {
        anchors.fill: parent
        drag.target: mainRectangle
        drag.axis: Drag.XandYAxis

    }
    Column
    {
        id: mainColumn
        height : (mainRectangle.height-mainRectangle.radius)
        width:mainRectangle.width
        anchors.top:parent.top
        anchors.topMargin: 0

        Rectangle
        {
            id: header
            //x: 50
            //y: 153
            width: parent.width
            height: parent.height*0.2
            radius: 6
            anchors.horizontalCenter: parent.horizontalCenter
            color : "#AFFFE7"



            TextInput
            {
                id: className
                anchors.centerIn: parent
                width: parent.width*0.7
                height: 20
				//text: fieldsList.listView.currentIndex
				text : myClass.name
				Binding
				{
					target:className
					property: "text"
					value:myClass.name


				}
				Connections
				{
					target:className
					onTextChanged:{myClass.name=className.text}
				}

//				Binding
//				{
//					target:myClass
//					property: "name"
//					value:className.text


//				}
				fillColor:
				{
					if(focus)
						"green"
					else
						"lightgreen"
				}


            }
        }

        Rectangle
        {
            id:fieldsPart
            //x: 0
            //y: 120
            width: mainRectangle.width
            height: parent.height*0.4
            radius:4
            color:"#FFC6FF"
            ListWithAdd
            {
                id:fieldsList
                anchors.fill: parent
				listModel:myFunctions




				listDelegate:ListItemDelegate
				{
				width:mainRectangle.width
				height:20
				}


				mouseArea.onClicked:
				{
					listView.currentIndex=listView.count-1
					myFunctions.addEmpty()

				}



    }
}
Rectangle
{
    width:mainRectangle.width
    height:3
    color: "black"
}

ListWithAdd
{
    width:mainRectangle.width
    height:parent*0.4
	listModel:myAttributes
	listDelegate: ListItemDelegate
	{
		width:mainRectangle.width
		height:20
	}

	mouseArea.onClicked:
	{
		listView.currentIndex=listView.count-1
		myAttributes.addEmpty()

	}
}






}

SizeGrip
{
    target: mainRectangle
}









}





