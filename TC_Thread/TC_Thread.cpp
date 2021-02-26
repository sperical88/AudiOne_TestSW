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

void ResponseHandlerThread::handleResponse(const QByteArray &msg)
{
	mutex.lock();
	qDebug() << Q_FUNC_INFO << "Enqueue response message";
    responseQueue.enqueue(msg);
	waitCondition.wakeOne();
	mutex.unlock();
}

void ResponseHandlerThread::run()
{
	QByteArray msg;
	do
	{
		mutex.lock();
		if (responseQueue.isEmpty()) {
			waitCondition.wait(&mutex);
		}
		mutex.unlock();
					 
		if(mutex.tryLock())
		{
			qDebug() << Q_FUNC_INFO << "Dequeue response";
			//mutex.lock();
			//qDebug() << Q_FUNC_INFO << responseQueue.dequeue();
			msg = responseQueue.dequeue();
			mutex.unlock();
		}
		//handle msg
		//qDebug() << Q_FUNC_INFO << "message ID : " << msg[RESP_INDEX_MESSAGE_ID];
		//qDebug() << Q_FUNC_INFO << "message Type : " << msg[RESP_INDEX_MESSAGE_TYPE];
		printf("message ID : %d\n", msg[RESP_INDEX_MESSAGE_ID]);
		printf("meesage Type : %d\n", msg[RESP_INDEX_MESSAGE_TYPE]);
//		qDebug() << Q_FUNC_INFO << "message  : " << msg[0];

		qDebug() << "Just show again for Test...  Input TestType (BSP:11 Video:12 Radio:13 MCU:14 Ethernet:15 Audio:16  ALL:17)";
	} while(true);
}


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
    msg.resize(REQ_INDEX_MAX_SIZE);
    
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
