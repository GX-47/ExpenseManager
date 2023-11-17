/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *title;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *newBtn;
    QPushButton *deleteBtn;
    QPushButton *displayBtn;
    QPushButton *totalBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(806, 559);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #E2DED3;\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(0, 9, 801, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Footlight MT Light")});
        font.setPointSize(50);
        font.setUnderline(false);
        title->setFont(font);
        title->setStyleSheet(QString::fromUtf8("color: #E31748;"));
        title->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 120, 671, 131));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Modern No. 20")});
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: #0B8457;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(500, 300, 141, 181));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft JhengHei UI")});
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: #000033;\n"
"background: #CCFFCC"));
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 300, 211, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        newBtn = new QPushButton(layoutWidget);
        newBtn->setObjectName("newBtn");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Small Fonts")});
        font3.setBold(true);
        newBtn->setFont(font3);
        newBtn->setStyleSheet(QString::fromUtf8("background: #39FF14;\n"
"color: #1F51FF"));

        verticalLayout->addWidget(newBtn);

        deleteBtn = new QPushButton(layoutWidget);
        deleteBtn->setObjectName("deleteBtn");
        deleteBtn->setFont(font3);
        deleteBtn->setStyleSheet(QString::fromUtf8("background: #FF3131;\n"
"color: #fff"));

        verticalLayout->addWidget(deleteBtn);

        displayBtn = new QPushButton(layoutWidget);
        displayBtn->setObjectName("displayBtn");
        displayBtn->setFont(font3);
        displayBtn->setStyleSheet(QString::fromUtf8("background: #350B99;\n"
"color: #fff"));

        verticalLayout->addWidget(displayBtn);

        totalBtn = new QPushButton(layoutWidget);
        totalBtn->setObjectName("totalBtn");
        totalBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 7, 110);\n"
"color: #fff;"));

        verticalLayout->addWidget(totalBtn);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 806, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "Expense Manager", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Usage:\n"
"\n"
"1. Create Entry  : Add a new Entry\n"
" 2. Delete Entry  : Delete a previous Entry\n"
" 3. Modify  : Edit existing entry\n"
" 4.Display  : View all the your Entries\n"
" 5.Total : View your total expenses", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Categories: </span></p><ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\"><li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Shopping </li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Vehicle </li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Lifestyle </li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Clothing </li><li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Investments </li><li style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Miscellaneous </li></ul></body>"
                        "</html>", nullptr));
        newBtn->setText(QCoreApplication::translate("MainWindow", "Create Entry", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "Delete Entry", nullptr));
        displayBtn->setText(QCoreApplication::translate("MainWindow", "Display", nullptr));
        totalBtn->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
