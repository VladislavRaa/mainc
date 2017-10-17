#include <iostream>
#include "cFile.h"

void show_input (cFile* file, int number_of_file) {
    for(int i = 0; i < number_of_file; i++) {
        file[i].show();
    }
}

void sort_by_name (cFile* file, int number_of_file) {
    cFile temp;
    for (int i = 0; i < number_of_file - 1; i++) {
        if(strcmp(file[i].get_file_name(),file[i+1].get_file_name()) == 1) {
            temp = file[i+1];
            file[i+1] = file[i];
            file[i] = temp;
        }
    }
    show_input(file, number_of_file);
}

void sort_by_hits (cFile* file, int number_of_file, int hits) {
    for(int i = 0; i < number_of_file; i++) {
        if (file[i].get_number_of_hits() > hits)
            file[i].show();

    }
}

void sort_by_size (cFile* file, int number_of_file, int size) {
    for(int i = 0; i < number_of_file; i++) {
        if (file[i].get_size_of_file() > size)
            file[i].show();
    }
}

int main() {

    int number_of_file = 0;
    char *name = new char[128];
    int size = 0;
    int date = 0;
    int hits = 0;

    cFile *file = new cFile [sizeof(cFile)];

    while (true) {
        std::cout << "ENTER the Name: " << std::endl;
        std::cin >> name;
        std::cout << "ENTER size, date in format: ddmmyyyy, hits: " << std::endl;
        std::cin >> size >> date >> hits;

        if (size < 0 || date < 0 || hits < 0) {
            std::cout << "wrong file" << std::endl;
            break;
        }

        file[number_of_file].set(name, size, date, hits);
        number_of_file++;
    }

    show_input (file, number_of_file);

    std::cout << "function_sort_by_name: " << std::endl;
    sort_by_name(file, number_of_file );

    int input_hits;
    std::cout << "ENTER number of hits: " << std::endl;
    std::cin >> input_hits;
    sort_by_hits (file, number_of_file, input_hits);

    int input_size;
    std::cout << "ENTER size: " << std::endl;
    std::cin >> input_size;
    sort_by_size (file, number_of_file, input_size);

    delete [] name;
    delete [] file;

    return 0;
}