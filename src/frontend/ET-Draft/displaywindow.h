// displaywindow.h
#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class displaywindow;
}

class displaywindow : public QDialog
{
    Q_OBJECT

public:
    explicit displaywindow(QWidget *parent = nullptr);
    ~displaywindow();

    // Function to display CSV file in QListView
    void displayCSVFile(const QString &filePath);

private:
    Ui::displaywindow *ui;
};

#endif // DISPLAYWINDOW_H
