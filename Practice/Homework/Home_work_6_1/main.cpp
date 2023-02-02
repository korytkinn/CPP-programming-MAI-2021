#include <iostream>

using namespace std;

class Massiv {
    //��������� �������
    int arraySize = 0;
    //    int* massiv; // ������������ ������, �� ����� ������������ ��������
    int** indikatorArray;
    int rowCount, columnCount;

public:
    Massiv() // ����������� �� ���������
    {
        indikatorArray = nullptr;
    }
    /*
    Massiv(int rowCount, int columnCount) // ����������� � ����� �����������
    {
        indikatorArray = new int* [rowCount]; // rowCount ������ � �������
        for (int count = 0; count < rowCount; count++)
            indikatorArray[count] = new int[columnCount]; // � columnCount ��������
    }
    */
    ~Massiv()
    {
        for (int count = 0; count < rowCount; count++)
            delete[] indikatorArray[count];
        //        cout << "rabotaet destruktor" << endl;
    }

    //����������� �����������
    Massiv(const Massiv& copy)
    {
        cout << " Konstryktor kopirovaniya nachal raboty\n\n";
        arraySize = copy.arraySize;

        rowCount = copy.rowCount;
        columnCount = copy.columnCount;

        indikatorArray = new int* [rowCount]; // rowCount ������ � �������
        for (int count = 0; count < rowCount; count++)
            indikatorArray[count] = new int[columnCount]; // � columnCount ��������

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                indikatorArray[i][j] = copy.indikatorArray[i][j];
            }
        }
    } //����� ��������� �����������

        // ���������� ��������� ������������
    Massiv& operator= (const Massiv& copy)
    {
        cout << " Pereopredelennii operator prisvaivaniya nachal raboty\n\n";

        // �������� �� ����������������
        if (this == &copy)
            return *this;
        delete[] indikatorArray;
        if (copy.indikatorArray == nullptr)
        {
            indikatorArray = nullptr;
            return *this;
        }


        // ��������� ����������� ��������
        arraySize = copy.arraySize;

        rowCount = copy.rowCount;
        columnCount = copy.columnCount;

        indikatorArray = new int* [rowCount]; // rowCount ������ � �������
        for (int count = 0; count < rowCount; count++)
            indikatorArray[count] = new int[columnCount]; // � columnCount ��������

        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                indikatorArray[i][j] = copy.indikatorArray[i][j];
            }
        }

        // ���������� ������� ������, ����� ����� ����������� ������� � ������� ���������� ���������� �������� ������������
        return *this;
    }

    void creator()
    {
        cout << "Enter stroks count: ";
        cin >> rowCount;
        cout << "Enter stolbtsov count: ";
        cin >> columnCount;
        indikatorArray = new int* [rowCount]; // rowCount ������ � �������
        for (int count = 0; count < rowCount; count++)
            indikatorArray[count] = new int[columnCount]; // � columnCount ��������


        // ��������� ������
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
