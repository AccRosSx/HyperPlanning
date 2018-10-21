//
//  Mysql.hpp
//  HyperPlanning
//
//  Created by Birintha Srichuthesgaran on 20/10/2018.
//  Copyright © 2018 Birintha Srichuthesgaran. All rights reserved.
//

#ifndef Mysql_hpp
#define Mysql_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <vector>

using namespace std;
class Mysql{
    sql::Driver *driver;
    sql::Connection *con;
public:
    sql::Statement *stmt;
    Mysql();
    bool Insert(string table, vector<vector<string>> Arg);
    int GetId(string table);
    int Update(string table, int target, vector<vector<string>> Arg);
};
#endif /* Mysql_hpp */
