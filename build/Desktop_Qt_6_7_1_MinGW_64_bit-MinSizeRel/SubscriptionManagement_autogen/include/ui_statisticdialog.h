/********************************************************************************
** Form generated from reading UI file 'statisticdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICDIALOG_H
#define UI_STATISTICDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statisticDialog
{
public:
    QStackedWidget *stackedWidget2;
    QWidget *statisticPage;
    QLabel *label;
    QComboBox *statisticBox;
    QPushButton *confirmButton;
    QPushButton *returnButton;
    QWidget *DatePage;
    QDateEdit *dateEdit;
    QPushButton *data_confirmButton;
    QPushButton *data_returnButton;
    QLabel *label_5;
    QWidget *deadlinePage;
    QLineEdit *deadlineEdit;
    QPushButton *dead_confirmButton;
    QPushButton *dead_returnButton;
    QLabel *label_4;
    QWidget *sexPage;
    QLineEdit *sexEdit;
    QPushButton *sex_confirmButton;
    QPushButton *sex_returnButton;
    QLabel *label_2;
    QWidget *quantityPage;
    QLineEdit *quantityEdit;
    QPushButton *quan_confirmPage;
    QPushButton *quan_returnButton;
    QLabel *label_3;

    void setupUi(QDialog *statisticDialog)
    {
        if (statisticDialog->objectName().isEmpty())
            statisticDialog->setObjectName("statisticDialog");
        statisticDialog->resize(300, 200);
        statisticDialog->setMinimumSize(QSize(300, 200));
        statisticDialog->setMaximumSize(QSize(300, 200));
        statisticDialog->setStyleSheet(QString::fromUtf8("QDialog\n"
"{\n"
"	background-image:none\n"
"}"));
        stackedWidget2 = new QStackedWidget(statisticDialog);
        stackedWidget2->setObjectName("stackedWidget2");
        stackedWidget2->setGeometry(QRect(0, 0, 300, 200));
        stackedWidget2->setMinimumSize(QSize(300, 200));
        stackedWidget2->setMaximumSize(QSize(300, 200));
        statisticPage = new QWidget();
        statisticPage->setObjectName("statisticPage");
        statisticPage->setMinimumSize(QSize(300, 200));
        statisticPage->setMaximumSize(QSize(300, 200));
        label = new QLabel(statisticPage);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 271, 41));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        statisticBox = new QComboBox(statisticPage);
        statisticBox->setObjectName("statisticBox");
        statisticBox->setGeometry(QRect(70, 70, 161, 41));
        QFont font1;
        font1.setPointSize(9);
        statisticBox->setFont(font1);
        confirmButton = new QPushButton(statisticPage);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(60, 140, 80, 30));
        returnButton = new QPushButton(statisticPage);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(160, 140, 80, 30));
        stackedWidget2->addWidget(statisticPage);
        DatePage = new QWidget();
        DatePage->setObjectName("DatePage");
        DatePage->setMinimumSize(QSize(300, 200));
        DatePage->setMaximumSize(QSize(300, 200));
        dateEdit = new QDateEdit(DatePage);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(70, 80, 141, 31));
        data_confirmButton = new QPushButton(DatePage);
        data_confirmButton->setObjectName("data_confirmButton");
        data_confirmButton->setGeometry(QRect(55, 140, 80, 30));
        data_returnButton = new QPushButton(DatePage);
        data_returnButton->setObjectName("data_returnButton");
        data_returnButton->setGeometry(QRect(155, 140, 91, 31));
        label_5 = new QLabel(DatePage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(65, 20, 201, 31));
        label_5->setFont(font);
        stackedWidget2->addWidget(DatePage);
        deadlinePage = new QWidget();
        deadlinePage->setObjectName("deadlinePage");
        deadlinePage->setMinimumSize(QSize(300, 200));
        deadlinePage->setMaximumSize(QSize(300, 16777215));
        deadlineEdit = new QLineEdit(deadlinePage);
        deadlineEdit->setObjectName("deadlineEdit");
        deadlineEdit->setGeometry(QRect(80, 80, 121, 31));
        deadlineEdit->setReadOnly(true);
        dead_confirmButton = new QPushButton(deadlinePage);
        dead_confirmButton->setObjectName("dead_confirmButton");
        dead_confirmButton->setGeometry(QRect(55, 140, 80, 30));
        dead_returnButton = new QPushButton(deadlinePage);
        dead_returnButton->setObjectName("dead_returnButton");
        dead_returnButton->setGeometry(QRect(155, 140, 80, 30));
        label_4 = new QLabel(deadlinePage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 10, 261, 51));
        label_4->setFont(font);
        stackedWidget2->addWidget(deadlinePage);
        sexPage = new QWidget();
        sexPage->setObjectName("sexPage");
        sexPage->setMinimumSize(QSize(300, 200));
        sexPage->setMaximumSize(QSize(300, 200));
        sexEdit = new QLineEdit(sexPage);
        sexEdit->setObjectName("sexEdit");
        sexEdit->setGeometry(QRect(80, 70, 131, 41));
        sexEdit->setReadOnly(true);
        sex_confirmButton = new QPushButton(sexPage);
        sex_confirmButton->setObjectName("sex_confirmButton");
        sex_confirmButton->setGeometry(QRect(55, 140, 80, 30));
        sex_confirmButton->setMinimumSize(QSize(0, 0));
        sex_returnButton = new QPushButton(sexPage);
        sex_returnButton->setObjectName("sex_returnButton");
        sex_returnButton->setGeometry(QRect(155, 140, 80, 30));
        label_2 = new QLabel(sexPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 10, 271, 41));
        label_2->setFont(font);
        stackedWidget2->addWidget(sexPage);
        quantityPage = new QWidget();
        quantityPage->setObjectName("quantityPage");
        quantityPage->setMinimumSize(QSize(300, 200));
        quantityPage->setMaximumSize(QSize(300, 200));
        quantityEdit = new QLineEdit(quantityPage);
        quantityEdit->setObjectName("quantityEdit");
        quantityEdit->setGeometry(QRect(80, 80, 121, 31));
        quantityEdit->setReadOnly(true);
        quan_confirmPage = new QPushButton(quantityPage);
        quan_confirmPage->setObjectName("quan_confirmPage");
        quan_confirmPage->setGeometry(QRect(55, 140, 80, 30));
        quan_returnButton = new QPushButton(quantityPage);
        quan_returnButton->setObjectName("quan_returnButton");
        quan_returnButton->setGeometry(QRect(155, 140, 80, 30));
        label_3 = new QLabel(quantityPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 10, 171, 31));
        label_3->setFont(font);
        stackedWidget2->addWidget(quantityPage);

        retranslateUi(statisticDialog);

        QMetaObject::connectSlotsByName(statisticDialog);
    } // setupUi

    void retranslateUi(QDialog *statisticDialog)
    {
        statisticDialog->setWindowTitle(QCoreApplication::translate("statisticDialog", "\347\273\237\350\256\241\350\256\242\351\230\205\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("statisticDialog", "\350\257\267\351\200\211\346\213\251\344\275\240\346\203\263\350\246\201\347\273\237\350\256\241\347\232\204\347\261\273\345\236\213", nullptr));
        confirmButton->setText(QCoreApplication::translate("statisticDialog", "\347\241\256\350\256\244", nullptr));
        returnButton->setText(QCoreApplication::translate("statisticDialog", "\350\277\224\345\233\236", nullptr));
        data_confirmButton->setText(QCoreApplication::translate("statisticDialog", "\347\241\256\345\256\232", nullptr));
        data_returnButton->setText(QCoreApplication::translate("statisticDialog", "\350\277\224\345\233\236", nullptr));
        label_5->setText(QCoreApplication::translate("statisticDialog", "\350\257\267\350\276\223\345\205\245\346\210\252\346\255\242\346\227\245\346\234\237", nullptr));
        dead_confirmButton->setText(QCoreApplication::translate("statisticDialog", "\347\241\256\350\256\244", nullptr));
        dead_returnButton->setText(QCoreApplication::translate("statisticDialog", "\350\277\224\345\233\236", nullptr));
        label_4->setText(QCoreApplication::translate("statisticDialog", "\346\210\252\346\255\242\346\227\245\346\234\237\344\270\272\350\257\245\346\227\245\346\234\237\347\232\204\344\270\252\346\225\260\344\270\272", nullptr));
        sex_confirmButton->setText(QCoreApplication::translate("statisticDialog", "\347\241\256\350\256\244", nullptr));
        sex_returnButton->setText(QCoreApplication::translate("statisticDialog", "\350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("statisticDialog", "\350\257\245\347\261\273\345\236\213\347\273\237\350\256\241\347\273\223\346\236\234\344\270\272", nullptr));
        quan_confirmPage->setText(QCoreApplication::translate("statisticDialog", "\347\241\256\350\256\244", nullptr));
        quan_returnButton->setText(QCoreApplication::translate("statisticDialog", "\350\277\224\345\233\236", nullptr));
        label_3->setText(QCoreApplication::translate("statisticDialog", "\346\235\202\345\277\227\347\232\204\346\200\273\350\256\242\351\230\205\346\225\260\344\270\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class statisticDialog: public Ui_statisticDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICDIALOG_H
