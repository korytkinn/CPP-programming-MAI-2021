#include <iostream>

using namespace std;

int sqrt(int x)
{
	if (x == 0 || x == 1)
	{
		return x;
	}

	int i = 1;
	int result = 1;
	while (result <= x)
	{
		i++;
		result = i * i;
	}
	return i - 1;
}

class Dynmas
{
	double** matrix;
	int x;
	int y;


public:
	Dynmas()
	{
		matrix = nullptr;
		x = 0;
		y = 0;
	}
	~Dynmas()
	{
		for (int i = 0; i < y; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	void creator()
	{
		cout << "Enter matrix sizes (int) x and (int) y." << endl;
		while (x <= 0)
		{
			cout << "Enter array size (int) x = ";
			cin >> x;
			if (x <= 0)
			{
				cout << "Wrong array size of x = " << x << endl;
			}
		}

		while (y <= 0)
		{
			cout << "Enter array size (int) y = ";
			cin >> y;
			if (y <= 0)
			{
				cout << "Wrong array size of y = " << y << endl;
			}
		}

		matrix = new double* [y];
		for (int i = 0; i < y; i++)
		{
			matrix[i] = new double[x];
		}

		cout << "Enter matrix elements (double)." << endl;

		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << "Enter element [" << i << "][" << j << "]: ";
				cin >> matrix[i][j];
			}
		}

		cout << "\nYour entered matrix is:" << endl;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}

	}

	void display()
	{
		if (matrix == nullptr)
		{
			cout << "\nMatrix not found" << endl;
		}
		else
		{
			cout << "Your matrix:" << endl;
			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

	Dynmas(const Dynmas& ob1)
	{
		x = ob1.x;
		y = ob1.y;
		matrix = new double* [y];
		for (int i = 0; i < y; i++)
		{
			matrix[i] = new double[x];
		}
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				matrix[i][j] = ob1.matrix[i][j];
			}
		}
	}

	Dynmas& operator=(const Dynmas& ob1) //присваивание копированием
	{
		if (this == &ob1)
		{
			return *this;
		}
		for (int i = 0; i < y; i++)
		{
			delete[] matrix[i];
		}
		matrix = nullptr;;
		x = 0;
		y = 0;
		if (ob1.matrix != nullptr && ob1.x != 0 && ob1.y != 0)
		{
			y = ob1.y;
			x = ob1.x;
			matrix = new double* [y];
			for (int i = 0; i < y; i++)
			{
				matrix[i] = new double[x];
			}

			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					matrix[i][j] = ob1.matrix[i][j];
				}
			}
		}
		return *this;
	}

	Dynmas& operator=(Dynmas&& ob1) //присваивание перемещением
	{
		if (this == &ob1)
		{
			return *this;
		}
		for (int i = 0; i < y; i++)
		{
			delete[] matrix[i];
		}
		matrix = nullptr;
		x = 0;
		y = 0;
		if (ob1.matrix != nullptr && ob1.x != 0 && ob1.y != 0)
		{
			matrix = ob1.matrix;
			x = ob1.x;
			y = ob1.y;

			for (int i = 0; i < y; i++)
			{
				delete[] ob1.matrix[i];
			}
			ob1.matrix = nullptr;
			ob1.x = 0;
			ob1.y = 0;
		}
	}

	Dynmas operator+(const Dynmas& ob1)
	{
		Dynmas ob3;

		int kolvo = x * y + ob1.x * ob1.y;
		cout << "kolvo = " << kolvo << endl;
		cout << "ob1.x = " << ob1.x << ", ob1.y = " << ob1.y << endl;
		cout << "x = " << x << ", y = " << y << endl;
		int koren = sqrt(kolvo);

		if (koren * koren == kolvo)
		{
			ob3.x = koren;
			ob3.y = koren;

			ob3.matrix = new double*[koren];
			for (int i = 0; i < koren; i++)
			{
				ob3.matrix[i] = new double[koren];
			}

			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					ob3.matrix[i][j] = matrix[i][j];
				}
			}


			double* array2 = new double[ob1.x * ob1.y];
			int indikator = 0;
			for (int i = 0; i < ob1.y; i++)
			{
				for (int j = 0; j < ob1.x; j++)
				{
					array2[indikator] = ob1.matrix[i][j];
					indikator++;
				}
			}

			indikator = 0;
			for (int i = y; i < koren; i++) // забивка второго массива
			{
				for (int j = 0; j < koren; j++)
				{
					ob3.matrix[i][j] = array2[indikator];
					indikator++;
				}
			}

			return ob3;
		}
		else
		{
			int index = 0;
			int newsize = 0;
			int newx;
			int newy;
			if (x * y < ob1.x * ob1.y)
			{
				newx = x;
				newy = y;
			}
			else
			{
				newx = ob1.x;
				newy = ob1.y;
			}

			while (newsize < kolvo)
			{
				if (index % 2 == 0)
				{
					newx++;
					newsize = newx * newy;
					index++;
				}
				else
				{
					newy++;
					newsize = newx * newy;
					index++;
				}
			}

			ob3.x = newx;
			ob3.y = newy;
			ob3.matrix = new double* [newy];
			for (int i = 0; i < ob3.y; i++)
			{
				ob3.matrix[i] = new double[ob3.x];
			}

			for (int i = 0; i < ob3.y; i++)
			{
				for (int j = 0; j < ob3.x; j++)
				{
					ob3.matrix[i][j] = 0;
				}
			}

			double* array = new double[ob1.x * ob1.y + x*y];
			int indikator = 0;

			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					array[indikator] = matrix[i][j];
					indikator++;
				}
			}

			for (int i = 0; i < ob1.y; i++)
			{
				for (int j = 0; j < ob1.x; j++)
				{
					array[indikator] = ob1.matrix[i][j];
					indikator++;
				}
			}

			indikator = 0;
			for (int i = 0; i < ob3.y; i++)
			{
				for (int j = 0; j < ob3.x; j++)
				{
					if (indikator == x * y + ob1.x * ob1.y)
					{
						i = ob3.y;
						j = ob3.x;
						break;
					}
					ob3.matrix[i][j] = array[indikator];
					indikator++;
				}
			}



			return ob3;
		}
	}


};



int main()
{
	Dynmas test1;
	test1.creator();
//	test1.display();

	Dynmas test2;
	test2.creator();
//	cout << "test2:\n";
//	test2.display();

	Dynmas test3 = test1 + test2;
	cout << "\ntest3 = test1 + test2\n";
	test3.display();
}
