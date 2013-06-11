import QtQuick 1.1
Item
{
	id:item
	property ClassDiagram obj1
	property ClassDiagram obj2
	property bool hThenV:true

	Connector
	{
		id:connector
		hThenV: item.hThenV
		color:"black"
		thickness: 5
		x1:item.getX1()
		y1:item.getY1()
		x2:item.getX2()
		y2:item.getY2()
		z:Math.min(obj1.z,obj2.z)-1
	}
	function getX1()
	{
		return obj1.x+obj1.width/2;
	}

	function getY1()
	{
		return obj1.y+obj1.height/2;
	}

	function getX2()
	{
		return obj2.x+obj2.width/2;
	}



	function getY2()
	{
		return obj2.y+obj2.height/2;
	}

	function left(o)
	{
		return Qt.point(o.x,o.y+o.height/2);
	}
	function right(o)
	{
		return Qt.point(o.x+o.width,o.y+o.height/2);
	}

	function top(o)
	{
		return Qt.point(o.x+o.width/2,o.y);
	}

	function bottom(o)
	{
		return Qt.point(o.x+o.width/2,o.y+o.height);
	}


}
