#ifndef ADDSUBSCRIBERDIALOG_H
#define ADDSUBSCRIBERDIALOG_H

#include <QDialog>
#include <QRegularExpression>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include "subscriber.h"

namespace Ui {
class addSubscriberDialog;
}

class addSubscriberDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addSubscriberDialog(QWidget *parent = nullptr);

    ~addSubscriberDialog();

    //初始化界面
    void initUI();

    //添加清空数据函数
    void clearData();

signals:
    void sig_addSub(Subscriber &sub);

private slots:
    void on_confirmButton_released();

    void on_cancelButton_released();

private:
    Ui::addSubscriberDialog *ui;


};

#endif // ADDSUBSCRIBERDIALOG_H
