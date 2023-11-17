#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QStringListModel>

namespace Ui {
class deleteWindow;
}

class deleteWindow : public QDialog
{
    Q_OBJECT

public:
    explicit deleteWindow(QWidget *parent = nullptr);
    ~deleteWindow();

private slots:
    void loadDataFromCSV(const QString &filename);

    void on_delete_BTN_clicked();

    void on_pushButton_clicked();

private:
    Ui::deleteWindow *ui;
    QListWidget *listwidget;
    QStringListModel *model;
};

#endif // DELETEWINDOW_H
