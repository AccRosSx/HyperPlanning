#include "formateurr.h"
#include "formateur.h"
#include "ui_formateurr.h"
#include "reservation.h"

formateurR::formateurR(QWidget *parent,QSqlDatabase *hp, int id) :
    QDialog(parent),
    ui(new Ui::formateurR)
{
    ui->setupUi(this);
    idFormateur=id;
    QSqlQuery q(*hp);
       q.prepare("select * from formateurs where idFormateur = " + QString::number(idFormateur));
       if(q.exec())
       {
           while(q.next())
           {
               idMatiere=q.value(3).toInt();
           }
       }
    db=hp;
}

formateurR::~formateurR()
{
    delete ui;
}

void formateurR::on_gerer_clicked()
{
    reservation resa(nullptr,db,idMatiere);
    this->hide();
    resa.setWindowTitle("HyperPlanning - Formateur");
    resa.setModal(true);
    resa.exec();
    this->show();
}

void formateurR::on_consulter_clicked()
{
    formateur ft(nullptr,db,idFormateur);
    ft.setModal(true);
    ft.setWindowTitle("HyperPlanning - Formateur");
    this->hide();
    ft.exec();
    this->show();

}
