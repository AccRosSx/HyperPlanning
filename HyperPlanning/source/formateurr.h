#ifndef FORMATEURR_H
#define FORMATEURR_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class formateurR;
}

class formateurR : public QDialog
{
    Q_OBJECT

public:
    explicit formateurR(QWidget *parent = nullptr,QSqlDatabase *hp = nullptr, int id = 0);
    ~formateurR();

private slots:
    void on_gerer_clicked();

    void on_consulter_clicked();

private:
    Ui::formateurR *ui;
    QSqlDatabase *db;
    int idFormateur;
    int idMatiere;
};

#endif // FORMATEURR_H
