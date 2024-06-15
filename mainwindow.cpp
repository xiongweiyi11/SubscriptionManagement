#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QKeyEvent>    //用于键盘操作
#include <QFile>    //用于文件操作
#include <QDebug>
#include <QTextStream>  //文本流，有助于解决编码问题
#include "addsubscriberdialog.h"
#include "editdialog.h"
#include "statisticdialog.h"
#include <QDate>
QString number;


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , dlg(NULL)
    , edi(NULL)
    ,ui(new Ui::MainWindow)
    ,isDataSaved(true)
{
    ui->setupUi(this);


    //注册自定义的对象，以便传递自定义信号
    qRegisterMetaType<Subscriber>("Subscriber");
    qRegisterMetaType<Subscriber>("Subscriber&");

    dlg=new addSubscriberDialog(this);  //在对象树中不用管生命值

    edi=new editDialog(this);

    //关联槽函数
    connect(dlg,&addSubscriberDialog::sig_addSub,this,&MainWindow::slot_addSub);

    connect(edi,&editDialog::sig_editSub,this,&MainWindow::slot_editSub);

    loadData("file.txt");

    //设置表格数据不能被选中修改
    ui->viewTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::loadData(const QString &filename)  //加载数据
{
    QFile fileNum("file_num.txt");

    if (!fileNum.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }

    QTextStream streamNum(&fileNum);
    QFile file(filename);
    //打开文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open file failed";
        return;
    }

    //读取文件
    QTextStream stream(&file);

    //保存表头
   // m_fields=stream.readLine().split("\t",Qt::SkipEmptyParts); //用于去除空格

    //读取数据
    while(!stream.atEnd())
    {
        //保存数据
        QString line = stream.readLine();
        QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
        if (lineData.length() == 7)
        { // 确保每行数据包含7个字段
            Subscriber s;
            s.number = lineData[0];
            s.name = lineData[1];
            s.sex = lineData[2];
            s.phoneNumber = lineData[3];
            s.magazine = lineData[4];
            s.quantity = lineData[5];
            s.deadline = lineData[6];
            m_subscribers.push_back(s);
            streamNum<<s.number<<"\n";
        } else {
            qDebug() << "数据缺失，应为7个，是为" << lineData.length();
        }
    }
    for(auto s:m_subscribers)   //遍历所有subscriber类对象
    {
        s.display();
    }
    file.close();   //关闭文件
}


