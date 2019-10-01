#include <iostream>
#include "Database/header/database.h"
int main()
{
    std::string sql = "CREATE TABLE PERSON("
                      "ID INT PRIMARY KEY     NOT NULL, "
                      "NAME           TEXT    NOT NULL, "
                      "SURNAME          TEXT     NOT NULL, "
                      "AGE            INT     NOT NULL, "
                      "ADDRESS        CHAR(50), "
                      "SALARY         REAL );";
    std::vector<std::string> tablecolumns;
    std::vector<std::string> tablevalues;
    std::vector<std::string> selectcolumn;
    std::vector<std::string> selectcolumn2;
    std::vector<std::string> updatecolumn;
    std::vector<std::string> whereclause;
    std::string table = "PERSON";
    tablecolumns = {"ID", "NAME", "SURNAME","AGE","ADDRESS","SALARY"};
    tablevalues ={"3", "Mimi", "Minji", "26", "Pangani", "1500000"};
    selectcolumn = { "NAME", "SURNAME","AGE","SALARY"};
    selectcolumn2 = {"*"};
    updatecolumn = {"NAME = 'PINJE MUSEE'","AGE = 25"};
    whereclause = {"`ID` = 3"};
    Database db;
    db.database ="../assets/files/database3.db";
//    db.getDb();
//    db.select(table,{},{});
//    db.update(table,updatecolumn,whereclause);
    db.del(table,whereclause);
    return 0;
}

