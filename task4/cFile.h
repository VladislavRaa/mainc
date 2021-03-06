#ifndef UNTITLED3_FILE_H
#define UNTITLED3_FILE_H
//
// Created by Vladislav Raspopin on 15.10.17.
//
class cFile {

public:

    void set_file_name(const char* file_name);
    void set_size_of_file(int size_of_file);
    void set_date_of_creation(int size_of_file);
    void set_number_of_hits(int size_of_file);
    const char* get_file_name();
    int get_size_of_file ();
    int get_date_of_creation ();
    int get_number_of_hits ();
    void show  ();
    char* new_file_name(const char *str);
    cFile (cFile const& copy_object); //copy constructor
    cFile (char* file_name, int size_of_file, int date_of_creation, int number_of_hits);
    cFile ();
    ~cFile ();
    cFile& operator = (const cFile& other);

private:

    char* file_name;
    int size_of_file;
    int date_of_creation;
    int number_of_hits;

};

#endif //UNTITLED3_FILE_H
