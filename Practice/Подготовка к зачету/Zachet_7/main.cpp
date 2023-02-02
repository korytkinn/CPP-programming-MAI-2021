#include <iostream>

using namespace std;

class Dynmas
{
	double* massiv;
	int razmer;
public:
	Dynmas()
	{
		massiv = nullptr;
		razmer = 0;
	}
	~Dynmas()
	{
		delete[] massiv;
	}
	void creator()
	{
		while (razmer <= 0)
		{
			cout << "Enter array size (int): ";
			cin >> razmer;
			if (razmer <= 0)
			{
				cout << "\nWrong array size = " << razmer << endl;
			}
		}
		massiv = new double[razmer];
		cout << "Enter array elements (double)." << endl;
		for (int i = 0; i < razmer; i++)
		{
			cout << "Enter " << i + 1 << " of " << razmer << " element: ";
			cin >> massiv[i];
		}
	}
	void display() const
	{
		if (massiv == nullptr || razmer == 0)
		{
			cout << "\nYou dont have an array" << endl;
		}
		else
		{
			cout << "\nYour array:" << endl;
			for (int i = 0; i < razmer; i++)
			{
				cout << massiv[i] << " ";
			}
			cout << endl;
		}
	}

	/*
	Dynmas(const Dynmas& ob1)
	{
		if (ob1.massiv != nullptr && ob1.razmer != 0)
		{
			razmer = ob1.razmer;
			massiv = new double[razmer];
			for (int i = 0; i < razmer; i++)
			{
				massiv[i] = ob1.massiv[i];
			}
		}
	}
	*/
//	Dynmas operator=(const Dynmas& ob1);



	Dynmas& operator+=(int x)
	{
		if (massiv == nullptr)
		{
			return *this;
		}
//		Dynmas ob(*this);
		for (int i = 0; i < razmer; i++)
		{
			massiv[i] += x;
		}
		return *this;
	}

		Dynmas& operator+=(double x)
	{
		if (massiv == nullptr)
		{
			return *this;
		}
//		Dynmas ob(*this);
		for (int i = 0; i < razmer; i++)
		{
			massiv[i] += x;
		}
		return *this;
	}

	Dynmas(Dynmas&& ob1) //конструктор перемещения
	{
		if (ob1.massiv != nullptr && ob1.razmer != 0)
		{
			massiv = ob1.massiv;
			razmer = ob1.razmer;
			ob1.massiv = nullptr;
			ob1.razmer = 0;
		}
	}
	Dynmas& operator=(Dynmas&& ob1) // присваивание перемещением
	{
		if (this == &ob1)
		{
			return *this;
		}
		delete[] massiv;
		massiv = nullptr;
		razmer = 0;

		if (ob1.massiv != nullptr && ob1.razmer != 0)
		{
			massiv = ob1.massiv;
			razmer = ob1.razmer;
			ob1.massiv = nullptr;
			ob1.razmer = 0;
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
	Dynmas test1;
	test1.creator();
	test1.display();
	test1 += 5;
	test1.display();

		test1 += 4.7;
	test1.display();

	Dynmas test2[2];
	test2[0].creator();
	test2[1].creator();
	for (int i = 0; i < 2; i++)
	{
		cout << "\ni = " << i << endl;
		test2[i].display();
	}

	obmen_peremesheniem(test2[0], test2[1]);
	for (int i = 0; i < 2; i++)
	{
		cout << "\ni = " << i << endl;
		test2[i].display();
	}

	return 0;
}
