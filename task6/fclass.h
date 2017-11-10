//
// Created by Vladislav Raspopin on 30.10.17.
//
#ifndef UNTITLED_FCLASS_H
#define UNTITLED_FCLASS_H

#include <iostream>

class fclass {

public:
    virtual void set_file_name (const char* file_name) = 0;
    virtual void massage() const = 0;
    ~fclass();

    friend std::ostream& operator << (std::ostream& , const fclass& );
    virtual void Print(std::ostream& out) const = 0;



};

#endif //UNTITLED_FCLASS_H
