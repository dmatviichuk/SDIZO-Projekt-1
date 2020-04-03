#include <iostream>
#include "Test.h"
#include "RandomInputDataGenerator.h"
using namespace std;

int main() {
    Test test;
    RandomInputDataGenerator generator;
    int input = 9;

    cout << "SDIZO-Projekt-1, Dmytro Matviichuk 240545" << endl << endl;

    while (input != 0) {
        cout << "Wybierz test lub wygeneruj liczby:" << endl;
        cout << "    1. Generacja liczb" << endl;
        cout << "    2. Tablica Dynamiczna" << endl;
        cout << "    3. Lista" << endl;
        cout << "    4. Kopiec Binarny" << endl;
        cout << "    5. Binarne drzewo poszukiwań" << endl;
        cout << "    6. Autor oraz Instukcja" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Zamykamy gdy input==0
        if (input == 0) return 0;

        switch (input) {
            default:
                cout << "Zły wybór!" << endl;
                break;
            case 0:
                break;
            case 1:
                generator.Generator();
                cout << "Generacja liczb do pliku tekstowego:" << endl;
                break;
            case 2:
                cout << "Początek testu tablicy dynamicznej:" << endl;
                test.testArray();
                break;
            case 3:
                cout << "Początek testu listy:" << endl;
               test.testDoublyLinkedList();
                break;
            case 4:
                cout << "Początek testu kopca binarnego:" << endl;
                test.testHeap();
                break;
            case 5:
                cout << "Początek testu binarne drzewa poszukiwań:" << endl;
                test.testBST();
                break;
            case 6:
                cout << "                        SDIZO-Projekt-1" << endl;
                cout << "                Autor: Dmytro Matviichuk 240545" << endl;
                cout << "Instukcja: Proszę wpisać nazwę pliku tekstowgo bez .txt (program to zrobi samodzielnie)" << endl << endl << endl;
                break;

        }
    }
    return 0;
}