#include "consultation.h"
#include "ui_consultation.h"

consultation::consultation(QWidget *parent,QSqlDatabase *hp) :
    QDialog(parent),
    ui(new Ui::consultation)
{
    ui->setupUi(this);
    db=hp;
    refresh(true);
}

consultation::~consultation()
{
    delete ui;
}

void consultation::refresh(bool clr)
{
    QSqlQuery *query = new QSqlQuery(*db);
    QSqlQueryModel *qm = new QSqlQueryModel;

    if(clr == true)
    {
        ui->comboBox->clear();

        query->prepare("select idGroupe from groupes");
        ui->comboBox->addItem(" ");
        if(query->exec())
        {
            while(query->next())
            {
                ui->comboBox->addItem(query->value(0).toString());
            }
        }

    }


    QString order = "";
    QString grp = "";
    QString name="";

    if(ui->checkBox->isChecked())
    {
        order = " order by nom";
    }
    if(ui->comboBox->currentText().remove(QChar(' '),Qt::CaseInsensitive) != "")
    {
        grp = "where (idGroupe1= " + ui->comboBox->currentText() + " or idGroupe2=" + ui->comboBox->currentText() + " or idGroupe3=" + ui->comboBox->currentText() + " or idGroupe4="+ui->comboBox->currentText()+" or idGroupe5="+ui->comboBox->currentText() + ")";
    }
    if(ui->lineEdit->text().remove(QChar(' '),Qt::CaseInsensitive)!="")
    {
        if(grp!="")
        {
            name = " AND nom like '%" + ui->lineEdit->text() + "%'";
        }
        else
        {
            name = " where nom like '%" + ui->lineEdit->text() + "%'";
        }
    }


    query->prepare("select * from stagiaires " + grp +name + order);


    query->exec();

    qm->setQuery(*query);

    ui->tableView->setModel(qm);

}
void consultation::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    refresh(false);
}

void consultation::on_comboBox_activated(const QString &arg1)
{
     refresh(false);
}

void consultation::on_checkBox_stateChanged(int arg1)
{
    refresh(false);
}
