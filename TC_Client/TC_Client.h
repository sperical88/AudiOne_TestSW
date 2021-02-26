#ifndef __TC_CLIENT_H__
#define __TC_CLIENT_H__

#include <QtCore/QObject>
#include <QtCore/QFile>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusPendingCall>
#include "../TC_Thread/TC_Thread.h"

class TestCaseClient: public QObject
{
    Q_OBJECT

public:
#ifndef AUTO_START_SERVER
	 void start();
#endif

public slots:
#ifdef AUTO_START_SERVER
    void start(const QString &);
#endif
    void callFinishedSlot(QDBusPendingCallWatcher *);  //called when the aysnc work is completed
    void workFinishedSlot(const QByteArray &);		//From Server Object

	Q_NOREPLY void quit();
public:
    QFile qstdin;
	QDBusInterface *iface;
	//TODO: implement response hanler
	ResponseHandlerThread *responseHandler;

private slots:
    void on_requestMsg(const QByteArray &);		//From UI Thread

signals:
    void responseMsg(const QString &);
};

#endif
