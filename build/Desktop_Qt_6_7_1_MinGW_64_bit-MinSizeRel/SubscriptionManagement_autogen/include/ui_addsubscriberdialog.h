/********************************************************************************
** Form generated from reading UI file 'addsubscriberdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSUBSCRIBERDIALOG_H
#define UI_ADDSUBSCRIBERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_addSubscriberDialog
{
public:
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLineEdit *numberEdit;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *phoneEdit;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *magazineBox;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *quantityBox;
    QLabel *label_7;
    QDateEdit *deadlineEdit;
    QRadioButton *manButton;
    QRadioButton *womanButton;

    void setupUi(QDialog *addSubscriberDialog)
    {
        if (addSubscriberDialog->objectName().isEmpty())
            addSubscriberDialog->setObjectName("addSubscriberDialog");
        addSubscriberDialog->resize(400, 300);
        addSubscriberDialog->setMinimumSize(QSize(400, 300));
        addSubscriberDialog->setMaximumSize(QSize(400, 300));
        confirmButton = new QPushButton(addSubscriberDialog);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(100, 250, 81, 31));
        cancelButton = new QPushButton(addSubscriberDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(200, 250, 81, 31));
        label = new QLabel(addSubscriberDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(92, 22, 27, 16));
        numberEdit = new QLineEdit(addSubscriberDialog);
        numberEdit->setObjectName("numberEdit");
        numberEdit->setGeometry(QRect(150, 20, 150, 22));
        nameEdit = new QLineEdit(addSubscriberDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(150, 56, 150, 22));
        label_2 = new QLabel(addSubscriberDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(92, 58, 27, 16));
        phoneEdit = new QLineEdit(addSubscriberDialog);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setGeometry(QRect(150, 117, 150, 22));
        label_3 = new QLabel(addSubscriberDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(91, 117, 51, 20));
        label_4 = new QLabel(addSubscriberDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(91, 157, 51, 16));
        magazineBox = new QComboBox(addSubscriberDialog);
        magazineBox->setObjectName("magazineBox");
        magazineBox->setGeometry(QRect(150, 154, 151, 22));
        label_5 = new QLabel(addSubscriberDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(92, 88, 27, 16));
        label_6 = new QLabel(addSubscriberDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(92, 190, 36, 16));
        quantityBox = new QSpinBox(addSubscriberDialog);
        quantityBox->setObjectName("quantityBox");
        quantityBox->setGeometry(QRect(150, 186, 150, 22));
        label_7 = new QLabel(addSubscriberDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(91, 217, 51, 21));
        deadlineEdit = new QDateEdit(addSubscriberDialog);
        deadlineEdit->setObjectName("deadlineEdit");
        deadlineEdit->setGeometry(QRect(150, 216, 150, 22));
        manButton = new QRadioButton(addSubscriberDialog);
        manButton->setObjectName("manButton");
        manButton->setGeometry(QRect(160, 87, 41, 18));
        womanButton = new QRadioButton(addSubscriberDialog);
        womanButton->setObjectName("womanButton");
        womanButton->setGeometry(QRect(227, 87, 51, 18));

        retranslateUi(addSubscriberDialog);

        QMetaObject::connectSlotsByName(addSubscriberDialog);
    } // setupUi

    void retranslateUi(QDialog *addSubscriberDialog)
    {
        addSubscriberDialog->setWindowTitle(QCoreApplication::translate("addSubscriberDialog", "\346\267\273\345\212\240\350\256\242\351\230\205\344\277\241\346\201\257", nullptr));
        confirmButton->setText(QCoreApplication::translate("addSubscriberDialog", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("addSubscriberDialog", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("addSubscriberDialog", "\347\274\226\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("addSubscriberDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("addSubscriberDialog", "\346\211\213\346\234\272\345\217\267\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("addSubscriberDialog", "\346\235\202\345\277\227\345\215\225\344\275\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("addSubscriberDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("addSubscriberDialog", "\350\256\242\351\230\205\346\225\260\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("addSubscriberDialog", "\346\210\252\346\255\242\346\227\245\346\234\237\357\274\232", nullptr));
        manButton->setText(QCoreApplication::translate("addSubscriberDialog", "\347\224\267", nullptr));
        womanButton->setText(QCoreApplication::translate("addSubscriberDialog", "\345\245\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addSubscriberDialog: public Ui_addSubscriberDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSUBSCRIBERDIALOG_H
