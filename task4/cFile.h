#include <string>
//
// Created by Vladislav Raspopin on 15.10.17.
//

#ifndef UNTITLED3_FILE_H
#define UNTITLED3_FILE_H


class cFile {

public:

    void set (char* file_name, int size_of_file, int date_of_creation, int number_of_hits);
    char* get_file_name();
    int get_size_of_file ();
    int get_date_of_creation ();
    int get_number_of_hits ();
    void show  ();
    char* new_file_name(const char *str);
    cFile (cFile const& copy_object); //copy constructor
    cFile (char* file_name, int size_of_file, int date_of_creation, int number_of_hits);
    cFile ();
    ~cFile ();
private:

    char* file_name;
    int size_of_file;
    int date_of_creation;
    int number_of_hits;

private:

};


#endif //UNTITLED3_FILE_H
