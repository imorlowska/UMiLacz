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
                    color:"#CEFFE7"





                        TextInput
                        {

                            id:fieldName
                            anchors.fill: parent
							text:itemText
							Binding
							{
								target:fieldName
								property: "text"
								value:object.name


							}
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
                            }

                            Keys.onDeletePressed:rectDelete.deleteCurrent()



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
