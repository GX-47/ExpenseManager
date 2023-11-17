#include "mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newBtn_clicked()
{
    newwindow = new newWindow(this);
    newwindow->show();
}

void MainWindow::on_deleteBtn_clicked()
{
    deleteWindow *deletewindow = new deleteWindow(this);
    deletewindow->exec();
}

void MainWindow::on_displayBtn_clicked()
{
    displaywindow *displayWindow = new displaywindow(this);
    displayWindow->exec();
}

void MainWindow::on_totalBtn_clicked()
{
    QFile file("Expenses.csv");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Could not open the file");
        return;
    }

    QTextStream in(&file);
    double sum = 0.0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(","); // Adjust the delimiter based on your CSV format

        if (!fields.isEmpty()) {
            bool ok;
            double value = fields[0].toDouble(&ok);

            if (ok) {
                sum += value;
            }
        }
    }

    file.close();

    // Display the sum in a dialog box
    QMessageBox::information(this, "Total", "Your total expenditure: " + QString::number(sum));
}
