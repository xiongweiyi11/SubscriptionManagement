#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "editdialog.h"
#include "subscriber.h"
#include <QStringList>  //类似于字符串数组
#include <QList>    //也类型于数组
#include <QTableWidgetItem>
#include "addsubscriberdialog.h"

// qint32  rowindex;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //键盘操作
    void keyPressEvent(QKeyEvent *event) override;

    //保存编辑行号
    qint32 rowindex;
    //加载数据（从文件中读取数据）
    void loadData(const QString& filename);

    QList<Subscriber> m_subscribers;    //保存所有subscriber

    Subscriber sub;
    //用于插入图片
    // void paintEvent(QPaintEvent *event) override;

    int getSelectedUnit();

// signals:
    // void sendData(QString &str);


private slots:
    void on_viewButton_released();

    void on_statisticButton_released();

    void on_closeButton_released();

    void on_addButton_released();

    //添加槽函数
    void slot_addSub(Subscriber &sub);
    // void on_saveButton_released();

    void slot_editSub(Subscriber &sub);

    void on_returnButton_released();

    //void on_statisticButton_2_clicked();

    void on_returnButton_3_clicked();

    void on_editButton_2_clicked();

    void on_search_clicked();

    void on_returnButton_2_clicked();

    void on_searchButton_released();

    void on_saveButton_released();

    void on_viewButton_2_clicked();

    void on_delebtn_released();

    void on_backbtn_released();

    void on_pushButton_clicked();

    void on_dele2Button_released();

private:
    Ui::MainWindow *ui;
    //QStringList m_fields;   //保存表头
    addSubscriberDialog *dlg;   //添加学生信息窗口
    editDialog *edi;

    bool isDataSaved;

};
#endif // MAINWINDOW_H
