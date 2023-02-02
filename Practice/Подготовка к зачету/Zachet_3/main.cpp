#include <iostream>

using namespace std;

class Dynmas
{
protected:
	double* massiv1;
	double* massiv2;

	int razmer1;
	int razmer2;

	double number1;
	double number2;

public:
	Dynmas()
	{
		massiv1 = nullptr;
		massiv2 = nullptr;
		razmer1 = 0;
		razmer2 = 0;

		number1 = 0;
		number2 = 0;
	}

	Dynmas(int _razmer1, int _razmer2, double _number1, double _number2)
	{
		razmer1 = _razmer1;
		razmer2 = _razmer2;

		number1 = _number1;
		number2 = _number2;

		if (razmer1 <= 0)
		{
			cout << "Wrong 1st array size" << endl;
			cout << "New size = 5" << endl;
			razmer1 = 5;
		}

		if (razmer2 <= 0)
		{
			cout << "Wrong 2nd array size" << endl;
			cout << "New size = 5" << endl;
			razmer2 = 5;
		}

		massiv1 = new double[razmer1];
		massiv2 = new double[razmer2];

		for (int i = 0; i < razmer1; i++)
		{
			massiv1[i] = number1;
		}

		for (int i = 0; i < razmer2; i++)
		{
			massiv2[i] = number2;
		}
	}

	~Dynmas()
	{
		delete[] massiv1;
		delete[] massiv2;
	}

	void display() const
	{
		if (razmer1 <= 0)
		{
			cout << "\n1st array size <= 0" << endl;
		}
		else
		{
			cout << "1st array:" << endl;
			for (int i = 0; i < razmer1; i++)
			{
				cout << massiv1[i] << " ";
			}
			cout << endl;
		}

		if (razmer2 <= 0)
		{
			cout << "\n2nd array size <= 0" << endl;
		}
		else
		{
			cout << "2nd array:" << endl;
			for (int i = 0; i < razmer2; i++)
			{
				cout << massiv2[i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

//	Dynmas(const Dynmas& ob); // копирование запрещено
//	Dynmas& operator=(const Dynmas& ob); // присваивание запрещено

	Dynmas(const Dynmas& ob)
	{
		razmer1 = ob.razmer1;
		razmer2 = ob.razmer2;

		massiv1 = new double[razmer1];
		massiv2 = new double[razmer2];

		for (int i = 0; i < razmer1; i++)
		{
			massiv1[i] = ob.massiv1[i];
		}

		for (int i = 0; i < razmer2; i++)
		{
			massiv2[i] = ob.massiv2[i];
		}
	}

	Dynmas& operator=(const Dynmas& ob)
	{
		if (this == &ob)
		{
			return *this;
		}

		razmer1 = ob.razmer1;
		razmer2 = ob.razmer2;

		massiv1 = new double[razmer1];
		massiv2 = new double[razmer2];

		for (int i = 0; i < razmer1; i++)
		{
			massiv1[i] = ob.massiv1[i];
		}

		for (int i = 0; i < razmer2; i++)
		{
			massiv2[i] = ob.massiv2[i];
		}
	}

};

class Second : public Dynmas
{
	double sum1;
	double sum2;

	int part1;
	int part2;

public:
	Second()
	{
	}

	Second(int _razmer1, int _razmer2, double _number1, double _number2):Dynmas(_razmer1, _razmer2, _number1, _number2)
	{
		sum1 = 0;
		sum2 = 0;
		part1 = 0;
		part2 = 0;
	}
	void summer()
	{
		for (int i = 0; i < razmer1; i++)
		{
			sum1 += massiv1[i];
		}
		for (int i = 0; i < razmer2; i++)
		{
			sum2 += massiv2[i];
		}

		part1 = sum1; // обрубаем остаток
		part2 = sum2; // обрубаем остаток

		if (sum1-part1 <= 0.5)
		{
			sum1 = part1;
		}
		else
		{
			sum1 = sum1 - (sum1-part1) +1;
		}

		if (sum2 - part2 <= 0.5)
		{
			sum2 = part2;
		}
		else
		{
			sum2 = sum2 - (sum2 - part2) + 1;
		}

		// тестовый вывод
		cout << "sum1 = " << sum1 << ", sum2 = " << sum2 << endl;

	}
};
int main()
{
	Dynmas test1(5,7, 5.5,15.5);
	test1.display();

	Dynmas test2 = test1;
	test2.display();

	Dynmas test3(test2);
	test3.display();

	cout << "Second" << endl;
	Second test4(9, 7, 17.3, 11.6);
	test4.display();
	test4.summer();
}
