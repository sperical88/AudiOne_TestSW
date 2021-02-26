#include <stdio.h>

#include <QtCore/QCoreApplication>
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <QtCore/QProcess>
#include <QtDBus/QtDBus>
#include <QtCore/QThread>

#include "TC_Common.h"
#include "TC_Client.h"
#include "../TC_Thread/TC_Thread.h"
#include "TC_ClientAdaptor.h"

void TestCaseClient::quit()
{
	QTimer::singleShot(0, QCoreApplication::instance(), &QCoreApplication::quit);
}

void TestCaseClient::callFinishedSlot(QDBusPendingCallWatcher *call)
{
    qDebug() << Q_FUNC_INFO << "[Async] Received response from TestSW agent... ";

    //QDBusPendingReply<QString, QByteArray> reply = *call;
    QDBusPendingReply<QByteArray> reply = *call;
    if (reply.isError()) {
        //showError();
        qDebug() << Q_FUNC_INFO << "[Async] reply fail.";
    } else {
		//QByteArray respMsg = reply.argumentAt<0>;
		QByteArray respMsg = reply.value();
        qDebug() << Q_FUNC_INFO << "[Async] Reply was succeed ";
		//TODO : enqueue response
		//qDebug() << Q_FUNC_INFO << "message ID : " << respMsg[RESP_INDEX_MESSAGE_ID];
		printf("message ID : %d\n", respMsg[RESP_INDEX_MESSAGE_ID]);
		responseHandler->handleResponse(respMsg);
    }
    call->deleteLater();
}

void TestCaseClient::on_requestMsg(const QByteArray &msg)
{
    printf("[AYSNC] Call on_requestMsg to handle signal from UI Thread.\n");
    QDBusPendingCall async = iface->asyncCall("reqTestFromClient", msg);
    QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(async, this);
    QObject::connect(watcher, SIGNAL(finished(QDBusPendingCallWatcher*)),
                 this, SLOT(callFinishedSlot(QDBusPendingCallWatcher*)));
	printf("[AYSNC] return imediately and wait for response from testSW agent. \n");
}

#ifdef AUTO_START_SERVER
void TestCaseClient::start(const QString &name)
{
    if (name != TC_CLIENT_SERVICE_NAME)
        return;

	// find our remote
    iface = new QDBusInterface(TC_CLIENT_SERVICE_NAME, "/", TC_SERVER_SERVICE_NAME,
                               QDBusConnection::sessionBus(), this);
    if (!iface->isValid()) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        QCoreApplication::instance()->quit();
    }
    connect(iface, SIGNAL(aboutToQuit()), QCoreApplication::instance(), SLOT(quit()));

	ClientInputThread *thread = new ClientInputThread(this->iface);
    QObject::connect(thread, &ClientInputThread::finished, thread, &QObject::deleteLater);
	QObject::connect(thread, &ClientInputThread::finished, QCoreApplication::instance(), SLOT(quit()));
	QObject::connect(thread, SIGNAL(requestMsg(const QByteArray &)), this, SLOT(on_requestMsg(const QByteArray &)));

	 // Start thread
     qDebug() << Q_FUNC_INFO << "start Thread";
     thread->start();
}
#else
void TestCaseClient::start()
{
    // find our remote
    iface = new QDBusInterface(TC_CLIENT_SERVICE_NAME, "/", TC_SERVER_SERVICE_NAME,
                               QDBusConnection::sessionBus(), this);
    if (!iface->isValid()) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        QCoreApplication::instance()->quit();
    }
	//connect(iface, SIGNAL(aboutToQuit()), QCoreApplication::instance(), SLOT(quit()));

	ClientInputThread *thread = new ClientInputThread(iface);
    QObject::connect(thread, &ClientInputThread::finished, thread, &QObject::deleteLater);
    QObject::connect(thread, SIGNAL(requestMsg(const QByteArray &)), this, SLOT(on_requestMsg(const QByteArray &)));
    // Start thread
    qDebug() << Q_FUNC_INFO << "start Thread";
    thread->start();

	responseHandler = new ResponseHandlerThread();
	qDebug() << Q_FUNC_INFO << "start Response hanlder Thread";
	responseHandler->start();
}
#endif

void TestCaseClient::workFinishedSlot(const QByteArray &reply)
{
    qDebug() << "[SLOT][Client] workFinishedSlot";
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    TestCaseClient tcClient;

    if (!QDBusConnection::sessionBus().isConnected()) {
        fprintf(stderr, "Cannot connect to the D-Bus session bus.\n"
                "To start it, run:\n"
                "\teval `./utils/dbus-launch --auto-syntax`\n");
        return 1;
    }


#ifdef AUTO_START_SERVER	
    printf("call ServiceWatcher\n");
    QDBusServiceWatcher serviceWatcher(TC_CLIENT_SERVICE_NAME, QDBusConnection::sessionBus(),
                                       QDBusServiceWatcher::WatchForRegistration);

    printf("Connect to tcClient\n");
    QObject::connect(&serviceWatcher, &QDBusServiceWatcher::serviceRegistered,
                     &tcClient, &TestCaseClient::start);

    QProcess tcServer;
    printf("Start QProcess.... Server\n");
    tcServer.start("./TC_Server/TC_Server &");
#else
	tcClient.start();
#endif
    
	app.exec();
    return 0;
}
