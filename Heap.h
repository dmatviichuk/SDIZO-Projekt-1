#ifndef SDIZO_PROJEKT_1_HEAP_H
#define SDIZO_PROJEKT_1_HEAP_H

class Heap {

public:
    int *array;
    unsigned int size;

    Heap();
    ~Heap();

    void add(int);
    void del(int);
    bool checkExists(int);
    void printHeap();
    void improveStructure();
    int levelNumbers();
};

#endif //SDIZO_PROJEKT_1_HEAP_H
