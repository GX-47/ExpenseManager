/********************************************************************************
** Form generated from reading UI file 'displaywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWINDOW_H
#define UI_DISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_displaywindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListView *dataDisplay;

    void setupUi(QDialog *displaywindow)
    {
        if (displaywindow->objectName().isEmpty())
            displaywindow->setObjectName("displaywindow");
        displaywindow->resize(883, 470);
        displaywindow->setStyleSheet(QString::fromUtf8("background-color: #E2DED3;\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(displaywindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(displaywindow);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Octopus Game")});
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #A80139;\n"
"background: #3EC4D0;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        dataDisplay = new QListView(displaywindow);
        dataDisplay->setObjectName("dataDisplay");

        verticalLayout->addWidget(dataDisplay);


        retranslateUi(displaywindow);

        QMetaObject::connectSlotsByName(displaywindow);
    } // setupUi

    void retranslateUi(QDialog *displaywindow)
    {
        displaywindow->setWindowTitle(QCoreApplication::translate("displaywindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("displaywindow", "Previous Data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displaywindow: public Ui_displaywindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
