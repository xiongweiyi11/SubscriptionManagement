#include "addsubscriberdialog.h"
#include "ui_addsubscriberdialog.h"
#include "subscriber.h"


addSubscriberDialog::addSubscriberDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addSubscriberDialog)
{
    ui->setupUi(this);
}

addSubscriberDialog::~addSubscriberDialog()
{
    delete ui;
}

void addSubscriberDialog::initUI()  //对话框初始化
{
    //编号
    ui->numberEdit->setPlaceholderText("请输入四位编号");
    //以下保证只能输入四位编号
    QRegularExpression regId("^[0-9]{4}$");
    ui->numberEdit->setValidator(new QRegularExpressionValidator(regId,this));

    //名称,只允许输入中文和字母
    QRegularExpression regName("^[a-zA-Z\u4e00-\u9fa5]{1,}$");
    ui->nameEdit->setValidator(new QRegularExpressionValidator(regName,this) );

    //性别男生默认
    ui->manButton->setChecked(true);

    //手机号
    ui->phoneEdit->setPlaceholderText("请输入11位手机号");
    //以下保证只能输入11位编号
    QRegularExpression regPhone("^[1-9][0-9]{10} $");
    ui->phoneEdit->setValidator(new QRegularExpressionValidator(regPhone,this));

    //杂志下拉框初始化
    // 清除下拉列表中的所有现有项
    ui->magazineBox->clear();
    // 添加新项
    ui->magazineBox->addItem("新华社");
    ui->magazineBox->addItem("凤凰社");
    ui->magazineBox->addItem("长安社");
    ui->magazineBox->addItem("人民社");
    //设置当前框内值
    ui->magazineBox->setCurrentText(0);
}

//清空数据
void addSubscriberDialog::clearData()
{
    ui->numberEdit->clear();
    ui->nameEdit->clear();
    ui->phoneEdit->clear();
    ui->manButton->setChecked(true);
    ui->magazineBox->setCurrentText("新华社");
    ui->quantityBox->clear();
    ui->deadlineEdit->clear();
}

void addSubscriberDialog::on_confirmButton_released()
{
    //输入合法性判断

    //第一步：输入信息的合法性
    //1.编号
    int numLength=ui->numberEdit->text().length();
    if(numLength!=4)
    {
        QMessageBox::information(this,"提示","编号输入不合规！！！");
         return;
    }

    //以下代码用于判断编号是否唯一
    QFile fileNum("file_num.txt");
    fileNum.open(QIODevice::ReadOnly);
     QTextStream streamNum(&fileNum);
    QString line ;
     bool flag=0;
     while(!streamNum.atEnd())
     {
         line = streamNum.readLine().trimmed();
         qDebug()<<line<<"\n";
         if(line==ui->numberEdit->text().trimmed())
         {
             flag=1;
         }
     }
     fileNum.close();
     if(flag)
     {
         QMessageBox::information(this,"提示","编号重复！！！");
         return;
     }
     else
     {
        fileNum.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream out(&fileNum);
        out << ui->numberEdit->text() << "\n";
        fileNum.close();
        streamNum<<ui->numberEdit->text()<<"\n";
     }

    //2.手机号
    int phoneLength=ui->phoneEdit->text().length();
    if(phoneLength!=11)
    {
        QMessageBox::information(this,"提示","手机号输入不合规！！！");
        return;
    }

    //第二步：获取数据
    QString addNum=ui->numberEdit->text();
    QString addName=ui->nameEdit->text();
    QString addSex;
    if(ui->manButton->isChecked())
    {
        addSex="男";
    }
    else
    {
         addSex="女";
    }
    QString addPhoNUM=ui->phoneEdit->text();
    QString addMaga=ui->magazineBox->currentText();
    QString addQuan=ui->quantityBox->text();
    QString addDdl=ui->deadlineEdit->text();
    qDebug()<<addNum<<addName<<addSex<<addPhoNUM<<addMaga<<addQuan<<addDdl;
    Subscriber s;
    s.setData(addNum,addName,addSex,addPhoNUM,addMaga,addQuan,addDdl);

    //发送信号
    emit sig_addSub(s);

    //清空数据以便再次添加
    clearData();

}


void addSubscriberDialog::on_cancelButton_released()
{
    close();
}

