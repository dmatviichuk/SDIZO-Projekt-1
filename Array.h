#ifndef SDIZO_PROJEKT_1_ARRAY_H
#define SDIZO_PROJEKT_1_ARRAY_H

class Array {

public:

    int *PointerOnHead;
    int sizeArray;

    Array();
    ~Array();

    void addBeggining(int value);
    void addEnd(int value);
    void addAnywhere(int value, int position);
    void deleteFirst();
    void deleteLast();
    void deleteAny(int position);
    bool checkExists(int value);
    void printArray();
};

#endif //SDIZO_PROJEKT_1_ARRAY_H
