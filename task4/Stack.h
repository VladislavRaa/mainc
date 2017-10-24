//
// Created by Vladislav Raspopin on 21.10.17.
//
#include <iostream>

#ifndef UNTITLED4_STACK_H
#define UNTITLED4_STACK_H

struct listitem
{
    char* data;
    listitem* next;
};

class Stack {

public:
    Stack();
    Stack(const Stack&);
    ~Stack() {clear();};
    Stack* push(const char* data);
    Stack& clear();
    char* pop();
    const char* see() const; // посмотреть элемент в вершине стека
    Stack& operator = (const Stack& stack);
    bool empty() const { return head==0; }
    void show();
    friend std::ostream& operator << (std::ostream&, const Stack&);

private:
    listitem* head;
};


#endif //UNTITLED4_STACK_H
