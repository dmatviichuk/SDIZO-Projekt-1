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

    //Zaalokuj pamięć na tablicę większa o jeden element niż poprzednio
    //Przypisz podaną wartość jako pierwszy element tablicy
    int *newPointerOnHead = new int[sizeArray + 1];
    newPointerOnHead[0] = value;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < sizeArray; i++) {
        newPointerOnHead[i + 1] = PointerOnHead[i];
    }

    //Zwolnij pamięć poprzedniej tablicy
    //Zastąp wskaźnik na głowę tablicy nowym
    delete PointerOnHead;
    PointerOnHead= newPointerOnHead;

    //Zwiększamy rozmiar tablicy o 1
    sizeArray++;

}

void Array::addEnd(int value) {

    //Zaalokuj pamięć na tablicę większa o jeden element niż poprzednio
    //Przypisz podaną wartość jako ostatni element tablicy
    int *newPointerOnHead = new int[sizeArray + 1];
    newPointerOnHead[sizeArray] = value;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < sizeArray; i++) {
        newPointerOnHead[i] = PointerOnHead[i];
    }

    //Zwolnij pamięć poprzedniej tablicy
    //Zastąp wskaźnik na głowę tablicy nowym
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

        //Zaalokuj pamięć na tablicę większa o jeden element niż poprzednio
        //Przypisz podaną wartość jako element tablicy na wybranej pozycji
        int *newPointerOnHead = new int[sizeArray + 1];
        newPointerOnHead[position] = value;

        //Przepisz dane ze starej tablicy do nowej
        //Przerwij przed wybraną pozycją
        for (int i = 0; i < position; i++) {
            newPointerOnHead[i] = PointerOnHead[i];
        }

        //Uzupełnij dane w tablicy po wybranej pozycji
        //Przepisz dane ze starej tablicy do nowej
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

        //Przepisz elementy starej tablicy poza ostatnim
        for (int i = 0; i < sizeArray - 1; i++) {
            newPointerOnHead[i] = PointerOnHead[i];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
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
        //Zaalokuj pamięć na tablicę mniejszą o jeden element niż poprzednio
        int *newPointerOnHead = new int[sizeArray - 1];

        //Przepisz elementy starej tablicy poza pierwszym
        for (int i = 0; i < sizeArray - 1; i++) {
            newPointerOnHead[i] = PointerOnHead[i + 1];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
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
        //Zaalokuj pamięć na tablicę mniejszą o jeden element niż poprzednio
        int *newPointerOnHead = new int[sizeArray - 1];

        //Przepisz elementy do wybranej pozycji
        for (int i = 0; i < position; i++) {
            newPointerOnHead[i] = PointerOnHead[i];
        }

        //Przepisz elementy po wybranej pozycji
        for (int i = position; i < sizeArray - 1; i++) {
            newPointerOnHead[i] = PointerOnHead[i + 1];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
        delete[] PointerOnHead;
         PointerOnHead= newPointerOnHead;

        //Zmniejszamy rozmiar tablicy o 1
        sizeArray--;
    } else {
        cout << "W tablicy nie istnieje [" << position << "] pozycji!" << endl;
    }


}

bool Array::checkExists(int value) {
    //Przeszukaj tablicę pod kątem wartości
    for (int i = 0; i < sizeArray; i++) {
        //Jeżeli wartość wystąpi w iteracji zwróc true
        if (PointerOnHead[i] == value) {
            cout << "Szukana wartość zajmuje w tablicy pozycję [" << i << "]" << endl;
            return true;
        }
    }
    //Jeżeli wartość nie wystąpuje w żadnej iteracji tabeli zwróć false
    cout << "Wartość nie występuje w tablicy" << endl;
    return false;
}

void Array::printArray() {
    cout << "Aktualny stan tablicy:" << endl;
    //Jeżeli Array nie ma elementów, wyświetl komunikat
    //W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
    if  (PointerOnHead != NULL) {
        for (int i = 0; i < sizeArray; i++) {
            cout << "    [" << i << "] " << PointerOnHead[i] << endl;
        }
    } else {
        cout << "Tablica nie ma żadnych elementów!" << endl;
    }
}
