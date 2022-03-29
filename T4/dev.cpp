#include "dev.h"
#include "ui_dev.h"

Dev::Dev(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dev)
{
    ui->setupUi(this);

    QPixmap pix(":/src/dev.png");
    int w = ui->devback->width();
    int h = ui->devback->height();
    ui->devback->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->message->setVisible(false);
    ui->message->setText("<font color='green'>Devolvido com sucesso!</font>");

    DIR *dir;
    struct dirent *names;

    QVector<QStringList> fnames;
    dir = opendir("../T4/Emp/");
    if (dir != NULL) {
       while (names = readdir(dir)) {
          fnames.append(QStringList(names->d_name));
       }
    }

    ui->listfile->clear();

    fnames.erase(fnames.begin());
    fnames.erase(fnames.begin());

    for(int i=0; i < fnames.size(); i++)
    {
       ui->listfile->addItems(fnames.at(i));
    }
}

Dev::~Dev()
{
    delete ui;
}

void Dev::on_pushButton_clicked()
{
    delete ui->listfile->currentItem();
    ui->message->setVisible(true);
}

