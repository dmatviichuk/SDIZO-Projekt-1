#include "ElementsDLL.h"
ElementsDLL::ElementsDLL(int value, ElementsDLL *next, ElementsDLL *previous) {

    ElementsDLL::value = value;
    ElementsDLL::next = next;
    ElementsDLL::previous = previous;

}