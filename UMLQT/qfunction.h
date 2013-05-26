#ifndef FUNC_H
#define FUNC_H

#include <QObject>
#include "../umlFunction.h"
#include <string>

class QFunction:public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

	public:
		QFunction(QObject *parent=0);
		QFunction(umlFunction* function, QObject *parent=0);

		QString getName() const;
		void setName(const QString &name);

		umlFunction* getFunction(){return function;}

	signals:
		void nameChanged();

	private:
		umlFunction* function;

};

#endif // FUNC_H
