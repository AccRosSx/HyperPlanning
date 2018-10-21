//
//  Mysql.cpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#include "Mysql.hpp"

Mysql::Mysql(){
    try{
        driver = get_driver_instance();
        con = driver->connect("tcp://hosting.rubrash.com:3306", "bibi", "@13102018");
        con->setSchema("bibiphzc_");
        stmt = con->createStatement();
    }
    catch (sql::SQLException &e) {
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}
bool Mysql::Insert(string table,vector<vector<string>> Arg){
    // Convertir Arg[0][0-Arg.size] en  string column par exemple 'nom','prenom','role'
    // Convertir Arg[1][] en string values
    string columns;
    string values;
    string separator = "`,`";
    for(int i = 0; i < Arg[0].size(); i++)
    {
        if(i == 0)
        {
            columns = "`" + Arg[0][i];
        }
        else
        {
            columns += separator + Arg[0][i];
            if(i+1 == Arg[0].size())
            {
                columns+= "`";
            }
        }
    }
    separator = "','";
    for(int i = 0; i < Arg[1].size(); i++)
    {
        if(i == 0)
        {
            values = "'"+Arg[1][i];
        }
        else
        {
            values += separator + Arg[1][i];
                if(i+1 == Arg[1].size())
                {
                    values+= "'";
                }
        }
    }
    //cout << columns << endl;
    //cout << values <<endl;
    //cout <<"INSERT INTO " + table + "(" + columns + ") VALUES (" + values + ")" << endl;
    sql::PreparedStatement *pstmt;
    pstmt = con->prepareStatement("INSERT INTO " + table + "(" + columns + ") VALUES (" + values + ")");
    if(pstmt->executeQuery()){
        delete pstmt;
        return true;
    }
    else{
        delete pstmt;
        return false;
    }
}


int Mysql::GetId(string table)
{
    Mysql connexion;
    sql::ResultSet *res;
    res = connexion.stmt->executeQuery("SELECT `AUTO_INCREMENT` FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_SCHEMA = 'bibiphzc_' AND TABLE_NAME = '" + table + "'");
    res->next();
    return res->getInt("AUTO_INCREMENT") - 1;
}

int Mysql::Update(string table, int target, vector<vector<string>> Arg)
{
    sql::PreparedStatement *pstmt;
    // UPDATE personne SET idGroupe=3,matricule=20180468 WHERE id=83
    // arg[0][0]=arg[1][0],
    string values;
    for(int i = 0; i < Arg[0].size(); i++){
        values += "`" + Arg[0][i] + "`='" + Arg[1][i] + "'";
        if(i + 1 != Arg[0].size()) values += ",";
    }
    cout << values << endl;
    pstmt = con->prepareStatement("UPDATE " + table + " SET "+ values +" WHERE id=" + to_string(target) );
    if(pstmt->executeQuery()){
        delete pstmt;
        return true;
    }
    else{
        delete pstmt;
        return false;
    }
    
}

