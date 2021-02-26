#ifndef __TC_THREAD_H__
#define __TC_THREAD_H__

#include <QtCore/QThread>
#include <QtDBus/QtDBus>
#include <QtCore/QFile>
#include <QtCore/QQueue>
#include <QtCore/QMutex>
#include <QtCore/QWaitCondition>

class SampleThread : public QThread
{
    Q_OBJECT
public:
    SampleThread();
    ~SampleThread();
public:
	QDBusInterface *iface;
protected:
    void run();
signals:
    void completeSimpleThread(const QString &);
};

//TODO: implement response hanler 
class ResponseHandlerThread : public QThread
{
	Q_OBJECT
public:
//	ResponseHandlerThread();
//	~ResponseHandlerThread();
	void handleResponse(const QByteArray &msg);
private:
	QQueue<QByteArray> responseQueue;
	QWaitCondition waitCondition;
	QMutex mutex;

protected:
	void run();
signals:

};


class ClientInputThread : public QThread
{
    Q_OBJECT
public:
    ClientInputThread();
    ClientInputThread(QDBusInterface *iface);
    ~ClientInputThread();
    
protected:
    void run();

public:
    QFile qstdin;
    QDBusInterface *iface;

private slots:
    //void on_responseMsg(QString &);

signals:
    void requestMsg(const QByteArray &);
};

#endif
