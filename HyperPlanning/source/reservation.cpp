#include "reservation.h"
#include "ui_reservation.h"

reservation::reservation(QWidget *parent,QSqlDatabase *hp,int tgt) :
    QDialog(parent),
    ui(new Ui::reservation)
{
    ui->setupUi(this);
    db=hp;
    target = tgt ;
    ui->date->setDate(QDate::currentDate());
    refresh();
}

reservation::~reservation()
{
    delete ui;
}

void reservation::refresh()
{
    ui->idGrp->clear();
    ui->salle->clear();
    ui->idResa->clear();


    QSqlQuery *query = new QSqlQuery(*db);

    if(target == 0)
    {
        query->prepare("select idGroupe from groupes");
    }
    else
    {
        query->prepare("select idGroupe from groupes t1 left outer join formateurs t2 on t2.idFormateur = t1.idFormateur left outer join matieres t3 on t3.idMatiere = t2.idMatiere where t2.idMatiere =  " + QString::number(target));
    }
    if(query->exec())
    {
        while(query->next())
        {
            ui->idGrp->addItem(query->value(0).toString());

        }
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }


    query->prepare("Select t4.type,idGroupe,count(idMatricule) as nb from groupes t1 left outer join stagiaires t2 on (idGroupe1=idGroupe or idGroupe2=idGroupe or idGroupe3=idGroupe or idGroupe4=idGroupe or idGroupe5=idGroupe) left outer join formateurs t3 on t1.idFormateur=t3.idFormateur left outer join matieres t4 on t4.idMatiere=t3.idMatiere where idGroupe=" + ui->idGrp->currentText() + " group by idGroupe,t4.type");

    if(query->exec())
    {
        while(query->next())
        {
            QSqlQuery *query2 = new QSqlQuery(*db);
            query2->prepare("select * from salles where nbPlaces >= " + query->value(2).toString() + " and type = '" + query->value(0).toString() + "'");

            if(query2->exec())
            {
                while(query2->next())
                {
                    ui->salle->addItem(query2->value(0).toString());
                }
            }
            else
            {
                ui->errorLabel->setText("Erreur");
            }
        }
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }

    query->prepare("select * from reservations where idGroupe = "  + ui->idGrp->currentText() + " order by dateJour,hDebut");
    query->exec();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery(*query);

    ui->tableView->setModel(model);


    QSqlQuery *query3 = new QSqlQuery(*db);
    query3->prepare("select * from reservations");
    query3->exec();


    while(query3->next())
    {
        ui->idResa->addItem(query3->value(0).toString());
    }

    query3->prepare("select * from reservations where idReservation = " + ui->idResa->currentText());
    query3->exec();

    if(query3->next())
    {


        ui->hDeb_2->setTime(QTime::fromString(query3->value(3).toString(),"h"));

        ui->date_2->setDate(QDate::fromString(query3->value(5).toString(),"yyyy-MM-dd"));


    }




}

void reservation::on_idGrp_activated(const QString &arg1)
{
    QSqlQuery *query = new QSqlQuery(*db);

    ui->salle->clear();
    query->prepare("Select t4.type,idGroupe,count(idMatricule) as nb from groupes t1 left outer join stagiaires t2 on (idGroupe1=idGroupe or idGroupe2=idGroupe or idGroupe3=idGroupe or idGroupe4=idGroupe or idGroupe5=idGroupe) left outer join formateurs t3 on t1.idFormateur=t3.idFormateur left outer join matieres t4 on t4.idMatiere=t3.idMatiere where idGroupe=" + ui->idGrp->currentText() + " group by idGroupe,t4.type");

    if(query->exec())
    {
        while(query->next())
        {
            QSqlQuery *query2 = new QSqlQuery(*db);
            query2->prepare("select * from salles where nbPlaces >= " + query->value(2).toString() + " and type = '" + query->value(0).toString() + "'");

            if(query2->exec())
            {
                while(query2->next())
                {
                    ui->salle->addItem(query2->value(0).toString());
                }
            }
            else
            {
                ui->errorLabel->setText("Erreur");
            }
        }
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }

    query->prepare("select * from reservations where idGroupe = "  + ui->idGrp->currentText() + " order by dateJour,hDebut");
    query->exec();

    QSqlQueryModel *model = new QSqlQueryModel;

    model->setQuery(*query);

    ui->tableView->setModel(model);

}

