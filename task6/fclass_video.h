//
// Created by Vladislav Raspopin on 31.10.17.
//

#ifndef UNTITLED_FCLASS_VIDEO_H
#define UNTITLED_FCLASS_VIDEO_H
#include "fclass.h"

class fclass_video: public fclass {
public:
    explicit fclass_video (char* file_name);
    void set_file_name (const char* file_name) ;
    char *new_file_name(const char *str);
    void Print(std::ostream& out) const;
    void massage() const ;

    ~fclass_video();

private:
    char* file_name;
};


#endif //UNTITLED_FCLASS_VIDEO_H
