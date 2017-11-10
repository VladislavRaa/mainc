//
// Created by Vladislav Raspopin on 31.10.17.
//

#include "fclass_video.h"
void fclass_video::set_file_name (const char* file_name) {
    char buf [] = ".wmv";
    delete [] this->file_name;
    size_t newSize = strlen(file_name)+ strlen(buf)+ 1;
    this->file_name = new char [newSize];
    strlcpy(this->file_name, file_name, sizeof(this->file_name));
    strlcpy(this->file_name, file_name, sizeof(this->file_name));
    strcat(this->file_name, buf);
}

fclass_video::fclass_video (char* file_name)
        : file_name(file_name) {

    this->file_name = new_file_name(file_name);
    set_file_name(file_name);
}

char* fclass_video::new_file_name(const char *str) {
    char* new_name;
    new_name = new char[strlen(str)];
    return new_name;
}

fclass_video::~fclass_video() {
    delete [] file_name;
}

void fclass_video::massage() const {
    std::cout << "this video: ";
}

void fclass_video::Print(std::ostream& out) const {
    out << this->file_name;
}
