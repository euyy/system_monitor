#ifndef PROCESSWINDOW_H
#define PROCESSWINDOW_H
#include "processList.h"
#include <QWidget>
#include <QTimer>
#include <QTableWidget>
#include <QTableWidgetItem>

namespace Ui {
class processwindow;
}

class processwindow : public QWidget
{
    Q_OBJECT

public:
    explicit processwindow(QWidget *parent = 0);
    ~processwindow();

private:
    Ui::processwindow *ui;
    QTimer *timer;
    vector<struct Process> processlist;                 //存储所有监视进程的信息
    double cpulevel1=70,cpulevel2=100,cpulevel3=150;    //根据该值将cpu值划分为不同等级，进而上色
    double memlevel1=70,memlevel2=100,memlevel3=150;    //根据该值将内存值划分为不同等级，进而上色
private slots:
    void showProcessInfo();
    void updateProcessInfo();
    void refreshProcessInfo();
    void on_pushButton_refresh_clicked();
    void on_pushButton_kill_clicked();
};

#endif // PROCESSWINDOW_H
