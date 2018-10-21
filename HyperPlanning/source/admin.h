#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr,QSqlDatabase *hp = nullptr);
    ~admin();

private slots:
    void on_createMatiere_clicked();

    void on_createForm_clicked();

    void on_createGrp_clicked();

    void on_idMatiere_3_activated(const QString &arg1);

    void on_idForm2_activated(const QString &arg1);

    void on_Modify_clicked();

    void on_idMatiere_4_activated(const QString &arg1);

    void on_ModifyMat_clicked();

    void on_Drop_clicked();

    void on_dropMat_clicked();

    void on_idGrp_activated(const QString &arg1);

    void on_modifyGrp_clicked();

    void on_dropGrp_clicked();

    void on_createStg_clicked();

    void on_idMatricule_activated(const QString &arg1);

    void on_modifyStg_clicked();

    void on_dropGrp_2_clicked();

    void on_dropStg_2_clicked();

private:
    Ui::admin *ui;
    QSqlDatabase *db;
    void refreshSubjects();
};

#endif // ADMIN_H
