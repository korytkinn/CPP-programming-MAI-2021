#include <iostream>

using namespace std;

class Dynamic
{
    int** matrix = nullptr;
    int* massiv = nullptr;
    int x = 0;
    int y = 0;
    int number = 0;
public:

    Dynamic(const Dynamic& ob); //копирование запрещено
    Dynamic& operator=(const Dynamic& ob); //Присваивание запрещено

    friend int sum(const Dynamic &dyn1);
    friend int sum(const Dynamic &dyn1, const Dynamic &dyn2);
    friend int sum(const Dynamic &dyn1, const Dynamic &dyn2, const Dynamic &dyn3);
    friend int sum(const Dynamic &dyn1, const Dynamic &dyn2, const Dynamic &dyn3, const Dynamic &dyn4);

    Dynamic(int x_user, int number_user)
    {
        while(x_user <=0)
        {
            cout << "Wrong massiv size = " << x_user << "\nEnter new correct x>=1:\n";
            cin >> x_user;
        }
        x = x_user;
        number = number_user;

        massiv = new int[x];
        for (int i = 0; i < x; i++)
        {
            massiv[i] = number;
        }
    }
    Dynamic(int x_user, int y_user, int number_user)
    {
        while(x_user <=0)
        {
            cout << "Wrong size of x = " << x_user << "\nEnter new correct x>=1:\n";
            cin >> x_user;
        }
        while(y_user <=0)
        {
            cout << "Wrong size of y = " << y_user << "\nEnter new correct y>=1:\n";
            cin >> y_user;
        }

        x = x_user;
        y = y_user;
        number = number_user;
        matrix = new int* [y]; // rowCount строки в массиве
        for (int count = 0; count < (y); count++)
            matrix[count] = new int[x]; // и columnCount столбцов

        // зануляем массив
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
        if (matrix != nullptr)
        {
            cout << "\nMatrix:" << endl;
            for (int i = 0; i < y; i++)
            {
                for (int j = 0; j < x; j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "\nMassiv:" << endl;

            for (int i = 0; i < x; i++)
            {
                cout << massiv[i] << " ";
            }
            cout << endl;
        }



    }
};

int sum(const Dynamic &dyn1) {
    int summa = 0;
    if(dyn1.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
//        cout << "massiv nullptr" << endl;

        for (int i = 0; i < dyn1.y; i++)
        {
            for (int j = 0; j < dyn1.x; j++)
            {
                summa += dyn1.matrix[i][j];
            }
        }


    }
    if(dyn1.matrix == nullptr) //если у нас одномерный массив
    {
//        cout << "matrix nullptr" << endl;

        for (int i = 0; i < dyn1.x; i++)
        {
            summa+= dyn1.massiv[i];
        }

    }
    return summa;
} //конец sum для одного аргумента

int sum(const Dynamic &dyn1, const Dynamic &dyn2) {
    int sum1 = 0;
    int sum2 = 0;

    //проверка для dyn1
    if(dyn1.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn1.y; i++)
        {
            for (int j = 0; j < dyn1.x; j++)
            {
                sum1 += dyn1.matrix[i][j];
            }
        }

    }
    if(dyn1.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn1.x; i++)
        {
            sum1+= dyn1.massiv[i];
        }
    }

    //проверка для dyn2
    if(dyn2.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn2.y; i++)
        {
            for (int j = 0; j < dyn2.x; j++)
            {
                sum1 += dyn2.matrix[i][j];
            }
        }

    }
    if(dyn2.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn2.x; i++)
        {
            sum1+= dyn2.massiv[i];
        }
    }
    return sum1+sum2;
} //конец функции для двух аргументов

int sum(const Dynamic &dyn1, const Dynamic &dyn2, const Dynamic &dyn3) {
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    //проверка для dyn1
    if(dyn1.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn1.y; i++)
        {
            for (int j = 0; j < dyn1.x; j++)
            {
                sum1 += dyn1.matrix[i][j];
            }
        }

    }
    if(dyn1.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn1.x; i++)
        {
            sum1+= dyn1.massiv[i];
        }
    }

    //проверка для dyn2
    if(dyn2.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn2.y; i++)
        {
            for (int j = 0; j < dyn2.x; j++)
            {
                sum1 += dyn2.matrix[i][j];
            }
        }

    }
    if(dyn2.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn2.x; i++)
        {
            sum1+= dyn2.massiv[i];
        }
    }


    //проверка для dyn3
    if(dyn3.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn3.y; i++)
        {
            for (int j = 0; j < dyn3.x; j++)
            {
                sum1 += dyn3.matrix[i][j];
            }
        }

    }
    if(dyn3.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn3.x; i++)
        {
            sum1+= dyn3.massiv[i];
        }
    }

    return sum1+sum2+sum3;
} //конец функции для трех аргументов

int sum(const Dynamic &dyn1, const Dynamic &dyn2, const Dynamic &dyn3, const Dynamic &dyn4) {
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int sum4 = 0;

    //проверка для dyn1
    if(dyn1.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn1.y; i++)
        {
            for (int j = 0; j < dyn1.x; j++)
            {
                sum1 += dyn1.matrix[i][j];
            }
        }

    }
    if(dyn1.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn1.x; i++)
        {
            sum1+= dyn1.massiv[i];
        }
    }

    //проверка для dyn2
    if(dyn2.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn2.y; i++)
        {
            for (int j = 0; j < dyn2.x; j++)
            {
                sum1 += dyn2.matrix[i][j];
            }
        }

    }
    if(dyn2.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn2.x; i++)
        {
            sum1+= dyn2.massiv[i];
        }
    }


    //проверка для dyn3
    if(dyn3.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn3.y; i++)
        {
            for (int j = 0; j < dyn3.x; j++)
            {
                sum1 += dyn3.matrix[i][j];
            }
        }

    }
    if(dyn3.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn3.x; i++)
        {
            sum1+= dyn3.massiv[i];
        }
    }

    //проверка для dyn4
    if(dyn4.massiv == nullptr) //если у нас двумерный массив (матрица)
    {
        for (int i = 0; i < dyn4.y; i++)
        {
            for (int j = 0; j < dyn4.x; j++)
            {
                sum1 += dyn4.matrix[i][j];
            }
        }

    }
    if(dyn4.matrix == nullptr) //если у нас одномерный массив
    {
        for (int i = 0; i < dyn4.x; i++)
        {
            sum1+= dyn4.massiv[i];
        }
    }

    return sum1+sum2+sum3+sum4;
} //конец функции для четырех аргументов

int main()
{
    Dynamic test1(5, 10);
    Dynamic test2(5, 5, 99);
    Dynamic test3(15,15);
    Dynamic test4(4,4,5);

//    Dynamic bad1(0, 10);
//    Dynamic bad2(0,-1,5);

    //    cout << sum(test1, test2) << endl;

    test1.display();
    test2.display();
    test3.display();
    test4.display();

//    bad1.display();
//    bad2.display();

    cout << "\nsumma1 = " << sum(test1) << ", summa2 = " << sum(test2) << ", summa3 = " << sum(test3) << ", summa4 = " << sum(test4) << endl;
    cout << "test1 = " << sum(test1) << endl;
    cout << "test1+test2 = " << sum(test1,test2) << endl;
    cout << "test1+test2+test3 = " << sum(test1,test2,test3) << endl;
    cout << "test1+test2+test3+test4 = " << sum(test1,test2,test3,test4) << endl;

    return 0;
}
