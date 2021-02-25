#ifndef __TC_CLIENT_ADAPTOR_H__
#define __TC_CLIENT_ADAPTOR_H__

#include <QtCore/QObject>
#include <QtDBus/QDBusAbstractAdaptor>
#include <QtDBus/QDBusInterface>

#include "TC_Common.h"

class TestCaseClientAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "lge.tc.QtDBus.tcClient")
public:
    TestCaseClientAdaptor(QObject *obj) : QDBusAbstractAdaptor(obj)
	{ }
public:
	QDBusInterface *iface;
										   
public slots:
	void workFinishedSlot(const QByteArray &);      //From Server Object
signals:
	void workFinish(const QByteArray &);	//To Client main app.
};

#endif