void MainWindow::on_viewButton_released()
{

    //切换到查看页面
    ui->stackedWidget1->setCurrentWidget(ui->viewPage);

    m_subscribers.clear();
    loadData("file.txt");

    QFile fileNum("file_num.txt");

    if (!fileNum.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }

    QTextStream streamNum(&fileNum);


    //把list中的数据显示到表格中
    ui->viewTableWidget->setColumnCount(7);   //设置列数
    // ui->viewTableWidget->setHorizontalHeaderLabels(m_fields);   //设置表头

    //遍历所有订阅
    for(const auto &s:m_subscribers)
    {
        //获取新行的行数
        int row=ui->viewTableWidget->rowCount();
        //1.添加一个空行
        ui->viewTableWidget->insertRow(row);
        //2.把数据设置到空行中
        ui->viewTableWidget->setItem(row,0,new QTableWidgetItem(s.number));
        ui->viewTableWidget->setItem(row,1,new QTableWidgetItem(s.name));
        ui->viewTableWidget->setItem(row,2,new QTableWidgetItem(s.sex));
        ui->viewTableWidget->setItem(row,3,new QTableWidgetItem(s.phoneNumber));
        ui->viewTableWidget->setItem(row,4,new QTableWidgetItem(s.magazine));
        ui->viewTableWidget->setItem(row,5,new QTableWidgetItem(s.quantity));
        ui->viewTableWidget->setItem(row,6,new QTableWidgetItem(s.deadline));

        //用于刷新file_num数据
        streamNum<<s.number<<"\n";
    }

    fileNum.close();


    //以下用于删除空白行及其行号
    for (int i = ui->viewTableWidget->rowCount() - 1; i >= 0; --i)
    {
        bool isEmpty = true;
        for (int j = 0; j < ui->viewTableWidget->columnCount(); ++j)
        {
            QTableWidgetItem *item = ui->viewTableWidget->item(i, j);
            if (item && !item->text().trimmed().isEmpty())
            {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty)
        {
            ui->viewTableWidget->removeRow(i);
        }
    }
    ui->viewTableWidget->update(); // 刷新表格视图
}

void MainWindow::on_closeButton_released()
{
    //关闭程序
    close();
}

void MainWindow::on_statisticButton_released()
{
    statisticDialog sta(this);

    //对话框初始化
    sta.initUI();

    //模态弹出对话框
    sta.exec();

}

void MainWindow::on_addButton_released()
{
    isDataSaved=false;
    //创建一个学生，防止越界
    m_subscribers.push_back(*new Subscriber);
    //初始化对话框
    dlg->initUI();
    //模态弹出对话框
    dlg->exec();

}

//槽函数实现
void MainWindow::slot_addSub(Subscriber &sub)
{
     qDebug()<<"传递添加数据成功";
    //获取新行的行数
    int row=ui->viewTableWidget->rowCount();
    //1.添加一个空行
    ui->viewTableWidget->insertRow(row);
    //2.把数据设置到空行中
    ui->viewTableWidget->setItem(row,0,new QTableWidgetItem(sub.number));
    ui->viewTableWidget->setItem(row,1,new QTableWidgetItem(sub.name));
    ui->viewTableWidget->setItem(row,2,new QTableWidgetItem(sub.sex));
    ui->viewTableWidget->setItem(row,3,new QTableWidgetItem(sub.phoneNumber));
    ui->viewTableWidget->setItem(row,4,new QTableWidgetItem(sub.magazine));
    ui->viewTableWidget->setItem(row,5,new QTableWidgetItem(sub.quantity));
    ui->viewTableWidget->setItem(row,6,new QTableWidgetItem(sub.deadline));
}

// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::slot_editSub(Subscriber &sub1)
{
    qDebug()<<"传递编辑数据数据成功";

    sub=sub1;
    //qDebug()<<sub.number<<sub.name;

    qDebug()<<rowindex<<"****";
    ui->viewTableWidget_2->setItem(rowindex,0,new QTableWidgetItem(sub.number));
    ui->viewTableWidget_2->setItem(rowindex,1,new QTableWidgetItem(sub.name));
    ui->viewTableWidget_2->setItem(rowindex,2,new QTableWidgetItem(sub.sex));
    ui->viewTableWidget_2->setItem(rowindex,3,new QTableWidgetItem(sub.phoneNumber));
    ui->viewTableWidget_2->setItem(rowindex,4,new QTableWidgetItem(sub.magazine));
    ui->viewTableWidget_2->setItem(rowindex,5,new QTableWidgetItem(sub.quantity));
    ui->viewTableWidget_2->setItem(rowindex,6,new QTableWidgetItem(sub.deadline));


}

void MainWindow::on_saveButton_released()
{
    // 首先检查表格是否有数据
    if (ui->viewTableWidget->rowCount() == 0) {
        qDebug() << "没有数据可以保存，表格为空。";
        return;
    }

    QFile file("file.txt");

    //file_num 用于防止编号重复
    QFile fileNum("file_num.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }
    if (!fileNum.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }

    QTextStream stream(&file);
    QTextStream streamNum(&fileNum);

    for (int i = 0; i < ui->viewTableWidget->rowCount(); i++) {
        Subscriber subscriber; // 创建 Subscriber 对象

        // 检查每个单元格是否存在并获取文本内容
        for (int j = 0; j < ui->viewTableWidget->columnCount(); j++) {
            QTableWidgetItem* item = ui->viewTableWidget->item(i, j);
            // 根据列索引 j 赋值给 subscriber 对象的相应成员变量
            switch (j) {
            case 0: subscriber.number = item->text(); break;
            case 1: subscriber.name = item->text(); break;
            case 2: subscriber.sex = item->text(); break;
            case 3: subscriber.phoneNumber = item->text(); break;
            case 4: subscriber.magazine = item->text(); break;
            case 5: subscriber.quantity = item->text(); break;
            case 6: subscriber.deadline = item->text(); break;
            default: break;
            }
        }

        // 打印 subscriber 信息，用于调试
        qDebug().nospace() << "Subscriber " << i << ": "
                           << subscriber.number << ", "
                           << subscriber.name << ", "
                           << subscriber.sex << ", "
                           << subscriber.phoneNumber << ", "
                           << subscriber.magazine << ", "
                           << subscriber.quantity << ", "
                           << subscriber.deadline;

        // 写入文件
        stream << subscriber.number << "\t\t"
               << subscriber.name << "\t\t"
               << subscriber.sex << "\t\t"
               << subscriber.phoneNumber << "\t\t"
               << subscriber.magazine << "\t\t"
               << subscriber.quantity << "\t\t"
               << subscriber.deadline << "\n";

        streamNum<<subscriber.number<<"\n";
    }

    file.close(); // 关闭文件
    fileNum.close();
    isDataSaved=true;
}

//设置返回按钮
void MainWindow::on_returnButton_released()
{
    //若用户没有保存则提醒
    if (!isDataSaved)
    {
        // 显示确认对话框
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "确认返回", "您尚未保存更改。是否确认返回？", QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::No)
        {
            // 用户选择不返回，按钮点击事件结束
            return;
        }
    }

    // 切换到统计页面

    ui->stackedWidget1->setCurrentWidget(ui->menuPage);

    // 重新设置起始位置为0
     ui->viewTableWidget->setRowCount(0);

    // 重置保存标志
    isDataSaved = true;
}

//设置按下ESC返回主菜单
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        //若用户没有保存则提醒
        if (!isDataSaved)
        {
            // 显示确认对话框
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "确认返回", "您尚未保存更改。是否确认返回？", QMessageBox::Yes|QMessageBox::No);

            if (reply == QMessageBox::No)
            {
                // 用户选择不返回，按钮点击事件结束
                return;
            }
        }

        // 切换到统计页面

        ui->stackedWidget1->setCurrentWidget(ui->menuPage);

        // 重新设置起始位置为0
        ui->viewTableWidget->setRowCount(0);

        // 重置保存标志
        isDataSaved = true;
    }
}


