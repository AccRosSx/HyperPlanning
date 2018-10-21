#ifndef RESERVATION_H
#define RESERVATION_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class reservation;
}

class reservation : public QDialog
{
    Q_OBJECT

public:
    explicit reservation(QWidget *parent = nullptr,QSqlDatabase *hp = nullptr,int tgt = 0);
    ~reservation();

private slots:
    void on_idGrp_activated(const QString &arg1);

    void on_createResa_clicked();

    void on_idResa_activated(const QString &arg1);

    void on_modifyResa_clicked();

    void on_dropResa_clicked();

private:
    Ui::reservation *ui;
    QSqlDatabase *db;
    bool checkConflit();
    int target;
    void refresh();
};

#endif // RESERVATION_H
