#include <stdio.h>
#include <stdlib.h>

#include <QtCore/QCoreApplication>
#include <QtCore/QTimer>
#include <QtDBus/QtDBus>

#include "TC_Common.h"
#include "TC_Server.h"
#include "../TC_Thread/TC_Thread.h"

void TestCaseServer::quit()
{
    QTimer::singleShot(0, QCoreApplication::instance(), &QCoreApplication::quit);
}

//QString TestCaseServer::reqTestFromClient(const int testType)
//QString TestCaseServer::reqTestFromClient(const TestCaseMessage &msg)
QByteArray TestCaseServer::reqTestFromClient(const QByteArray &msg)
{
	responseMsg.resize(RESP_INDEX_MAX_SIZE);
    qDebug() << "start reqTestFromClient in TC_Server";

    //int testType = msg.getMessageID();
    int testType = msg[REQ_INDEX_MESSAGE_ID];
    qDebug() <<  "testType : " << testType;
	responseMsg[RESP_INDEX_MESSAGE_ID] = msg[REQ_INDEX_MESSAGE_ID];
	responseMsg[RESP_INDEX_MESSAGE_TYPE] = msg[REQ_INDEX_MESSAGE_TYPE];
	responseMsg[RESP_INDEX_TESTCASE_ID] = msg[REQ_INDEX_TESTCASE_ID];

	qDebug() << Q_FUNC_INFO << "message ID : " << responseMsg[RESP_INDEX_MESSAGE_ID];
	qDebug() << Q_FUNC_INFO << "Req... message ID : " << responseMsg[REQ_INDEX_MESSAGE_ID];
	printf("message ID : %d\n", responseMsg[RESP_INDEX_MESSAGE_ID]);


    switch(testType)
    {
        case MESSAGE_ID_ALL_AUTO_TEST:
            fprintf(stderr, "call allAutoTest\n");
            responseMsg = TestCaseServer::allAutoTest();
            //emit QDBusPendingCallWatcher::finished(reply);
            //return "Fail";
            break;
        case MESSAGE_ID_AUDIO_TEST:
        {
			responseMsg = audioTestMain((testCaseID)msg[REQ_INDEX_TESTCASE_ID]);
            break;
        }
        case MESSAGE_ID_BSP_TEST:
        {
            responseMsg = bspTestMain((testCaseID)msg[REQ_INDEX_TESTCASE_ID]);
            break;
        }
        case MESSAGE_ID_VIDEO_TEST:
            break;
    }

	//Temporary make msg for test.
	responseMsg[RESP_INDEX_MESSAGE_ID] = msg[REQ_INDEX_MESSAGE_ID];
	responseMsg[RESP_INDEX_MESSAGE_TYPE] = msg[REQ_INDEX_MESSAGE_TYPE];
	responseMsg[RESP_INDEX_TESTCASE_ID] = msg[REQ_INDEX_TESTCASE_ID];
	qDebug() << Q_FUNC_INFO << "message ID : " << responseMsg[RESP_INDEX_MESSAGE_ID];

	return responseMsg;
}

QByteArray TestCaseServer::audioTest1(const QString &arg)
{
	qDebug() << "audioTest1 is called!!";
	return responseMsg;
}

QByteArray TestCaseServer::audioTest2(const QString &arg)
{
	qDebug() << "audioTest2 is called!!";
	return responseMsg;
}

QByteArray TestCaseServer::audioTest3(const QString &arg)
{
	qDebug() << "audioTest3 is called!!";
	return responseMsg;
}



QByteArray TestCaseServer::audioTestMain(testCaseID tcID)
{
    QByteArray reply;
    switch(tcID)
    {
        case TEST_CASE_ID_A1:
            reply = TestCaseServer::audioTest1("Audio Test TC A1");
            break;
        case TEST_CASE_ID_A2:
            reply = TestCaseServer::audioTest2("Audio Test TC A2");
            break;
        case TEST_CASE_ID_A3:
            reply = TestCaseServer::audioTest3("Audio Test TC A3");
            break;
    }
    return reply;
}


QByteArray TestCaseServer::bspTestMain(testCaseID tcID)
{
    QByteArray reply;
    switch(tcID)
    {
        case TEST_CASE_ID_A1:
            reply = TestCaseServer::bspTest1("BSP Test TC A1");
            break;
        case TEST_CASE_ID_A2:
            reply = TestCaseServer::bspTest2("BSP Test TC A2");
            break;
        case TEST_CASE_ID_A3:
            reply = TestCaseServer::bspTest3("BSP Test TC A3");
            break;
    }
    return reply;
}

QByteArray TestCaseServer::bspTest1(const QString &arg)
{
	qDebug() << "bspTest1 is called!!";
	return responseMsg;
}

QByteArray TestCaseServer::bspTest2(const QString &arg)
{
	qDebug() << "bspTest2 is called!!";
	return responseMsg;
}

QByteArray TestCaseServer::bspTest3(const QString &arg)
{
	qDebug() << "bspTest3 is called!!";
	return responseMsg;
}

QByteArray TestCaseServer::allAutoTest()
{
    QString reply;
    
    //Execute Test 1
    SampleThread *thread = new SampleThread;
    QObject::connect(thread, &SampleThread::finished, thread, &QObject::deleteLater);
    QObject::connect(thread, SIGNAL(completeSimpleThread(const QString &)), this, SLOT(on_completeSimpleThread(const QString &)));

    // Start thread
    qDebug() << Q_FUNC_INFO << "start Thread";
    thread->start();
	qDebug() << "[Async] Thread : Please wait for complete work.";
	thread->wait();
    
	//Send Message including test result for each test case to Client(HOW???)

    //return result if all test are completed
	qDebug() << Q_FUNC_INFO << "work done in allAutoTest";
	
	reply = "[Async] allAutoTest work done in thread";
    //return reply;
	return responseMsg;
}

void TestCaseServer::on_completeSimpleThread(const QString &result)
{
    const QByteArray reply;
    qDebug() << "Work in thread is complte.  How can I pass the result to Client? How to send the signal to Dbus client....?";
	
	//TODO : send a signal to client when a work is finished.
/*	
	this->iface = new QDBusInterface(TC_SERVER_SERVICE_NAME, "/", TC_CLIENT_SERVICE_NAME,
                                QDBusConnection::sessionBus(), this);
    connect(this, SIGNAL(workFinished(const QByteArray &)), iface, SLOT(workFinishedSlot(const QByteArray &)));
    emit workFinished(reply);
*/	
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    printf("start TC_Server\n");

    QObject obj;
    TestCaseServer *tcServer = new TestCaseServer(&obj);
    QObject::connect(&app, &QCoreApplication::aboutToQuit, tcServer, &TestCaseServer::aboutToQuit);
    QDBusConnection::sessionBus().registerObject("/", &obj);

    printf("register client service to dbus\n");
    if (!QDBusConnection::sessionBus().registerService(TC_CLIENT_SERVICE_NAME)) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::sessionBus().lastError().message()));
        exit(1);
    }

    app.exec();
    printf("TC_Server exit\n");
    return 0;
}
