#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setWindowTitle("About");

    QPixmap pix(":/src/imagem.png");
    int w = ui->imagem->width();
    int h = ui->imagem->height();
    ui->imagem->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

about::~about()
{
    delete ui;
}
