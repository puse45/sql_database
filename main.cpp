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
    std::string table = "PERSON";
    tablecolumns = {"ID", "NAME", "SURNAME","AGE","ADDRESS","SALARY"};
    tablevalues ={"2", "Pius Musyoki Musee", "Musyoki", "26", "Pangani", "1500000"};
    Database db;
    db.database ="../assets/files/database3.db";
    db.getDb();
    db.createTable(sql);
    db.insert(table,tablecolumns,tablevalues);
    return 0;
}

