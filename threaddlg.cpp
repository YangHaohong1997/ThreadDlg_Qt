#include "threaddlg.h"
#include <QHBoxLayout>

ThreadDlg::ThreadDlg(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("线程"));
    startBtn = new QPushButton(tr("开始"));
    stopBtn  = new QPushButton(tr("停止"));
    quitBtn  = new QPushButton(tr("退出"));
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(startBtn);
    mainLayout->addWidget(stopBtn);
    mainLayout->addWidget(quitBtn);
    connect(startBtn,SIGNAL(clicked(bool)),this,SLOT(slotStart()));
    connect(stopBtn,SIGNAL(clicked(bool)),this,SLOT(slotStop()));
    connect(quitBtn,SIGNAL(clicked(bool)),this,SLOT(close()));

}

void ThreadDlg::slotStart()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        workThread[i] = new WorkThread();
    }
    for(int i = 0; i < MAXSIZE; i++)
    {
        workThread[i]->start();
    }
    startBtn->setEnabled(false);
    stopBtn->setEnabled(true);

}

void ThreadDlg::slotStop()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        workThread[i]->terminate();
        workThread[i]->wait();
    }
    startBtn->setEnabled(true);
    stopBtn->setEnabled(false);
}

ThreadDlg::~ThreadDlg()
{
    delete startBtn;
    delete stopBtn;
    delete quitBtn;
}

