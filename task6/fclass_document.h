//
// Created by Vladislav Raspopin on 31.10.17.
//

#ifndef UNTITLED_FCLASS_DOCUMENT_H
#define UNTITLED_FCLASS_DOCUMENT_H

#include "fclass.h"

class fclass_document: public fclass{
public:
    explicit fclass_document (char* file_name);
    void set_file_name (const char* file_name) ;
    char *new_file_name(const char *str);
    void Print(std::ostream& out) const;
    void massage() const ;

    ~fclass_document();

private:
    char* file_name;
};


#endif //UNTITLED_FCLASS_DOCUMENT_H
