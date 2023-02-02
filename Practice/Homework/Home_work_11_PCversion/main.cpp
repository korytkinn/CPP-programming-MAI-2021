#include <iostream>

using namespace std;

class Dynmas
{
	int* massiv;
	int razmer;
public:
	Dynmas() // конструктор
	{
		massiv = nullptr;
		razmer = 0;
	}

	Dynmas(const Dynmas& ob1) //конструктор копирования
	{
		razmer = ob1.razmer;
		massiv = new int[razmer];

		for (int i = 0; i < razmer; i++)
		{
			massiv[i] = ob1.massiv[i];
		}
	}

	~Dynmas() // деструктор
	{
		delete[] massiv;
	}

	Dynmas& operator=(const Dynmas &ob1) //оператор присваивания
	{
		if (this == &ob1)
		{
			return *this;
		}

		razmer = ob1.razmer;
		massiv = new int[razmer];

		for (int i = 0; i < razmer; i++)
		{
			massiv[i] = ob1.massiv[i];
		}

		return *this;
	}

	Dynmas& operator--(); // prefix

	Dynmas operator--(int); // postfix

	Dynmas operator-=(int x)
	{
		if (massiv == nullptr)
		{
			return *this;
		}
		Dynmas ob(*this);
		for (int i = 0; i < razmer; i++)
		{
			massiv[i] -= x;
		}
		return *this;
	}

	void creator()
	{
		cout << "Enter array size (int): ";
		cin >> razmer;
		massiv = new int[razmer];
		cout << "\nEnter " << razmer << "(int) elements:" << endl;
		for (int i = 0; i < razmer; i++)
		{
			cout << "Enter " << i+1 << " element: ";
			cin >> massiv[i];
		}
	}

	void display()
	{
		cout << "\nYour array include " << razmer << " elements:" << endl;
		for (int i = 0; i < razmer; i++)
		{
			cout << massiv[i] << " ";
		}
		cout << endl;
	}


};

int main()
{
	Dynmas test1;
	test1.creator();
	test1.display();

	cout << "\ntest2 = test1: \n";
	Dynmas test2 = test1;
	test2.display();

	cout << "\ntest2 -= 5\n";
	test2 -= 5;
	test2.display();

	cout << "\ntest2--\n";
	test2--;
	test2.display();

	cout << "\n--test2\n";
	--test2;
	test2.display();
}

Dynmas& Dynmas::operator--() // prefix
{
	if (massiv == nullptr)
	{
		return *this;
	}

	for (int i = 0; i < razmer; i++)
	{
		--massiv[i];
	}
	return *this;
}

Dynmas Dynmas::operator--(int) // postfix
{
	if (massiv == nullptr)
	{
		return *this;
	}
	Dynmas ob(*this);
	for (int i = 0; i < razmer; i++)
	{
		--massiv[i];
	}
	return ob;
}
