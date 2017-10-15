#include <iostream>
#include "cFile.h"

void sort_by_name (cFile* file, int number_of_file) {
    cFile temp;
    for (int i = 0; i < number_of_file - 1; i++) {
        if(strcmp(file[i].get_file_name(),file[i+1].get_file_name()) == 1) {
            temp = file[i+1];
            file[i+1] = file[i];
            file[i] = temp;
        }
    }
}

void sort_by_hits (cFile* file, int number_of_file, int hits) {
    for(int i = 0; i < number_of_file; i++) {
        if (file[i].get_number_of_hits() > hits)
            file[i].show();

    }
}

void sort_by_date (cFile* file, int number_of_file, int date) {
    for(int i = 0; i < number_of_file; i++) {
        if (file[i].get_date_of_creation() > number_of_file)
            file[i].show();

    }
}

int main() {



    char str[]="big bag";
    char * name = str;
    int size = 11;
    int date = 22;
    int hits = 33;
    int number_of_file = 3;


   // cFile *file = new cFile (name, size, date, hits);

     cFile *file = new cFile [sizeof(cFile)];

    file[0].set(name, size, date, hits);

    std::cout << "----file0----" << std::endl;


    char str1 [] ="apple bag";
    name = str1;
    size = 44;
    date = 55;
    hits = 66;

    file[1].set(name, size, date, hits);
    std::cout << "----file1----" << std::endl;



    char str2 [] ="clion bag";
    name = str2;
    size = 77;
    date = 88;
    hits = 99;

    file[2].set(name, size, date, hits);

    std::cout << "----file2----" << std::endl;


    for(int i = 0; i < 3; i++){
        file[i].show();
    }


    sort_by_name(file, 3);

    std::cout << "----sort----" << std::endl;

    for(int i = 0; i < 3; i++){
        file[i].show();
    }

    sort_by_hits (file, number_of_file, 65);
    sort_by_date (file, number_of_file,  67);

    delete [] file;


    return 0;
}