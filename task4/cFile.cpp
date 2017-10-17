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
   // strcpy(this->file_name, copy_object.file_name);
    strlcpy(this->file_name, copy_object.file_name, strlen(copy_object.file_name) + 1);//safe


}

void cFile::set (char* file_name, int size_of_file, int date_of_creation, int number_of_hits) {
    this->file_name = new char [strlen(file_name) + 1];
    //strlcpy(this->file_name, file_name, strlen(file_name) + 1);
    strcpy(this->file_name, file_name);
    this->size_of_file = size_of_file;
    this->date_of_creation = date_of_creation;
    this->number_of_hits = number_of_hits;
}

char* cFile::get_file_name () {
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

cFile::~cFile () {}