void MainWindow::on_returnButton_3_clicked()
{
    ui->stackedWidget1->setCurrentWidget(ui->searchPage);
}

// ////////////////////////////////////////////////////// /////////////////////////////////////////////////////
void MainWindow::on_editButton_2_clicked()
{



    qint32 number1=MainWindow::getSelectedUnit();
    if(number1==999)
    {
        QMessageBox::information(this,"提示","请先选择需要编辑的数据！！！");


    }
    else
    {
        qDebug()<<number1;
        QList<Subscriber> m_subscribers1;    //保存所有subscriber
        // QFile fileNum("file_num.txt");

        // if (!fileNum.open(QIODevice::WriteOnly | QIODevice::Text)) {
        //     qDebug() << "打开文件失败";
        //     return;
        // }

        //QTextStream streamNum(&fileNum);
        QFile file("file.txt");
        //打开文件
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"open file failed";
            return ;
        }

        //读取文件
        QTextStream stream(&file);

        //保存表头
        // m_fields=stream.readLine().split("\t",Qt::SkipEmptyParts); //用于去除空格

        //读取数据
        while(!stream.atEnd())
        {

            //保存数据
            QString line = stream.readLine();
            QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
            if (lineData.length() == 7)
            { // 确保每行数据包含7个字段
                Subscriber s;
                s.number = lineData[0];
                s.name = lineData[1];
                s.sex = lineData[2];
                s.phoneNumber = lineData[3];
                s.magazine = lineData[4];
                s.quantity = lineData[5];
                s.deadline = lineData[6];
                m_subscribers1.push_back(s);
                // streamNum<<s.number<<"\n";
            } else {
                qDebug() << "数据缺失，应为7个，是为" << lineData.length();
            }
        }

        number=m_subscribers1[number1].number;
        qDebug()<<number;
        //emit sendData(number);
        // for(auto s:m_subscribers1)   //遍历所有subscriber类对象
        // {
        //     s.display();
        // }
        file.close();   //关闭文件

        //需要弹出connect响应的信号发送者和信号，很重要
        edi->initUI();
        edi->exec();
    }

}

