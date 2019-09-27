//
// Created by viscan on 9/27/19.
//

#include "../header/database.h"


Database::Database() {
    bool status = createfile->makeFile(databasePath);
    if(status){
        sqlite3* DB;
        int exit = 0;
        exit = sqlite3_open(databasePath, &DB);

        if (exit) {
            std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
            return (-1);
        }
        else

            sqlite3_close(DB);
        return (0);
    }
    else{
        std::cout<<"Error creating database file"<<std::endl;
    }
}

Database::~Database() {
    delete createfile;

}
const bool Database::connect() {


}

const std::string Database::createTable(const char *table) {

    std::cout<<"Create"<<std::endl;
}

const std::string Database::select(const char *table, const std::vector<std::string> colomns,
                                   const std::vector<std::string> where, const std::vector<std::string> values)
{

    std::cout<<"Select"<<std::endl;
}

const std::string Database::insert(const char *table, const std::vector<std::string> colomns,
                                   const std::vector<std::string> values)
{
    std::cout<<"Insert"<<std::endl;

}

const std::string Database::update(const char *table, const std::vector<std::string> colomns,
                                   const std::vector<std::string> where, const std::vector<std::string> values)
{
    std::cout<<"Update"<<std::endl;
}

const std::string Database::del(const char *table, const std::vector<std::string> where,
                                const std::vector<std::string> values)
{
    std::cout<<"Delete"<<std::endl;
}