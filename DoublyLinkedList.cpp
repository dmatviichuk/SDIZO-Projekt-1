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
        //Ustaw element ktory był pierwszym jako aktualny
        currentElement = firstElement;
        //Zastąp pierwszy element newm
        //Ustaw jego wartość oraz element kolejny na element aktualny (były pierwszy)
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
        //Zastąp ostatni element newm
        //Ustaw jego wartość oraz element previous na element aktualny (były ostatni)
        lastElement = new ElementsDLL(value, NULL, currentElement);
        currentElement->next = lastElement;
    }
    //Zwiększamy rozmiar listy
    size++;
}

void DoublyLinkedList::addAnywhere(int value, int position) {

    //Sprawdź czy w liście istnieje position podana przez użytkownika
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

    //Sprawdź w której połowie listy znajduje się wybrany element
    if (position < size / 2) {
        //liczone od indeksu zerowego
        //Przypisz za aktualny element pierwszy
        currentElement = firstElement;

        //Przesuwamy wszyskie elementy o jeden
        for (int i = 1; i < position - 1; ++i) {
            currentElement = currentElement->next;
        }

    } else {

        //Przypisz za aktualny element ostatni
        currentElement = lastElement;

        //Przesuwamy wszyskie elementy o jeden
        for (int i = 0; i < DoublyLinkedList::size - position - 1; ++i) {
            currentElement = currentElement->previous;
        }

    }

    //Stwórz new element listy z podanymi parametrami
    ElementsDLL *newElementsDLL = new ElementsDLL(value, currentElement, currentElement->next);

    //przypisz new element w odpowiednim miejscu tablicy
    currentElement->next->previous = newElementsDLL;
    currentElement->next = newElementsDLL;

    //Zwiększamy rozmiar listy
    size = size + 1;
}

void DoublyLinkedList::deleteFirst() {

    //przypisz drugi element jako aktualny
    currentElement = firstElement->next;

    //Usuwamy pierwszy element
    delete firstElement;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny element jako pierwszy
    //Jeżeli nie, wyzeruj elementy listy
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

    //Przypisz przedostani element jako aktualny
    currentElement = lastElement->previous;
    //Usuń ostatni element
    delete lastElement;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny element jako ostatni
    //Jeżeli nie, wyzeruj elementy listy
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

    //Sprawdź w której połowie listy znajduje się wybrany element
    if (position < size / 2) {

        //Przypisz za aktualny element pierwszy
        currentElement = firstElement;

        //Przesuwamy wszyskie elementy o jeden
        for (int i = 1; i < position - 1; ++i) {
            currentElement = currentElement->next;
        }

    } else {

        //Przypisz za aktualny element ostatni
        currentElement = lastElement;

        //Przesuwamy wszyskie elementy o jeden
        for (int i = 0; i < size - position - 1; ++i) {
            currentElement = currentElement->previous;
        }

    }

    //Stwórz new element listy z podanymi parametrami

    ElementsDLL *newElementsDLL = currentElement->next;

    //przypisz new element w odpowiednim miejscu tablicy
    currentElement->next = newElementsDLL->next;
    currentElement->next->previous = newElementsDLL;

    delete[]newElementsDLL;

    //Zmniejszamy rozmiar listy
    size--;

}

bool DoublyLinkedList::checkExists(int value) {

    //Jeżeli DoublyLinkedList jest pusta, zwróć false z automatu
    if (size == 0) {
        return false;

    }

    //Przypisa pierwszy element jako aktualny
    currentElement = firstElement;

    //Przeszukaj listę pod kątem wartości
    for (int i = 0; i < size; i++) {
        if (currentElement->value == value) {
            cout << "Szukana wartość zajmuje w liście pozycję [" << i << "]" << endl;
            return true;
        }

        currentElement = currentElement->next;
    }

    //Jeżeli wartość nie wystąpiła w żadnej iteracji listy zwróć false
    cout << "Szukana wartość nie występuje w liście" << endl;
    return false;
}

void DoublyLinkedList::printList() {

    //Ustaw jako akutualny element pierwszy element listy
    currentElement = firstElement;

    for (int i = 0; i < size; i++) {

        cout << "[" << i << "] " << currentElement->value << endl;

        //Przypisz kolejny element listy jako aktualny
        currentElement = currentElement->next;

    }

}