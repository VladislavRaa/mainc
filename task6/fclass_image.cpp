//
// Created by Vladislav Raspopin on 30.10.17.
//
#include "fclass_image.h"

void fclass_image::set_file_name (const char* file_name) {
    char buf [] = ".jpeg";
    delete [] this->file_name;
    size_t newSize = strlen(file_name)+ strlen(buf)+ 1;
    this->file_name = new char [newSize];
    strlcpy(this->file_name, file_name, sizeof(this->file_name));
    strlcpy(this->file_name, file_name, sizeof(this->file_name));
    strcat(this->file_name, buf);
}

fclass_image::fclass_image (char* file_name)
    : file_name(file_name) {
    this->file_name = new_file_name(file_name);
    set_file_name(file_name); //!!!
}

char *fclass_image::new_file_name(const char *str) {
    char* new_name;
    new_name = new char[strlen(str)];
    return new_name;
}

fclass_image::~fclass_image(){
    delete[] file_name;
}

void fclass_image::massage() const {
    std::cout << "this image: ";
}

void fclass_image::Print(std::ostream& out) const {
    out << this->file_name;
}
