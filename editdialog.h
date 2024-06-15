#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include "subscriber.h"
#include <QDialog>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class editDialog;
}

class editDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editDialog(QWidget *parent = nullptr);
    ~editDialog();

     void initUI();

signals:
    void sig_editSub(Subscriber &sub);



private slots:
    void on_confirmButton_released();


    void on_cancelButton_released();

private:
    Ui::editDialog *ui;
    QString str;


};

#endif // EDITDIALOG_H
