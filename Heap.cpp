#include "Heap.h"
#include <iostream>
#include "Heap.h"
using namespace std;

//Konstruktor
Heap::Heap() {
    Heap::array = NULL;
    Heap::size = 0;
}
//Destruktor
Heap::~Heap() {

    if (Heap::size > 0) {
        delete[]array;
    }

}

void Heap::add(int value) {

    //Wartości w kopcu nie mogą się powtarzać
    //Kontynuuj tylko, jeżeli wartość nie istnieje jeszcze w kopcu
    if (!Heap::checkExists(value)) {

        //Stwórz nową tablicę większą o jeden element
        int *newarray = new int[size + 1];

        //Przepisanie danych ze starej tablicy do nowej
        for (int i = 0; i < size; i++) {
            newarray[i] = array[i];
        }

        //Dodanie wybranej wartości do kopca
        newarray[size] = value;

        //Usuń starą tablicę
        delete[]array;

        //Zastąp starą tablicę nową
        array = newarray;

        //Popraw kolejność elementów w kopcu
        Heap::improveStructure();

        //Zwiększ size kopca
        size++;


    }

}

void Heap::del(int value) {

    //Iteracja po całej tablicy kopca w elu znalezienia wartości
    for (int i = 0; i < size; i++) {

        if (array[i] == value) {

            //Stwórz nową tablicę, pomniejszoną o jeden element
            int *newarray = new int[size - 1];

            //Przepisz elementy z tablicy do pozycji na której znajduje się usuwany element
            for (int k = 0; k < i; k++) {
                newarray[k] = array[k];
            }

            //Przepisz pozostałe elementy przesunięte o jedną pozycję
            for (int k = i + 1; k < size; k++) {
                newarray[k - 1] = array[k];
            }

            //usuń starą tablicę i przypisz na jej miejsce nową
            delete[]array;
            array = newarray;

            //Zmniejsz size tablicy
            size--;

            //Popraw kolejność elementów w tablicy kopca
            Heap::improveStructure();
            return;

        }

    }

}

bool Heap::checkExists(int value) {

    //Przeszukaj tablicę pod kątem wartości
    for (int i = 0; i < size; i++) {
        //Jeżeli wartość wystąpi w iteracji zwróc true
        if (array[i] == value) {
            cout << "Szukana wartość zajmuje w tablicy kopca pozycję [" << i << "]" << endl;
            return true;
        }

    }
    /*
    //Jeżeli wartość nie wystąpiła w żadnej iteracji tabeli zwróć false
    cout << "Szukana wartość nie występuje w kopcu" << endl;
    return false;
*/
}



void Heap::printHeap() {

    cout << "Tablica kopca:" << endl;
    if (array != NULL) {
        for (int i = 0; i < size; i++) {
            cout << "    [" << i << "] " << array[i] << endl;
        }
    } else {
        cout << " Kopiec nie ma żadnych elementów!" << endl;
    }
}

void Heap::printTreeHeap() {
    cout << "Drzewo kopca:" << endl;
}

void Heap::improveStructure() {
    int temp = 0;

    //Pętla która sortuje elementy kopca w odpowiedniej kolejności
    for (int i = size; 0 < i; i--) {
        if (array[i - 1] < array[i]) {
            temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
        }
    }
}