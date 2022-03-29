#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Biblioteca");

    img = new about();
    emp = new Emp();
    doa = new Doa();
    dev = new Dev();

    QPixmap pix(":/src/inicial.png");
    int w = ui->background->width();
    int h = ui->background->height();
    ui->background->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
    img->show();
}



void MainWindow::on_b_emp_clicked()
{
    emp->show();
}


void MainWindow::on_b_doa_clicked()
{
    doa->show();
}


void MainWindow::on_b_dev_clicked()
{
    dev->show();
}


void MainWindow::on_actionSair_triggered()
{
    close();
}

