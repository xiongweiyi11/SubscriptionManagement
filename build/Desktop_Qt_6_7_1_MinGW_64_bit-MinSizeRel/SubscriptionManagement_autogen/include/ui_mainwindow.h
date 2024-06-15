/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QStackedWidget *stackedWidget1;
    QWidget *menuPage;
    QLabel *label;
    QPushButton *closeButton;
    QPushButton *searchButton;
    QPushButton *viewButton;
    QPushButton *viewButton_2;
    QWidget *deletePage;
    QTableWidget *viewTableWidget_3;
    QPushButton *delebtn;
    QPushButton *backbtn;
    QLabel *label_7;
    QDateEdit *deadlineEdit_2;
    QPushButton *pushButton;
    QWidget *resultPage;
    QTableWidget *viewTableWidget_2;
    QPushButton *editButton_2;
    QPushButton *returnButton_3;
    QPushButton *dele2Button;
    QWidget *searchPage;
    QPushButton *search;
    QPushButton *returnButton_2;
    QDateEdit *deadlineEdit_1;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_5;
    QLineEdit *magEdit;
    QLineEdit *sexEdit;
    QLineEdit *nameEdit;
    QWidget *viewPage;
    QTableWidget *viewTableWidget;
    QPushButton *addButton;
    QPushButton *saveButton;
    QPushButton *returnButton;
    QPushButton *statisticButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(960, 640);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(960, 640));
        MainWindow->setMaximumSize(QSize(960, 640));
        MainWindow->setStyleSheet(QString::fromUtf8("QStackedWidget#stackedWidget1\n"
"{\n"
"	border-image:url(:/image/background.jpg);\n"
"}\n"
"\n"
"QStackedWidget#stackedWidget1 QPushButton\n"
"{\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	background-color: rgb(0,153,255);\n"
"	color:rgb(255,255,255);\n"
"}\n"
"\n"
"QStackedWidget#stackedWidget1 QPushButton:hover\n"
"{\n"
"	background-color: rgb(0,141,235);\n"
"	color: rgb(0, 170, 255);\n"
"}\n"
"\n"
""));
        stackedWidget1 = new QStackedWidget(MainWindow);
        stackedWidget1->setObjectName("stackedWidget1");
        stackedWidget1->setGeometry(QRect(10, 0, 960, 640));
        sizePolicy.setHeightForWidth(stackedWidget1->sizePolicy().hasHeightForWidth());
        stackedWidget1->setSizePolicy(sizePolicy);
        stackedWidget1->setMinimumSize(QSize(960, 640));
        stackedWidget1->setMaximumSize(QSize(960, 640));
        stackedWidget1->setStyleSheet(QString::fromUtf8(""));
        menuPage = new QWidget();
        menuPage->setObjectName("menuPage");
        menuPage->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(menuPage);
        label->setObjectName("label");
        label->setGeometry(QRect(275, 80, 430, 80));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignCenter);
        closeButton = new QPushButton(menuPage);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(380, 460, 210, 50));
        QFont font1;
        font1.setPointSize(16);
        closeButton->setFont(font1);
        searchButton = new QPushButton(menuPage);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(380, 300, 210, 50));
        searchButton->setFont(font1);
        viewButton = new QPushButton(menuPage);
        viewButton->setObjectName("viewButton");
        viewButton->setGeometry(QRect(380, 220, 210, 50));
        viewButton->setFont(font1);
        viewButton_2 = new QPushButton(menuPage);
        viewButton_2->setObjectName("viewButton_2");
        viewButton_2->setGeometry(QRect(380, 380, 210, 50));
        viewButton_2->setFont(font1);
        stackedWidget1->addWidget(menuPage);
        deletePage = new QWidget();
        deletePage->setObjectName("deletePage");
        viewTableWidget_3 = new QTableWidget(deletePage);
        if (viewTableWidget_3->columnCount() < 7)
            viewTableWidget_3->setColumnCount(7);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        viewTableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        viewTableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        viewTableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        viewTableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        viewTableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        viewTableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        viewTableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        viewTableWidget_3->setObjectName("viewTableWidget_3");
        viewTableWidget_3->setGeometry(QRect(110, 110, 731, 411));
        QFont font3;
        font3.setPointSize(9);
        viewTableWidget_3->setFont(font3);
        delebtn = new QPushButton(deletePage);
        delebtn->setObjectName("delebtn");
        delebtn->setGeometry(QRect(330, 540, 130, 50));
        backbtn = new QPushButton(deletePage);
        backbtn->setObjectName("backbtn");
        backbtn->setGeometry(QRect(510, 540, 130, 50));
        label_7 = new QLabel(deletePage);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(270, 45, 121, 41));
        QFont font4;
        font4.setPointSize(12);
        label_7->setFont(font4);
        deadlineEdit_2 = new QDateEdit(deletePage);
        deadlineEdit_2->setObjectName("deadlineEdit_2");
        deadlineEdit_2->setGeometry(QRect(400, 51, 150, 31));
        pushButton = new QPushButton(deletePage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 50, 100, 35));
        stackedWidget1->addWidget(deletePage);
        resultPage = new QWidget();
        resultPage->setObjectName("resultPage");
        viewTableWidget_2 = new QTableWidget(resultPage);
        if (viewTableWidget_2->columnCount() < 7)
            viewTableWidget_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font2);
        viewTableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font2);
        viewTableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font2);
        viewTableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font2);
        viewTableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font2);
        viewTableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font2);
        viewTableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font2);
        viewTableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        viewTableWidget_2->setObjectName("viewTableWidget_2");
        viewTableWidget_2->setGeometry(QRect(0, 0, 711, 580));
        viewTableWidget_2->setFont(font3);
        editButton_2 = new QPushButton(resultPage);
        editButton_2->setObjectName("editButton_2");
        editButton_2->setGeometry(QRect(760, 130, 131, 50));
        QFont font5;
        font5.setPointSize(18);
        editButton_2->setFont(font5);
        returnButton_3 = new QPushButton(resultPage);
        returnButton_3->setObjectName("returnButton_3");
        returnButton_3->setGeometry(QRect(760, 390, 131, 50));
        returnButton_3->setFont(font5);
        dele2Button = new QPushButton(resultPage);
        dele2Button->setObjectName("dele2Button");
        dele2Button->setGeometry(QRect(760, 260, 131, 51));
        dele2Button->setFont(font5);
        stackedWidget1->addWidget(resultPage);
        searchPage = new QWidget();
        searchPage->setObjectName("searchPage");
        search = new QPushButton(searchPage);
        search->setObjectName("search");
        search->setGeometry(QRect(310, 370, 131, 50));
        search->setFont(font1);
        returnButton_2 = new QPushButton(searchPage);
        returnButton_2->setObjectName("returnButton_2");
        returnButton_2->setGeometry(QRect(500, 370, 131, 50));
        returnButton_2->setFont(font1);
        deadlineEdit_1 = new QDateEdit(searchPage);
        deadlineEdit_1->setObjectName("deadlineEdit_1");
        deadlineEdit_1->setGeometry(QRect(440, 301, 121, 31));
        label_8 = new QLabel(searchPage);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(380, 155, 51, 21));
        label_8->setFont(font1);
        label_2 = new QLabel(searchPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(380, 205, 51, 21));
        label_2->setFont(font1);
        label_9 = new QLabel(searchPage);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(380, 255, 51, 21));
        label_9->setFont(font1);
        label_10 = new QLabel(searchPage);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(340, 305, 91, 21));
        label_10->setFont(font1);
        label_5 = new QLabel(searchPage);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 50, 321, 61));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setTextFormat(Qt::MarkdownText);
        label_5->setAlignment(Qt::AlignCenter);
        magEdit = new QLineEdit(searchPage);
        magEdit->setObjectName("magEdit");
        magEdit->setGeometry(QRect(440, 250, 121, 31));
        sexEdit = new QLineEdit(searchPage);
        sexEdit->setObjectName("sexEdit");
        sexEdit->setGeometry(QRect(440, 201, 121, 31));
        nameEdit = new QLineEdit(searchPage);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(440, 152, 121, 31));
        stackedWidget1->addWidget(searchPage);
        viewPage = new QWidget();
        viewPage->setObjectName("viewPage");
        viewPage->setStyleSheet(QString::fromUtf8("QWidget#viewPage\n"
"{\n"
"	border-image:url(:/image/background.jpg);\n"
"}\n"
"\n"
"QWidget#viewPage QPushButton\n"
"{\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	background-color: rgb(0,153,255);\n"
"	color:rgb(255,255,255);\n"
"}\n"
"\n"
"QWidget#viewPage QPushButton:hover\n"
"{\n"
"	background-color: rgb(0,141,235);\n"
"	color: rgb(0, 170, 255);\n"
"}\n"
"\n"
""));
        viewTableWidget = new QTableWidget(viewPage);
        if (viewTableWidget->columnCount() < 7)
            viewTableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font2);
        viewTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font2);
        viewTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font2);
        viewTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font2);
        viewTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font2);
        viewTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font2);
        viewTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font2);
        viewTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem20);
        viewTableWidget->setObjectName("viewTableWidget");
        viewTableWidget->setGeometry(QRect(0, 0, 711, 580));
        viewTableWidget->setFont(font3);
        addButton = new QPushButton(viewPage);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(770, 220, 131, 50));
        addButton->setFont(font5);
        saveButton = new QPushButton(viewPage);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(770, 330, 131, 50));
        saveButton->setFont(font5);
        returnButton = new QPushButton(viewPage);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(770, 440, 131, 50));
        returnButton->setFont(font5);
        statisticButton = new QPushButton(viewPage);
        statisticButton->setObjectName("statisticButton");
        statisticButton->setGeometry(QRect(770, 110, 131, 50));
        statisticButton->setFont(font5);
        stackedWidget1->addWidget(viewPage);
        saveButton->raise();
        returnButton->raise();
        addButton->raise();
        viewTableWidget->raise();
        statisticButton->raise();

        retranslateUi(MainWindow);

        stackedWidget1->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\235\202\345\277\227\350\256\242\351\230\205\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\235\202\345\277\227\350\256\242\351\230\205\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\346\235\202\345\277\227\350\256\242\351\230\205\346\225\260\346\215\256", nullptr));
        viewButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\346\235\202\345\277\227\350\256\242\351\230\205\346\225\260\346\215\256", nullptr));
        viewButton_2->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\350\277\207\346\234\237\350\256\242\351\230\205\346\225\260\346\215\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = viewTableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = viewTableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = viewTableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = viewTableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = viewTableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\346\235\202\345\277\227\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = viewTableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\350\256\242\351\230\205\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = viewTableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\346\210\252\346\255\242\346\227\245\346\234\237", nullptr));
        delebtn->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        backbtn->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\346\210\252\346\255\242\346\227\245\346\234\237\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = viewTableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = viewTableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = viewTableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = viewTableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = viewTableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "\346\235\202\345\277\227\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = viewTableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\350\256\242\351\230\205\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = viewTableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "\346\210\252\346\255\242\346\227\245\346\234\237", nullptr));
        editButton_2->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        returnButton_3->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        dele2Button->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        search->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        returnButton_2->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\275\215\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\346\210\252\346\255\242\346\227\245\346\234\237\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = viewTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = viewTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = viewTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = viewTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "\346\211\213\346\234\272\345\217\267\347\240\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = viewTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\346\235\202\345\277\227\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = viewTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\350\256\242\351\230\205\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = viewTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "\346\210\252\346\255\242\346\227\245\346\234\237", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        returnButton->setText(QCoreApplication::translate("MainWindow", "\350\277\224\345\233\236", nullptr));
        statisticButton->setText(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
