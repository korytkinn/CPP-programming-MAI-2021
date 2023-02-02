#include <iostream>

using namespace std;

class Dynmas
{
    int** matrix;
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
            delete[] matrix[i];
    }

    Dynmas(Dynmas& ob1)
    {
        if ((ob1.matrix != nullptr) && (ob1.x != 0) && (ob1.y != 0))
        {
            matrix = new int* [ob1.y];
            x = ob1.x;
            y = ob1.y;
            for (int i = 0; i < ob1.y; i++)
            {
                matrix[i] = new int[ob1.x];
            }

            for (int i = 0; i < ob1.y; i++)
            {
                for (int j = 0; j < ob1.x; j++)
                {
                    matrix[i][j] = ob1.matrix[i][j];
                }
            }

        }
    }

    Dynmas& operator=(const Dynmas& ob1)
    {
        if (this == &ob1)
        {
            return *this;
        }
        for (int i = 0; i < y; i++)
            delete[] matrix[i];
        matrix = nullptr;
        x = 0;
        y = 0;

        if ((ob1.matrix != nullptr) && (ob1.x != 0) && (ob1.y != 0))
        {
            matrix = new int* [ob1.y];
            x = ob1.x;
            y = ob1.y;
            for (int i = 0; i < ob1.y; i++)
            {
                matrix[i] = new int[ob1.x];
            }

            for (int i = 0; i < ob1.y; i++)
            {
                for (int j = 0; j < ob1.x; j++)
                {
                    matrix[i][j] = ob1.matrix[i][j];
                }
            }
        }

        return *this;

    }

    void creator()
    {
        cout << "Enter strok count: ";
        cin >> y;
        cout << "Enter stolbtsov count: ";
        cin >> x;

        matrix = new int* [y];
        for (int i = 0; i < y; i++)
        {
            matrix[i] = new int[x];
        }


        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                matrix[i][j] = 0;
            }
        }

        cout << "\nEnter first stroka:" << endl;
        for (int i = 0; i < x; i++)
        {
            cout << "\nEnter Matrix[" << 0 << "][" << i << "]: ";
            cin >> matrix[0][i];
        }

        cout << "\nEnter first stolbets:" << endl;
        for (int i = 0; i < y; i++)
        {
            cout << "\nEnter Matrix[" << i << "][" << 0 << "]: ";
            cin >> matrix[i][0];
        }

        for (int i = 1; i < y; i++)
        {
            for (int j = 1; j < x; j++)
            {
                matrix[i][j] = matrix[i][0] * matrix[0][j];
            }
        }


        /*
        cout << "Enter matrix[" << y << "][" <<x <<"]:"<<endl;
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                cout << "\nEnter Matrix[" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
        */
    }
    void display()
    {
        cout << "\nMatrix:" << endl;
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                cout << matrix[i][j] << "\t";
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

    return 0;
}
