#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class adminMenu;
}

class adminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit adminMenu(QWidget *parent = nullptr,QSqlDatabase *hp = nullptr);

    ~adminMenu();

private slots:
    void on_gerer_clicked();

    void on_planifier_clicked();

    void on_consulter_clicked();

private:
    Ui::adminMenu *ui;
    QSqlDatabase *db;
};

#endif // ADMINMENU_H
