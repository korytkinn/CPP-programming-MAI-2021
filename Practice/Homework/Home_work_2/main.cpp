#include <iostream>

using namespace std;

class Drob
{
	int celoe;
	int chislitel;
	int znamenatel;

public:

	Drob()
	{
		celoe = 0;
	chislitel = 0;
	znamenatel = 1;
	}


	void display() // ������� ������ ����� � �������
	{
	    cout << "\nYour fraction = ";
		if (chislitel == 0 && znamenatel == 0)
		{
			cout << celoe << endl;
		}
		else
		{
		cout << celoe << " " << chislitel << "/" << znamenatel << endl;
		}
	}

	void input() // ������� ����� ����� + ��������������� � "�����������" ����
	{
		cout << "Please enter a fraction.\n";
		cout << "\nCelaya chast: ";
		cin >> celoe;

//		WrongChislitel: // ��� �����
		do
		{
            cout << "\nChislitel (greater than zero): ";
            cin >> chislitel;
            if (chislitel < 0)
            {
                cout << "Your chislitel < 0. Wrong number\n";
            }
		} while (chislitel < 0);

		/*
		cin >> chislitel;
		if (chislitel < 0)
		{
			cout << "Your chislitel < 0. Wrong number\n";
			goto WrongChislitel;
		}
		*/

//		WrongZnamenatel: // ��� �����
		do
        {
                cout << "\nZnamenatel (greater than zero): ";
        		cin >> znamenatel;
                if (znamenatel == 0 || znamenatel < 0)
                    {
                        cout << "Your znamenatel < 0 or = 0. Wrong znamental!\n";
                    }
        } while(znamenatel == 0 || znamenatel < 0);

//		cin >> znamenatel;
//		if (znamenatel == 0 || znamenatel < 0)
//		{
//			cout << "Wrong znamental!\n";
//			goto WrongZnamenatel;
//		}

		// TODO - ������������ ����� - ��������� � ����������� ����
		int num1, num2, negative = 0;
		if (celoe < 0)
		{
			negative = 1;
		}
		num1 = abs(celoe * znamenatel) + chislitel; //����� ���������
		chislitel = num1; // ����� ���������, �� ����������� ������

		// �������� �� �������
		if (negative == 0)
		{
			num1 = chislitel / znamenatel; // �������� ������� - ����� �����
		}
		else
		{
			num1 = -(chislitel / znamenatel); // �������� ������� - ����� �����
		}
		num2 = chislitel % znamenatel; // ������� - ����� ���������
		if (num2 == 0)
		{
			celoe = num1;
			chislitel = 0;
			znamenatel = 0;
		}
		else
		{
			celoe = num1;
			chislitel = num2;
		}


	}

};

int main()
{
	Drob myDrob;

	myDrob.input();
	myDrob.display();
}
