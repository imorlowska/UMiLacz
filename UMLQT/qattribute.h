#ifndef FUNC_H
#define FUNC_H

#include <QObject>
#include "../umlAttribute.h"
#include <string>

class QAttribute:public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

	public:
		QAttribute(QObject *parent=0);
		QAttribute(umlAttribute* attribute, QObject *parent=0);

		QString getName() const;
		void setName(const QString &name);

		umlAttribute* getAttribute(){return attribute;}

	signals:
		void nameChanged();

	private:
		umlAttribute* attribute;

};

#endif // FUNC_H
