#ifndef DEV_H
#define DEV_H

#include <QDialog>
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QVector>
#include <dirent.h>
#include <string>
#include <fstream>

namespace Ui {
class Dev;
}

class Dev : public QDialog
{
    Q_OBJECT

public:
    explicit Dev(QWidget *parent = nullptr);
    ~Dev();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dev *ui;
};

#endif // DEV_H
