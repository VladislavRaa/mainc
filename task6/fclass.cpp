//
// Created by Vladislav Raspopin on 30.10.17.
//

#include "fclass.h"

fclass::~fclass(){};

std::ostream& operator << (std::ostream& out, const fclass& base)
{
    base.Print(out);
    return out;
}
