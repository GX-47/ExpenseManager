// displaywindow.cpp
#include "displaywindow.h"
#include <QDebug>
#include <QFile>
#include "ui_displaywindow.h"

displaywindow::displaywindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::displaywindow)
{
    ui->setupUi(this);

    // Replace "Expenses.csv" with the actual path to your CSV file
    QString csvFilePath = "Expenses.csv";

    // Call the displayCSVFile function to show the contents of the CSV file
    displayCSVFile(csvFilePath);
}

void displaywindow::displayCSVFile(const QString &filePath)
{
    // Open the CSV file
    QFile file(filePath);
    if (!file.exists()) {
        qDebug() << "File does not exist:" << filePath;
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle error opening the file
        qDebug() << "Error opening file:" << file.errorString();
        return;
    }

    // Read and display the contents of the CSV file
    QTextStream in(&file);
    QString fileContent = in.readAll();

    // Split the content into lines
    QStringList lines = fileContent.split("\n");

    // Insert an empty line after each data line
    for (int i = 0; i < lines.size(); i += 2) {
        lines.insert(i + 1, ""); // Insert an empty string
    }

    // Set the model for the QListView
    QStringListModel *model = new QStringListModel(lines);
    ui->dataDisplay->setModel(model);

    file.close();
}

displaywindow::~displaywindow()
{
    delete ui;
}
