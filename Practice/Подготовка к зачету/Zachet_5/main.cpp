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
		while (razmer1 <= 0)
		{
			cout << "Enter 1st array size (int number) >0: ";
			cin >> razmer1;
			if (razmer1 <= 0)
			{
				cout << "\nWrong 1st array size = " << razmer1 << endl;
			}
		}
		massiv1 = new double[razmer1];

		while (razmer2 <= 0)
		{
			cout << "\nEnter 2nd array size (int number) >0: ";
			cin >> razmer2;
			if (razmer2 <= 0)
			{
				cout << "\nWrong 2nd array size = " << razmer2 << endl;
			}
		}
		massiv2 = new double[razmer2];


		while (razmer3 <= 0)
		{
			cout << "\nEnter 3rd array size (int number) >0: ";
			cin >> razmer3;
			if (razmer3 <= 0)
			{
				cout << "\nWrong 3rd array size = " << razmer3 << endl;
			}
		}
		massiv3 = new double[razmer3];


		cout << "\nEnter 1st array elements (double)." << endl;
		for (int i = 0; i < razmer1; i++)
		{
			cout << "\nEnter (double) number, element " << i + 1 << "of " << razmer1 << ": ";
			cin >> massiv1[i];
		}

		cout << "\nEnter 2nd array elements (double)." << endl;

		for (int i = 0; i < razmer2; i++)
		{
			cout << "\nEnter (double) number, element " << i + 1 << "of " << razmer2 << ": ";
			cin >> massiv2[i];
		}

		cout << "\nEnter 3rd array elements (double)." << endl;

		for (int i = 0; i < razmer3; i++)
		{
			cout << "\nEnter (double) number, element " << i + 1 << "of " << razmer3 << ": ";
			cin >> massiv3[i];
		}



	}
	void display() const
	{
		if (razmer1 == 0)
		{
			cout << "\n1st array size = 0" << endl;
		}
		else
		{
			cout << "\n1st array:" << endl;
			for (int i = 0; i < razmer1; i++)
			{
				cout << massiv1[i] << " ";
			}
			cout << endl;
		}

		if (razmer2 == 0)
		{
			cout << "\n2nd array size = 0" << endl;
		}
		else
		{
			cout << "\n2nd array:" << endl;
			for (int i = 0; i < razmer2; i++)
			{
				cout << massiv2[i] << " ";
			}
			cout << endl;
		}

		if (razmer3 == 0)
		{
			cout << "\n3rd array size = 0" << endl;
		}
		else
		{
			cout << "\n3rd array:" << endl;
			for (int i = 0; i < razmer3; i++)
			{
				cout << massiv3[i] << " ";
			}
			cout << endl;
		}



	}

//	Dynmas(const Dynmas& ob1);
//	Dynmas operator=(const Dynmas& ob1);

	Dynmas(const Dynmas& ob1)
	{
		razmer1 = ob1.razmer1;
		razmer2 = ob1.razmer2;
		razmer3 = ob1.razmer3;

		massiv1 = new double[razmer1];
		massiv2 = new double[razmer2];
		massiv3 = new double[razmer3];

		for (int i = 0; i < razmer1; i++)
		{
			massiv1[i] = ob1.massiv1[i];
		}

		for (int i = 0; i < razmer2; i++)
		{
			massiv2[i] = ob1.massiv2[i];
		}

		for (int i = 0; i < razmer3; i++)
		{
			massiv3[i] = ob1.massiv3[i];
		}
	}

	Dynmas operator=(const Dynmas& ob1)
	{
		if (this == &ob1)
		{
			return *this;
		}

		razmer1 = ob1.razmer1;
		razmer2 = ob1.razmer2;
		razmer3 = ob1.razmer3;

		massiv1 = new double[razmer1];
		massiv2 = new double[razmer2];
		massiv3 = new double[razmer3];

		for (int i = 0; i < razmer1; i++)
		{
			massiv1[i] = ob1.massiv1[i];
		}

		for (int i = 0; i < razmer2; i++)
		{
			massiv2[i] = ob1.massiv2[i];
		}

		for (int i = 0; i < razmer3; i++)
		{
			massiv3[i] = ob1.massiv3[i];
		}

	}

	void counter()
	{
		double sum1 = 0;
		double sum2 = 0;
		double sum3 = 0;

		for (int i = 0; i < razmer1; i++)
		{
			sum1 += massiv1[i];
		}
		sum1 = sum1 / razmer1;

		for (int i = 0; i < razmer2; i++)
		{
			sum2 += massiv2[i];
		}
		sum2 = sum2 / razmer2;

		for (int i = 0; i < razmer3; i++)
		{
			sum3 += massiv3[i];
		}
		sum3 = sum3 / razmer3;

		if (sum1 > sum2)
		{
			if (sum1 > sum3)
			{

			}
			if (sum1 == sum3)
			{

			}
		}

		if (sum1 > sum2 && sum1 >= sum3)
		{
			cout << "\n Srednee arifmeticheskoe = " << sum1 << endl;
			cout << "\n1st array:" << endl;
			for (int i = 0; i < razmer1; i++)
			{
				cout << massiv1[i] << " ";
			}
			cout << endl;
		}

		if (sum2 > sum1 && sum2 >= sum3)
		{
			cout << "\n Srednee arifmeticheskoe = " << sum2 << endl;
			cout << "\n2nd array:" << endl;
			for (int i = 0; i < razmer2; i++)
			{
				cout << massiv2[i] << " ";
			}
			cout << endl;
		}

		if (sum3 > sum1 && sum3 >= sum2)
		{
			cout << "\n Srednee arifmeticheskoe = " << sum3 << endl;
			cout << "\n3rd array:" << endl;
			for (int i = 0; i < razmer3; i++)
			{
				cout << massiv3[i] << " ";
			}
			cout << endl;
		}


	}

};

int main()
{
	Dynmas test1;
	test1.creator();
	test1.display();

	Dynmas test2(test1);
	test2.display();

	Dynmas test3 = test2;
	test3.display();
	test3.counter();
}
