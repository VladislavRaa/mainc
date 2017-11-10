//
// Created by Vladislav Raspopin on 21.10.17.
//
#include "Stack.h"

Stack::Stack () {
    head = 0;
    size = 0;
}

Stack::Stack (const Stack& stack) {
    head = 0;
    *this = stack;
}

Stack* Stack::push (const char* data) {
    listitem* item = new listitem;
    item->data = new char [strlen(data) + 1];
    strcpy(item->data, data);
    item->next = head;
    head = item;
    size++;
    return this;
}

Stack& Stack::clear () {

    while (head) {
        listitem* temp = head->next;
        delete head;
        head = temp;
    }
    return *this;
}

char* Stack::pop () {

    if (empty ()) {
        return NULL;
    }

    listitem* old = head;
    head = head->next;
    char *data = old->data;
    delete old;
    size--;
    return data;
}


Stack& Stack::operator = (const Stack& stack) {

    if (this == &stack) return *this;

    clear();

    if (!stack.empty()) {
        head = new listitem;
        listitem* cur = head;
        listitem* src = stack.head;

        while (src) {
            cur->data = src->data;
            if (src->next) {
                cur->next = new listitem;
                cur = cur->next;
            } else
                cur->next = 0;
            src = src->next;
        }
    }
    return *this;
}

int Stack::retutn_size() {
    return size;
}

std::ostream& operator << (std::ostream& s, const Stack& stack) {
    listitem* item = stack.head;
    while(item) {
        s << item->data << std::endl;
        item = item->next;
    }
    return s;
}
