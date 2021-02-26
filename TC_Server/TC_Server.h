#ifndef __TESTCASE_SERVER_H__
#define __TESTCASE_SERVER_H__

#include <QtCore/QObject>
#include <QtDBus/QDBusAbstractAdaptor>
#include <QtDBus/QDBusVariant>
#include <QtDBus/QDBusPendingCall>
#include <QtDBus/QDBusInterface>

#include "TC_Common.h"

class TestCaseServer: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "lge.tc.QtDBus.tcServer")

public:
    TestCaseServer(QObject *obj) : QDBusAbstractAdaptor(obj)
    { }

    QByteArray audioTestMain(testCaseID tcID);
    QByteArray audioTest1(const QString &arg);
    QByteArray audioTest2(const QString &arg);
    QByteArray audioTest3(const QString &arg);

    QByteArray bspTestMain(testCaseID tcID);
    QByteArray bspTest1(const QString &arg);
    QByteArray bspTest2(const QString &arg);
    QByteArray bspTest3(const QString &arg);

    QByteArray allAutoTest();

public:
    QDBusInterface *iface;
	QByteArray responseMsg;

public slots:
    //Q_SCRIPTABLE QString reqTestFromClient(const int testType);
    //Q_SCRIPTABLE QString reqTestFromClient(const TestCaseMessage &msg);
    QByteArray reqTestFromClient(const QByteArray &msg);

    void on_completeSimpleThread(const QString &);

    Q_NOREPLY void quit();

signals:
    void finished(QDBusPendingCallWatcher *self);
    void workFinished(const QByteArray &);
    void aboutToQuit();    
};

#endif
