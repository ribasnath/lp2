#ifndef EMP_H
#define EMP_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <vector>

namespace Ui {
class Emp;
}

class Emp : public QDialog
{
    Q_OBJECT

public:
    explicit Emp(QWidget *parent = nullptr);
    ~Emp();

private slots:
    void on_enviar_clicked();

private:
    Ui::Emp *ui;
};

#endif // EMP_H
