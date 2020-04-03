#include <iostream>
#include <fstream>
#include "Test.h"
#include "Time.h"
#include "Array.h"
#include "DoublyLinkedList.h"
#include "Heap.h"
#include "BinarySearchTree.h"

using namespace std;


void Test::testArray() {
    srand(time(NULL));
    Time time;
    Array array;
    int input = 10;
    int value;

    string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;

    while (input != 0) {
        cout << "Wybierz funkcję tablicy, żeby zmierzyć czas wykonania operacji:" << endl;
        cout << "    1. Dodaj na początek tablicy" << endl;
        cout << "    2. Dodaj na koniec tablicy" << endl;
        cout << "    3. Dodaj w dowolnym miejscu tablicy" << endl;
        cout << "    4. Usuń pierwszy element z tablicy" << endl;
        cout << "    5. Usuń ostatni element z tablicy" << endl;
        cout << "    6. Usuń dowolny element z tablicy" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablicę" << endl;
        cout << "    0. Wyjście do menu głownego" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Wyjście do menu gdy input==0
        if (input == 0) return;

        cout << "Plik z danymi wejściowymi: ";
        cin >> inputData;
        cout << "Plik z wynikami testu: ";
        cin >> outputData;

        //Otwieramy pliki
        inputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + inputData + ".txt");
        outputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/OutputData/Array/" + outputData + ".txt", fstream::out);

        //Sprawdzamy czy plik został otwarty poprawnie
        if (inputFile.is_open()) {
            cout << "Otwarto plik " << inputData + ".txt" << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (outputFile.is_open()) {
            cout << "Otwarto plik " << outputData + ".txt" << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (input) {
            default:
                cout << "Zły wybór" << endl;
                break;

            case 0:
                return;

            case 1:
                cout << "Początek testu:" << endl;
                while (inputFile.good()) {
                    //Wczytujemy wartość z pliku
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    array.addBeggining(value);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 2:
                cout << "Początek testu:" << endl;

                while (inputFile.good()) {
                    //Wczytujemy wartość z pliku
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    array.addEnd(value);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 3:
                cout << "Początek testu:" << endl;

                while (inputFile.good()) {
                    //Wczytujemy wartość z pliku
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    array.addAnywhere(value, rand() % array.sizeArray);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 4:
                cout << "Początek testu:" << endl;

                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    array.addBeggining(value);
                }
                while (array.sizeArray != 0) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    array.deleteFirst();
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 5:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    array.addBeggining(value);
                }
                while (array.sizeArray != 0) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    array.deleteLast();
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 6:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    array.addBeggining(value);
                }
                while (array.sizeArray != 0) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    array.deleteAny(rand() % array.sizeArray);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 7:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    array.addBeggining(value);
                }

                for (int i = 0; i < array.sizeArray; i++) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    array.checkExists(rand() % 2000000 - 1000000);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 8:
                time.TimeStart();
                array.printArray();
                time.TimeEnd();
                cout << "Czas wykonania: " << time.TimeExecution() << "ms" << endl;
                break;
        }

    }
}

void Test::testDoublyLinkedList() {
    srand(time(NULL));
    Time time;
    DoublyLinkedList list;
    int input = 10;
    int value;
    string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;

    while (input != 0) {
        cout << "Wybierz funkcję listy, żeby zmierzyć czas wykonania operacji:" << endl;
        cout << "    1. Dodaj na początek listy" << endl;
        cout << "    2. Dodaj na koniec listy" << endl;
        cout << "    3. Dodaj w dowolnym miejscu listy" << endl;
        cout << "    4. Usuń pierwszy element z listy" << endl;
        cout << "    5. Usuń ostatni element z listy" << endl;
        cout << "    6. Usuń dowolny element z listy" << endl;
        cout << "    7. Wyszukaj element na liście" << endl;
        cout << "    8. Wydrukuj listę" << endl;
        cout << "    0. Wyjście do menu głownego" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Wyjście do menu gdy input==0
        if (input == 0) return;

        cout << "Plik z danymi wejściowymi: ";
        cin >> inputData;
        cout << "Plik z wynikami testu: ";
        cin >> outputData;

        //Otwieramy pliki
        inputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + inputData + ".txt");
        outputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/OutputData/DoublyLinkedList/" + outputData + ".txt", fstream::out);
        //Sprawdzamy czy plik został otwarty poprawnie
        if (inputFile.is_open()) {
            cout << "Otwarto plik " << inputData + ".txt" << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (outputFile.is_open()) {
            cout << "Otwarto plik " << outputData + ".txt" << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (input) {
            default:
                cout << "Zły wybór" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    //Wczytujemy wartość z pliku
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    list.addBeggining(value);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 2:
                while (inputFile.good()) {
                    //Wczytujemy wartość z pliku
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    list.addEnd(value);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 3:
                while (inputFile.good()) {
                    //Wczytujemy wartość z pliku
                    inputFile >> value;

                    if (list.size == 0) {
                        time.TimeStart();
                        list.addAnywhere(value, 0);
                        time.TimeEnd();
                    } else {
                        time.TimeStart();
                        list.addAnywhere(value, 1);
                        time.TimeEnd();
                    }
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 4:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    list.addBeggining(value);
                }
                while (list.size != 0) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    list.deleteFirst();
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 5:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    list.addBeggining(value);
                }
                while (list.size != 0) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    list.deleteLast();
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 6:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    list.addBeggining(value);
                }
                while (list.size != 0) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    list.deleteAny(rand() % list.size);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 7:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    list.addBeggining(value);
                }

                for (int i = 0; i < list.size; i++) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    list.checkExists(rand() % 2000000 - 1000000);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 8:
                time.TimeStart();
                list.printList();
                time.TimeEnd();
                cout << "Czas wykonania: " << time.TimeExecution() << "ms" << endl;
                break;

        }

    }
}

