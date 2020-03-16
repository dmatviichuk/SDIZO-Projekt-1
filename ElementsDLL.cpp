//
// Created by asus on 15/03/2020.
//

#include "ElementsDLL.h"
ElementsDLL::ElementsDLL(int value, ElementsDLL *next, ElementsDLL *previous) {

    ElementsDLL::value = value;
    ElementsDLL::next = next;
    ElementsDLL::previous = previous;

}