#include <iostream>

using namespace std;

class Dynamic
{
    int** matrix;
    int* massiv;
    int x = 0;
    int y = 0;
    int number = 0;
public:

    Dynamic(const Dynamic &ob);
    Dynamic& operator=(const Dynamic &ob);


    Dynamic(int x_user, int number_user)
    {
        x = x_user;
        number = number_user;

        massiv = new int[x];
        for(int i =0;i<x;i++)
        {
            massiv[i]=number;
        }
    }
    Dynamic(int x_user, int y_user, int number_user)
    {
        x = x_user;
        y = y_user;
        number = number_user;
        matrix = new int* [y];
        for (int count = 0; count < (y); count++)
            matrix[count] = new int[x];

        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                matrix[i][j] = number;
            }
        }


    }
    ~Dynamic()
    {
        delete[] massiv;

        for (int i = 0; i < y; i++)
        {
                delete[] matrix[i];
        }
    }

    void display()
    {
        if(y != 0)
        {
        cout << "\nMatrix:" << endl;
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout<< endl;
        }
        } else
        {
        cout << "\nMassiv:" << endl;

            for(int i=0;i<x;i++)
            {
                cout << massiv[i] << " ";
            }
                    cout << endl;
        }



    }
};

int main()
{
    Dynamic test1(5,10);
    Dynamic test2(5,5, 99);

    test1.display();
    test2.display();

    return 0;
}
