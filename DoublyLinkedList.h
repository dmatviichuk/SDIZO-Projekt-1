#ifndef SDIZO_PROJEKT_1_DOUBLYLINKEDLIST_H
#define SDIZO_PROJEKT_1_DOUBLYLINKEDLIST_H

#include <iostream>
#include "ElementsDLL.h"
using namespace std;

class DoublyLinkedList {

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    int size;

    ElementsDLL *firstElement;
    ElementsDLL *lastElement;
    ElementsDLL *currentElement;

    void addBeggining(int value);
    void addAnywhere(int value, int position);
    void addEnd(int value);
    void deleteFirst();
    void deleteLast();
    void deleteAny(int);
    void printList();
    bool checkExists(int value);
};

#endif //SDIZO_PROJEKT_1_DOUBLYLINKEDLIST_H
