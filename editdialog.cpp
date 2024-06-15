#include "editdialog.h"
#include "ui_editdialog.h"

extern QString number;

editDialog::editDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editDialog)
    ,str(number)

{
    ui->setupUi(this);

    // MainWindow *mai=new MainWindow(this);

    // connect(mai,&MainWindow::sendData,this,&editDialog::recieveData);




}

editDialog::~editDialog()
{
    delete ui;
}

void editDialog::initUI()
{
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

    Subscriber s1;
    for(auto &s:m_subscribers1)   //遍历所有subscriber类对象
    {
        if(s.number==number)
        {
            s1=s;
        }

    }

    //编号
    //设置默认为要更改的数据
    ui->numberEdit->setText(s1.number);
    //以下保证只能输入四位编号
    QRegularExpression regId("^[0-9]{4}$");
    ui->numberEdit->setValidator(new QRegularExpressionValidator(regId,this));

    //名称,只允许输入中文和字母
    QRegularExpression regName("^[a-zA-Z\u4e00-\u9fa5]{1,}$");
    ui->nameEdit->setValidator(new QRegularExpressionValidator(regName,this) );

    //设置默认为要更改的数据
    ui->nameEdit->setText(s1.name);

    //设置性别为默认为要更改的数据
    if(s1.sex=="男")
    {
        ui->manButton->setChecked(true);
    }
    else
    {
        ui->womanButton->setChecked(true);
    }

    //手机号
    //设置默认为要更改的数据
    ui->phoneEdit->setText("请输入11位手机号");
    //以下保证只能输入11位编号
    QRegularExpression regPhone("^[1-9][0-9]{10} $");
    ui->phoneEdit->setValidator(new QRegularExpressionValidator(regPhone,this));
    //设置默认为要更改的数据
    ui->phoneEdit->setText(s1.phoneNumber);

    //杂志下拉框初始化
    // 清除下拉列表中的所有现有项
    ui->magazineBox->clear();
    // 添加新项
    ui->magazineBox->addItem("新华社");
    ui->magazineBox->addItem("凤凰社");
    ui->magazineBox->addItem("长安社");
    ui->magazineBox->addItem("人民社");
    //设置当前框内值
    //设置默认为要更改的数据
    ui->magazineBox->setCurrentText(s1.magazine);

    //qDebug()<<str<<"@";
    ui->quantityBox->setValue(s1.quantity.toInt());

    //设置默认为要更改的数据
    QString deadlineStr = s1.deadline; // 假设这是获取的字符串形式的截止日期
    QDate deadlineDate = QDate::fromString(deadlineStr, "yyyy/M/d"); // 假设日期格式为ISO标准格式
    ui->deadlineEdit->setDate(deadlineDate);

}

void editDialog::on_confirmButton_released()
{
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

    //1.编号
    int numLength=ui->numberEdit->text().length();
    if(numLength!=4)
    {
        QMessageBox::information(this,"提示","编号输入不合规！！！");
        return;
    }

    //以下代码用于判断编号是否唯一
    QFile fileNum("C:\\QT_Document\\SubscriptionManagement\\file_num.txt");
    fileNum.open(QIODevice::ReadOnly);
    QTextStream streamNum(&fileNum);
    QString line ;
    bool flag=0;
    while(!streamNum.atEnd())
    {
        line = streamNum.readLine().trimmed();
        qDebug()<<line<<"\n";
        if(line==ui->numberEdit->text().trimmed()&&line!=number)
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
    QString addPhoNum=ui->phoneEdit->text();
    QString addMaga=ui->magazineBox->currentText();
    QString addQuan=ui->quantityBox->text();
    QString addDdl=ui->deadlineEdit->text();
    Subscriber s1;
    for(auto &s:m_subscribers1)   //遍历所有subscriber类对象
    {
        if(s.number==number)
        {
            s.number = addNum;
            s.name = addName;
            s.sex = addSex;
            s.phoneNumber = addPhoNum;
            s.magazine = addMaga;
            s.quantity = addQuan;
            s.deadline = addDdl;

            s1.setData(addNum,addName,addSex,addPhoNum,addMaga,addQuan,addDdl);


        }

    }
    emit sig_editSub(s1);



    QFile file1("file.txt");


    if (!file1.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "打开文件失败";
        return;
    }


    QTextStream stream1(&file1);

    for(auto &s:m_subscribers1)   //遍历所有subscriber类对象
    {
        qDebug()<< s.number << "\t\t"
                 << s.name << "\t\t"
                 << s.sex << "\t\t"
                 << s.phoneNumber << "\t\t"
                 << s.magazine << "\t\t"
                 << s.quantity << "\t\t"
                 << s.deadline << "\n";
        // 写入文件
        stream1 << s.number << "\t\t"
                << s.name << "\t\t"
                << s.sex << "\t\t"
                << s.phoneNumber << "\t\t"
                << s.magazine << "\t\t"
                << s.quantity << "\t\t"
                << s.deadline << "\n";
    }

    close();


}

void editDialog::on_cancelButton_released()
{
    close();
}

