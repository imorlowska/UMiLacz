#include <QApplication>
#include "qmlapplicationviewer.h"
#include <QDeclarativeContext>

#include "qclass.h"


#include "qfunction.h"
#include "functionsmodel.h"
#include "qobjectlistmodel.h"
#include <QObjectList>


umlClass cl;
void createModel()
{
//  ListModel *model = new ListModel(qApp);
//  model->appendRow(new FruitItem("Apple"));
//  model->appendRow(new FruitItem("PineApple"));
//  model->appendRow(new FruitItem("Grape"));
//  return model;

	cl.setName("shitClass");


	cl.addFunction((new umlFunction())->setName("func")->setType(((new umlSimpleType())->setType(int_))));
	cl.addFunction((new umlFunction())->setName("func2"));
	cl.addFunction((new umlFunction())->setName("func3"));

	cl.addAttribute((new umlAttribute())->setName("state1")->setType(((new umlSimpleType())->setType(int_))));

}


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
	viewer.setMainQmlFile(QLatin1String("qml/UML/ClassDiagram.qml"));
    viewer.showExpanded();
    QDeclarativeContext* context = viewer.rootContext();

	createModel();
	QClass d(&cl);

	context->setContextProperty("myClass",&d);
	context->setContextProperty("myAttributes",&d.getAttributes());
	context->setContextProperty("myFunctions",&d.getFunctions());

    return app->exec();
}
