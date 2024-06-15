#include "subscriber.h"
#include <QDebug>

Subscriber::Subscriber() {}

//设置对象数据
bool Subscriber::setData(QString number, QString name, QString sex, QString phoneNumber, QString magazine, QString quantity, QString deadline)
{
    this->number=number;
    this->name=name;
    this->sex=sex;
    this->phoneNumber=phoneNumber;
    this->magazine=magazine;
    this->quantity=quantity;
    this->deadline=deadline;
    return 1;
}


void Subscriber::display()  //测试保存是否成功
{
    qDebug()<<number<<name<<sex <<phoneNumber <<magazine<<quantity<<deadline;
}
