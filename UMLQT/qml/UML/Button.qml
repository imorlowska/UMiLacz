import QtQuick 1.1

Rectangle {
	width: 40
	height: 40
	color:"red"
	property alias mousearea:ma
	property alias name: buttonText.text
	Text {
		id:buttonText
		anchors.verticalCenter: parent.verticalCenter

		font.bold: true
	}
	MouseArea
	{
		id:ma
		anchors.fill: parent
	}

}
