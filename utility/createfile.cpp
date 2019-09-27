//
// Created by viscan on 9/27/19.
//
#include "createfile.h"

Createfile::Createfile() {
    m_creation_status = false;
}
Createfile::~Createfile() {
}

bool Createfile::makeFile(const char* filename) {
    boost::filesystem::path my_file(filename);

    if (boost::filesystem::exists(my_file))
    {
        m_creation_status = true;
        return m_creation_status;
    }
    else
    {
        std::ofstream file { filename };
        m_creation_status =true;
        return m_creation_status;
    }
}

