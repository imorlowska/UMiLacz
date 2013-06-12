import QtQuick 1.1

Rectangle {


	property variant myDiagram;
	width: 500
	height: 360

	Rectangle {
		id: editorPane
		x: 100
		y: 0
		width: parent.width-100
		height: parent.height
		color: "#ffffff"
		MouseArea
		{
			anchors.fill: parent
			onPressed:
			{
				editorPane.focus=true;
			}
		}

		property int cn;
		property int ct:-1;
		property variant class1;
		property variant class2;
		function commitConnection()
		{
			if(ct==-1 || class1 === undefined || class2 === undefined) return;
			console.log("connect "+class1.name + " " + class2.name);
			var ret = myDiagram.connections.addConnection(class1,class2,ct,cn);
			ct = -1;
			class1 = undefined;
			class2 = undefined;
			if(ret !== "")
				errorText.setError(ret);
		}

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
				smooth: false
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
				if(editorPane.ct!=-1)
				{
					if(editorPane.class1 === undefined)
					{

						editorPane.class1 = object;
						console.log("class1 is " + editorPane.class1.name);
					}
					else
					{

						editorPane.class2 = object;
						console.log("class2 is " + editorPane.class2.name);
						editorPane.commitConnection();
					}

				}

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
Rectangle
{
	anchors.horizontalCenter: parent.horizontalCenter
	width:editorPane.width
	height: editorPane.height

	border.width: 1
	border.color: "grey"
	z:100500
	opacity:errorText.opacity
	Text
	{
		id: errorText
  font.pointSize: 30
  wrapMode: Text.WordWrap
  horizontalAlignment: Text.AlignHCenter
		anchors.fill: parent

		verticalAlignment: Text.AlignVCenter
		font.pixelSize: 25
		state:"noerror"
		states:
			[
			State
			{
				name:"error"
				PropertyChanges {
					target: errorText
					opacity : 0.8
					color: "#FF3848";

				}
			},
			State
			{
				name:"noerror"
				PropertyChanges {
					target: errorText
					opacity : 0.0

					color: "white";
				}
			}

		]
		transitions:
			[
			Transition {
				from: "noerror"
				to: "error"
				reversible: true
				ParallelAnimation
				{
					NumberAnimation
					{
						target: errorText;
						property: "opacity";
						duration: 500;
						easing.type: Easing.InOutQuad
					}
					ColorAnimation
					{
						duration: 500
					}
				}
			}
		]
		function setError(txt)
		{
			text=txt;
			state="error";
		}
		MouseArea
		{
			anchors.fill: parent
			onPressed:
			{
				errorText.state="noerror"
			}
		}
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
				name: "Extends"
				mousearea.onClicked:
				{

					editorPane.ct = 0;
					editorPane.cn = 0;

				}
			}
			Button {
				width: editorToolbar.width
				name: "Composition"
				mousearea.onClicked:
				{

					editorPane.ct = 2;
					editorPane.cn = 0;

				}
			}
			Button {
				width: editorToolbar.width
				name: "Association"
				mousearea.onClicked:
				{

					editorPane.ct = 3;
					editorPane.cn = 0;

				}
			}

			Button {
				width: editorToolbar.width
				name: "UMiL"
				mousearea.onClicked:
				{

					myDiagram.UMiL();

				}
			}
		}
	}
}


}
