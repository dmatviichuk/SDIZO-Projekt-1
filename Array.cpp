#include <iostream>
#include "Array.h"
using namespace std;

//Konstruktor
Array::Array() {

    Array: PointerOnHead = NULL;
    Array::sizeArray = 0;

}
//Destruktor
Array::~Array() {

    if  (PointerOnHead != NULL) {
        delete[]PointerOnHead;
    }
}

void Array::addBeggining(int value) {
    int *newPointerOnHead = new int[sizeArray + 1];
    newPointerOnHead[0] = value;
    //Przepisujemy dane ze starej tablicy do nowej
    for (int i = 0; i < sizeArray; i++) {
        newPointerOnHead[i + 1] = PointerOnHead[i];
    }
    delete PointerOnHead;
    PointerOnHead= newPointerOnHead;
    //Zwiększamy rozmiar tablicy o 1
    sizeArray++;

}

void Array::addEnd(int value) {
    int *newPointerOnHead = new int[sizeArray + 1];
    newPointerOnHead[sizeArray] = value;

    for (int i = 0; i < sizeArray; i++) {
        newPointerOnHead[i] = PointerOnHead[i];
    }
    delete PointerOnHead;
    PointerOnHead= newPointerOnHead;

    //Zwiększamy rozmiar tablicy o 1
    sizeArray++;

}

void Array::addAnywhere(int value, int position) {
    //Sprawdzamy czy istnieje wybrana pozycja w tablicy, jeżeli nie to nie dodajemy liczbę
    if (position < 0 || position > sizeArray) {
        cout << "W tablicy nie istnieje [" << position << "] pozycji!" << endl;
    } else {
        //Przepisujemy podaną wartość jako element tablicy na wybranej pozycji
        int *newPointerOnHead = new int[sizeArray + 1];
        newPointerOnHead[position] = value;

        //Przepisujemy dane ze starej tablicy do nowej
        //Przerwamy(break) przed wybraną pozycją
        for (int i = 0; i < position; i++) {
            newPointerOnHead[i] = PointerOnHead[i];
        }
        //Uzupełniamy dane w tablicy
        //Przepisujemy dane ze starej tablicy do nowej
        for (int i = position; i < sizeArray; i++) {
            newPointerOnHead[i + 1] = PointerOnHead[i];
        }

        //Zwolnij pamięć poprzedniej tablicy
        //Zastąp wskaźnik na głowę tablicy nowym
        delete PointerOnHead;
         PointerOnHead= newPointerOnHead;

        //Zwiększamy rozmiar tablicy o 1
        sizeArray++;

    }
}

void Array::deleteLast() {
    //Sprawdzamy czy tablica nie jest pusta
    if (sizeArray > 0) {
        int *newPointerOnHead = new int[sizeArray - 1];

        //Przepisujemy elementy starej tablicy poza ostatnim
        for (int i = 0; i < sizeArray - 1; i++) {
            newPointerOnHead[i] = PointerOnHead[i];
        }
        //Przepisujemy nowy wskaźnik na jego miejsce
        delete[] PointerOnHead;
         PointerOnHead= newPointerOnHead;

        //Zmniejszamy rozmiar tablicy o 1
        sizeArray--;
    } else {
        cout << "W tablicy nie ma elementów!" << endl;
    }
}

void Array::deleteFirst() {

    //Sprawdzamy czy tablica nie jest pusta
    if (sizeArray > 0) {
        int *newPointerOnHead = new int[sizeArray - 1];
        //Przepisujemy elementy starej tablicy poza pierwszym
        for (int i = 0; i < sizeArray - 1; i++) {
            newPointerOnHead[i] = PointerOnHead[i + 1];
        }
        delete[] PointerOnHead;
         PointerOnHead= newPointerOnHead;
        //Zmniejszamy rozmiar tablicy o 1
        sizeArray--;
    } else {
        cout << "W tablicy nie ma elementów!" << endl;
    }

}

void Array::deleteAny(int position) {

    //Sprawdzamy czy tablica nie jest pusta
    if (sizeArray > 0 || position > 0 || position < sizeArray) {
        int *newPointerOnHead = new int[sizeArray - 1];
        //Przepisujemy elementy do wybranej pozycji
        for (int i = 0; i < position; i++) {
            newPointerOnHead[i] = PointerOnHead[i];
        }
        //Przepisujemy elementy
        for (int i = position; i < sizeArray - 1; i++) {
            newPointerOnHead[i] = PointerOnHead[i + 1];
        }
        delete[] PointerOnHead;
         PointerOnHead= newPointerOnHead;
        //Zmniejszamy rozmiar tablicy o 1
        sizeArray--;
    } else {
        cout << "W tablicy nie istnieje [" << position << "] pozycji!" << endl;
    }


}

bool Array::checkExists(int value) {
    for (int i = 0; i < sizeArray; i++) {
        if (PointerOnHead[i] == value) {
            cout << "Szukana wartość zajmuje w tablicy pozycję [" << i << "]" << endl;
            return true;
        }
    }
    //Wartość nie wystąpuje > false
    cout << "Wartość nie występuje w tablicy" << endl;
    return false;
}

void Array::printArray() {
    cout << "Aktualny stan tablicy:" << endl;
    //Jeżeli tablica nie ma elementów, wyświetlamy komunikat że nie ma elementów lub drukujemy wszystkie elementy tablicy
    if  (PointerOnHead != NULL) {
        for (int i = 0; i < sizeArray; i++) {
            cout << "    [" << i << "] " << PointerOnHead[i] << endl;
        }
    } else {
        cout << "Tablica nie ma żadnych elementów!" << endl;
    }
}
