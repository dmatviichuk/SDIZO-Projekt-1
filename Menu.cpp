#include <iostream>
#include "Test.h"
#include "RandomInputDataGenerator.h"
using namespace std;

int main() {
    Test test;
    RandomInputDataGenerator generator;
    int input = 100;

    cout << "SDIZO-Projekt-1, Dmytro Matviichuk 240545" << endl << endl;

    while (input != 0) {
        cout << "Wybierz test:" << endl;
        cout << "    1. Tablica Dynamiczna" << endl;
        cout << "    2. Lista" << endl;
        cout << "    3. Kopiec Binarny" << endl;
        cout << "    4. Generacja liczb" << endl;
        cout << "    5. Drzewo Czerowno-Czarne" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Zamknij, jeżeli wybrano 0
        if (input == 0) return 0;

        switch (input) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Rozpoczynam test tablicy dynamicznej..." << endl;
                test.testArray();

                break;

            case 2:
                cout << "Rozpoczynam test listy..." << endl;
               test.testDoublyLinkedList();
                break;

            case 3:
                cout << "Rozpoczynam test kopca binarnego..." << endl;
                test.testHeap();
                break;

            case 4:
                generator.Generator();
                cout << "Generacja liczb do pliku teksowego..." << endl;
                break;

            case 5:
                cout << "Rozpoczynam test drzewa..." << endl;
               // test.testBinarySearchTree();
                break;

        }
    }
    return 0;
}