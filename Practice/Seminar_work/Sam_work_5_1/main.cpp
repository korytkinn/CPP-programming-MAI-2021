#include <iostream>

using namespace std;
class A {
protected:
    //������
    int arraySize = 0;
    int* massiv; // ������������ ������, �� ����� ������������ ��������


public:
    //�����������
    A() {
    massiv=nullptr;
    }
    //����������
    ~A() {
    delete[]massiv;}
    void creator()
    {
        cout << "Please enter next things:\n";
        cout << "Array size: ";
        cin >> arraySize;

        massiv = new int[arraySize]; //������ ������ �������

        cout << "Enter array elements (" << arraySize << "):\n";
        for (int i = 0; i < arraySize; i++)
            cin >> massiv[i];
    }

    void display() //����� ������ ������� �����
    {
        cout << "\nYour array:\n";
        for (int i = 0; i < arraySize; i++)
        {
            cout << massiv[i] << " ";
        }
    }

};

class B: public A {
    public:
        B() {

        }
    void outputer()
    {
        int index=0;
        cout << "\nLets output random element.";
        cout << "\nEnter element index (from 0): ";
        cin >> index;
        cout << "\nYour element = " << massiv[index] << endl;
    }

    void changer()
    {
        int index=0;
        cout <<"\nLets change random element.";
        cout << "\nEnter element index (from 0): ";
        cin >> index;
        cout << "\nEnter a new value for element ["<< index <<"]: ";
        cin >> massiv[index];
        cout << massiv[index];
    }

};
int main()
{
    B test;
    test.creator();
    test.display();
    test.outputer();
    test.changer();
    return 0;
}
