#ifndef STATISTICDIALOG_H
#define STATISTICDIALOG_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

namespace Ui {
class statisticDialog;
}

class statisticDialog : public QDialog
{
    Q_OBJECT

public:
    explicit statisticDialog(QWidget *parent = nullptr);
    void initUI();
    ~statisticDialog();

private slots:
    void on_returnButton_released();

    void on_confirmButton_released();

    //void on_return1Button_released();

    //void on_confirm1Button_released();

    void on_sex_confirmButton_released();

    void on_sex_returnButton_released();

    void on_quan_confirmPage_released();

    void on_quan_returnButton_released();

    void on_dead_confirmButton_released();

    void on_dead_returnButton_released();

    void on_data_confirmButton_released();

    void on_data_returnButton_released();


private:
    Ui::statisticDialog *ui;
};

#endif // STATISTICDIALOG_H
