//
// Created by Vladislav Raspopin on 30.10.17.
//
#ifndef UNTITLED_FCLASS_IMAGE_H
#define UNTITLED_FCLASS_IMAGE_H

#include "fclass.h"
#include <iostream>

class fclass_image: public fclass {

public:
    explicit fclass_image (char* file_name);
    void massage() const ;
    void set_file_name (const char* file_name);
    char *new_file_name (const char *str);
    void Print (std::ostream& out) const;

    ~fclass_image();
private:
    char* file_name;
};


#endif //UNTITLED_FCLASS_IMAGE_H
