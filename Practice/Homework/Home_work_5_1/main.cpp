#include <iostream>

using namespace std;

class Massiv {
    //приватная область
    int arraySize = 0;
    //    int* massiv; // оригинальный массив, на время тестирования выключим
    int** indikatorArray;
    int rowCount, columnCount;

public:
    Massiv() // конструктор по умолчанию
    {
        indikatorArray = nullptr;
    }
    /*
    Massiv(int rowCount, int columnCount) // конструктор с двумя параметрами
    {
        indikatorArray = new int* [rowCount]; // rowCount строки в массиве
        for (int count = 0; count < rowCount; count++)
            indikatorArray[count] = new int[columnCount]; // и columnCount столбцов
    }
    */
    ~Massiv()
    {
        for (int count = 0; count < rowCount; count++)
            delete[] indikatorArray[count];
        //        cout << "rabotaet destruktor" << endl;
    }
    void creator()
    {
        cout << "Enter stroks count: ";
        cin >> rowCount;
        cout << "Enter stolbtsov count: ";
        cin >> columnCount;
        indikatorArray = new int* [rowCount]; // rowCount строки в массиве
        for (int count = 0; count < rowCount; count++)
            indikatorArray[count] = new int[columnCount]; // и columnCount столбцов


        // зануляем массив
        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                cout << "Enter [" << i + 1 << "][" << j + 1 << "] element: ";
                cin >> indikatorArray[i][j];
            }
        }
    }
    void display()
    {
        cout << "\nYour array: " << endl;
        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                cout << indikatorArray[i][j] << " ";

            }
            cout << endl;
        }
    }
};

int main()
{
    Massiv test;
    test.creator();
    test.display();
//    test.creator();
//    test.display();

}