qint32 MainWindow::getSelectedUnit(){
    // 获取表格所选行的指针，若表格中没有任何一行被选中，则指针指向空
    QList<QTableWidgetItem*> items = ui->viewTableWidget_2->selectedItems();
    if(!items.empty()) //表格有某行被选中
    {
        //获取该行的成员数
        qint32 count = items.count();
        // 获取该行的行号
        rowindex = ui->viewTableWidget_2->row(items.at(0));
        // 打印该行所有成员内容
        for(int i = 0; i < count; i++)
        {
            QTableWidgetItem *item = items.at(i); //该行第i列的item
            //qDebug() << item->text(); //获取内容
        }
        //qDebug() <<rowindex;
        return rowindex;
    }
    else
    {
        return 999;

    }

}

void MainWindow::on_search_clicked()
{
    //切换到查看页面
    ui->stackedWidget1->setCurrentWidget(ui->resultPage);


    //把list中的数据显示到表格中
    ui->viewTableWidget_2->setColumnCount(7);   //设置列数
    // ui->viewTableWidget_2->setHorizontalHeaderLabels(m_fields);   //设置表头
    //遍历所有订阅
    //设置初始行号为0
    ui->viewTableWidget_2->setRowCount(0);

    QFile file("file.txt");
    //打开文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open file failed";
        return ;
    }

    //读取文件
    QTextStream stream(&file);

    QList<Subscriber> m_subscribers1;

    //读取数据
    while(!stream.atEnd())
    {
        //保存数据
        QString line = stream.readLine();
        QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
        if (lineData.length() == 7)
        { // 确保每行数据包含7个字段
            Subscriber s;
            s.number = lineData[0];
            s.name = lineData[1];
            s.sex = lineData[2];
            s.phoneNumber = lineData[3];
            s.magazine = lineData[4];
            s.quantity = lineData[5];
            s.deadline = lineData[6];
            m_subscribers1.push_back(s);
            // streamNum<<s.number<<"\n";
        } else {
            qDebug() << "数据缺失，应为7个，是为" << lineData.length();
        }
    }
    file.close();   //关闭文件
    for(const auto &s:m_subscribers1)
    {
        if((s.name==ui->nameEdit->text()||ui->nameEdit->text() == "")&&(s.deadline<ui->deadlineEdit_1->text())&&(s.sex==ui->sexEdit->text()||ui->sexEdit->text() == "")&&(s.magazine==ui->magEdit->text()||ui->magEdit->text() == "")){
            //获取新行的行数
            int row=ui->viewTableWidget_2->rowCount();
            //1.添加一个空行
            ui->viewTableWidget_2->insertRow(row);

            ui->viewTableWidget_2->setSelectionMode(QAbstractItemView::ExtendedSelection);
            //2.把数据设置到空行中
            ui->viewTableWidget_2->setItem(row,0,new QTableWidgetItem(s.number));
            ui->viewTableWidget_2->setItem(row,1,new QTableWidgetItem(s.name));
            ui->viewTableWidget_2->setItem(row,2,new QTableWidgetItem(s.sex));
            ui->viewTableWidget_2->setItem(row,3,new QTableWidgetItem(s.phoneNumber));
            ui->viewTableWidget_2->setItem(row,4,new QTableWidgetItem(s.magazine));
            ui->viewTableWidget_2->setItem(row,5,new QTableWidgetItem(s.quantity));
            ui->viewTableWidget_2->setItem(row,6,new QTableWidgetItem(s.deadline));
        }

    }

    //以下用于删除空白行及其行号
    for (int i = ui->viewTableWidget_2->rowCount() - 1; i >= 0; --i)
    {
        bool isEmpty = true;
        for (int j = 0; j < ui->viewTableWidget_2->columnCount(); ++j)
        {
            QTableWidgetItem *item = ui->viewTableWidget_2->item(i, j);
            if (item && !item->text().trimmed().isEmpty())
            {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty)
        {
            ui->viewTableWidget_2->removeRow(i);
        }
    }



    ui->viewTableWidget_2->update(); // 刷新表格视图
}


