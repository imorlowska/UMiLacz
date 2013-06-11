import QtQuick 1.1

Item
{
	id:connection
	property bool hThenV
	property bool threeSegs
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
		color:"red"
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
		width: connection.thickness
		height: getH()
		color:"green"
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
				return connection.thickness;
			return vertical.height;
		}

		function getW()
		{
			if(!hThenV)
				return connection.thickness;
			return horizintal.width;
		}

	}
}
