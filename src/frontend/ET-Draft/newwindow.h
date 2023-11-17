#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QWidget>

namespace Ui {
class newWindow;
}

class newWindow : public QDialog
{
    Q_OBJECT

public:
    explicit newWindow(QWidget *parent = nullptr);
    ~newWindow();

private slots:
    void on_pushButton_clicked();
    void on_submitBtn_clicked();
    void saveDataToCSV(const QString &filename);

private:
    Ui::newWindow *ui;
};

#endif // NEWWINDOW_H
