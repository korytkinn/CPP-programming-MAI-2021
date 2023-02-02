#include <iostream>

using namespace std;

int sqrt(int x)
{
	// Ѕаза
	if (x == 0 || x == 1)
		return x;

	// —тартуем с 1, пробуем все цифры до
	// i*i больше или равно x
	int i = 1, result = 1;
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
		cout << "\nDestryktor porabotal\n";
	}

	void creator()
	{
		cout << "Enter matrix sizes." << endl;
		while (x <= 0)
		{
			cout << "Enter (int) matrix size of x = ";
			cin >> x;
			if (x <= 0)
			{
				cout << "Wrong size of x = " << x << endl;
			}
		}

		while (y <= 0)
		{
			cout << "Enter (int) matrix size of y = ";
			cin >> y;
			if (y <= 0)
			{
				cout << "Wrong size of y = " << y << endl;
			}
		}

		matrix = new double* [y];
		for (int i = 0; i < y; i++)
		{
			matrix[i] = new double[x];
		}

		cout << "Enter (double) elements of matrix" << endl;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << "Enter [" << i + 1 << "][" << j + 1 << "] element: ";
				cin >> matrix[i][j];
			}
		}

	}
	void display() const
	{
		if (matrix == nullptr)
		{
			cout << "\nWe dont have a matrix" << endl;
		}
		else
		{
			cout << "\nYour matrix:" << endl;
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
	Dynmas& operator=(const Dynmas& ob1)
	{
		if (this == &ob1)
		{
			return *this;
		}
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

		cout << "\noperator = porabotal\n";
		return *this;
	}

	Dynmas operator+(const Dynmas& ob1)
	{
		Dynmas ob3;
		int indikator = 0;
		int kolvo = x * y + ob1.x * ob1.y;


		int koren = sqrt(kolvo); // корень из количества элементов

		if (koren * koren >= kolvo)
		{
			if (koren * koren == kolvo) // произведение равно, забиваем
			{
//				Dynmas ob3;

				ob3.x = koren;
				ob3.y = koren;

				ob3.matrix = new double* [koren];
				for (int i = 0; i < koren; i++)
				{
					ob3.matrix[i] = new double[koren];
				}

				for (int i = 0; i < y; i++) //забиваем элементы из внутренней матрицы
				{
					for (int j = 0; j < x; j++)
					{
						ob3.matrix[i][j] = matrix[i][j];
					}
				}

				// для второго
				double* array2 = new double[ob1.x + ob1.y];
				indikator = 0;
				for (int i = 0; i < ob1.y; i++)
				{
					for (int j = 0; j < ob1.x; j++)
					{
						array2[indikator] = ob1.matrix[i][j];
						//				cout << array2[indikator] << " ";
						indikator++;
					}
				}

				for (int i = y; i < ob3.y; i++) //забиваем элементы из внутренней матрицы
				{
					for (int j = 0; j < ob3.x; j++)
					{
						ob3.matrix[i][j] = array2[indikator];
						indikator++;
					}
				}
				return ob3;
			}

		}
		else
		{
			int newx = 0;
			int newy = 0;

			if (x * y > ob1.x * ob1.y)
			{
				newx = ob1.x;
				newy = ob1.y;
			}
			else
			{
				newx = x;
				newy = y;
			}

			int iteraciya = 1;
			while (newx * newy < kolvo)
			{
				if (iteraciya % 2 == 0)
				{
					newy++;
					iteraciya++;
				}
				else
				{
					newx++;
					iteraciya++;
				}
			}

			// создание матрицы
//			Dynmas ob3;
			ob3.x = newx;
			ob3.y = newy;

			ob3.matrix = new double* [ob3.y];
			for (int i = 0; i < ob3.y; i++)
			{
				ob3.matrix[i] = new double[ob3.x];
			}

			cout << "ob3.x = " << ob3.x << ", ob3.y = " << ob3.y << endl;


			for (int i = 0; i < ob3.y; i++)
			{
				for (int j = 0; j < ob3.x; j++)
				{
					ob3.matrix[i][j] = 0;
				}
			}

			// для первого
			double* array1 = new double[x * y];
			indikator = 0;
			for (int i = 0; i < y; i++)
			{
				for (int j = 0; j < x; j++)
				{
					array1[indikator] = matrix[i][j];
					//				cout << array2[indikator] << " ";
					indikator++;
				}
			}

			// для второго
			double* array2 = new double[ob1.x + ob1.y];
			indikator = 0;
			for (int i = 0; i < ob1.y; i++)
			{
				for (int j = 0; j < ob1.x; j++)
				{
					array2[indikator] = ob1.matrix[i][j];
					//				cout << array2[indikator] << " ";
					indikator++;
				}
			}


			int indikator1 = 0;
			int indikator2 = 0;
			int newi=0;
			int newj=0;

			int counter = 0;


			// zabiv

			for (int i = 0; i < ob3.y; i++)
			{
				for (int j = 0; j < ob3.x; j++)
				{
					if (indikator1 < x * y)
					{
						ob3.matrix[i][j] = array1[indikator1];
						indikator1++;
					}
					else
					{
						ob3.matrix[i][j] = array2[indikator2];
						indikator2++;
					}
				}
			}



			return ob3;



		} // конец else
//		return ob3;
	}

};

int main()
{
	Dynmas test1;
	test1.creator();
	test1.display();

	Dynmas test2;
	test2.creator();
	test2.display();

	Dynmas test3 = test1 + test2;
	test3.display();

	return 0;
}
