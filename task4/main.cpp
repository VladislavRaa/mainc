#include <iostream>
#include "Stack.h"

int main() {

    Stack stack;
    stack.push("fuck");
    stack.push("fuckkk");
    stack.push("fuckkk");

    stack.push("fuckkk");

    int i = 0;
    while (!stack.empty()) {

        stack.show();
        stack.pop();
        std::cout << i  << std::endl;
        i++;
    }


    return 0;
}