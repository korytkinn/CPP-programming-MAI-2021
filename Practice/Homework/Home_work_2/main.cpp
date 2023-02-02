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


	void display() // функция вывода дроби в консоль
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

	void input() // функция ввода дроби + преобразовывает к "правильному" виду
	{
		cout << "Please enter a fraction.\n";
		cout << "\nCelaya chast: ";
		cin >> celoe;

//		WrongChislitel: // Это лейбл
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

//		WrongZnamenatel: // Это лейбл
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

		// TODO - обрабатывать дробь - приводить к правильному виду
		int num1, num2, negative = 0;
		if (celoe < 0)
		{
			negative = 1;
		}
		num1 = abs(celoe * znamenatel) + chislitel; //новый числитель
		chislitel = num1; // новый числитель, но знаменатель старый

		// приведем по красоте
		if (negative == 0)
		{
			num1 = chislitel / znamenatel; // неполное частное - новое целое
		}
		else
		{
			num1 = -(chislitel / znamenatel); // неполное частное - новое целое
		}
		num2 = chislitel % znamenatel; // остаток - новый числитель
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
