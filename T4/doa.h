#ifndef DOA_H
#define DOA_H

#include <QDialog>

namespace Ui {
class Doa;
}

class Doa : public QDialog
{
    Q_OBJECT

public:
    explicit Doa(QWidget *parent = nullptr);
    ~Doa();

private slots:
    void on_enviar_b_clicked();

private:
    Ui::Doa *ui;
};

#endif // DOA_H
