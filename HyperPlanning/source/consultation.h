#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <QDialog>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


namespace Ui {
class consultation;
}

class consultation : public QDialog
{
    Q_OBJECT

public:
    explicit consultation(QWidget *parent = nullptr,QSqlDatabase *hp = nullptr);
    ~consultation();

private slots:
    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_activated(const QString &arg1);

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::consultation *ui;
    QSqlDatabase *db;
    void refresh(bool clr);
};

#endif // CONSULTATION_H
