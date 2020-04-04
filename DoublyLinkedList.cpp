#include <iostream>
#include "DoublyLinkedList.h"
#include "ElementsDLL.h"
using namespace std;

//Konstruktor
DoublyLinkedList::DoublyLinkedList() {

    DoublyLinkedList::firstElement = NULL;
    DoublyLinkedList::currentElement = NULL;
    DoublyLinkedList::lastElement = NULL;
    DoublyLinkedList::size = 0;

}
//Destruktor
DoublyLinkedList::~DoublyLinkedList() {

    for (int i = 0; i < DoublyLinkedList::size; i++) {

        //Robimy kolejny element jako aktualny
        currentElement = firstElement->next;
        //Usuwamy pierwszy element
        delete firstElement;

        firstElement = currentElement;
    }
}

void DoublyLinkedList::addBeggining(int value) {

    //Sprawdzamy, czy istnieje pierwszy element
    if (firstElement == NULL) {
         //Tworzymy nowy element i robimy go jako element pierwszy i ostatni
        firstElement = new ElementsDLL(value, NULL, NULL);
        lastElement = firstElement;

    } else {
        //Robimy element pierwszy jako aktualny
        currentElement = firstElement;
        //Zamieniamy pierwszy element nowym
        firstElement = new ElementsDLL(value, currentElement, NULL);
        currentElement->previous = firstElement;
    }
    //Zwiększamy rozmiar listy
    size = size + 1;
}

void DoublyLinkedList::addEnd(int value) {
    //Sprawdzamy, czy istnieje pierwszy element
    if (firstElement == NULL) {
         //Tworzymy nowy element i robimy go jako element pierwszy i ostatni
        lastElement = new ElementsDLL(value, NULL, NULL);
        firstElement = lastElement;

    } else {
        //Ustaw element który był ostatnim jako aktualny
        currentElement = lastElement;
        //Zamieniamy pierwszy element nowym
        lastElement = new ElementsDLL(value, NULL, currentElement);
        currentElement->next = lastElement;
    }
    //Zwiększamy rozmiar listy
    size++;
}

void DoublyLinkedList::addAnywhere(int value, int position) {
    //Sprawdzamy czy w liście istnieje pozycja
    if (position < 0 || position > size) {
        cout << "W liście nie istnieje position [" << position << "]" << endl;
        return;
    }
   //Sprawdzamy czy pozycja jest pierwsza
    if (position == 0) {
        DoublyLinkedList::addBeggining(value);
        return;
    }
    //Sprawdzamy czy pozycja jest ostatnią
    if (position == size - 1) {
        addEnd(value);
        return;
    }
    //Sprawdzamy w której połowie listy znajduje się wybrany element
    if (position < size / 2) {
        //Przepisujemy za aktualny element pierwszy
        currentElement = firstElement;
        //Przesuwamy wszyskie elementy o jeden
        for (int i = 1; i < position - 1; ++i) {
            currentElement = currentElement->next;
        }

    } else {
        //Przepisujemy za aktualny element ostatni
        currentElement = lastElement;
        //Przesuwamy wszyskie elementy o jeden
        for (int i = 0; i < DoublyLinkedList::size - position - 1; ++i) {
            currentElement = currentElement->previous;
        }
    }
    //Robimy nowyelement listy z parametrami:
    ElementsDLL *newElementsDLL = new ElementsDLL(value, currentElement, currentElement->next);
    //Przepisujemy new element w odpowiednim miejscu tablicy
    currentElement->next->previous = newElementsDLL;
    currentElement->next = newElementsDLL;
    //Zwiększamy rozmiar listy
    size = size + 1;
}

void DoublyLinkedList::deleteFirst() {
    //Przepisujemy drugi element jako aktualny
    currentElement = firstElement->next;
    //Usuwamy pierwszy element
    delete firstElement;
    //Sprawdzamy, czy w liście są jeszcze jakieś elementy
    if (size > 1) {
        currentElement->previous = NULL;
        firstElement = currentElement;
    } else {
        currentElement = NULL;
        firstElement = NULL;
        lastElement = NULL;
    }
    //Zmniejszamy rozmiar listy
    size--;
}

void DoublyLinkedList::deleteLast() {
    //Przepisujemy przedostani element jako aktualny
    currentElement = lastElement->previous;
    //Usuwamy ostatni element
    delete lastElement;
    //Sprawdzamy, czy w liście są jakieś elementy
    if (size > 1) {
        currentElement->next = NULL;
        lastElement = currentElement;
    } else {
        currentElement = NULL;
        firstElement = NULL;
        lastElement = NULL;
    }
    //Zmniejszamy rozmiar listy
    size--;
}

void DoublyLinkedList::deleteAny(int position) {
    //Sprawdzamy czy w liście istnieje pozycja(gdy wpisujemy pozycję, ale mój program robi test automatyczny)
    if (position < 0 || position > size) {
        cout << "W liście nie istnieje[" << position << "] pozycji" << endl;
        return;
    }
    //Sprawdzamy czy pozycja jest pierwsza
    if (position == 0) {
        deleteFirst();
        return;
    }
    //Sprawdzamy czy pozycja jest ostatnią
    if (position == size - 1) {
        deleteLast();
        return;
    }
    //Sprawdzamy w której połowie listy znajduje się wybrany element
    if (position < size / 2) {
        //Przepisujemy za aktualny element pierwszy
        currentElement = firstElement;
        //Przesuwamy wszyskie elementy o jeden
        for (int i = 1; i < position - 1; ++i) {
            currentElement = currentElement->next;
        }
    } else {
        //Przepisujemy za aktualny element ostatni
        currentElement = lastElement;
        //Przesuwamy wszyskie elementy o jeden
        for (int i = 0; i < size - position - 1; ++i) {
            currentElement = currentElement->previous;
        }
    }
    //Stwórz new element listy z podanymi parametrami
    ElementsDLL *newElementsDLL = currentElement->next;
    //Przepisujemy new element w odpowiednim miejscu tablicy
    currentElement->next = newElementsDLL->next;
    currentElement->next->previous = newElementsDLL;
    delete[]newElementsDLL;
    //Zmniejszamy rozmiar listy
    size--;
}

bool DoublyLinkedList::checkExists(int value) {
    //Gdy lista jest pusta, zwracamy false
    if (size == 0) {
        return false;
    }
    //Robimy pierwszy element jako aktualny
    currentElement = firstElement;
    for (int i = 0; i < size; i++) {
        if (currentElement->value == value) {
            cout << "Szukana wartość zajmuje w liście pozycję [" << i << "]" << endl;
            return true;
        }
        currentElement = currentElement->next;
    }
    //Wartość nie wystąpuje > false
    cout << "Szukana wartość nie występuje w liście" << endl;
    return false;
}

void DoublyLinkedList::printList() {
    //Robimy akutualnym pierwszy element listy
    currentElement = firstElement;

    for (int i = 0; i < size; i++) {

        cout << "[" << i << "] " << currentElement->value << endl;
        //Robimy kolejny element listy jak aktualny
        currentElement = currentElement->next;

    }

}