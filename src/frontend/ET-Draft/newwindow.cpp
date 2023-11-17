#include "newwindow.h"
#include "ui_newwindow.h"

newWindow::newWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newWindow)
{
    ui->setupUi(this);
}

newWindow::~newWindow()
{
    delete ui;
}

void newWindow::saveDataToCSV(const QString &filename)
{
    QFile file(filename);

    // Check if the file exists
    bool fileExists = file.exists();

    // Open the file for writing (append mode)
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        // If the file is newly created, write the header
        if (!fileExists) {
            stream << "Amount (in ₹)"
                   << ","
                   << "Date"
                   << ","
                   << "Description"
                   << ","
                   << "Category"
                   << ","
                   << "Payment Method"
                   << "\n";
        }

        // Retrieve data from UI elements
        QString amount = ui->amountInput->text();
        QString date = ui->dateEdit->text();
        QString description = ui->plainTextEdit->toPlainText();
        QString category = ui->comboBox->currentText();
        // Assuming you have a payment method input field, replace 'paymentMethodInput' with the actual input field name
        QString paymentMethod = ui->paymentMethodInput->currentText();

        // Write new data to the file in CSV format
        stream << amount << "," << date << "," << description << "," << category << ","
               << paymentMethod << "\n";

        file.close();
    } else {
        QMessageBox::critical(this, "Error", "Could not open the file for writing.");
    }
}

void newWindow::on_pushButton_clicked()
{
    close();
}

void newWindow::on_submitBtn_clicked()
{
    saveDataToCSV("Expenses.csv");

    ui->amountInput->clear();
    ui->dateEdit->clear();
    ui->plainTextEdit->clear();
    ui->comboBox->clear();

    QMessageBox::information(this, "Data Entry", "Data submitted Successfully");

    close();
}
