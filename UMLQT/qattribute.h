#ifndef FUNC_H
#define FUNC_H

#include <QObject>
#include "../umlAttribute.h"
#include <string>

class QAttribute:public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(bool correct READ getCorrect NOTIFY correctChanged)
	public:
		QAttribute(QObject *parent=0);
		QAttribute(umlAttribute* attribute, QObject *parent=0);

		QString getName() const;
		void setName(const QString &name);

		umlAttribute* getAttribute(){return attribute;}
		Q_INVOKABLE
		void commit();

		bool getCorrect(){return correct;}

	signals:
		void nameChanged();
		void correctChanged();

	private:
		umlAttribute* attribute;
		bool correct=true;
		QString tmpString;
		bool parse(const QString& str);

};

#endif // FUNC_H