bool reservation::checkConflit()
{
    QSqlQuery *query_2 = new QSqlQuery(*db);

    query_2->prepare("select idMatricule,dateJour,hDebut,count(idReservation) from stagiaires t1 left outer join reservations t2 on(idGroupe1=idGroupe or idGroupe2=idGroupe or idGroupe3=idGroupe or idGroupe4=idGroupe or idGroupe5=idGroupe) group by idMatricule,dateJour,hDebut");

    if(query_2->exec())
    {
        while(query_2->next())
        {
            if(query_2->value(3).toInt()>1)
                return true;
        }
    }

    return false;


}
void reservation::on_createResa_clicked()
{
    QSqlQuery *query = new QSqlQuery(*db);

    query->prepare("select count(idReservation) from reservations where idGroupe = " + ui->idGrp->currentText() + " and hDebut = " + QString::number(ui->hDeb->time().hour())+ " and dateJour = '" + ui->date->date().toString("yyyy-MM-dd") +"'");

    if(query->exec())
    {
        int nb=-1;
        while(query->next())
        {
            nb= query->value(0).toInt();
        }

        if(nb==0)
        {
            if(QDate::currentDate()<=ui->date->date())
            {
                if(!checkConflit())
                {
                    if(ui->hDeb->time().hour()>= 8 && ui->hDeb->time().hour()<=20)
                    {
                        query->prepare("select count(idReservation) from reservations where idGroupe=" + ui->idGrp->currentText());

                        if(query->exec())
                        {
                            int volume=0;
                            while(query->next())
                            {
                                volume=query->value(0).toInt();
                            }
                            query->prepare("select t1.idMatiere,volumeHoraire,idGroupe from matieres t1 left outer join formateurs t2 on t1.idMatiere=t2.idMatiere left OUTER join groupes t3 on t3.idFormateur=t2.idFormateur where idGroupe=" + ui->idGrp->currentText());

                            if(query->exec())
                            {
                                int volume2=0;

                                while(query->next())
                                {
                                    volume2=query->value(1).toInt();
                                }

                                if(volume*2 + 2 <= volume2)
                                {
                                    query->prepare("insert into reservations (idSalle,idGroupe,hDebut,hFin,dateJour) values("+ui->salle->currentText()+","+ui->idGrp->currentText()+","+QString::number(ui->hDeb->time().hour())+","+QString::number(ui->hDeb->time().hour()+2) + ",'" + ui->date->date().toString("yyyy-MM-dd") + "')");
                                    if(query->exec())
                                    {
                                        refresh();
                                        if(!checkConflit())
                                        {
                                            ui->errorLabel->setText("Réservation enregistrée");

                                        }
                                        else
                                        {
                                            ui->errorLabel->setText("Conflit détecté");

                                            query->prepare("delete from reservations where idReservation = " + ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->model()->rowCount()-1,0)).toString());
                                            query->exec();
                                            refresh();

                                        }


                                    }
                                    else
                                    {
                                        ui->errorLabel->setText("Erreur");
                                    }
                                }
                                else
                                {
                                    ui->errorLabel->setText("Volume horaire dépassé");
                                }


                            }
                            else
                            {
                                ui->errorLabel->setText("Erreur");
                            }


                        }
                        else
                        {
                            ui->errorLabel->setText("Heure de cours 8h - 22h");
                        }
                    }
                    else
                    {
                        ui->errorLabel->setText("Conflit détecté");
                    }

                }
                else
                {
                    ui->errorLabel->setText("Date incorrecte");
                }

            }
            else
            {
                ui->errorLabel->setText("Une réservation est déjà enregistrée pour cette période");
            }
        }
        else
        {
            ui->errorLabel->setText("Erreur");
        }

    }
}

void reservation::on_idResa_activated(const QString &arg1)
{
    QSqlQuery *query3 = new QSqlQuery(*db);

    query3->prepare("select * from reservations where idReservation = " + ui->idResa->currentText());
    query3->exec();

    if(query3->next())
    {


        ui->hDeb_2->setTime(QTime::fromString(query3->value(3).toString(),"h"));

        ui->date_2->setDate(QDate::fromString(query3->value(5).toString(),"yyyy-MM-dd"));

    }


}

void reservation::on_modifyResa_clicked()
{
    QSqlQuery *query3 = new QSqlQuery(*db);
    QString exhDeb,exDate;

    query3->prepare("select * from reservations where idReservation =" + ui->idResa->currentText() );

    if(query3->exec())
    {
        while(query3->next())
        {
            exhDeb = query3->value(3).toString();
            exDate=query3->value(3).toString();
        }
    }
    else
    {
        ui->errorLabel->setText("Erreur1");
    }

    query3->prepare("update reservations set hDebut = " + QString::number(ui->hDeb_2->time().hour()) + ", dateJour = '" + ui->date_2->date().toString("yyyy-MM-dd") + "' , hFin = hDebut +2 where idReservation = " + ui->idResa->currentText());
    if(query3->exec())
    {
        if(checkConflit())
        {
            ui->errorLabel->setText("Conflit détecté");
            query3->prepare("update reservations set hDebut = " + exhDeb + ", dateJour = '" + exDate + "', hFin = hDebut +2 where idReservation = " + ui->idResa->currentText());
            query3->exec();
        }
        else
        {
            ui->errorLabel->setText("Réservation modifiée");
        }
    }
    else
    {
        ui->errorLabel->setText("Erreur2");
    }



    refresh();
}

void reservation::on_dropResa_clicked()
{
    QSqlQuery *query3 = new QSqlQuery(*db);
    QString exhDeb,exDate;

    query3->prepare("delete from reservations where idReservation =" + ui->idResa->currentText() );

    if(query3->exec())
    {
        ui->errorLabel->setText("Réservation supprimée");
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }

    refresh();
}
