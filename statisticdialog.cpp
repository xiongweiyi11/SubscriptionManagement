#include "statisticdialog.h"
#include "subscriber.h"
#include "ui_statisticdialog.h"

statisticDialog::statisticDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::statisticDialog)
{
    ui->setupUi(this);
}

//对话框初始化
void statisticDialog::initUI()
{
    //杂志下拉框初始化
    // 清除下拉列表中的所有现有项
    ui->statisticBox->clear();
    // 添加新项
    ui->statisticBox->addItem("性别");
    ui->statisticBox->addItem("订阅数");
    ui->statisticBox->addItem("订阅期限");
    //设置当前框内值
    ui->statisticBox->setCurrentText(0);


}

statisticDialog::~statisticDialog()
{
    delete ui;
}

void statisticDialog::on_confirmButton_released()
{
    QString str=ui->statisticBox->currentText();
    qDebug()<<str;



    if(str=="性别")
    {
        ui->stackedWidget2->setCurrentWidget(ui->sexPage);
        qint32 i=0;
        qint32 j=0;
        QFile file("C:\\QT_Document\\SubscriptionManagement\\file.txt");
        //打开文件
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"open file failed";
            return;
        }

        //读取文件
        QTextStream stream(&file);
        //读取数据
        while(!stream.atEnd())
        {
            //保存数据
            QString line = stream.readLine();
            QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
             Subscriber s;
            if (lineData.length() == 7)
            { // 确保每行数据包含7个字段

                s.number = lineData[0];
                s.name = lineData[1];
                s.sex = lineData[2];
                s.phoneNumber = lineData[3];
                s.magazine = lineData[4];
                s.quantity = lineData[5];
                s.deadline = lineData[6];
            } else {
                qDebug() << "数据缺失，应为7个，是为" << lineData.length();
            }
            if(s.sex=="男")
            {
                ++i;
            }
            else
            {
                ++j;
            }


        }
         file.close();

        ui->sexEdit->setText(QString("男生：%1人,女生：%2人").arg(i).arg(j));

    }
    else if(str=="订阅数")
    {
        ui->stackedWidget2->setCurrentWidget(ui->quantityPage);
        qint32 i=0;
        QFile file("C:\\QT_Document\\SubscriptionManagement\\file.txt");
        //打开文件
        if(!file.open(QIODevice::ReadOnly))
        {
            qDebug()<<"open file failed";
            return;
        }

        //读取文件
        QTextStream stream(&file);
        //读取数据
        while(!stream.atEnd())
        {
            //保存数据
            QString line = stream.readLine();
            QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
            Subscriber s;
            if (lineData.length() == 7)
            {
                s.number = lineData[0];
                s.name = lineData[1];
                s.sex = lineData[2];
                s.phoneNumber = lineData[3];
                s.magazine = lineData[4];
                s.quantity = lineData[5];
                s.deadline = lineData[6];
                i+=s.quantity.toInt();
            } else {
                qDebug() << "数据缺失，应为7个，是为" << lineData.length();
            }

        }
        file.close();
        ui->quantityEdit->setText(QString::number(i));

    }
    else
    {
        ui->stackedWidget2->setCurrentWidget(ui->DatePage);


    }


}

void statisticDialog::on_returnButton_released()
{
    close();
}



void statisticDialog::on_sex_confirmButton_released()
{
    close();
}


void statisticDialog::on_sex_returnButton_released()
{
    ui->stackedWidget2->setCurrentWidget(ui->statisticPage);
}


void statisticDialog::on_quan_confirmPage_released()
{
    close();
}


void statisticDialog::on_quan_returnButton_released()
{
     ui->stackedWidget2->setCurrentWidget(ui->statisticPage);
}



void statisticDialog::on_data_confirmButton_released()
{
    ui->stackedWidget2->setCurrentWidget(ui->deadlinePage);
    QString str=ui->dateEdit->text();
    qDebug()<<str;
    qint32 i=0;
    QFile file("C:\\QT_Document\\SubscriptionManagement\\file.txt");
    //打开文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"open file failed";
        return;
    }

    //读取文件
    QTextStream stream(&file);
    //读取数据
    while(!stream.atEnd())
    {
        //保存数据
        QString line = stream.readLine();
        QStringList lineData = line.split("\t", Qt::SkipEmptyParts);    //用于去除空格
        Subscriber s;
        if (lineData.length() == 7)
        {
            s.number = lineData[0];
            s.name = lineData[1];
            s.sex = lineData[2];
            s.phoneNumber = lineData[3];
            s.magazine = lineData[4];
            s.quantity = lineData[5];
            s.deadline = lineData[6];
        } else {
            qDebug() << "数据缺失，应为7个，是为" << lineData.length();
        }

        //统计过期的数据
        if(str>s.deadline)
        {
            ++i;
        }

    }
    file.close();
    ui->deadlineEdit->setText(QString::number(i));
}


void statisticDialog::on_data_returnButton_released()
{
    ui->stackedWidget2->setCurrentWidget(ui->statisticPage);
}




void statisticDialog::on_dead_confirmButton_released()
{
    close();
}


void statisticDialog::on_dead_returnButton_released()
{
    ui->stackedWidget2->setCurrentWidget(ui->DatePage);
}