void MainWindow::on_returnButton_2_clicked()
{

    ui->stackedWidget1->setCurrentWidget(ui->menuPage);
}


void MainWindow::on_searchButton_released()
{
     ui->stackedWidget1->setCurrentWidget(ui->searchPage);
    ui->nameEdit->clear();
    ui->sexEdit->clear();
    ui->magEdit->clear();

    //设置Date Edit初始值
    QDate initialDate(2050, 1, 1); // 例如，设置为 2024年6月12日
    ui->deadlineEdit_1->setDate(initialDate);


}


void MainWindow::on_viewButton_2_clicked()
{
    ui->stackedWidget1->setCurrentWidget(ui->deletePage);

}

void MainWindow::on_delebtn_released() {
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认删除",
        "确定要删除此订阅记录吗？",
        QMessageBox::Yes | QMessageBox::No
        );
    if (reply != QMessageBox::Yes) {
        return; // 如果用户选择 No，则直接返回
    }

    QFile file("file.txt");
    //打开文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open file failed";
        return ;
    }

    //读取文件
    QTextStream stream(&file);

    QList<Subscriber> m_subscribers1;

    //读取数据
    while(!stream.atEnd())
    {
        //保存数据
        QString line = stream.readLine();
        QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
        // 从界面获取截止日期
        QString deletime = ui->deadlineEdit_2->text();
        if (lineData.length() == 7)
        { // 确保每行数据包含7个字段


            Subscriber s;
            s.number = lineData[0];
            s.name = lineData[1];
            s.sex = lineData[2];
            s.phoneNumber = lineData[3];
            s.magazine = lineData[4];
            s.quantity = lineData[5];
            s.deadline = lineData[6];
            if(deletime<s.deadline)
            {
                m_subscribers1.push_back(s);

            }

        } else {
            qDebug() << "数据缺失，应为7个，是为" << lineData.length();
        }

    }
    file.close();   //关闭文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }
    QTextStream stream1(&file);
    for(auto &s:m_subscribers1)
    {
        stream << s.number << "\t\t"
               << s.name << "\t\t"
               << s.sex << "\t\t"
               << s.phoneNumber << "\t\t"
               << s.magazine << "\t\t"
               << s.quantity << "\t\t"
               << s.deadline << "\n";
    }

    //用于清除除了表头外的信息
    ui->viewTableWidget_3->clearContents();

    //以下用于删除空白行及其行号
    for (int i = ui->viewTableWidget_3->rowCount() - 1; i >= 0; --i)
    {
        bool isEmpty = true;
        for (int j = 0; j < ui->viewTableWidget_3->columnCount(); ++j)
        {
            QTableWidgetItem *item = ui->viewTableWidget_3->item(i, j);
            if (item && !item->text().trimmed().isEmpty())
            {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty)
        {
            ui->viewTableWidget_3->removeRow(i);
        }
    }
    ui->viewTableWidget_3->update(); // 刷新表格视图
}


void MainWindow::on_backbtn_released()
{
    ui->stackedWidget1->setCurrentWidget(ui->menuPage);
}



