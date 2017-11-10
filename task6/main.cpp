#include <iostream>

#include "fclass_image.h"
#include "fclass_video.h"
#include "fclass_document.h"

int main() {

    fclass* file[4];
    char name[] = "apple";
    file[0] = new fclass_image(name);

    char name1 [] = "test";
    file[1] = new fclass_video(name1);

    char name2 [] = "computer";
    file[2] = new fclass_document(name2);

    char name3 [] = "good";
    file[3] = new fclass_video(name3);


    std::cout << t;

    for (int i = 0; i < 4; i++) {
        file[i]->massage();
        std::cout << *file[i] << std::endl;

    }




    return 0;
}