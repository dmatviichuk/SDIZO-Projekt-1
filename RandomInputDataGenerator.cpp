#include "RandomInputDataGenerator.h"
#include <iostream>
#include <fstream>
using namespace std;

void RandomInputDataGenerator::Generator()

{
    int length;
    string nameFile;
    ofstream file;

    cout << "Wpisz nazwę pliku(bez .txt): ";
    cin >> nameFile;
    cout << "Wpisz ilość liczb: ";
    cin >> length;
    file.open("/home/asus/CLionProjects/SDIZO-Projekt-1/InputData/" + nameFile + ".txt", fstream::out);

    srand(( unsigned) (0));
    for (int index = 0; index < length; index++)
    {
        int ran_data = rand() % 2000000 - 20000 ;
        cout << ran_data << endl;
        file << ran_data << '\n';
    }
    file.close();
}