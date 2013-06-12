import QtQuick 1.1

Item
{
	id:connection
	property variant model;
	property variant object;
	property bool hThenV
	property bool threeSegs
	property int x1
	property int y1
	property int x2
	property int y2
	property int realThickness:hover?thickness+3:thickness
	property int thickness
	property color color
	property bool hover:maHor.containsMouse || maVert.containsMouse || maThird.containsMouse


	Keys.onDeletePressed:
	{
		model.deleteConnection(object);
	}

	Rectangle
	{
		id:horizintal
		x:getX()
		y:getY()
		width: getW()
		height: connection.realThickness
		color:"red"
		border.width:connection.activeFocus?2:0
		border.color:"grey"



		MouseArea
		{
			id:maHor
			hoverEnabled: true
			anchors.fill: parent
			onPressed:
			{
				connection.focus=true;
			}
		}

		function getX()
		{
			if(threeSegs)
			{	if(hThenV)
					return Math.min(Math.min(connection.x1,connection.x2)+
									Math.abs(connection.x1-connection.x2)/2,
									connection.x1);
				else
					Math.min(connection.x1,connection.x2);
			}
			return Math.min(connection.x1,connection.x2);
		}
		function getY()
		{
			if(connection.hThenV)
			{
				return connection.y1;
			}
			else
			{
				if(threeSegs) return Math.min(connection.y1,connection.y2) + Math.abs(connection.y1-connection.y2)/2;
				return connection.y2;
			}
		}

		function getW()
		{
			if(threeSegs && hThenV)
				return Math.abs(connection.x1 - connection.x2)/2;
			return Math.abs(connection.x1 - connection.x2);
		}
	}
	Rectangle
	{

		id:vertical
		x:getX()
		y:getY()
		width: connection.realThickness
		height: getH()
		color:"green"
		border.width:connection.activeFocus?2:0
		border.color:"grey"
		MouseArea
		{
			id:maVert
			hoverEnabled: true
			anchors.fill: parent
			onPressed:
			{
				connection.focus=true;
			}
		}

		function getY()
		{
			if(hThenV)
				return Math.min(connection.y1,connection.y2);
			return Math.min(Math.min(connection.y1,connection.y2) +
							Math.abs(connection.y1-connection.y2)/2,connection.y1);
		}
		function getX()
		{
			if(connection.hThenV)
			{
				if(threeSegs)
					return Math.min(connection.x1,connection.x2)
							+ Math.abs(connection.x1-connection.x2)/2;
				return connection.x2;
			}
			else
			{
				if(threeSegs)
					return connection.x1;
				return Math.min(connection.x1,connection.x2);
			}
		}

		function getH()
		{
			if(threeSegs && !hThenV)
				return Math.abs(connection.y1 - connection.y2)/2;
			return Math.abs(connection.y1 - connection.y2);
		}
	}
	Rectangle
	{
		id:third
		visible: connection.threeSegs
		x:getX()
		y:getY()
		width: getW()
		height: getH()
		color:"blue"
		border.width:connection.activeFocus?2:0
		border.color:"grey"
		MouseArea
		{
			id:maThird
			hoverEnabled: true
			anchors.fill: parent
			onPressed:
			{
				connection.focus=true;
			}
		}

		function getX()
		{
			if(hThenV)
				return Math.min(Math.min(connection.x1,connection.x2) +
								Math.abs(connection.x1-connection.x2)/2,connection.x2);
			return x2;
		}
		function getY()
		{
			if(connection.hThenV)
			{
				return connection.y2;
			}
			else
			{
				return Math.min(Math.min(connection.y1,connection.y2) +
									   Math.abs(connection.y1-connection.y2)/2,connection.y2);
			}
		}

		function getH()
		{
			if(hThenV)
				return connection.realThickness;
			return vertical.height;
		}

		function getW()
		{
			if(!hThenV)
				return connection.realThickness;
			return horizintal.width;
		}

	}
}
