#include "doa.h"
#include "ui_doa.h"
#include "T3/library.hpp"

Doa::Doa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Doa)
{
    ui->setupUi(this);
    this->setWindowTitle("Doação");

    QPixmap pix(":/src/Doa.png");
    int w = ui->doaback->width();
    int h = ui->doaback->height();
    ui->doaback->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->sucess->setVisible(false);
    ui->sucess->setText("<font color='green'>Registrado com sucesso!</font>");
}

Doa::~Doa()
{
    delete ui;
}

void Doa::on_enviar_b_clicked()
{
    string path = "../T4/Doa/";
    string fname;
    string name, addr, email;
    string cpf, telefone;

    name = ui->name->text().toStdString();
    addr = ui->addr->text().toStdString();
    email = ui->email->text().toStdString();
    cpf = ui->cpf->text().toStdString();
    telefone = ui->phone->text().toStdString();

    User* u = new User(name, addr, email);
    DoaUser* doa = new DoaUser(u, cpf, telefone);

    string ttl, auth;
    int year;

    ttl = ui->ttl->text().toStdString();
    auth = ui->auth->text().toStdString();
    year = ui->year->text().toInt();

    Book* book = new Book(ttl, auth, year);
    Ficha* f = new Ficha(u, book);

    srand(time(0));
    int i = rand();
    fname = path+"d"+std::to_string(i)+".txt";

    SaveDoa(fname, f, doa);
    ui->enviar_b->setEnabled(false);
    ui->sucess->setVisible(true);
}

