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

    Q_SCRIPTABLE QString audioTestMain(testCaseID tcID);
    Q_SCRIPTABLE QString audioTest1(const QString &arg);
    Q_SCRIPTABLE QString audioTest2(const QString &arg);
    Q_SCRIPTABLE QString audioTest3(const QString &arg);

    Q_SCRIPTABLE QString bspTestMain(testCaseID tcID);
    Q_SCRIPTABLE QString bspTest1(const QString &arg);
    Q_SCRIPTABLE QString bspTest2(const QString &arg);
    Q_SCRIPTABLE QString bspTest3(const QString &arg);

    Q_SCRIPTABLE QString allAutoTest();

public:
    QDBusInterface *iface;

public slots:
    //Q_SCRIPTABLE QString reqTestFromClient(const int testType);
    //Q_SCRIPTABLE QString reqTestFromClient(const TestCaseMessage &msg);
    Q_SCRIPTABLE QString reqTestFromClient(const QByteArray &msg);

    void on_completeSimpleThread(const QString &);

    Q_NOREPLY void quit();

signals:
    void finished(QDBusPendingCallWatcher *self);
    void workFinished(const QByteArray &);
    void aboutToQuit();    
};

#endif
