#include <iostream>

using namespace std;

class Dynmas
{
	int* massiv;
	int razmer;

public:
	static int kolvo;
	Dynmas()
	{
		massiv = nullptr;
		razmer = 0;
		kolvo++;
	}
	~Dynmas()
	{
		delete[] massiv;
		kolvo--;
	}

	Dynmas(const Dynmas& ob); // копирование запрещено

	Dynmas& operator=(const Dynmas& ob); // присваивание запрещено

	void creator()
	{
		while (razmer <= 0)
		{
			cout << "Enter array size > 0 (int): ";
			cin >> razmer;
			if (razmer <= 0)
			{
				cout << "\nWrong array size = " << razmer << endl;
			}
		}
		massiv = new int[razmer];
		cout << "Enter " << razmer << " (int) elements.\n";
		for (int i = 0; i < razmer; i++)
		{
			cout << "Enter " << i + 1 << " element (int): ";
			cin >> massiv[i];
		}
	}

	void display() const
	{
		if (razmer == 0)
		{
			cout << "\nArray size = 0" << endl;
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

	void leftmove(int n)
	{
		int karman;
		for (int i = 0; i < n; i++)
		{
			karman = massiv[0];
			for (int j = 0; j < razmer; j++)
			{
				massiv[j] = massiv[j + 1];
			}
			massiv[razmer - 1] = karman;
		}
	}

};
int Dynmas::kolvo = 0;

int main()
{
	Dynmas test1;
	test1.creator();
	test1.display();
	test1.leftmove(3);
	test1.display();

	Dynmas test2;
	test2.display();

	cout << "kolvo = " << Dynmas::kolvo << endl;
}
