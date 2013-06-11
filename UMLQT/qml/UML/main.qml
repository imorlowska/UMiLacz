import QtQuick 1.1

Rectangle {


	property variant myDiagram;
	width: 500
    height: 360

	Rectangle {
		id: editorPane
		x: 100
		y: 0
		width: 400
		height: 360
		color: "#ffffff"
	Rectangle
	{

		id:diagramName
		anchors.left: parent.left
		anchors.top:parent.top
		width:103
		height:19
		color:"#C9FFDD"
		border.color: "black"
		border.width: 3
		TextInput
		{
			id:txt
			anchors.fill:parent
			anchors.topMargin: 3
			anchors.leftMargin:  3
			anchors.bottomMargin:  3
			anchors.rightMargin: 3
			//text : myDiagram.name
	  horizontalAlignment: TextInput.AlignLeft
			Binding
			{
				target:txt
				property: "text"
				value:myDiagram.name


			}
			Connections
			{
				target:txt
				onTextChanged:{myDiagram.name=diagramName.text}
			}
		}
	}

	Repeater
	{
		id:repeater
		objectName: "repeater"
		//property variant myDiagram;
		//property variant myClasses;
		model:myDiagram.classes;
		property int maxZ:1;
		delegate: ClassDiagram
		{

			myClass:object
			myFunctions:object.functions
			myAttributes:object.attributes
			z:repeater.maxZ
			mouseArea.onPressed:
			{
				repeater.maxZ++;
				z=repeater.maxZ;
//				if(editorPane.cd1 == undefined)
//					cd1 = this;
//				else if(editorPane.cd2 == undefined)
//					cd2=this;
			}
			mouseArea.onReleased:
			{
				//z=0;
			}

		}
	}



	Repeater
	{
		id:connRepeater
		model:myDiagram.connections
		delegate:Connection
		{
			obj1:getClassDiagram(object.class1)
			obj2:getClassDiagram(object.class2)
			connRep:connRepeater
			connObject:object
			function getClassDiagram(c)
			{
				var myIndex=0;
				console.log(repeater.count);
				for(myIndex=0;myIndex<repeater.model.count;myIndex++)
				{
					if(repeater.itemAt(myIndex).myClass.id === c.id)
						return repeater.itemAt(myIndex);
					//i++;
				}
			}

		}
}

MouseArea {
	x: 0
	y: 0
	anchors.rightMargin: 0
	anchors.bottomMargin: 0
	anchors.leftMargin: 0
	anchors.topMargin: 0
	anchors.fill: parent
	onClicked:
	{
		console.log(mouse.x + "," + mouse.y+"\n");
	}
}
	}






 Rectangle {
	 id: rectangle1
	 x: 0
	 y: 0
	 width: 100
	 height: parent.height
	 gradient: Gradient {
		 GradientStop {
			 position: 0
			 color: "#6f4242"
		 }

		 GradientStop {
			 position: 1
			 color: "#000000"
		 }
	 }

	 ListView {
		 id: editorToolbar
		 x: 0
		 y: 0
		 width: parent.width
		 height: parent.height
   rotation: 0
		 model: VisualItemModel {
			 Button {
				 width: editorToolbar.width
				 name: "New class"
				 mousearea.onClicked: {
							//editorPane.children.
							//var component = Qt.createComponent("ClassDiagram.qml");
//							if(component.status === Component.Ready)
//							{
//								var cd = component.createObject(repeater);
//								cd.x=50;
//								cd.y=50;
//							}
					 myDiagram.addEmptyClass();


						}
			 }
				 Button {
					 width: editorToolbar.width
					 name: "Connect"
					 mousearea.onClicked: {
								//editorPane.children.
								//var component = Qt.createComponent("ClassDiagram.qml");
	//							if(component.status === Component.Ready)
	//							{
	//								var cd = component.createObject(repeater);
	//								cd.x=50;
	//								cd.y=50;
	//							}
						 myDiagram.addEmptyClass();

							}
			 }
		 }
	 }
 }


}
