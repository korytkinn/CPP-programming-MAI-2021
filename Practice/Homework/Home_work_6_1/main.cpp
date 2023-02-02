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

    //конструктор копирования
    Massiv(const Massiv& copy)
    {
        cout << " Konstryktor kopirovaniya nachal raboty\n\n";
        arraySize = copy.arraySize;

        rowCount = copy.rowCount;
        columnCount = copy.columnCount;

        indikatorArray = new int* [rowCount]; // rowCount строки в массиве
        for (int count = 0; count < rowCount; count++)
            indikatorArray[count] = new int[columnCount]; // и columnCount столбцов

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                indikatorArray[i][j] = copy.indikatorArray[i][j];
            }
        }
    } //конец оператора копирования

        // Перегрузка оператора присваивания
    Massiv& operator= (const Massiv& copy)
    {
        cout << " Pereopredelennii operator prisvaivaniya nachal raboty\n\n";

        // Проверка на самоприсваивание
        if (this == &copy)
            return *this;
        delete[] indikatorArray;
        if (copy.indikatorArray == nullptr)
        {
            indikatorArray = nullptr;
            return *this;
        }


        // Выполняем копирование значений
        arraySize = copy.arraySize;

        rowCount = copy.rowCount;
        columnCount = copy.columnCount;

        indikatorArray = new int* [rowCount]; // rowCount строки в массиве
        for (int count = 0; count < rowCount; count++)
            indikatorArray[count] = new int[columnCount]; // и columnCount столбцов

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                indikatorArray[i][j] = copy.indikatorArray[i][j];
            }
        }

        // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
        return *this;
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


        // заполняем массив
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
    Massiv second(test);
    cout << "\nSecond here (kopirovanie):\n";
    second.display();

    Massiv third;
    third = test;
    cout << "\nThird here (prisvoenie):\n";
    second.display();
}
