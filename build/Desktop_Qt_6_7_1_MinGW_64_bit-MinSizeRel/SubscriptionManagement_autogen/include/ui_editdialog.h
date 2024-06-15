/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

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

class Ui_editDialog
{
public:
    QRadioButton *womanButton;
    QComboBox *magazineBox;
    QLineEdit *phoneEdit;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *cancelButton;
    QLabel *label;
    QLabel *label_5;
    QPushButton *confirmButton;
    QLabel *label_3;
    QLineEdit *numberEdit;
    QSpinBox *quantityBox;
    QLabel *label_4;
    QLineEdit *nameEdit;
    QDateEdit *deadlineEdit;
    QLabel *label_2;
    QRadioButton *manButton;

    void setupUi(QDialog *editDialog)
    {
        if (editDialog->objectName().isEmpty())
            editDialog->setObjectName("editDialog");
        editDialog->resize(400, 300);
        womanButton = new QRadioButton(editDialog);
        womanButton->setObjectName("womanButton");
        womanButton->setGeometry(QRect(207, 80, 51, 18));
        magazineBox = new QComboBox(editDialog);
        magazineBox->setObjectName("magazineBox");
        magazineBox->setGeometry(QRect(130, 147, 151, 22));
        phoneEdit = new QLineEdit(editDialog);
        phoneEdit->setObjectName("phoneEdit");
        phoneEdit->setGeometry(QRect(130, 110, 150, 22));
        label_6 = new QLabel(editDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(72, 183, 36, 16));
        label_7 = new QLabel(editDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(71, 210, 51, 21));
        cancelButton = new QPushButton(editDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(180, 243, 81, 31));
        label = new QLabel(editDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(72, 15, 27, 16));
        label_5 = new QLabel(editDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(72, 81, 27, 16));
        confirmButton = new QPushButton(editDialog);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(80, 243, 81, 31));
        label_3 = new QLabel(editDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(71, 110, 51, 20));
        numberEdit = new QLineEdit(editDialog);
        numberEdit->setObjectName("numberEdit");
        numberEdit->setGeometry(QRect(130, 13, 150, 22));
        quantityBox = new QSpinBox(editDialog);
        quantityBox->setObjectName("quantityBox");
        quantityBox->setGeometry(QRect(130, 179, 150, 22));
        label_4 = new QLabel(editDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(71, 150, 51, 16));
        nameEdit = new QLineEdit(editDialog);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(130, 49, 150, 22));
        deadlineEdit = new QDateEdit(editDialog);
        deadlineEdit->setObjectName("deadlineEdit");
        deadlineEdit->setGeometry(QRect(130, 209, 150, 22));
        label_2 = new QLabel(editDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(72, 51, 27, 16));
        manButton = new QRadioButton(editDialog);
        manButton->setObjectName("manButton");
        manButton->setGeometry(QRect(140, 80, 41, 18));

        retranslateUi(editDialog);

        QMetaObject::connectSlotsByName(editDialog);
    } // setupUi

    void retranslateUi(QDialog *editDialog)
    {
        editDialog->setWindowTitle(QCoreApplication::translate("editDialog", "\347\274\226\350\276\221\350\256\242\351\230\205\344\277\241\346\201\257", nullptr));
        womanButton->setText(QCoreApplication::translate("editDialog", "\345\245\263", nullptr));
        label_6->setText(QCoreApplication::translate("editDialog", "\350\256\242\351\230\205\346\225\260\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("editDialog", "\346\210\252\346\255\242\346\227\245\346\234\237\357\274\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("editDialog", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("editDialog", "\347\274\226\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("editDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        confirmButton->setText(QCoreApplication::translate("editDialog", "\347\241\256\345\256\232", nullptr));
        label_3->setText(QCoreApplication::translate("editDialog", "\346\211\213\346\234\272\345\217\267\347\240\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("editDialog", "\346\235\202\345\277\227\345\215\225\344\275\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("editDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
        manButton->setText(QCoreApplication::translate("editDialog", "\347\224\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editDialog: public Ui_editDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