void Test::testHeap() {
    srand(time(NULL));
    Time time;
    Heap heap;
    int input = 10;
    int value;
    string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;

    while (input != 0) {
        cout << "Wybierz funkcję kopca, żeby zmierzyć czas wykonania operacji:" << endl;
        cout << "    1. Dodaj element do kopca" << endl;
        cout << "    2. Usuń element z kopca" << endl;
        cout << "    3. Wyszukaj element" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    5. Wydrukuj drzewo kopca" << endl;
        cout << "    0. Wyjście do menu głownego" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Wyjście do menu gdy input==0
        if (input == 0) return;

        cout << "Plik z danymi wejściowymi: ";
        cin >> inputData;
        cout << "Plik z wynikami testu: ";
        cin >> outputData;

        //Otwieramy pliki
        inputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + inputData + ".txt");
        outputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/OutputData/Heap/" + outputData + ".txt", fstream::out);
        //Sprawdzamy czy plik został otwarty poprawnie
        if (inputFile.is_open()) {
            cout << "Otwarto plik " << inputData + ".txt" << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (outputFile.is_open()) {
            cout << "Otwarto plik " << outputData + ".txt" << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (input) {
            default:
                cout << "Zły wybór" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    //Wczytujemy wartość z pliku
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    heap.add(value);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 2:


                while (inputFile.good()) {
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    heap.del(value);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 3:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    heap.add(value);
                }

                for (int i = 0; i < heap.size; i++) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    heap.checkExists(rand() % 2000000 - 1000000);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 4:
                time.TimeStart();
                heap.printHeap();
                time.TimeEnd();
                cout << "Czas wykonania: " << time.TimeExecution() << "ms" << endl;
                break;
            case 5:
                time.TimeStart();
                heap.printTreeHeap();
                time.TimeEnd();
                cout << "Czas wykonania: " << time.TimeExecution() << "ms" << endl;
                break;
        }

    }
}

void Test::testBST() {
    srand(time(NULL));
    Time time;
    BinarySearchTree binarysearchtree;
    int input = 10;
    int value, k;
    string sp;
    string sn;
    Node * root, * node;
    string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;

    while (input != 0) {
        cout << "Wybierz funkcję BST, żeby zmierzyć czas wykonania operacji:" << endl;
        cout << "    1. Dodaj element do BST" << endl;
        cout << "    2. Usuń element z BST" << endl;
        cout << "    3. Wyszukaj element w BST" << endl;
        cout << "    4. Wydrukuj BST" << endl;
        cout << "    0. Wyjście do menu głownego" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

       //Wyjście do menu gdy input==0
        if (input == 0) return;

        cout << "Plik z danymi wejściowymi: ";
        cin >> inputData;
        cout << "Plik z wynikami testu: ";
        cin >> outputData;

        //Otwieramy pliki
        inputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + inputData + ".txt");
        outputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/OutputData/BinarySearchTree/" + outputData + ".txt", fstream::out);
        //Sprawdzamy czy plik został otwarty poprawnie
        if (inputFile.is_open()) {
            cout << "Otwarto plik " << inputData + ".txt" << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (outputFile.is_open()) {
            cout << "Otwarto plik " << outputData + ".txt" << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (input) {
            default:
                cout << "Zły wybór" << endl;
                break;

            case 0:
                break;
            case 1:
                while (inputFile.good()) {
                    //Wczytujemy wartość z pliku
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    binarysearchtree.addValue(value);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 2:
                while (inputFile.good()) {
                    inputFile >> value;
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    binarysearchtree.deleteValue(value);
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }
                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 3:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    binarysearchtree.findValue(node, value);
                }

                for (int i = 0; i < binarysearchtree.size; i++) {
                    //Funkcja z pomiarem czasu
                    time.TimeStart();
                    time.TimeEnd();
                    //Zapis do pliku wyniki pomiaru
                    cout << time.TimeExecution() << " ms" << endl;
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamykamy pliki
                inputFile.close();
                outputFile.close();
                break;

            case 4:
                time.TimeStart();
                binarysearchtree.printBST("", "", binarysearchtree.root); // wyświetlamy drzewo
                time.TimeEnd();
                cout << "Czas wykonania: " << time.TimeExecution() << "ms" << endl;
                break;
        }

    }
}
