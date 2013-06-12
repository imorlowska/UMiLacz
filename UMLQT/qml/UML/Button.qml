import QtQuick 1.1

Rectangle {
	width: 40
	height: 40

	property alias mousearea:ma
	property alias name: buttonText.text
	property color basic:"#FF595E"
	property color pressedC : "red"
	property color hover:"#FF6321"

	color : getColor()
	Text {
		id:buttonText
		anchors.verticalCenter: parent.verticalCenter

		font.bold: true
	}
	MouseArea
	{
		id:ma
		anchors.fill: parent
		hoverEnabled: true

	}
	function getColor()
	{
		if(ma.pressed)
			return pressedC;
		if(ma.containsMouse)
			return hover;
		return basic;
	}

}
