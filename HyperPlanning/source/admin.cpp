#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent,QSqlDatabase *hp) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    ui->rattrapage->setDate(QDate::currentDate());
    db=hp;
    refreshSubjects();
}

admin::~admin()
{
    delete ui;
}

void admin::refreshSubjects()
{
    ui->idMatiere->clear();
    ui->idMatiere_3->clear();
    ui->idMatiere_4->clear();
    ui->idForm->clear();
    ui->idForm2->clear();
    ui->idForm_2->clear();
    ui->idGrp->clear();
    ui->idGrp1->clear();
    ui->idGrp2->clear();
    ui->idGrp3->clear();
    ui->idGrp4->clear();
    ui->idGrp5->clear();
    ui->idGrp1->addItem("0");
    ui->idGrp2->addItem("0");
    ui->idGrp3->addItem("0");
    ui->idGrp4->addItem("0");
    ui->idGrp5->addItem("0");

    ui->idGrp1_2->clear();
    ui->idGrp2_2->clear();
    ui->idGrp3_2->clear();
    ui->idGrp4_2->clear();
    ui->idGrp5_2->clear();
    ui->idGrp1_2->addItem("0");
    ui->idGrp2_2->addItem("0");
    ui->idGrp3_2->addItem("0");
    ui->idGrp4_2->addItem("0");
    ui->idGrp5_2->addItem("0");
    ui->idMatricule->clear();


    if(db->open())
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *query = new QSqlQuery(*db);

        QSqlQueryModel *model_2 = new QSqlQueryModel();
        QSqlQuery *query_2 = new QSqlQuery(*db);

        QSqlQueryModel *model_3 = new QSqlQueryModel();
        QSqlQuery *query_3 = new QSqlQuery(*db);

        QSqlQuery *query_4 = new QSqlQuery(*db);

        QSqlQuery *query_5 = new QSqlQuery(*db);

        QSqlQuery *query_6 = new QSqlQuery(*db);

        QSqlQueryModel *model_7 = new QSqlQueryModel();
        QSqlQuery *query_7 = new QSqlQuery(*db);

        QSqlQuery *query_8 = new QSqlQuery(*db);

       // QSqlQuery *query_9 = new QSqlQuery(*db);

        query->prepare("select * from matieres");
        query->exec();

        model->setQuery(*query);

        ui->tableView->setModel(model);
        ui->tableView->scrollToBottom();
        while(query->next())
        {
            ui->idMatiere->addItem(query->value(0).toString());
            ui->idMatiere_3->addItem(query->value(0).toString());
            ui->idMatiere_4->addItem(query->value(0).toString());

        }

        query_2->prepare("select * from formateurs");
        query_2->exec();

        model_2->setQuery(*query_2);

        ui->tableView_2->setModel(model_2);
ui->tableView_2->scrollToBottom();
        while(query_2->next())
        {
            ui->idForm->addItem(query_2->value(0).toString());
            ui->idForm2->addItem(query_2->value(0).toString());
            ui->idForm_2->addItem(query_2->value(0).toString());
        }

        query_3->prepare("select * from groupes");
        query_3->exec();

        model_3->setQuery(*query_3);

        ui->tableView_3->setModel(model_3);
        ui->tableView_3->scrollToBottom();
        while(query_3->next())
        {
            ui->idGrp->addItem(query_3->value(0).toString());
            ui->idGrp1->addItem(query_3->value(0).toString());
            ui->idGrp2->addItem(query_3->value(0).toString());
            ui->idGrp3->addItem(query_3->value(0).toString());
            ui->idGrp4->addItem(query_3->value(0).toString());
            ui->idGrp5->addItem(query_3->value(0).toString());
            ui->idGrp1_2->addItem(query_3->value(0).toString());
            ui->idGrp2_2->addItem(query_3->value(0).toString());
            ui->idGrp3_2->addItem(query_3->value(0).toString());
            ui->idGrp4_2->addItem(query_3->value(0).toString());
            ui->idGrp5_2->addItem(query_3->value(0).toString());
        }



        query_4->prepare("select * from formateurs t1 left outer join (select * from log where acces=2 OR acces=3) t2 on t1.idFormateur = id where idFormateur = " + ui->idForm2->currentText());
        query_4->exec();
        while(query_4->next())
        {

            ui->nomForm_3->setText(query_4->value(1).toString());
            ui->prenomForm_3->setText(query_4->value(2).toString());
            ui->pw_3->setText(query_4->value(5).toString());
            ui->username_3->setText(query_4->value(4).toString());

        }




        query_5->prepare("select * from matieres where idMatiere = " + ui->idMatiere_4->currentText());
        query_5->exec();
        while(query_5->next())
        {
            ui->nomMatiere_2->setText(query_5->value(1).toString());
            ui->volume_2->setValue(query_5->value(2).toInt());
            ui->type_2->setCurrentText(query_5->value(3).toString());
            ui->duree_2->setCurrentText(query_5->value(4).toString());
            ui->rattrapage_2->setDate(QDate::fromString(query_5->value(5).toString(),"yyyy-MM-dd"));
        }

        query_6->prepare("select * from groupes where idGroupe = " + ui->idGrp->currentText());
        query_6->exec();
        while(query_6->next())
        {
            ui->idForm_2->setCurrentIndex(ui->idForm_2->findText(query_6->value(1).toString()));
        }


        query_7->prepare("select * from stagiaires");
        query_7->exec();

        model_7->setQuery(*query_7);

        ui->tableView_4->setModel(model_7);
        ui->tableView_4->scrollToBottom();

        while(query_7->next())
        {
            ui->idMatricule->addItem(query_7->value(0).toString());
        }

        int row = 0;

        while(ui->idMatricule->currentText().toInt() != ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,0)).toInt() && row < ui->tableView_4->model()->rowCount())
        {
            row++;
        }
        ui->nomStg_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,1)).toString());
        ui->prenomStg_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,2)).toString());
        ui->sexeStg_2->setCurrentIndex(ui->sexeStg_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,6)).toString()));
        ui->dateNaissance_2->setDate(QDate::fromString(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,3)).toString(),"yyyy-MM-dd"));
        ui->rue_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,8)).toString());
        ui->cp_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,9)).toString());
        ui->numeroRue_2->setValue(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,7)).toInt());
        ui->ville_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,10)).toString());
        ui->portable_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,12)).toString());
        ui->fixe_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,11)).toString());
        ui->idGrp1_2->setCurrentIndex(ui->idGrp1_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,13)).toString()));
        ui->idGrp2_2->setCurrentIndex(ui->idGrp2_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,14)).toString()));
        ui->idGrp3_2->setCurrentIndex(ui->idGrp3_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,15)).toString()));
        ui->idGrp4_2->setCurrentIndex(ui->idGrp4_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,16)).toString()));
        ui->idGrp5_2->setCurrentIndex(ui->idGrp5_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,17)).toString()));

        query_8->prepare("select * from log where acces = 1 and id = " + ui->idMatricule->currentText());
        query_8->exec();

        ui->usrStg_2->setText("");
        ui->pwStg_2->setText("");

        while(query_8->next())
        {
            ui->usrStg_2->setText(query_8->value(0).toString());
            ui->pwStg_2->setText(query_8->value(1).toString());
        }
        //delete model;
        //delete query;
    }
    else
    {
        ui->errorLabel->setText("error");
    }


}
void admin::on_createMatiere_clicked()
{
    if(ui->nomMatiere->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
    {
        if(ui->volume->value()%2 == 0 && ui->volume->value()!=0)
        {
            if(ui->rattrapage->date()>QDate::currentDate())
            {
                QSqlQuery *query = new QSqlQuery(*db);
                query->prepare("insert into matieres(nom,volumeHoraire,type,dureeExamen,dateRattrapage) values ('" + ui->nomMatiere->text() + "'," + QString::number(ui->volume->value()) + ",'" + ui->type->currentText() + "'," + ui->duree->currentText() + ",'" + ui->rattrapage->date().toString("yyyy-MM-dd") + "')");

                if(query->exec())
                {
                    ui->errorLabel->setText("Nouvelle matière créée");
                }
                else
                {
                    ui->errorLabel->setText("Erreur");
                }
                refreshSubjects();
            }
            else
            {
                ui->errorLabel->setText("Invalid date");
            }
            ui->nomMatiere->setText("");
            ui->volume->setValue(0);
            ui->rattrapage->setDate(QDate::currentDate());
        }
        else
        {
            ui->errorLabel->setText("Invalid volume");
        }
    }
    else
    {
        ui->errorLabel->setText("Invalid name");
    }
}

void admin::on_createForm_clicked()
{
    if(ui->nomForm->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
    {
        if(ui->prenomForm->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
        {
            if(ui->username->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
            {
                if(ui->pw->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                {
                    QSqlQuery *query = new QSqlQuery(*db);
                    query->prepare("insert into formateurs(nom,prenom,idMatiere) values('" + ui->nomForm->text() + "','" + ui->prenomForm->text() + "'," + ui->idMatiere->currentText() + ")");


                    if(query->exec())
                    {
                        ui->errorLabel->setText("Nouveau formateur crée");
                        refreshSubjects();
                        query->prepare("insert into log values('" + ui->username->text() + "','" + ui->pw->text() + "'," + ui->idForm->itemText(ui->idForm->count()-1) + ",2)");
                        query->exec();

                    }
                    else
                    {
                        ui->errorLabel->setText("Erreur");
                    }

                    refreshSubjects();

                }
                else
                {
                    ui->errorLabel->setText("Invalid password");
                }


            }
            else
            {
                ui->errorLabel->setText("Invalid username");
            }
        }
        else
        {
            ui->errorLabel->setText("Invalid first name");
        }
    }
    else
    {
        ui->errorLabel->setText("Invalid lastname");
    }

}

void admin::on_createGrp_clicked()
{
    QSqlQuery *query = new QSqlQuery(*db);
    query->prepare("insert into groupes (idFormateur) values(" + ui->idForm->currentText() + ")");


    if(query->exec())
    {
        ui->errorLabel->setText("Nouveau groupe crée");
        refreshSubjects();
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }
}

void admin::on_idMatiere_3_activated(const QString &arg1)
{

}

void admin::on_idForm2_activated(const QString &arg1)
{

    QSqlQuery *query_4 = new QSqlQuery(*db);


    query_4->prepare("select * from formateurs t1 left outer join (select * from log where acces=2 OR acces=3) t2 on t1.idFormateur = id where idFormateur = " + ui->idForm2->currentText());
    query_4->exec();
    while(query_4->next())
    {

        ui->nomForm_3->setText(query_4->value(1).toString());
        ui->prenomForm_3->setText(query_4->value(2).toString());
        ui->pw_3->setText(query_4->value(5).toString());
        ui->username_3->setText(query_4->value(4).toString());

    }



}

void admin::on_Modify_clicked()
{
    if(ui->nomForm_3->text().remove(QChar(' '),Qt::CaseInsensitive) != ""  && ui->prenomForm_3->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
    {
        QSqlQuery *query = new QSqlQuery(*db);
        query ->prepare("update formateurs set nom='" + ui->nomForm_3->text() + "', prenom='" +  ui->prenomForm_3->text() + "',idMatiere=" + ui->idMatiere_3->currentText()  + " where idFormateur ="+ui->idForm2->currentText());
        if(query->exec())
        {
            query->prepare("update log set usr = '" + ui->username_3->text() + "', pwd='" + ui->pw_3->text() + "' where (acces=2 or acces =3) and id ="+ui->idForm2->currentText());
            query->exec();
            ui->errorLabel->setText("Formateur modifié");
            refreshSubjects();
        }
        else
        {
            ui->errorLabel->setText("Erreur");
        }

    }

}

void admin::on_idMatiere_4_activated(const QString &arg1)
{
    QSqlQuery *query_4 = new QSqlQuery(*db);


    query_4->prepare("select * from matieres where idMatiere = " + ui->idMatiere_4->currentText());
    query_4->exec();
    while(query_4->next())
    {
        ui->nomMatiere_2->setText(query_4->value(1).toString());
        ui->volume_2->setValue(query_4->value(2).toInt());
        ui->type_2->setCurrentText(query_4->value(3).toString());
        ui->duree_2->setCurrentText(query_4->value(4).toString());
        ui->rattrapage_2->setDate(QDate::fromString(query_4->value(5).toString(),"yyyy-MM-dd"));
    }
}

void admin::on_ModifyMat_clicked()
{
    if(ui->nomMatiere_2->text().remove(QChar(' '),Qt::CaseInsensitive) != ""  && ui->rattrapage_2->date()>QDate::currentDate() && ui->volume_2->value()%2==0 && ui->volume_2->value()!=0)
    {
        QSqlQuery *query = new QSqlQuery(*db);

        query->prepare("update matieres set nom='" + ui->nomMatiere_2->text() + "',volumeHoraire=" + QString::number(ui->volume_2->value()) + ", type='" + ui->type_2->currentText() + "',dureeExamen='" + ui->duree_2->currentText() + "',dateRattrapage = '" + ui->rattrapage_2->date().toString("yyyy-MM-dd") + "' where idMatiere = " + ui->idMatiere_4->currentText());


        if(query->exec())
        {
            ui->errorLabel->setText("Matière modifiée");
            refreshSubjects();
        }
        else
        {
            ui->errorLabel->setText("Erreur");
        }

    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }
}

void admin::on_Drop_clicked()
{
    QSqlQuery *query = new QSqlQuery(*db);

    query->prepare("delete from log where id = " + ui->idForm2->currentText());
    query->exec();


    query->prepare("select * from groupes where idFormateur = " + ui->idForm2->currentText());
    query->exec();

    while(query->next()){
        //resa eleve
        QSqlQuery *query2 = new QSqlQuery(*db);

        query2->prepare("delete from reservations where idGroupe = " + query->value(0).toString());
        query2->exec();
        query2->prepare("update stagiaires set idGroupe1 = case when idGroupe1 =" +query->value(0).toString() + " then 0 else idGroupe1 end,idGroupe2 = case when idGroupe2 =" + query->value(0).toString() + " then 0 else idGroupe2 end" + ",idGroupe3 = case when idGroupe3 = " +query->value(0).toString() +" then 0 else idGroupe3 end"+",idGroupe4= case when idGroupe4="+query->value(0).toString()+" then 0 else idGroupe4 end" +",idGroupe5= case when idGroupe5="+query->value(0).toString()+" then 0 else idGroupe5 end"  +" where idMatricule=idMatricule");
        query2->exec();

    }
    query->prepare("delete from groupes where idFormateur = " + ui->idForm2->currentText());
    query->exec();
    query->prepare("delete from formateurs where idFormateur = " + ui->idForm2->currentText());

    if(query->exec())
    {
        ui->errorLabel->setText("Formateur supprimé");


        refreshSubjects();
    }
    else
    {
        ui->errorLabel->setText("delete from formateurs where idFormateur = " + ui->idForm2->currentText());
    }

}

void admin::on_dropMat_clicked()
{
    QSqlQuery *query4 = new QSqlQuery(*db);
    query4->prepare("select * from formateurs where idMatiere = " + ui->idMatiere_4->currentText());
    query4->exec();

    while(query4->next())
    {
        QSqlQuery *query = new QSqlQuery(*db);

        query->prepare("delete from log where id = " + query4->value(0).toString());
        query->exec();


        query->prepare("select * from groupes where idFormateur = " + query4->value(0).toString());
        query->exec();

        while(query->next()){
            //resa eleve
            QSqlQuery *query2 = new QSqlQuery(*db);

            query2->prepare("delete from reservations where idGroupe = " + query->value(0).toString());
            query2->exec();
            query2->prepare("update stagiaires set idGroupe1 = case when idGroupe1 =" +query->value(0).toString() + " then 0 else idGroupe1 end,idGroupe2 = case when idGroupe2 =" + query->value(0).toString() + " then 0 else idGroupe2 end" + ",idGroupe3 = case when idGroupe3 = " +query->value(0).toString() +" then 0 else idGroupe3 end"+",idGroupe4= case when idGroupe4="+query->value(0).toString()+" then 0 else idGroupe4 end" +",idGroupe5= case when idGroupe5="+query->value(0).toString()+" then 0 else idGroupe5 end"  +" where idMatricule=idMatricule");
            query2->exec();

        }
        query->prepare("delete from groupes where idFormateur = " + query4->value(0).toString());
        query->exec();
        query->prepare("delete from formateurs where idFormateur = " + query4->value(0).toString());

        if(query->exec())
        {
            ui->errorLabel->setText("Formateur supprimé");


            refreshSubjects();
        }
        else
        {
            ui->errorLabel->setText("delete from formateurs where idFormateur = " + query4->value(0).toString());
        }
    }

    query4->prepare("delete from matieres where idMatiere = " + ui->idMatiere_4->currentText());

    if(query4->exec())
    {
        ui->errorLabel->setText("Matière Supprimée");

        refreshSubjects();
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }

}

void admin::on_idGrp_activated(const QString &arg1)
{
    QSqlQuery *query_6 = new QSqlQuery(*db);

    query_6->prepare("select * from groupes where idGroupe = " + ui->idGrp->currentText());
    query_6->exec();
    while(query_6->next())
    {
        ui->idForm_2->setCurrentIndex(ui->idForm_2->findText(query_6->value(1).toString()));
    }

}

void admin::on_modifyGrp_clicked()
{
    QSqlQuery *query = new QSqlQuery(*db);

    query->prepare("update groupes set idFormateur=" + ui->idForm_2->currentText() + " where idGroupe = " + ui->idGrp->currentText());

    if(query->exec())
    {
        ui->errorLabel->setText("Groupe modifié");

        refreshSubjects();
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }


}

void admin::on_dropGrp_clicked()
{
    QSqlQuery *query = new QSqlQuery(*db);
    query->prepare("delete from reservations where idGroupe = "+ ui->idGrp->currentText());
    query->exec();
    query->prepare("update stagiaires set idGroupe1 = case when idGroupe1 =" +ui->idGrp->currentText() + " then 0 else idGroupe1 end,idGroupe2 = case when idGroupe2 =" + ui->idGrp->currentText() + " then 0 else idGroupe2 end" + ",idGroupe3 = case when idGroupe3 = " +ui->idGrp->currentText() +" then 0 else idGroupe3 end"+",idGroupe4= case when idGroupe4="+ui->idGrp->currentText()+" then 0 else idGroupe4 end" +",idGroupe5= case when idGroupe5="+ui->idGrp->currentText()+" then 0 else idGroupe5 end"  +" where idMatricule=idMatricule");
    query->exec();
    query->prepare("delete from groupes where idGroupe = "+ ui->idGrp->currentText());
    if(query->exec())
    {
        ui->errorLabel->setText("Groupe supprimé");
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }


    refreshSubjects();

}

void admin::on_createStg_clicked()
{
    if(ui->nomStg->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
    {
        if(ui->prenomStg->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
        {
            if(ui->dateNaissance->date()<= QDate::fromString("2005-01-01", "yyyy-MM-dd"))
            {
                if(ui->numeroRue->value()>0)
                {
                    if(ui->rue->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                    {
                        if(ui->ville->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                        {
                            if(ui->cp->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                            {
                                if(ui->fixe->text().remove(QChar(' '),Qt::CaseInsensitive) != "" && ui->fixe->text().remove(QChar(' '),Qt::CaseInsensitive).length()==10)
                                {
                                    if(ui->portable->text().remove(QChar(' '),Qt::CaseInsensitive) != "" && ui->portable->text().remove(QChar(' '),Qt::CaseInsensitive).length()==10)
                                    {
                                        if(ui->usrStg->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                                        {
                                            if(ui->pwStg->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                                            {
                                                if(ui->idGrp1->currentText().toInt() != 0  || ui->idGrp2->currentText().toInt() != 0 || ui->idGrp3->currentText().toInt() != 0 || ui->idGrp4->currentText().toInt() != 0 || ui->idGrp5->currentText().toInt() != 0)
                                                {
                                                    QSqlQuery *query = new QSqlQuery(*db);
                                                    query->prepare("insert into stagiaires(nom,prenom,dateNaissance,sexe,numeroRue,nomRue,codePostal,nomVille,numeroDom,numeroMob,idGroupe1,idGroupe2,idGroupe3,idGroupe4,idGroupe5) values('" + ui->nomStg->text() + "','" + ui->prenomStg->text() + "','" + ui->dateNaissance->date().toString("yyyy-MM-dd") + "','" + ui->sexeStg->currentText() + "'," + QString::number(ui->numeroRue->value()) + ",'" + ui->rue->text() + "','"  + ui->cp->text() + "','" + ui->ville->text() + "','" + ui->fixe->text() + "','" + ui->portable->text() + "'," + ui->idGrp1->currentText() + "," + ui->idGrp2->currentText() + "," + ui->idGrp3->currentText() + "," +ui->idGrp4->currentText() + "," + ui->idGrp5->currentText() + ")");
                                                    if(query->exec())
                                                    {
                                                        ui->errorLabel->setText("Stagiaire cré(é)e")  ;

                                                        refreshSubjects();

                                                        query->prepare("insert into log values('" +  ui->usrStg->text() + "','" + ui->pwStg->text() + "'," + ui->tableView_4->model()->data(ui->tableView_4->model()->index(ui->tableView_4->model()->rowCount()-1,0)).toString() + ",1)");
                                                        query->exec();




                                                    }
                                                    else
                                                    {
                                                        ui->errorLabel->setText("Erreur");
                                                    }
                                                }
                                                else
                                                {
                                                    ui->errorLabel->setText("Un stagiaire participe à au moins un groupe");
                                                }
                                            }
                                            else
                                            {
                                                ui->errorLabel->setText("Mot de passe incorrect");
                                            }
                                        }
                                        else
                                        {
                                            ui->errorLabel->setText("Username incorrect");
                                        }
                                    }
                                    else
                                    {
                                        ui->errorLabel->setText("Numéro portable incorrect");
                                    }
                                }
                                else
                                {
                                    ui->errorLabel->setText("Numéro fixe incorrect");
                                }
                            }
                            else
                            {
                                ui->errorLabel->setText("CP incorrect");
                            }

                        }
                        else
                        {
                            ui->errorLabel->setText("Nom ville incorrect");
                        }
                    }
                    else
                    {
                        ui->errorLabel->setText("Nom rue incorrect");
                    }
                }
                else
                {
                    ui->errorLabel->setText("Numéro rue incorrect");
                }
            }
            else
            {
                ui->errorLabel->setText("Date incorrecte");
            }
        }
        else
        {
            ui->errorLabel->setText("Prénom incorrect");
        }
    }
    else
    {
        ui->errorLabel->setText("Nom incorrect");
    }


}

void admin::on_idMatricule_activated(const QString &arg1)
{
    int row = 0;

    while(ui->idMatricule->currentText().toInt() != ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,0)).toInt() && row < ui->tableView_4->model()->rowCount())
    {
        row++;
    }
    ui->nomStg_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,1)).toString());
    ui->prenomStg_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,2)).toString());
    ui->sexeStg_2->setCurrentIndex(ui->sexeStg_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,6)).toString()));
    ui->dateNaissance_2->setDate(QDate::fromString(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,3)).toString(),"yyyy-MM-dd"));
    ui->rue_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,8)).toString());
    ui->cp_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,9)).toString());
    ui->numeroRue_2->setValue(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,7)).toInt());
    ui->ville_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,10)).toString());
    ui->portable_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,12)).toString());
    ui->fixe_2->setText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,11)).toString());
    ui->idGrp1_2->setCurrentIndex(ui->idGrp1_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,13)).toString()));
    ui->idGrp2_2->setCurrentIndex(ui->idGrp2_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,14)).toString()));
    ui->idGrp3_2->setCurrentIndex(ui->idGrp3_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,15)).toString()));
    ui->idGrp4_2->setCurrentIndex(ui->idGrp4_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,16)).toString()));
    ui->idGrp5_2->setCurrentIndex(ui->idGrp5_2->findText(ui->tableView_4->model()->data(ui->tableView_4->model()->index(row,17)).toString()));

    QSqlQuery *query_4 = new QSqlQuery(*db);


    query_4->prepare("select * from log where acces = 1 and id = " + ui->idMatricule->currentText());
    query_4->exec();

    ui->usrStg_2->setText("");
    ui->pwStg_2->setText("");


    while(query_4->next())
    {
        ui->usrStg_2->setText(query_4->value(0).toString());
        ui->pwStg_2->setText(query_4->value(1).toString());
    }
}

