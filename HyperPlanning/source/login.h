#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    void connClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(QString host, QString user, QString pw, QString dbName)
    {
        db=QSqlDatabase::addDatabase("QMYSQL");
        db.setUserName(user);
        db.setPassword(pw);
        db.setDatabaseName(dbName);
        db.setHostName(host);

        if(db.open())
            return true;
        return false;
    }
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_logButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
