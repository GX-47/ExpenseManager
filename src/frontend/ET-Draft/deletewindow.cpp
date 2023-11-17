#include "deletewindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "ui_deletewindow.h"

deleteWindow::deleteWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::deleteWindow)
{
    ui->setupUi(this);

    // Create a QStringListModel
    model = new QStringListModel(this);

    // Set the model to the QListView
    ui->data_delete->setModel(model);

    // Call a function to load data from the CSV file
    loadDataFromCSV("Expenses.csv");
}

deleteWindow::~deleteWindow()
{
    delete ui;
}

void deleteWindow::loadDataFromCSV(const QString &filename)
{
    // Open the CSV file
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open the file for reading";
        return;
    }

    // Read the CSV file line by line
    QStringList dataList;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        // Skip the first line (header)
        if (!line.isEmpty() && !line.isNull()) {
            dataList << line;
            // Add a separator line after each data item
            dataList << "-----------------------------";
        }
    }

    // Set the QStringList as the model data
    model->setStringList(dataList);

    // Close the file
    file.close();
}

void deleteWindow::on_delete_BTN_clicked()
{
    QModelIndex selectedIndex = ui->data_delete->currentIndex();

    // Check if an item is selected
    if (selectedIndex.isValid()) {
        // Get the selected item's text
        QString selectedText = selectedIndex.data().toString();

        // Remove the separator line if present
        QString separator = "-----------------------------";
        if (selectedText == separator) {
            // Move to the previous item to get the actual data
            selectedIndex = model->index(selectedIndex.row() - 1, selectedIndex.column());
            selectedText = selectedIndex.data().toString();
        }

        // Remove the selected item from the model
        model->removeRow(selectedIndex.row());

        // Open the CSV file for writing
        QFile file("Expenses.csv");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);

            // Write the updated data to the CSV file
            QStringList data = model->stringList();
            for (const QString &line : data) {
                if (line != separator) {
                    stream << line << "\n";
                }
            }

            // Close the file
            file.close();
            QMessageBox::information(this, "", "Data deleted");
        } else {
            qDebug() << "Could not open the file for writing";
        }
    }
}

void deleteWindow::on_pushButton_clicked()
{
    close();
}
