#ifndef SDIZO_PROJEKT_1_ELEMENTSDLL_H
#define SDIZO_PROJEKT_1_ELEMENTSDLL_H

class ElementsDLL {

public:
    ElementsDLL *next;
    ElementsDLL *previous;
    int value;

    ElementsDLL(int, ElementsDLL *, ElementsDLL *);
};

#endif //SDIZO_PROJEKT_1_ELEMENTSDLL_H
