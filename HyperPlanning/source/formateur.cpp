#include "formateur.h"
#include "ui_formateur.h"

formateur::formateur(QWidget *parent,QSqlDatabase *hp, int id) :
    QDialog(parent),
    ui(new Ui::formateur)
{
    ui->setupUi(this);
    db=hp;
    idFormateur=id;
}

formateur::~formateur()
{
    delete ui;
}

void formateur::on_loadTable_clicked()
{

}

void formateur::loadTable(QString dateCondition)
{
    if(db->open()){
        ui->listWidget->clear();
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *query = new QSqlQuery(*db);

        query->prepare("select * from formateurs t1 left OUTER join groupes t2 on t1.idFormateur=t2.idFormateur left outer join reservations t3 on t2.idGroupe=t3.idGroupe left outer join matieres t4 on t4.idMatiere=t1.idMatiere where t1.idFormateur = " + QString::number(idFormateur) + " and " + dateCondition + "order by dateJour,hDebut");
        if(query->exec())
        {
            model->setQuery(*query);

            while(query->next())
            {
                ui->listWidget->addItem(query->value(11).toString()+", "+query->value(9).toString()+"-"+query->value(10).toString()+", Salle n°"+query->value(7).toString()+", "+query->value(1).toString()+" "+query->value(2).toString()+", "+query->value(13).toString());
            }

            delete model;
            delete query;
        }

        else
        {
            ui->errorLabel->setText(db->lastError().text());
        }
    }
    else
    {
        ui->errorLabel->setText(db->lastError().text());
    }
}

void formateur::on_loadTableDay_clicked()
{
    QString dateC;

    dateC="t3.dateJour='"+ui->calendarWidget->selectedDate().toString("yyyy-MM-dd")+"'";
    loadTable(dateC);
}

void formateur::on_loadTableWeek_clicked()
{
    QString dateC;


    dateC="t3.dateJour>='"+ui->calendarWidget->selectedDate().toString("yyyy-MM-dd")+"' AND t3.dateJour<='"+ui->calendarWidget->selectedDate().addDays(7).toString("yyyy-MM-dd")+"'";
    loadTable(dateC);
}

void formateur::on_loadTableMonth_clicked()
{
    QString dateC;

    dateC="t3.dateJour>='"+ui->calendarWidget->selectedDate().toString("yyyy-MM-dd")+"' AND t3.dateJour<='"+ui->calendarWidget->selectedDate().addMonths(1).toString("yyyy-MM-dd")+"'";
    loadTable(dateC);
}
