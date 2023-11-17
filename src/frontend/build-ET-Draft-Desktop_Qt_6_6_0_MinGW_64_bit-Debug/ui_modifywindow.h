/********************************************************************************
** Form generated from reading UI file 'modifywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYWINDOW_H
#define UI_MODIFYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_modifywindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *modifyList;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *modifywindow)
    {
        if (modifywindow->objectName().isEmpty())
            modifywindow->setObjectName("modifywindow");
        modifywindow->resize(399, 508);
        modifywindow->setStyleSheet(QString::fromUtf8("background-color: #E2DED3;\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(modifywindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(modifywindow);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Palatino Linotype")});
        font.setPointSize(22);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: yellow;\n"
"background: rgb(137, 207, 240)"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        modifyList = new QListView(modifywindow);
        modifyList->setObjectName("modifyList");

        verticalLayout->addWidget(modifyList);

        pushButton = new QPushButton(modifywindow);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("color: yellow;\n"
"background-color: green;\n"
"font-weight: bold;"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(modifywindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("color: #5D12E8;\n"
"font-weight: bold"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(modifywindow);

        QMetaObject::connectSlotsByName(modifywindow);
    } // setupUi

    void retranslateUi(QDialog *modifywindow)
    {
        modifywindow->setWindowTitle(QCoreApplication::translate("modifywindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("modifywindow", "Modify", nullptr));
        pushButton->setText(QCoreApplication::translate("modifywindow", "Modify", nullptr));
        pushButton_2->setText(QCoreApplication::translate("modifywindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modifywindow: public Ui_modifywindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYWINDOW_H
