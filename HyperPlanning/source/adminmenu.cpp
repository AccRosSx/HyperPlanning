#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "formateur.h"
#include "admin.h"
#include "reservation.h"
#include "consultation.h"

adminMenu::adminMenu(QWidget *parent,QSqlDatabase *hp) :
    QDialog(parent),
    ui(new Ui::adminMenu)
{
    ui->setupUi(this);
    db=hp;
}

adminMenu::~adminMenu()
{
    delete ui;
}

void adminMenu::on_gerer_clicked()
{
    admin ad(nullptr,db);
    ad.setWindowTitle("HyperPlanning - Admin");
    this->hide();
    ad.setModal(true);
    ad.exec();
    this->show();
}

void adminMenu::on_planifier_clicked()
{
    reservation resa(nullptr,db,0);
    this->hide();
    resa.setWindowTitle("HyperPlanning - Admin");
    resa.setModal(true);
    resa.exec();
    this->show();
}

void adminMenu::on_consulter_clicked()
{
    consultation cons(nullptr,db);
    this->hide();
    cons.setWindowTitle("HyperPlanning - Admin");
    cons.setModal(true);
    cons.exec();
    this->show();
}
