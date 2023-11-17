/********************************************************************************
** Form generated from reading UI file 'newwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWWINDOW_H
#define UI_NEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit;
    QFrame *line;
    QLabel *label;
    QLabel *label_4;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *amountInput;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_6;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QPushButton *submitBtn;
    QPushButton *pushButton;
    QComboBox *paymentMethodInput;

    void setupUi(QDialog *newWindow)
    {
        if (newWindow->objectName().isEmpty())
            newWindow->setObjectName("newWindow");
        newWindow->resize(333, 486);
        newWindow->setStyleSheet(QString::fromUtf8("background-color: #E2DED3;\n"
""));
        layoutWidget = new QWidget(newWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 290, 321, 26));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("color: black;\n"
"font-weight: bold"));

        horizontalLayout_3->addWidget(label_5);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: #472FF7"));

        horizontalLayout_3->addWidget(comboBox);

        plainTextEdit = new QPlainTextEdit(newWindow);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 220, 321, 41));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        line = new QFrame(newWindow);
        line->setObjectName("line");
        line->setGeometry(QRect(-10, 40, 331, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(newWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 9, 311, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Poor Richard")});
        font.setPointSize(15);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #472FF7;\n"
"letter-spacing: 10px"));
        label->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(newWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 200, 71, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: black;\n"
"font-weight: bold"));
        layoutWidget_2 = new QWidget(newWindow);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(10, 125, 181, 51));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("color: black;\n"
"font-weight: bold"));

        horizontalLayout_2->addWidget(label_3);

        amountInput = new QLineEdit(layoutWidget_2);
        amountInput->setObjectName("amountInput");
        amountInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(amountInput);

        layoutWidget_3 = new QWidget(newWindow);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(10, 80, 301, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_3);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: black;\n"
"font-weight: bold"));

        horizontalLayout->addWidget(label_2);

        dateEdit = new QDateEdit(layoutWidget_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setStyleSheet(QString::fromUtf8("color: #472FF7;\n"
"background: white"));

        horizontalLayout->addWidget(dateEdit);

        label_6 = new QLabel(newWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 340, 101, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: black;\n"
"font-weight: bold"));
        layoutWidget1 = new QWidget(newWindow);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(190, 355, 111, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        submitBtn = new QPushButton(layoutWidget1);
        submitBtn->setObjectName("submitBtn");
        submitBtn->setStyleSheet(QString::fromUtf8("color: #FF6D24;\n"
"font-weight: bold;"));

        verticalLayout_2->addWidget(submitBtn);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("color: #5D12E8;\n"
"font-weight: bold"));

        verticalLayout_2->addWidget(pushButton);

        paymentMethodInput = new QComboBox(newWindow);
        paymentMethodInput->addItem(QString());
        paymentMethodInput->addItem(QString());
        paymentMethodInput->addItem(QString());
        paymentMethodInput->addItem(QString());
        paymentMethodInput->setObjectName("paymentMethodInput");
        paymentMethodInput->setGeometry(QRect(10, 370, 171, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Rockwell")});
        paymentMethodInput->setFont(font1);
        paymentMethodInput->setStyleSheet(QString::fromUtf8("color: red;\n"
"background: white;"));

        retranslateUi(newWindow);

        QMetaObject::connectSlotsByName(newWindow);
    } // setupUi

    void retranslateUi(QDialog *newWindow)
    {
        newWindow->setWindowTitle(QCoreApplication::translate("newWindow", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("newWindow", "Category", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("newWindow", "Select Category", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("newWindow", "Shopping", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("newWindow", "Vehicle", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("newWindow", "LifeStyle", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("newWindow", "Clothing", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("newWindow", "Investments", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("newWindow", "Miscellaneous", nullptr));

        label->setText(QCoreApplication::translate("newWindow", "New Entry", nullptr));
        label_4->setText(QCoreApplication::translate("newWindow", "Description", nullptr));
        label_3->setText(QCoreApplication::translate("newWindow", "Amount(in \342\202\271)", nullptr));
        label_2->setText(QCoreApplication::translate("newWindow", "Date", nullptr));
        label_6->setText(QCoreApplication::translate("newWindow", "Payment Method", nullptr));
        submitBtn->setText(QCoreApplication::translate("newWindow", "Submit", nullptr));
        pushButton->setText(QCoreApplication::translate("newWindow", "Cancel", nullptr));
        paymentMethodInput->setItemText(0, QCoreApplication::translate("newWindow", "Choose payment method", nullptr));
        paymentMethodInput->setItemText(1, QCoreApplication::translate("newWindow", "Cash", nullptr));
        paymentMethodInput->setItemText(2, QCoreApplication::translate("newWindow", "Card", nullptr));
        paymentMethodInput->setItemText(3, QCoreApplication::translate("newWindow", "UPI", nullptr));

    } // retranslateUi

};

namespace Ui {
    class newWindow: public Ui_newWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWWINDOW_H
