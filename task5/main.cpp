#include <iostream>
#include "Stack.h"

int main() {

    char *name = new char[128];
    Stack *stack = new Stack [sizeof(Stack)];

    stack[1].push("a");
    stack[1].push("b");
    stack[1].push("c");

    std::cout << stack[1] << std::endl;
    std::cout << stack[1].retutn_size() << std::endl;

    stack[1].pop();

    std::cout << stack[1] << std::endl;
    std::cout << stack[1].retutn_size() << std::endl;

    std::cout << stack[1] << std::endl;

    std::cout << "----" << std::endl;



    delete [] name;
    delete [] stack;

    return 0;
}


