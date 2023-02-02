
#include <iostream>

using namespace std;

class Dynmas
{
	double* massiv1;
	double* massiv2;
	double* massiv3;

	int razmer1;
	int razmer2;
	int razmer3;

public:
	Dynmas()
	{
		massiv1 = nullptr;
		massiv2 = nullptr;
		massiv3 = nullptr;

		razmer1 = 0;
		razmer2 = 0;
		razmer3 = 0;
	}
	~Dynmas()
	{
		delete[] massiv1;
		delete[] massiv2;
		delete[] massiv3;
	}
	void creator()
	{
		cout << "\nEnter sizes of arrays" << endl;
		while (razmer1 <= 0)
		{
			cout << "Enter 1st array size (int): ";
			cin >> razmer1;
			if (razmer1 <= 0)
			{
				cout << "\nWrong 1st array size = " << razmer1 << endl;
			}
		}

		while (razmer2 <= 0)
		{
			cout << "Enter 2nd array size (int): ";
			cin >> razmer2;
			if (razmer2 <= 0)
			{
				cout << "\nWrong 2nd array size = " << razmer2 << endl;
			}
		}

		while (razmer3 <= 0)
		{
			cout << "Enter 3rd array size (int): ";
			cin >> razmer3;
			if (razmer3 <= 0)
			{
				cout << "\nWrong 3rd array size = " << razmer3 << endl;
			}
		}

		massiv1 = new double[razmer1];
		massiv2 = new double[razmer2];
		massiv3 = new double[razmer3];

		cout << "\nEnter 1st array elements (double)." << endl;
		for (int i = 0; i < razmer1; i++)
		{
			cout << "Enter " << i + 1 << " element of " << razmer1 << ": ";
			cin >> massiv1[i];
			cout << endl;
		}

		cout << "\nEnter 2nd array elements (double)." << endl;
		for (int i = 0; i < razmer2; i++)
		{
			cout << "Enter " << i + 1 << " element of " << razmer2 << ": ";
			cin >> massiv2[i];
			cout << endl;
		}

		cout << "\nEnter 3rd array elements (double)." << endl;
		for (int i = 0; i < razmer3; i++)
		{
			cout << "Enter " << i + 1 << " element of " << razmer3 << ": ";
			cin >> massiv3[i];
			cout << endl;
		}

	}
	void display() const
	{
		if (massiv1 == nullptr || razmer1 == 0)
		{
			cout << "Dont have 1st array or wrong array size = " << razmer1 << endl;
		}
		else
		{
			cout << "\n1st array: " << endl;
			for (int i = 0; i < razmer1; i++)
			{
				cout << massiv1[i] << " ";
			}
			cout << endl;
		}

		if (massiv2 == nullptr || razmer2 == 0)
		{
			cout << "Dont have 2nd array or wrong array size = " << razmer2 << endl;
		}
		else
		{
			cout << "\n2nd array: " << endl;
			for (int i = 0; i < razmer2; i++)
			{
				cout << massiv2[i] << " ";
			}
			cout << endl;
		}

		if (massiv3 == nullptr || razmer3 == 0)
		{
			cout << "Dont have 3rd array or wrong array size = " << razmer3 << endl;
		}
		else
		{
			cout << "\n3rd array: " << endl;
			for (int i = 0; i < razmer3; i++)
			{
				cout << massiv3[i] << " ";
			}
			cout << endl;
		}
	}

	Dynmas(const Dynmas& ob1);
	Dynmas& operator=(const Dynmas& ob1);

	double operator()(int number, int element)
	{
		if (number == 1)
		{
			if (element <= razmer1-1)
			{
				return massiv1[element];
			}
			else
			{
				return 0;
			}
		}

		if (number == 2)
		{
			if (element <= razmer2 - 1)
			{
				return massiv2[element];
			}
			else
			{
				return 0;
			}
		}

		if (number == 3)
		{
			if (element <= razmer3 - 1)
			{
				return massiv3[element];
			}
			else
			{
				return 0;
			}
		}

	}

	Dynmas(Dynmas&& ob1) // конструктор перемещения
	{
		if (ob1.massiv1 != nullptr && ob1.razmer1 != 0)
		{
			massiv1 = ob1.massiv1;
			razmer1 = ob1.razmer1;
			ob1.massiv1 = nullptr;
			ob1.razmer1 = 0;
		}
		if (ob1.massiv2 != nullptr && ob1.razmer2 != 0)
		{
			massiv2 = ob1.massiv2;
			razmer2 = ob1.razmer2;
			ob1.massiv2 = nullptr;
			ob1.razmer2 = 0;
		}

		if (ob1.massiv3 != nullptr && ob1.razmer3 != 0)
		{
			massiv3 = ob1.massiv3;
			razmer3 = ob1.razmer3;
			ob1.massiv3 = nullptr;
			ob1.razmer3 = 0;
		}
	}

	Dynmas& operator=(Dynmas&& ob1) // присваение перемещение
	{
		if (this == &ob1)
		{
			return *this;
		}
		delete[] massiv1;
		delete[] massiv2;
		delete[] massiv3;
		massiv1 = nullptr;
		massiv2 = nullptr;
		massiv3 = nullptr;
		razmer1 = 0;
		razmer2 = 0;
		razmer3 = 0;

		if (ob1.massiv1 != nullptr && ob1.razmer1 != 0)
		{
			massiv1 = ob1.massiv1;
			razmer1 = ob1.razmer1;
			ob1.massiv1 = nullptr;
			ob1.razmer1 = 0;
		}
		if (ob1.massiv2 != nullptr && ob1.razmer2 != 0)
		{
			massiv2 = ob1.massiv2;
			razmer2 = ob1.razmer2;
			ob1.massiv2 = nullptr;
			ob1.razmer2 = 0;
		}

		if (ob1.massiv3 != nullptr && ob1.razmer3 != 0)
		{
			massiv3 = ob1.massiv3;
			razmer3 = ob1.razmer3;
			ob1.massiv3 = nullptr;
			ob1.razmer3 = 0;
		}

		return *this;
	}

};

void obmen_peremesheniem(Dynmas& a, Dynmas& b)
{
	Dynmas c = move(a);
	a = move(b);
	b = move(c);
}

int main()
{
	/*
	Dynmas test1;
	test1.creator();
	test1.display();

	cout << test1(2, 1);
	*/

	cout << "rabotaem" << endl;
	Dynmas test2[2];
	for (int i = 0; i < 2; i++)
	{
		test2[i].creator();
	}
	for (int i = 0; i < 2; i++)
	{
		test2[i].display();
	}
		obmen_peremesheniem(test2[0], test2[1]);
	for (int i = 0; i < 2; i++)
	{
		test2[i].display();
	}
	return 0;
}
