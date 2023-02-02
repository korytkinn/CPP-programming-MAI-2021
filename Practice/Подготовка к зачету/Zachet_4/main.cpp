#include <iostream>

using namespace std;

class Dynmas
{
	double* massiv;
	int razmer;

	int* indixes;

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

//	Dynmas(const Dynmas& ob1); //копирование запрещено
//	Dynmas operator=(const Dynmas& ob1); //присваивание запрещено

	double& operator[](const int index)
	{
		return massiv[index];
	}

	void creator()
	{
		while (razmer <= 0)
		{
			cout << "\nEnter array > 0 (int number): ";
			cin >> razmer;
			if (razmer <= 0)
			{
				cout << "\nWrong array size = " << razmer << endl;
			}
		}
		massiv = new double[razmer];
		indixes = new int[razmer];

		for (int i = 0; i < razmer; i++)
		{
			cout << "\nEnter (double number), element " << i + 1 << " of " << razmer << ": ";
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
	void sorter()
	{
		//int* indixes = new int[razmer];
		for (int i = 0; i < razmer; i++)
		{
			indixes[i] = 0;
//			cout << indixes[i];
		}
		for (int i = 0; i < razmer; i++)
		{
			if (massiv[i] == 0)
			{
				continue;
			}
			long double d = massiv[i];
			long long number = (int)massiv[i];
			int count = 0;
			while (number != d)
			{
				count++;
				d *= 10;
				number = (int)d;
				cout << "\nd=" << d << endl;
				cout << "number=" << number << endl;
			}
			indixes[i] = count;
			cout << count << endl;
		}

		for (int i = 0; i < razmer-1; i++)
		{
			for (int j = 0; j < razmer-i-1; j++)
			{
//				int karman;
				if (indixes[j] > indixes[j+1])
				{
					int karman = indixes[j];
					indixes[j] = indixes[j + 1];
					indixes[j + 1] = karman;

					double karman2 = massiv[j];
					massiv[j] = massiv[j + 1];
					massiv[j + 1] = karman2;

				}
			}
		}
	}

};

int main()
{
	Dynmas test1;
	test1.creator();
	test1.display();
//	test1[3] = 7.7;
	test1.display();
	test1.sorter();
	test1.display();
}
