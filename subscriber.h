#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include <QString>
#include <QMetaType>

class Subscriber
{
public:
    Subscriber();

    bool setData(QString number, QString name, QString sex,
                 QString phoneNumber,QString magazine, QString quantity,QString deadline);

    void display(); //测试保存是否成功

    QString number;
    QString name;
    QString sex;
    QString phoneNumber;
    QString magazine;
    QString quantity;
    QString deadline;
};
Q_DECLARE_METATYPE(Subscriber)  //声明自定义类型
#endif // SUBSCRIBER_H
