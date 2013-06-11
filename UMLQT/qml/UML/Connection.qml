import QtQuick 1.1
Item
{
	id:item
	property variant obj1
	property variant obj2
	property bool hThenV:true
	property bool threeSegs:false
	property Repeater connRep
	property variant connObject

	Connector
	{
		id:connector
		hThenV: getOrientation()
		threeSegs: true
		color:"black"
		thickness: 2
		x1:item.getX1()
		y1:item.getY1()
		x2:item.getX2()
		y2:item.getY2()
		//z:150
	}
	Arrow
	{
		id:arrow1
		state:item.getState1()
		x:getX()
		y:getY()
		rotation: getRotation()
		function getX()
		{
			if(connector.hThenV)
			{
				if(connector.x1<connector.x2)
					return connector.x1;
				return connector.x1-width;
			}
			return connector.x1-width/2;
		}

		function getY()
		{
			if(!connector.hThenV)
			{
				if(connector.y1<connector.y2)
					return connector.y1;
				return connector.y1-height;
			}

			return connector.y1-height/2;
		}
		function getRotation()
		{
			if(connector.hThenV)
			{
				if(connector.x1 < connector.x2)
					return 0;
				return 180;
			}
			if(connector.y1 < connector.y2)
				return 90;
			return 270;

		}

		Text
		{
			id:text1
			text:getText1()
			x:getX()
			y:getY()
			MouseArea
			{
				anchors.fill: parent
				onClicked:
				{
					var number = connObject.number;

					connObject.number = (number+3)%9;

				}
			}
			function getX()
			{
				if(connector.hThenV)
				{
					if(connector.x1<connector.x2)
						return arrow1.x+arrow1.width;
					return arrow1.x-arrow1.width;
				}
				return arrow1.x+arrow1.width;
			}
			function getY()
			{
				if(!connector.hThenV)
				{
					if(connector.y1<connector.y2)
						return arrow1.y+arrow1.height;
					return arrow1.y-arrow1.height;
				}
				return arrow1.y-arrow1.height;
			}
		}

	}

	Arrow
	{
		id:arrow2
		x:getX()
		y:getY()
		rotation: getRotation()
		state:item.getState2()
		function getX()
		{
			if(connector.hThenV)
			{
				if(connector.x1<connector.x2)
					return connector.x2-width;
				return connector.x2;
			}
			return connector.x2-width/2;
		}

		function getY()
		{
			if(!connector.hThenV)
			{
				if(connector.y1<connector.y2)
					return connector.y2-height;
				return connector.y2;
			}

			return connector.y2-height/2;
		}
		function getRotation()
		{
			if(connector.hThenV)
			{
				if(connector.x1 < connector.x2)
					return 180;
				return 0;
			}
			if(connector.y1 < connector.y2)
				return 270;
			return 90;

		}
		Text
		{
			id:text2
			text:getText2()
			MouseArea
			{
				anchors.fill: parent
				onClicked:
				{
					var number = connObject.number;
					var row = number/3;
					connObject.number = row + (number+1)%3;

				}
			}
		}

	}

	function getState1()
	{
		if(connObject.type===0 || connObject.type===1)
		{
			return "association";
		}
		if(connObject.type===2)
			return "composition";
		return "association";

	}

	function getState2()
	{
		if(connObject.type===0 || connObject.type===1)
		{
			return "inheritance";
		}
		return "association";

	}

	function getText1()
	{
		var col = connObject.number/3;
		switch(col)
		{
		case 0:
			return "1"
		case 1:
			return "0..*"
		case 2:
			return "1..*";
		}
	}

	function getText1()
	{
		var col = connObject.number%3;
		switch(col)
		{
		case 0:
			return "1"
		case 1:
			return "0..*"
		case 2:
			return "1..*";
		}
	}



	/*function getX1()
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
	}*/

	function getX1()
	{
		if(obj1.x + obj1.width<= obj2.x)
		{

			//hThenV = true;
			return getRX1();

		}
		if(obj2.x + obj2.width<=obj1.x )
		{
			//hThenV = true;
			return getLX1();
		}

		if(obj1.y < obj2.y)
		{
			return getBX1();
		}
		return getTX1();

	}
	function getY1()
	{
		if(obj1.x + obj1.width<= obj2.x)
		{

			//hThenV = true;
			return getRY1();

		}
		if(obj2.x + obj2.width<=obj1.x )
		{

			return getLY1();
		}
		if(obj1.y < obj2.y)
		{
			return getBY1();
		}
		return getTY1();

	}

	function getX2()
	{

		if(obj1.x + obj1.width <= obj2.x)
			return getLX2();
		if(obj2.x+ obj2.width <= obj1.x)
			return getRX2();


		if(obj1.y < obj2.y)
		{
			return getTX2();
		}
		return getBX2();
	}

	function getY2()
	{


		if(obj2.x+ obj2.width <= obj1.x)
			return getRY2();
		if(obj1.x + obj1.width <= obj2.x)
			return getLY2();

		if(obj1.y < obj2.y)
		{
			return getTY2();
		}
		return getBY2();
	}

	function getLX1()
	{
		return obj1.x;
	}
	function getLY1()
	{
		var i=0;
		var pt=0,q=0;
		for(i=0;i<connRep.count;i++)
		{
			var c = connRep.itemAt(i);
			if(c.connObject.id === connObject.id) continue;
			if(c.obj1 === obj1)
			{
				if(c.obj2.x + c.obj2.width<=c.obj1.x)
				{
					q++;
					if(c.obj2.y < obj2.y)
						pt++;
				}
			}
			else if(c.obj2 === obj1)
			{
				if(c.obj1.x + c.obj1.width<=c.obj2.x)
				{
					q++;
					if(c.obj1.y< obj2.y)
						pt++;
				}
			}
		}
		if(q==0)
				return obj1.y+obj1.height/2;
		return obj1.y + (pt+1)*obj1.height/(q+2);
	}

	function getRX1()
	{

			return obj1.x+obj1.width;

	}
	function getRY1()
	{
		var i=0;
		var pt=0,q=0;
		for(i=0;i<connRep.count;i++)
		{
			var c = connRep.itemAt(i);
			if(c.connObject.id === connObject.id) continue;
			if(c.obj1 === obj1)
			{
				if(c.obj2.x + c.obj2.width>=c.obj1.x)
				{
					q++;
					if(c.obj2.myClass.id < obj2.myClass.id)
						pt++;
				}
			}
			else if(c.obj2 === obj1)
			{
				if(c.obj1.x + c.obj1.width>=c.obj2.x)
				{
					q++;
					if(c.obj1.y < obj2.y)
						pt++;
				}
			}
		}
		if(q==0)
				return obj1.y+obj1.height/2;
		return obj1.y + (pt+1)*obj1.height/(q+2);
	}

	function getTX1()
	{
		var i=0;
		var pt=0,q=0;
		for(i=0;i<connRep.count;i++)
		{
			var c = connRep.itemAt(i);
			if(c.connObject.id === connObject.id) continue;
			if(c.obj1 === obj1)
			{
				if(c.obj2.y + c.obj2.height<=c.obj1.y &&
						c.obj2.x+c.obj2.width>c.obj1.x&&
						c.obj2.x < c.obj1.x+c.obj1.width)
				{
					q++;
					if(c.obj2.x < obj2.x)
						pt++;
				}
			}
			else if(c.obj2 === obj1)
			{
				if(c.obj1.y + c.obj1.height<=c.obj2.y&&
						c.obj1.x+c.obj1.width>c.obj2.x&&
						c.obj1.x < c.obj2.x+c.obj2.width)
				{
					q++;
					if(c.obj1.x< obj2.x)
						pt++;
				}
			}
		}
		if(q==0)
				return obj1.x+obj1.width/2;
		return obj1.x + (pt+1)*obj1.width/(q+2);
	}
	function getTY1()
	{
		return obj1.y;
	}

	function getBX1()
	{
		var i=0;
		var pt=0,q=0;
		for(i=0;i<connRep.count;i++)
		{
			var c = connRep.itemAt(i);
			if(c.connObject.id === connObject.id) continue;
			if(c.obj1 === obj1)
			{
				if(c.obj2.y + c.obj2.height>=c.obj1.y &&
						c.obj2.x+c.obj2.width>c.obj1.x&&
						c.obj2.x < c.obj1.x+c.obj1.width)
				{
					q++;
					if(c.obj2.x < obj2.x)
						pt++;
				}
			}
			else if(c.obj2 === obj1)
			{
				if(c.obj1.y + c.obj1.height>=c.obj2.y&&
						c.obj1.x+c.obj1.width>c.obj2.x&&
						c.obj1.x < c.obj2.x+c.obj2.width)
				{
					q++;
					if(c.obj1.x< obj2.x)
						pt++;
				}
			}
		}
		if(q==0)
				return obj1.x+obj1.width/2;
		return obj1.x + (pt+1)*obj1.width/(q+2);
	}
	function getBY1()
	{
		return obj1.y+obj1.height;
	}


	function getLX2()
	{
		return obj2.x;
	}
	function getLY2()
	{
		var i=0;
		var pt=0,q=0;
		for(i=0;i<connRep.count;i++)
		{
			var c = connRep.itemAt(i);
			if(c.connObject.id === connObject.id) continue;
			if(c.obj1 === obj2)
			{
				if(c.obj2.x + c.obj2.width<=c.obj1.x)
				{
					q++;
					if(c.obj2.y < obj1.y)
						pt++;
				}
			}
			else if(c.obj2 === obj2)
			{
				if(c.obj1.x + c.obj1.width<=c.obj2.x)
				{
					q++;
					if(c.obj1.y < obj1.y)
						pt++;
				}
			}
		}
		if(q==0)
			return obj2.y+obj2.height/2;
		return obj2.y + (pt+1)*obj2.height/(q+2);
	}

	function getRX2()
	{
		return obj2.x+obj2.width;
	}
	function getRY2()
	{
		var i=0;
		var pt=0,q=0;
		for(i=0;i<connRep.count;i++)
		{
			var c = connRep.itemAt(i);
			if(c.connObject.id === connObject.id) continue;
			if(c.obj1 === obj2)
			{
				if(c.obj2.x + c.obj2.width>=c.obj1.x)
				{
					q++;
					if(c.obj2.y < obj1.y)
						pt++;
				}
			}
			else if(c.obj2 === obj2)
			{
				if(c.obj1.x + c.obj1.width>=c.obj2.x)
				{
					q++;
					if(c.obj1.y < obj1.y)
						pt++;
				}
			}
		}
//		if(q==0)
//			return obj2.y+obj2.height/2;
		return obj2.y + (pt+1)*obj2.height/(q+2);
	}

	function getTX2()
	{
		var i=0;
		var pt=0,q=0;
		for(i=0;i<connRep.count;i++)
		{
			var c = connRep.itemAt(i);
			if(c.connObject.id === connObject.id) continue;
			if(c.obj1 === obj2)
			{
				if(c.obj2.y + c.obj2.height<=c.obj1.y&&
						c.obj1.x+c.obj1.width>c.obj2.x&&
						c.obj1.x < c.obj2.x+c.obj2.width)
				{
					q++;
					if(c.obj2.x < obj1.x)
						pt++;
				}
			}
			else if(c.obj2 === obj2)
			{
				if(c.obj1.y + c.obj1.height<=c.obj2.y&&
						c.obj2.x+c.obj2.width>c.obj1.x&&
						c.obj2.x < c.obj1.x+c.obj1.width)
				{
					q++;
					if(c.obj1.x < obj1.x)
						pt++;
				}
			}
		}
		if(q==0)
			return obj2.x+obj2.width/2;
		return obj2.x + (pt+1)*obj2.width/(q+2);
	}
	function getTY2()
	{
		return obj2.y;
	}

	function getBX2()
	{
		var i=0;
		var pt=0,q=0;
		for(i=0;i<connRep.count;i++)
		{
			var c = connRep.itemAt(i);
			if(c.connObject.id === connObject.id) continue;
			if(c.obj1 === obj2)
			{
				if(c.obj2.y + c.obj2.height>=c.obj1.y&&
						c.obj1.x+c.obj1.width>c.obj2.x&&
						c.obj1.x < c.obj2.x+c.obj2.width)
				{
					q++;
					if(c.obj2.x < obj1.x)
						pt++;
				}
			}
			else if(c.obj2 === obj2)
			{
				if(c.obj1.y + c.obj1.height>=c.obj2.y&&
						c.obj2.x+c.obj2.width>c.obj1.x&&
						c.obj2.x < c.obj1.x+c.obj1.width)
				{
					q++;
					if(c.obj1.x < obj1.x)
						pt++;
				}
			}
		}
		if(q==0)
			return obj2.x+obj2.width/2;
		return obj2.x + (pt+1)*obj2.width/(q+2);
	}
	function getBY2()
	{
		return obj2.y+obj2.height;
	}

	function getOrientation()
	{
		if(obj1.x + obj1.width<= obj2.x)
		{

			//hThenV = true;
			return true;

		}
		if(obj2.x + obj2.width<=obj1.x )
		{
			return true;
		}
		return false;
	}

}
