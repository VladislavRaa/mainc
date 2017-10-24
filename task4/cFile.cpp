#include "cFile.h"
#include <iostream>
//
// Created by Vladislav Raspopin on 15.10.17.
//

cFile::cFile (cFile const& copy_object) {
    this->file_name = new char [strlen(copy_object.file_name) + 1];
    this->size_of_file = copy_object.size_of_file;
    this->date_of_creation = copy_object.date_of_creation;
    this->number_of_hits = copy_object.number_of_hits;
    strcpy(this->file_name, copy_object.file_name);
}

void cFile::set_file_name (const char* file_name) {
    delete [] this->file_name;
    size_t newSize = strlen(file_name) + 1;
    this->file_name = new char [newSize];
    strcpy(this->file_name, file_name);
}

void cFile::set_size_of_file (int size_of_file) {
    this->size_of_file = size_of_file;
}

void cFile::set_date_of_creation (int date_of_creation) {
    this->date_of_creation = date_of_creation;
}

void cFile::set_number_of_hits (int number_of_hits) {
    this->number_of_hits = number_of_hits;
}

const char* cFile::get_file_name () {
    return this->file_name;
}

int cFile::get_size_of_file () {
    return this->size_of_file;
}

int cFile::get_date_of_creation () {
    return this->date_of_creation;
}

int cFile::get_number_of_hits () {
    return this->number_of_hits;
}

void cFile::show () {
    std::cout << " File name: "       << file_name
              << " Size of file: "    << size_of_file
              << " Date of creation " << date_of_creation / 1000000 << "."
                                      << (date_of_creation % 1000000) / 10000 << "."
                                      << date_of_creation % 10000
              << " Number of hits "   << number_of_hits
                                      << std::endl;
}

char *cFile::new_file_name(const char *str)
{
    char* new_name;
    new_name = new char[strlen(str)];
    return new_name;
}

cFile::cFile () {};

cFile::cFile (char* file_name, int size_of_file = 0, int date_of_creation = 0, int number_of_hits = 0)
    : file_name(file_name),
      size_of_file(size_of_file),
      date_of_creation(date_of_creation),
      number_of_hits(number_of_hits)
{
    this->file_name = new_file_name(file_name);
}

cFile::~cFile () {
    delete [] this->file_name;
}

cFile& cFile::operator = (const cFile& other) {
    if (this == &other) {
        return *this;
    }
    file_name = new char [strlen(other.file_name) + 1];
    this->size_of_file = other.size_of_file;
    this->date_of_creation = other.date_of_creation;
    this->number_of_hits = other.number_of_hits;
    strlcpy(this->file_name, other.file_name, strlen(other.file_name) + 1);

    return *this;
}
