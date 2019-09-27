//
// Created by viscan on 9/27/19.
//

#ifndef DATABASE_CREATEFILE_H
#define DATABASE_CREATEFILE_H

#include <boost/filesystem.hpp>
#include <iostream>

class Createfile {

public:
    explicit Createfile();
    ~ Createfile();
    bool makeFile(const char* filename);

public:
    bool m_creation_status;

};


#endif //DATABASE_CREATEFILE_H
