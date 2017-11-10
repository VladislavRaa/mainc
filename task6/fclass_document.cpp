//
// Created by Vladislav Raspopin on 31.10.17.
//

#include "fclass_document.h"
void fclass_document::set_file_name (const char* file_name) {
    char buf [] = ".txt";
    delete [] this->file_name;
    size_t newSize = strlen(file_name)+ strlen(buf)+ 1;
    this->file_name = new char [newSize];
    strlcpy(this->file_name, file_name, sizeof(this->file_name));
    strlcpy(this->file_name, file_name, sizeof(this->file_name));
    strcat(this->file_name, buf);
}

fclass_document::fclass_document (char* file_name)
        : file_name(file_name) {
    this->file_name = new_file_name(file_name);
    set_file_name(file_name);

}

char *fclass_document::new_file_name(const char *str) {
    char* new_name;
    new_name = new char[strlen(str)];
    return new_name;
}

fclass_document::~fclass_document() {
    delete [] file_name;
}

void fclass_document::massage() const {
    std::cout << "this document: ";
}

void fclass_document::Print(std::ostream& out) const {
    out << this->file_name;
}
