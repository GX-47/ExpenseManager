#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <deletewindow.h>
#include <displaywindow.h>
#include <newwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newBtn_clicked();
    void on_deleteBtn_clicked();
    void on_displayBtn_clicked();

    void on_totalBtn_clicked();

private:
    Ui::MainWindow *ui;
    newWindow *newwindow;
};
#endif // MAINWINDOW_H
