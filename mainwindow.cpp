#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <string>
#include <QDir>
#include <QMessageBox>
#include <QStringList>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_PushButton_Next_clicked()
{
    if(pList != list.end()-1)
    {pList++;
    showimage(*pList);}
else{
        QMessageBox::information(this, tr("Warning"),
                                 tr("Done"));
    }

}


void MainWindow::on_pushButton_show_clicked()
{

}
void MainWindow::showimage(QString var){
    QPixmap pix(var);
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_pushButton_previous_clicked()
{

    if(pList != list.begin())
    {pList--;
    showimage(*pList);}
else{
        QMessageBox::information(this, tr("Warning"),
                                 tr("please click next"));

    }

}

void MainWindow::on_pushButton_start_clicked()
{
    QDir dir_2(ui->lineEdit->text());//"F:/solve/picture");

    QStringList filter;
       filter << QLatin1String("*.png");
       filter << QLatin1String("*.jpeg");
       filter << QLatin1String("*.jpg");
       dir_2.setNameFilters(filter);

    foreach (QFileInfo var, dir_2.entryInfoList()) {
        if(var.isFile()){
        list.append(var.absoluteFilePath());
                         }
       }
    pList = list.begin();
 showimage(list.front());

}
