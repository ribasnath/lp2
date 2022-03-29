#include "emp.h"
#include "ui_emp.h"
#include "T3/library.hpp"

Emp::Emp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Emp)
{
    ui->setupUi(this);
    this->setWindowTitle("Empréstimo");

    QPixmap pix(":/src/Emp.png");
    int w = ui->empback->width();
    int h = ui->empback->height();
    ui->empback->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->erro->setVisible(false);
    ui->erro->setText("<font color='red'>Não é permitido registrar mais de dois empréstimos por vez.</font>");
}

Emp::~Emp()
{
    delete ui;
}

void Emp::on_enviar_clicked()
{
    string path = "../T4/Emp/";
    string fname;
    string name, addr, email, curso;
    int mat;

    name = ui->name->text().toStdString();
    addr = ui->addr->text().toStdString();
    email = ui->email->text().toStdString();
    curso = ui->curso->text().toStdString();
    mat = ui->numat->text().toInt();

    User* u = new User(name, addr, email);
    EmUser* emp = new EmUser(u, mat, curso);

    if(CheckMat(mat) == 0) {
        ui->erro->setVisible(true);
        ui->enviar->setEnabled(false);
    }
    else if(CheckMat(mat) == 1)
        fname = path + "e"+std::to_string(mat)+"_2.txt";
    else
        fname = path + "e"+std::to_string(mat)+".txt";

    string ttl, auth;
    int year;

    ttl = ui->ttl->text().toStdString();
    auth = ui->auth->text().toStdString();
    year = ui->year->text().toInt();

    Book* book = new Book(ttl, auth, year);
    Ficha* f = new Ficha(u, book);

    SaveEmp(fname, f, emp);
}

