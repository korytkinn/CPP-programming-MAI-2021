#include <iostream>

using namespace std;

class Matrix
{
    int matrix[3][3];

public:
    Matrix()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    friend Matrix operator+(const Matrix& m1, const Matrix& m2);

    friend Matrix operator*(const Matrix& m1, const Matrix& m2);

    void display()
    {
        cout << "\nYour matrix:\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void creator()
    {
        cout << "New matrix creation process." << endl;
        cout << "Enter 9 elements:" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "\nEnter Matrix[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

};

//&m1 и &m2 - это константные ссылки на переданный аргумент
Matrix operator+(const Matrix& m1, const Matrix& m2)
{
    Matrix m3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m3.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }
    return m3;
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
    Matrix m3;
    // Умножение матриц
//    c = new double* [row1];
    for (int i = 0; i < 3; i++) // кол-во строк первой матрицы
    {
//        c[i] = new double[3];
        for (int j = 0; j < 3; j++) // кол-во столцов второй матрицы
        {
            m3.matrix[i][j] = 0;
            for (int k = 0; k < 3; k++) // кол-во столбцов первой матрицы
                m3.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
        }
    }
    return m3;
}

int main()
{
    Matrix test1;
    Matrix test2;

    test1.creator();
    test2.creator();

    test1.display();
    test2.display();

    Matrix test3 = test1 + test2;
    test3.display();

    Matrix test4 = test1 * test2;
    test4.display();

}
