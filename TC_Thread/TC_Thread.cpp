#include <stdio.h>

#include <QtCore/QDebug>
#include <QtDBus/QtDBus>
#include <QtCore/QFile>
#include <QtCore/QCoreApplication>

#include "TC_Thread.h"
#include "TC_Common.h"

SampleThread::SampleThread()
{
	qDebug() << Q_FUNC_INFO;
}

SampleThread::~SampleThread()
{
    qDebug() << Q_FUNC_INFO;
}

void SampleThread::run()
{
    qDebug() << Q_FUNC_INFO << "run Thread";
    
    for(int i=0; i<3; i++)
    {
        if ( QThread::currentThread()->isInterruptionRequested() ) {
            qDebug() << Q_FUNC_INFO << " terminated";
            return;
        }
        qDebug() << Q_FUNC_INFO << "sleep in Thread";
        QThread::sleep(1);
    } 
    const QString reply = "Thread is completed. Test result is OK.";
    emit completeSimpleThread(reply);
	qDebug() << Q_FUNC_INFO << "Complete Thread";
}

//TODO: implement response hanler
/*
ResponseHandlerThread::ResponseHandlerThread(TestCaseClient &tcClient)
{
	qDebug() << Q_FUNC_INFO << "create ReponseHandlerThread";
	this->tc = tcClient;
}

void ResponseHandlerThread::run()
{
	while (!tc.responseQueue.isEmpty())
	{
		qDebug() << "Dequeue response";
		qDebug() << Q_FUNC_INFO << tc.responseQueue.dequeue();
	}
}
*/

ClientInputThread::ClientInputThread()
{
    qDebug() << Q_FUNC_INFO << "create ClientInputThread";
}

ClientInputThread::ClientInputThread(QDBusInterface *iface)
{
    qDebug() << Q_FUNC_INFO << "create ClientInputThread with iface";
    this->iface = iface;
}

ClientInputThread::~ClientInputThread()
{
    qDebug() << Q_FUNC_INFO;
}

void ClientInputThread::run()
{
    bool ok;
    int inputType;
    //TestCaseMessage msg;
    QByteArray msg;
    msg.resize(REQ_IDEX_MAX_SIZE);
    
    // open stdin for reading
    qstdin.open(stdin, QIODevice::ReadOnly);

	qDebug() << "Input TestType (BSP:11 Video:12 Radio:13 MCU:14 Ethernet:15 Audio:16  ALL:17)";
    while (true) {
        QString line = QString::fromLocal8Bit(qstdin.readLine()).trimmed();
        if (line.isEmpty()) {
            iface->call("quit");
            return;
        }    
        msg[REQ_INDEX_MESSAGE_ID] = line.toInt(&ok, 10);

        msg[REQ_INDEX_MESSAGE_TYPE] = MESSAGE_TYPE_REQUEST;    

        printf("Skip some params ... \n");

        printf("Input Test Case ID (Just Temporary TCA1:100  TCA2:101   TCA3:103)\n");
        line = QString::fromLocal8Bit(qstdin.readLine()).trimmed();
        if (line.isEmpty()) {
            iface->call("quit");
            return;
        }    
        msg[REQ_INDEX_TESTCASE_ID] = line.toInt(&ok, 10);
        emit requestMsg(msg);
		QThread::usleep(10);
    }
}
