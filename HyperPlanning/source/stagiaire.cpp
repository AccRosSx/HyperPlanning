#include "stagiaire.h"
#include "ui_stagiaire.h"

stagiaire::stagiaire(QWidget *parent,QSqlDatabase *hp, int id) :
    QDialog(parent),
    ui(new Ui::stagiaire)
{
    ui->setupUi(this);

    db=hp;
    idMatricule=id;
}

stagiaire::~stagiaire()
{
    delete ui;
}


void stagiaire::loadTable(QString dateCondition)
{
    if(db->open()){
        ui->listWidget->clear();
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *query = new QSqlQuery(*db);

        query->prepare("Select t2.idSalle,t2.hDebut,t2.hFin,t4.nom , t4.prenom,t5.nom as nomMatiere,t2.dateJour from stagiaires t1 left outer join reservations t2 on (idGroupe1=idReservation OR idGroupe2=idReservation OR idGroupe3=idReservation OR idGroupe4=idReservation OR idGroupe5=idReservation) left outer join groupes t3 on t3.idGroupe=t2.idGroupe left outer join formateurs t4 on t4.idFormateur=t3.idFormateur LEFT outer join matieres t5 on t5.idMatiere = t4.idMatiere where idMatricule="+QString::number(idMatricule)+" AND "+dateCondition+" order by t2.dateJour,t2.hDebut");
        query->exec();

        model->setQuery(*query);

        while(query->next())
        {
            ui->listWidget->addItem(query->value(6).toString()+", "+query->value(1).toString()+"-"+query->value(2).toString()+", Salle n°"+query->value(0).toString()+", "+query->value(3).toString()+" "+query->value(4).toString()+", "+query->value(5).toString());
        }

        delete model;
        delete query;

        //ui->tableView->setModel(model);
    }
    else
    {
        ui->errorLabel->setText(db->lastError().text());
    }
}


void stagiaire::on_loadTableWeek_clicked()
{
    QString dateC;


    dateC="t2.dateJour>='"+ui->calendarWidget->selectedDate().toString("yyyy-MM-dd")+"' AND t2.dateJour<='"+ui->calendarWidget->selectedDate().addDays(7).toString("yyyy-MM-dd")+"'";
    loadTable(dateC);
}

void stagiaire::on_loadTableMonth_clicked()
{
    QString dateC;

    dateC="t2.dateJour>='"+ui->calendarWidget->selectedDate().toString("yyyy-MM-dd")+"' AND t2.dateJour<='"+ui->calendarWidget->selectedDate().addMonths(1).toString("yyyy-MM-dd")+"'";
    loadTable(dateC);
}

void stagiaire::on_loadTableDay_clicked()
{
    QString dateC;

    dateC="t2.dateJour='"+ui->calendarWidget->selectedDate().toString("yyyy-MM-dd")+"'";
    loadTable(dateC);
}
