//
// Created by viscan on 9/27/19.
//

#ifndef VISCAN_EMBEDED_DATABASE_H
#define VISCAN_EMBEDED_DATABASE_H
#include <iostream>
#include "utility/createfile.h"
#include <sqlite3.h>
#include <vector>

class Database{

public:
    explicit Database();
    ~ Database();
    const bool connect();
    const std::string createTable(const char* table);
    const std::string insert(const char* table, const std::vector<std::string> colomns, const std::vector<std::string> values);
    const std::string select(const char* table, const std::vector<std::string> colomns, const std::vector<std::string> where, const std::vector<std::string> values);
    const std::string update(const char* table, const std::vector<std::string> colomns, const std::vector<std::string> where, const std::vector<std::string> values);
    const std::string del(const char* table, const std::vector<std::string> where, const std::vector<std::string> values);

public:
    const char* m_host;
    const char* m_username;
    const char* m_password;
    const char* databasePath = "../assets/files/database.db";

private:
    Createfile* createfile = new Createfile();

};

#endif //VISCAN_EMBEDED_DATABASE_H



