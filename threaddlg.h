#ifndef THREADDLG_H
#define THREADDLG_H

#include <QDialog>
#include <QPushButton>
#include "workthread.h"
#define MAXSIZE 5							//MAXSIZE宏定义了线程的数目



class ThreadDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ThreadDlg(QWidget *parent = 0);
    ~ThreadDlg();

public slots:
    void slotStart();                       //槽函数用于启动线程
    void slotStop();						//槽函数用于终止线程

private:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *quitBtn;
    WorkThread *workThread[MAXSIZE];             //(a)
};

#endif // THREADDLG_H
