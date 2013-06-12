import QtQuick 1.1;

Rectangle
{
	//visible:connObject.type===3
	id:arrow
	color:"white"
	width:30
	height:30

	property Connector connector;
	Line
	{
		id:seg1
		color: "black"
	}
	Line
	{
		id:seg2
		color:"black"
	}
	Line
	{
		id:seg3
		color:"black"
	}
	Line
	{
		id:seg4
		color:"black"
	}

	transformOrigin: Item.Center


	//state: "inheritance"

	states:
	[
		State
		{
			name:"association"
			PropertyChanges
			{
				target: arrow
				opacity:0
				visible:false
				width:20
				height:20
			}
			StateChangeScript
			{
				script:
				{
					seg1.visible=false;
					seg2.visible=false;
					seg3.visible=false;
					seg4.visible=false;
				}
			}
		},

		State
		{
			name:"composition"
			PropertyChanges
			{
				target: arrow
				width:20
				height:20
			}
			PropertyChanges
			{
				target: seg1
				visible:true
				x1:0
				y1:arrow.height/2-1
				x2:arrow.width/2-1
				y2:arrow.height*0.25
			}
			PropertyChanges
			{
				target: seg2
				visible:true
				x1:arrow.width/2
				y1:arrow.height*0.25
				x2:arrow.width
				y2:arrow.height/2-1

			}
			PropertyChanges
			{
				target: seg3
				visible:true
				x1:arrow.width
				y1:arrow.height/2+1
				x2:arrow.width/2+1
				y2:arrow.height*0.75

			}
			PropertyChanges
			{
				target: seg4
				visible:true
				x1:arrow.width/2
				y1:arrow.height*0.75
				x2:0
				y2:arrow.height/2+1

			}
		},
		State
		{
			name:"inheritance"
			PropertyChanges
			{
				target: arrow
				width:15
				height:20
			}
			PropertyChanges
			{
				target: seg1
				visible:true
				x1:0
				y1:arrow.height/2
				x2:arrow.width
				y2:0
			}
			PropertyChanges
			{
				target: seg2
				visible:true
				x1:arrow.width
				y1:0
				x2:arrow.width
				y2:arrow.height
				//visible:false
			}
			PropertyChanges
			{
				target: seg3
				visible:true
				x1:arrow.width
				y1:arrow.height
				x2:0
				y2:arrow.height/2
			}
			PropertyChanges
			{
				target: seg4
				visible:false
			}
		}

	]
}