void MainWindow::on_pushButton_clicked()
{
    //切换到查看页面
     ui->stackedWidget1->setCurrentWidget(ui->deletePage);

    //设置初始行号为0
    ui->viewTableWidget_3->setRowCount(0);

    //把list中的数据显示到表格中
    ui->viewTableWidget_3->setColumnCount(7);   //设置列数
    // ui->viewTableWidget_2->setHorizontalHeaderLabels(m_fields);   //设置表头
    //遍历所有订阅


    QFile file("file.txt");
    //打开文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open file failed";
        return ;
    }

    //读取文件
    QTextStream stream(&file);

    QList<Subscriber> m_subscribers1;

    //读取数据
    while(!stream.atEnd())
    {
        //保存数据
        QString line = stream.readLine();
        QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
        if (lineData.length() == 7)
        { // 确保每行数据包含7个字段
            Subscriber s;
            s.number = lineData[0];
            s.name = lineData[1];
            s.sex = lineData[2];
            s.phoneNumber = lineData[3];
            s.magazine = lineData[4];
            s.quantity = lineData[5];
            s.deadline = lineData[6];
            m_subscribers1.push_back(s);
            // streamNum<<s.number<<"\n";
        } else {
            qDebug() << "数据缺失，应为7个，是为" << lineData.length();
        }
    }
    file.close();   //关闭文件
    for(const auto &s:m_subscribers1)
    {
        if(s.deadline<ui->deadlineEdit_2->text()){
            //获取新行的行数
            int row=ui->viewTableWidget_3->rowCount();
            //1.添加一个空行
            ui->viewTableWidget_3->insertRow(row);

            ui->viewTableWidget_3->setSelectionMode(QAbstractItemView::ExtendedSelection);
            //2.把数据设置到空行中
            ui->viewTableWidget_3->setItem(row,0,new QTableWidgetItem(s.number));
            ui->viewTableWidget_3->setItem(row,1,new QTableWidgetItem(s.name));
            ui->viewTableWidget_3->setItem(row,2,new QTableWidgetItem(s.sex));
            ui->viewTableWidget_3->setItem(row,3,new QTableWidgetItem(s.phoneNumber));
            ui->viewTableWidget_3->setItem(row,4,new QTableWidgetItem(s.magazine));
            ui->viewTableWidget_3->setItem(row,5,new QTableWidgetItem(s.quantity));
            ui->viewTableWidget_3->setItem(row,6,new QTableWidgetItem(s.deadline));
        }

    }

    //以下用于删除空白行及其行号
    for (int i = ui->viewTableWidget_3->rowCount() - 1; i >= 0; --i)
    {
        bool isEmpty = true;
        for (int j = 0; j < ui->viewTableWidget_3->columnCount(); ++j)
        {
            QTableWidgetItem *item = ui->viewTableWidget_3->item(i, j);
            if (item && !item->text().trimmed().isEmpty())
            {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty)
        {
            ui->viewTableWidget_3->removeRow(i);
        }
    }



    ui->viewTableWidget_3->update(); // 刷新表格视图
}

