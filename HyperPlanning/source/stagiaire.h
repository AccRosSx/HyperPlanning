#ifndef STAGIAIRE_H
#define STAGIAIRE_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class stagiaire;
}

class stagiaire : public QDialog
{
    Q_OBJECT

public:
    explicit stagiaire(QWidget *parent = nullptr,QSqlDatabase *hp = nullptr, int id = 0);
    ~stagiaire();

private slots:

    void on_loadTableWeek_clicked();

    void on_loadTableMonth_clicked();

    void on_loadTableDay_clicked();

private:
    Ui::stagiaire *ui;
    void loadTable(QString dateCondition);
    QSqlDatabase *db;
    int idMatricule;
};

#endif // STAGIAIRE_H
