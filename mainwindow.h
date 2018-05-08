#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void showimage(QString var);
    void on_PushButton_Next_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_previous_clicked();

    void on_pushButton_start_clicked();

private:
    QList<QString> list;
    QList<QString>::iterator pList;
int i ;
Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