//以下代码用于删除选中的数据
void MainWindow::on_dele2Button_released()
{

    qint32 number1=MainWindow::getSelectedUnit();
    QList<Subscriber> m_subscribers1;
    if(number1==999)
    {
        QMessageBox::information(this,"提示","请先选择需要删除的数据！！！");
        return;


    }
    else
    {    QMessageBox::StandardButton reply = QMessageBox::question(
            this, "确认删除",
            "确定要删除此订阅记录吗？",
            QMessageBox::Yes | QMessageBox::No
            );
        if (reply != QMessageBox::Yes) {
            return; // 如果用户选择 No，则直接返回
        }
        QFile file("file.txt");
        //打开文件
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"open file failed";
            return ;
        }

        //读取文件
        QTextStream stream(&file);



        //读取数据
        while(!stream.atEnd())
        {
            //保存数据
            QString line = stream.readLine();
            QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
            if (lineData.length() == 7)
            { // 确保每行数据包含7个字段
                Subscriber s;
                s.number = lineData[0];
                s.name = lineData[1];
                s.sex = lineData[2];
                s.phoneNumber = lineData[3];
                s.magazine = lineData[4];
                s.quantity = lineData[5];
                s.deadline = lineData[6];
                m_subscribers1.push_back(s);
                // streamNum<<s.number<<"\n";
            } else {
                qDebug() << "数据缺失，应为7个，是为" << lineData.length();
            }
        }
        file.close();   //关闭文件
    }

    QString number2=m_subscribers1[number1].number;
    qDebug()<<number2;

    QFile file1("file.txt");


    if (!file1.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }


    QTextStream stream1(&file1);

    for(auto &s:m_subscribers1)   //遍历所有subscriber类对象
    {
        if(s.number!=number2)
        {

         stream1 << s.number << "\t\t"
                << s.name << "\t\t"
                << s.sex << "\t\t"
                << s.phoneNumber << "\t\t"
                << s.magazine << "\t\t"
                << s.quantity << "\t\t"
                << s.deadline << "\n";
        }
    }
    QList<Subscriber> m_subscribers2;
    for (int i = 0; i < ui->viewTableWidget_2->rowCount(); i++) {
        Subscriber subscriber; // 创建 Subscriber 对象

        // 检查每个单元格是否存在并获取文本内容
        for (int j = 0; j < ui->viewTableWidget_2->columnCount(); j++) {
            QTableWidgetItem* item = ui->viewTableWidget_2->item(i, j);
            // 根据列索引 j 赋值给 subscriber 对象的相应成员变量
            switch (j) {
            case 0: subscriber.number = item->text(); break;
            case 1: subscriber.name = item->text(); break;
            case 2: subscriber.sex = item->text(); break;
            case 3: subscriber.phoneNumber = item->text(); break;
            case 4: subscriber.magazine = item->text(); break;
            case 5: subscriber.quantity = item->text(); break;
            case 6: subscriber.deadline = item->text(); break;
            default: break;
            }
        }
        m_subscribers2.push_back(subscriber);
        // // 打印 subscriber 信息，用于调试
        qDebug().nospace() << "Subscriber " << i << ": "
                           << subscriber.number << ", "
                           << subscriber.name << ", "
                           << subscriber.sex << ", "
                           << subscriber.phoneNumber << ", "
                           << subscriber.magazine << ", "
                           << subscriber.quantity << ", "
                           << subscriber.deadline;
    }

    ui->viewTableWidget_2->clearContents();
    // 重新设置起始位置为0
    ui->viewTableWidget_2->setRowCount(0);
    //遍历所有订阅
    for(const auto &s:m_subscribers2)
    {
        if(s.number!=number2)
        {
            int row=ui->viewTableWidget_2->rowCount();
            // //1.添加一个空行
             ui->viewTableWidget_2->insertRow(row);
            //2.把数据设置到空行中_2
            ui->viewTableWidget_2->setItem(row,0,new QTableWidgetItem(s.number));
            ui->viewTableWidget_2->setItem(row,1,new QTableWidgetItem(s.name));
            ui->viewTableWidget_2->setItem(row,2,new QTableWidgetItem(s.sex));
            ui->viewTableWidget_2->setItem(row,3,new QTableWidgetItem(s.phoneNumber));
            ui->viewTableWidget_2->setItem(row,4,new QTableWidgetItem(s.magazine));
            ui->viewTableWidget_2->setItem(row,5,new QTableWidgetItem(s.quantity));
            ui->viewTableWidget_2->setItem(row,6,new QTableWidgetItem(s.deadline));

        }


    }

    // //以下用于删除空白行及其行号
    // for (int i = ui->viewTableWidget_2->rowCount() - 1; i >= 0; --i)
    // {
    //     bool isEmpty = true;
    //     for (int j = 0; j < ui->viewTableWidget_2->columnCount(); ++j)
    //     {
    //         QTableWidgetItem *item = ui->viewTableWidget_2->item(i, j);
    //         if (item && !item->text().trimmed().isEmpty())
    //         {
    //             isEmpty = false;
    //             break;
    //         }
    //     }
    //     if (isEmpty)
    //     {
    //         ui->viewTableWidget_2->removeRow(i);
    //     }
    // }
    ui->viewTableWidget_2->update(); // 刷新表格视图
}

