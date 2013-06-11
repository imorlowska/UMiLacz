import QtQuick 1.1

Item
{
	id:connection
	property bool hThenV
	property int x1
	property int y1
	property int x2
	property int y2
	property int thickness
	property color color
	Rectangle
	{
		id:horizintal
		x:getX()
		y:getY()
		width: getW()
		height: connection.thickness
		color:connection.color
		function getX()
		{
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
				return connection.y2;
			}
		}

		function getW()
		{
			return Math.abs(connection.x1 - connection.x2);
		}
	}
	Rectangle
	{
		id:vertical
		x:getX()
		y:getY()
		width: connection.thickness
		height: getH()
		color:connection.color
		function getY()
		{
			return Math.min(connection.y1,connection.y2);
		}
		function getX()
		{
			if(connection.hThenV)
			{
				return connection.x2;
			}
			else
			{
				return connection.x1;
			}
		}

		function getH()
		{
			return Math.abs(connection.y1 - connection.y2);
		}
	}
}
