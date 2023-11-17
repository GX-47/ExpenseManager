/********************************************************************************
** Form generated from reading UI file 'deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEWINDOW_H
#define UI_DELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteWindow
{
public:
    QLabel *label;
    QFrame *line;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QListView *data_delete;
    QPushButton *delete_BTN;
    QPushButton *pushButton;

    void setupUi(QDialog *deleteWindow)
    {
        if (deleteWindow->objectName().isEmpty())
            deleteWindow->setObjectName("deleteWindow");
        deleteWindow->resize(389, 493);
        deleteWindow->setStyleSheet(QString::fromUtf8("background-color: #E2DED3;\n"
""));
        label = new QLabel(deleteWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 371, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("letter-spacing: 10px;\n"
"color: #F23456"));
        label->setAlignment(Qt::AlignCenter);
        line = new QFrame(deleteWindow);
        line->setObjectName("line");
        line->setGeometry(QRect(-10, 60, 401, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(deleteWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 90, 371, 371));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        data_delete = new QListView(layoutWidget);
        data_delete->setObjectName("data_delete");

        verticalLayout->addWidget(data_delete);

        delete_BTN = new QPushButton(layoutWidget);
        delete_BTN->setObjectName("delete_BTN");
        delete_BTN->setStyleSheet(QString::fromUtf8("background: #D72324;\n"
"color: #fff;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(delete_BTN);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("color: #107A8A;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(deleteWindow);

        QMetaObject::connectSlotsByName(deleteWindow);
    } // setupUi

    void retranslateUi(QDialog *deleteWindow)
    {
        deleteWindow->setWindowTitle(QCoreApplication::translate("deleteWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("deleteWindow", "Delete Entry", nullptr));
        delete_BTN->setText(QCoreApplication::translate("deleteWindow", "Delete", nullptr));
        pushButton->setText(QCoreApplication::translate("deleteWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteWindow: public Ui_deleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEWINDOW_H
