import QtQuick 1.1

Item
                {
                id:myDelegate
                Row
                {
                    id:row
                    width:parent.width
                    height:parent.height


                Rectangle
                {
                    id:bigger
                    width:parent.width*0.8
                    height: parent.height
					color:getColor()

					function getColor()
					{
						if(object.correct) return"#CEFFE7";
						return "#FFA3AF";
					}





                        TextInput
                        {

                            id:fieldName
                            anchors.fill: parent
							text:object.name
//							Binding
//							{
//								target:fieldName
//								property: "text"
//								value:object.name


//							}
							Connections
							{
								target:fieldName
								onTextChanged:{object.name=fieldName.text}
							}
                            activeFocusOnPress: false
                            selectByMouse: true
                            //focus:true
                            onFocusChanged:
                            {
                                font.italic = fieldName.focus
                                maOverField.enabled = ! fieldName.focus
                                rectDelete.show = focus
								if(!fieldName.focus)
									object.commit();
                            }

                            Keys.onDeletePressed:rectDelete.deleteCurrent()
							Keys.onReturnPressed:
							{
								fieldName.focus=false;
							}



                        }
                        MouseArea{
                            id:maOverField
                            anchors.fill: fieldName

                            onClicked:
                            {

                                if (mouse.button == Qt.LeftButton)
                                {
                                    fieldsList.listView.currentIndex=index
                                    maOverField.enabled=false
                                    fieldName.forceActiveFocus()
                              }
                            }
                        }

                }
                Rectangle
                {
                    id:rectDelete

                    width:parent.width*0.2
                    height:20
                    color:show?"red":bigger.color
                    property bool show:false


                    Text
                    {
                        visible:rectDelete.show
                        id:x
                        anchors.centerIn: parent
                        text:"X"

                    }
                    MouseArea
                    {
                        visible: rectDelete.show
                        id:maDelete
                        anchors.fill: parent
                        onClicked:
                        {
                            rectDelete.deleteCurrent()

                        }




                    }
                    function deleteCurrent()
                    {
                        //if(fieldsList.listView.isCurrentItem)
                            listModel.remove(listView.currentIndex);

                    }

                }
            }


    }