void admin::on_modifyStg_clicked()
{

    if(ui->nomStg_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
    {
        if(ui->prenomStg_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
        {
            if(ui->dateNaissance_2->date()<= QDate::fromString("2005-01-01", "yyyy-MM-dd"))
            {
                if(ui->numeroRue_2->value()>0)
                {
                    if(ui->rue_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                    {
                        if(ui->ville_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                        {
                            if(ui->cp_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                            {
                                if(ui->fixe_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "" && ui->fixe_2->text().remove(QChar(' '),Qt::CaseInsensitive).length()==10)
                                {
                                    if(ui->portable_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "" && ui->portable_2->text().remove(QChar(' '),Qt::CaseInsensitive).length()==10)
                                    {
                                        if(ui->usrStg_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                                        {
                                            if(ui->pwStg_2->text().remove(QChar(' '),Qt::CaseInsensitive) != "")
                                            {
                                                if(ui->idGrp1_2->currentText().toInt() != 0  || ui->idGrp2_2->currentText().toInt() != 0 || ui->idGrp3_2->currentText().toInt() != 0 || ui->idGrp4_2->currentText().toInt() != 0 || ui->idGrp5_2->currentText().toInt() != 0)
                                                {
                                                        QSqlQuery *query = new QSqlQuery(*db);

                                                        query->prepare("update stagiaires set nom = '" + ui->nomStg_2->text() + "', prenom = '" + ui->prenomStg_2->text() + "', dateNaissance = '" + ui->dateNaissance_2->date().toString("yyyy-MM-dd") + "', sexe = '" + ui->sexeStg_2->currentText() + "', numeroRue = " + ui->numeroRue_2->text() + ", nomRue= '" + ui->rue_2->text() + "', codePostal='" + ui->cp_2->text() +"', nomVille='" + ui->ville_2->text() +"', numeroDom='" + ui->fixe_2->text() +"', numeroMob= '" + ui->portable_2->text() + "', idGroupe1=" + ui->idGrp1_2->currentText() + ", idGroupe2=" +  ui->idGrp2_2->currentText()   + ", idGroupe3 = " + ui->idGrp3_2->currentText() + ", idGroupe4 = " +  ui->idGrp4_2->currentText() + ",idGroupe5=" +  ui->idGrp5_2->currentText() +" where idMatricule = " + ui->idMatricule->currentText());

                                                        if(query->exec())
                                                        {

                                                            ui->errorLabel->setText("Stagiaire modfié(e)");

                                                            query->prepare("update log set usr = '" + ui->usrStg_2->text() + "', pwd = '" + ui->pwStg_2->text() + "' where acces = 1 and id =" + ui->idMatricule->currentText() );
                                                            query->exec();
                                                            refreshSubjects();
                                                        }
                                                        else
                                                        {
                                                               ui->errorLabel->setText("Erreur");
                                                        }
                                                }
                                                else
                                                {
                                                    ui->errorLabel->setText("Un stagiaire participe à au moins un groupe");
                                                }
                                            }
                                            else
                                            {
                                                ui->errorLabel->setText("Mot de passe incorrect");
                                            }
                                        }
                                        else
                                        {
                                            ui->errorLabel->setText("Username incorrect");
                                        }
                                    }
                                    else
                                    {
                                        ui->errorLabel->setText("Numéro portable incorrect");
                                    }
                                }
                                else
                                {
                                    ui->errorLabel->setText("Numéro fixe incorrect");
                                }
                            }
                            else
                            {
                                ui->errorLabel->setText("CP incorrect");
                            }

                        }
                        else
                        {
                            ui->errorLabel->setText("Nom ville incorrect");
                        }
                    }
                    else
                    {
                        ui->errorLabel->setText("Nom rue incorrect");
                    }
                }
                else
                {
                    ui->errorLabel->setText("Numéro rue incorrect");
                }
            }
            else
            {
                ui->errorLabel->setText("Date incorrecte");
            }
        }
        else
        {
            ui->errorLabel->setText("Prénom incorrect");
        }
    }
    else
    {
        ui->errorLabel->setText("Nom incorrect");
    }
}

void admin::on_dropGrp_2_clicked()
{

}

void admin::on_dropStg_2_clicked()
{
    QSqlQuery *query = new QSqlQuery(*db);

    query->prepare("delete from stagiaires where idMatricule = " + ui->idMatricule->currentText());

    if(query->exec())
    {
        query->prepare("delete from log where acces = 1 and id = " + ui->idMatricule->currentText());

        if(query->exec())
        {
            ui->errorLabel->setText("Stagiaire supprimé(e)");

        }
        else
        {
            ui->errorLabel->setText("Erreur");
        }
        refreshSubjects();
    }
    else
    {
        ui->errorLabel->setText("Erreur");
    }

}
