#ifndef FORMATEUR_H
#define FORMATEUR_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class formateur;
}

class formateur : public QDialog
{
    Q_OBJECT

public:
    explicit formateur(QWidget *parent = nullptr,QSqlDatabase *hp = nullptr, int id = 0);
    ~formateur();

private slots:
    void on_loadTable_clicked();

    void on_loadTableDay_clicked();

    void on_loadTableWeek_clicked();

    void on_loadTableMonth_clicked();

private:
    Ui::formateur *ui;
    QSqlDatabase *db;
    int idFormateur;
    void loadTable(QString dateCondition);
};

#endif // FORMATEUR_H
