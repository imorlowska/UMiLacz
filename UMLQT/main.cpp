#include <QApplication>
#include "qmlapplicationviewer.h"
#include <QDeclarativeContext>
#include <QDeclarativeProperty>
#include <QDeclarativeComponent>
#include <QDeclarativeItem>

#include "qclass.h"
#include "qdiagram.h"

#include "qfunction.h"
#include "functionsmodel.h"
#include "qobjectlistmodel.h"
#include <QObjectList>


umlDiagram diagram;
void createModel()
{
//  ListModel *model = new ListModel(qApp);
//  model->appendRow(new FruitItem("Apple"));
//  model->appendRow(new FruitItem("PineApple"));
//  model->appendRow(new FruitItem("Grape"));
//  return model;

	umlClass* c1 = new umlClass();
	c1->setName("shitClass");


	c1->addFunction((new umlFunction())->setName("func")->
					setType(((new umlSimpleType())->setType(int_))));
	c1->addFunction((new umlFunction())->setName("func2"));
	c1->addFunction((new umlFunction())->setName("func3"));

	c1->addAttribute(
				(new umlAttribute())->
				setName("state1")->
				setType(((new umlSimpleType())->setType(int_))));

	diagram.addClass(c1);
	umlClass* c2 = new umlClass();
	c2->setName("crapClass");




	diagram.addClass(c2);
	diagram.addDependency
			(c1,c2,connectionType::contains_,connectionNumber::one2one);

}


Q_DECL_EXPORT int main(int argc, char *argv[])
{
//	int ti = qmlRegisterType<ClassesModel>();
//	ti = qmlRegisterInterface<FunctionsModel>("FunctionsModel");
//	ti = qmlRegisterInterface<AttributesModel>("AttributesModel");
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
	viewer.setMainQmlFile(QLatin1String("qml/UML/main.qml"));
    viewer.showExpanded();



	//QDeclarativeContext* context = viewer.rootContext();
	QObject* object = (QObject*)viewer.rootObject();
	//QObject* cd = object->findChild<QObject*>(QString("repeater"));
	//auto children = object->children();
	//QDeclarativeItem* main = dynamic_cast<QDeclarativeItem*>(object);
	/*QDeclarativeComponent component(viewer.engine(),QUrl::fromLocalFile("qml/UML/ClassDiagram.qml"));
	QObject* cd2 = component.create();
	QDeclarativeItem* cd2Item = dynamic_cast<QDeclarativeItem*>(cd2);
	cd2Item->setParentItem(main);
	cd2->setParent(object);
	cd2->setProperty("x",150);
	cd2->setProperty("y",150);*/
	//QDeclarativeContext context(viewer.rootContext());
	//context.setContextObject(cd);
	createModel();
	QDiagram d(&diagram);

//bool r =	QDeclarativeProperty::write(cd,"myClass",QVariant::fromValue(&d));
//	QDeclarativeProperty::write(cd,"myAttributes",QVariant::fromValue(&d.getAttributes()));
//	QDeclarativeProperty::write(cd,"myFunctions",QVariant::fromValue(&d.getFunctions()));

	object->setProperty("myDiagram",QVariant::fromValue(&d));
	//cd->setProperty("model",d.getClasses());
	//cd->setProperty("myAttributes",QVariant::fromValue(&d.getAttributes()));
	//cd->setProperty("myFunctions",QVariant::fromValue(&d.getFunctions()));

//	cd2->setProperty("myClass",QVariant::fromValue(&d));
//	cd2->setProperty("myAttributes",QVariant::fromValue(&d.getAttributes()));
//	cd2->setProperty("myFunctions",QVariant::fromValue(&d.getFunctions()));


//	context.setContextProperty("myClass",&d);
//	context.setContextProperty("myAttributes",&d.getAttributes());
//	context.setContextProperty("myFunctions",&d.getFunctions());

	return app->exec();

}
