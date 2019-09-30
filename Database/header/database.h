//
// Created by viscan on 9/27/19.
//

#ifndef VISCAN_EMBEDED_DATABASE_H
#define VISCAN_EMBEDED_DATABASE_H
#include <iostream>
#include "utility/createfile.h"
#include <sqlite3.h>
#include <vector>
#include <iterator>

class Database{

public:
    explicit Database();
    ~ Database();
    std::string getDb();
    bool setDb();
    const char * createTable(const std::string table);
    const std::string insert(const std::string table, std::vector<std::string> colomns, std::vector<std::string> values);
    const std::string select(const std::string table, const std::vector<std::string> colomns, const std::vector<std::string> where, const std::vector<std::string> values);
    const std::string update(const std::string table, const std::vector<std::string> colomns, const std::vector<std::string> where, const std::vector<std::string> values);
    const std::string del(const std::string table, const std::vector<std::string> where, const std::vector<std::string> values);
private:
    sqlite3* DB;
    const bool connectDb();

public:
    const char* m_host;
    const char* m_username;
    const char* m_password;
    const char* database = "../assets/files/database.db";

private:
    std::vector<std::string>::iterator m_colNameItr;
    std::vector<std::string>::iterator m_valueItr;
//    std::vector<std::string> m_sql;
    std::string m_sql;
    char* m_messaggeError = nullptr;
    bool m_creation_status = false;

//    Createfile* createfile = new Createfile();

};

#endif //VISCAN_EMBEDED_DATABASE_H



