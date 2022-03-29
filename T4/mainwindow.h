#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "T3/library.hpp"
#include "about.h"
#include "emp.h"
#include "doa.h"
#include "dev.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    about* img;
    Emp* emp;
    Doa* doa;
    Dev* dev;

private slots:
    void on_actionAbout_triggered();

    void on_b_emp_clicked();

    void on_b_doa_clicked();

    void on_b_dev_clicked();

    void on_actionSair_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
