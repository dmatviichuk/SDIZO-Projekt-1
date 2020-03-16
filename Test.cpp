#include <iostream>
#include <fstream>
#include "Test.h"
#include "Time.h"
#include "Array.h"
#include "DoublyLinkedList.h"
#include "Heap.h"

using namespace std;



void Test::testArray() {
    srand(time(NULL));
    Time time;
    Array array;
    int input = 99;
    int value;
    int position;


    string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;

    while (input != 0) {
        cout << "Wybierz funkcję tablicy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablicę" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Zamknij, jeżeli wybrano 0
        if (input == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> inputData;
        cout << "Plik z wynikami testu: ";
        cin >> outputData;

        //Otwórz pliki
        inputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + inputData + ".txt");
        outputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/OutputData/Array/" + outputData + ".txt", fstream::out);

        //Sprawdż czy plik jest otwarty poprawnie
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
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                return;

            case 1:
                cout << "Rozpoczynam test...";
                while (inputFile.good()) {
                    //Wczytaj wartość z pliku
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    array.addBeggining(value);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 2:
                cout << "Rozpoczynam test...";

                while (inputFile.good()) {
                    //Wczytaj wartość z pliku
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    array.addEnd(value);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 3:
                cout << "Rozpoczynam test...";

                while (inputFile.good()) {
                    //Wczytaj wartość z pliku
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    array.addAnywhere(value, rand() % array.sizeArray);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 4:
                cout << "Rozpoczynam test...";

                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    array.addBeggining(value);
                }
                while (array.sizeArray != 0) {
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    array.deleteFirst();
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    array.deleteLast();
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    array.deleteAny(rand() % array.sizeArray);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    array.checkExists(rand() % 2000000 - 1000000);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
    int input = 99;
    int value;
    int position;
    string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;




    while (input != 0) {
        cout << "Wybierz funkcję listy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj listę" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Zamknij, jeżeli wybrano 0
        if (input == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> inputData;
        cout << "Plik z wynikami testu: ";
        cin >> outputData;


        //Otwórz pliki
        inputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + inputData + ".txt");
        outputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/OutputData/DoublyLinkedList/" + outputData + ".txt", fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
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
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    //Wczytaj wartość z pliku
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    list.addBeggining(value);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 2:
                while (inputFile.good()) {
                    //Wczytaj wartość z pliku
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    list.addEnd(value);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 3:
                while (inputFile.good()) {
                    //Wczytaj wartość z pliku
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
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    list.deleteFirst();
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    list.deleteLast();
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    list.deleteAny(rand() % list.size);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    list.checkExists(rand() % 2000000 - 1000000);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
    int input = 99;
    int value;
    string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;

    while (input != 0) {
        cout << "Wybierz funkcję Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj Heap" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Zamknij, jeżeli wybrano 0
        if (input == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> inputData;
        cout << "Plik z wynikami testu: ";
        cin >> outputData;


        //Otwórz pliki
        inputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + inputData + ".txt");
        outputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/OutputData/Heap/" + outputData + ".txt", fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
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
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    //Wczytaj wartość z pliku
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    heap.add(value);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 2:


                while (inputFile.good()) {
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    heap.del(value);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
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
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    heap.checkExists(rand() % 2000000 - 1000000);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 4:
                time.TimeStart();
                heap.printHeap();
                time.TimeEnd();
                cout << "Czas wykonania: " << time.TimeExecution() << "ms" << endl;
                break;
        }

    }
}
/*
void Test::testBinarySearchTree() {
    srand(time(NULL));
    Time time;
    BinarySearchTree tree;
    int input = 99;
    int value;
    string outputData;
    string inputData;
    ofstream outputFile;
    ifstream inputFile;

    while (input != 0) {
        cout << "Wybierz funkcję Drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> input;

        //Zamknij, jeżeli wybrano 0
        if (input == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> inputData;
        cout << "Plik z wynikami testu: ";
        cin >> outputData;


        //Otwórz pliki
        inputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + inputData);
        outputFile.open("/home/asus/CLionProjects/SDIZO-Projekt-1/OutputData/BinarySearchTree/" + outputData, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (inputFile.is_open()) {
            cout << "Otwarto plik " << inputData << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (outputFile.is_open()) {
            cout << "Otwarto plik " << outputData << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (input) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                while (inputFile.good()) {
                    //Wczytaj wartość z pliku
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    tree.dodaj(value);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 2:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    tree.dodaj(value);
                }


                while (inputFile.good()) {
                    inputFile >> value;
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    tree.usun(value);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki
                inputFile.close();
                outputFile.close();
                break;

            case 3:
                //Wypełnij tablicę wartościami
                while (inputFile.good()) {
                    inputFile >> value;
                    tree.dodaj(value);
                }

                for (int i = 0; i < tree.size; i++) {
                    //Wykonaj funkcję z pomiarem
                    time.TimeStart();
                    tree.checkExists(rand() % 2000000 - 1000000);
                    time.TimeEnd();
                    //Zapisz do pliku wynik pomiaru
                    outputFile << time.TimeExecution() << endl;
                }

                //Zamknij oba pliki

                inputFile.close();
                outputFile.close();
                break;


            case 4:
                time.TimeStart();
                cout << "NIE DZIAŁA" << endl;
                time.TimeEnd();
                cout << "Czas wykonania: " << time.TimeExecution() << "ms" << endl;
                break;

        }

    }
}
*/