//
// Created by viscan on 9/27/19.
//

#include "../header/database.h"


Database::Database() {
    if(connectDb()){

    }
}

Database::~Database() {
//    delete createfile;

}

std::string Database::getDb() {
    std::cout<< "Current DB"<<database<<std::endl;
    return database;
}

bool Database::setDb() {

    boost::filesystem::path my_file(database);

    if (boost::filesystem::exists(my_file))
    {
        std::cerr << "Database exist" << std::endl;
        m_creation_status = true;
    }
    else
    {
        std::ofstream file { database };
        m_creation_status =true;
    }

    return m_creation_status;
}


const bool Database::connectDb() {
    if(setDb()){
        return 1;
    }
    else{
        return 0;
    }
}

const char * Database::createTable(const std::string table) {
    int exit = 0;
    exit = sqlite3_open(database, &DB);
    char* messaggeError;
    exit = sqlite3_exec(DB, table.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK) {
        std::cerr << "Table exist" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Table created Successfully" << std::endl;
    sqlite3_close(DB);
    return (0);
}

const std::string Database::select(const std::string table, const std::vector<std::string> colomns,
                                   const std::vector<std::string> where, const std::vector<std::string> values)
{

    std::cout<<"Select"<<std::endl;
}

const std::string Database::insert(const std::string table,std::vector<std::string> colomns, std::vector<std::string> values)
{
    m_messaggeError= nullptr;
    bool first= false;
    int exit = sqlite3_open(database, &DB);

        m_sql = "INSERT INTO " + table;
    if(!colomns.empty()) {
        m_sql += "(";
        for (m_colNameItr = colomns.begin(); m_colNameItr < colomns.end(); m_colNameItr++) {

            if (first) {
                m_sql += ',';
            }
            m_sql += *m_colNameItr;
            first = true;
        };
        m_sql += ")";
    }
        first = false;
        m_sql += "VALUES(";
        for (m_valueItr = values.begin(); m_valueItr < values.end(); m_valueItr++) {
            if (first) {
                m_sql += ',';
            }
            m_sql += '"' + *m_valueItr + '"';
            first = true;
        };
        m_sql += ");";

        std::cout << m_sql << std::endl;
        exit = sqlite3_exec(DB, m_sql.c_str(), NULL, 0, &m_messaggeError);
        if (exit != SQLITE_OK) {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(m_messaggeError);
        } else
            std::cout << "Records created Successfully!" << std::endl;


}

const std::string Database::update(const std::string, const std::vector<std::string> colomns,
                                   const std::vector<std::string> where, const std::vector<std::string> values)
{
    std::cout<<"Update"<<std::endl;
}

const std::string Database::del(const std::string, const std::vector<std::string> where,
                                const std::vector<std::string> values)
{
    std::cout<<"Delete"<<std::endl;
}