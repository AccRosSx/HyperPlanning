#include "login.h"
#include "ui_login.h"
#include "formateur.h"
#include "admin.h"
#include "reservation.h"
#include "adminmenu.h"
#include "stagiaire.h"
#include "formateurr.h"
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("HyperPlanning");
}

login::~login()
{
    connClose();
    delete ui;
}

void login::on_logButton_clicked()
{
    if(connOpen(ui->host->text(),ui->user->text(),ui->pw->text(),"hyperplanning")){


        QSqlQuery *query = new QSqlQuery(db);

        query->prepare("select id, acces from log where usr='" + ui->id->text() + "' AND pwd='"+ui->pw_2->text()+"'");
        query->exec();

        if(query->next())
        {
            ui->errorLabel->setText("connected");

            switch(query->value(1).toInt())
            {
            case 1:{

                stagiaire stg(nullptr,&db,query->value(0).toInt());
                stg.setModal(true);
                stg.setWindowTitle("HyperPlanning - Stagiaire");

                this->hide();
                stg.exec();
                this->show();
                break;
            }
            case 2:
            {
                formateur ft(nullptr,&db,query->value(0).toInt());
                ft.setModal(true);
                ft.setWindowTitle("HyperPlanning - Formateur");
                this->hide();
                ft.exec();
                this->show();
                break;
            }
            case 3:
            {
                formateurR ftr(nullptr,&db,query->value(0).toInt());
                ftr.setModal(true);
                ftr.setWindowTitle("HyperPlanning - Formateur Responsable");
                this->hide();
                ftr.exec();
                this->show();
                break;
            }
            case 4 :
            {
                 adminMenu adm(nullptr,&db);
                 adm.setModal(true);
                 adm.setWindowTitle("Hyper Planning - Admin");
                 this->hide();
                 adm.exec();
                 this->show();
                 break;
            }
            default:
                ui->errorLabel->setText("Utilisateur non reconnu");
                break;

            }




        }
        else
        {
             ui->errorLabel->setText("Utilisateur non reconnu");
        }

    }
    else
    {
        ui->errorLabel->setText(db.lastError().text());
    }
}
