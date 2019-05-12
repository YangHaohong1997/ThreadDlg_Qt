#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QThread>
#include <QDebug>

class WorkThread : public QThread
{
    Q_OBJECT
public:
    WorkThread();
protected:
    void run();
};

#endif // WORKTHREAD_H
