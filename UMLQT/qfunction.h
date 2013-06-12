#ifndef FUNC_H
#define FUNC_H

#include <QObject>
#include "../umlFunction.h"
#include <string>

class QFunction:public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(bool correct READ getCorrect NOTIFY correctChanged)

	public:
		QFunction(QObject *parent=0);
		QFunction(umlFunction* function, QObject *parent=0);

		QString getName() const;
		void setName(const QString &name);

		umlFunction* getFunction(){return function;}
		bool getCorrect(){return correct;}

		Q_INVOKABLE
		void commit();

	signals:
		void nameChanged();
		void correctChanged();


	private:
		umlFunction* function;

		bool parse(const QString& str);
		bool correct;
		QString tmpName;


};

#endif // FUNC_H
