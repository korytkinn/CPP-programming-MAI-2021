#include <iostream>

using namespace std;

class Parter
{


//    int* massiv = new int[arraySize]; // не нужно

    int arraySize = 0;
    int* massiv; // оригинальный массив, на время тестирования выключим

//    int arraySize = 11;
//    int arraySize = 5;
//    int arraySize = 8;
//    int massiv[11] = { 10,1,2,1,2,1,2,1,2,5,5 };
//    int massiv[11] = { 5,2,6,1,7 };
//    int massiv[8] = { 5,4,9,3,231,3,2,1 };



    int* mas1;
    int* mas2;
    int* mas3;

    int divpos1 = 0;
    int divpos2 = 0;

public:
    Parter()
    {
        massiv = nullptr;
        mas1 = nullptr;
        mas2 = nullptr;
        mas3 = nullptr;
    }

    ~Parter()
    {
        delete[]massiv;
        delete[]mas1;
        delete[]mas2;
        delete[]mas3;
    }



    void creator()
    {
        // на время тестирования динамику выключим


        //        int arraySize = 0;
        cout << "Please enter next things:\n";
        cout << "Array size (3 and above): ";
        cin >> arraySize;

        massiv = new int[arraySize]; //задаем размер массива

        cout << "Enter array elements (" << arraySize << "):\n";
        for (int i = 0; i < arraySize; i++)
            cin >> massiv[i];
    }

    void devider()
    {
        if (arraySize == 0)
        {
            cout << "nothing entered, bye" << endl;
            return;
        }

        // сумму элементов
        int sum = 0;
        for (int i = 0; i < arraySize; i++)
        {
            sum = sum + massiv[i];
        }

        // сумму на 3 делим
        int sumPart = sum / 3;

        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;

        int delta1 = 0;
        int delta2 = 0;
        int deltaRes = 0;
//        int delta3 = 0;

//        int divpos1 = 0;
//        int divpos2 = 0;



        // делим пробуем
        for (int i = 1; i < arraySize; i++) //первое индекс
        {

            for (int j = (i+1); j < (arraySize); j++) //второй индекс
            {

                // сумма первая
                for (int p = 0; p < i; p++)
                {
                    sum1 = sum1 + massiv[p];
                }

                // сумма вторая
                for (int q = i; q < j; q++)
                {
//                    cout << "q=" << q << endl; // OTKUDA

                    sum2 = sum2 + massiv[q];
                }

                // третья вторая
                for (int r = j; r < arraySize; r++)
                {
                    sum3 = sum3 + massiv[r];
                }


                if (i == 1 && j == 2)
                {
                    deltaRes = 10000;
                }


                /*
                if (i == 1 && j == 2) //стартовая дельта
                {
                    delta1 = sum1 - sum2;
                    if (delta1 < 0)
                        delta1 = delta1 * -1;

                    delta2 = sum3 - sum2;
                    if (delta2 < 0)
                        delta2 = delta2 * -1;

                    if (delta1 > delta2)
                    {
                        deltaRes = delta1;
                        divpos1 = i;
                        divpos2 = j;
                    }
                    else
                    {
                        deltaRes = delta2;
                        divpos1 = i;
                        divpos2 = j;
                    }
                }
                */


                int deltaTest1 = 0;
                int deltaTest2 = 0;
                int deltaTestRes = 0;

                deltaTest1 = sum1 - sum2;


                if (deltaTest1 < 0)
                    deltaTest1 = deltaTest1 * -1;

//                cout << "deltaTest1=" << deltaTest1 << endl;

                deltaTest2 = sum3 - sum2;
                if (deltaTest2 < 0)
                    deltaTest2 = deltaTest2 * -1;

//                cout << "deltaTest2=" << deltaTest2 << endl;

                if (deltaTest1 > deltaTest2)
                {
                    deltaTestRes = deltaTest1;
                }
                else
                {
                    deltaTestRes = deltaTest2;
                }

                //сравниваем текущую дельту с предыдущей

//                if (deltaRes > deltaTestRes)
                if (deltaTestRes < deltaRes)
                {
                    deltaRes = deltaTestRes;
                    divpos1 = i;
                    divpos2 = j;
                }

//                cout << "divposers:" << divpos1 << " " << divpos2 << endl;


                sum1 = 0;
                sum2 = 0;
                sum3 = 0;

            }
        }


//        cout << "divposers:" << divpos1 << " " << divpos2 << endl;
        // индексы есть, можем заполнять массивы

                //забиваем первый массив
        mas1 = new int[divpos1]; //задаем размер первого массива

        for (int i = 0; i < divpos1; i++)
        {
            mas1[i] = massiv[i];
        }

        //забиваем второй массив
        mas2 = new int[divpos2-divpos1]; //задаем размер первого массива

        for (int i = divpos1; i < divpos2; i++)
        {
            mas2[i - (divpos1)] = massiv[i];

        }

        //забиваем третий массив
        mas3 = new int[arraySize-divpos2]; //задаем размер первого массива

        for (int i = divpos2; i < arraySize; i++)
        {
            mas3[i - (divpos2)] = massiv[i];

        }


        //delta



        /*
        cout << "\nYour 1st array:\n";
        for (int i = 0; i < divpos1; i++)
        {
            cout << mas1[i] << " ";
        }


        cout << "\nYour 2nd array:\n";
        for (int i = 0; i < divpos2 - divpos1; i++)
        {
            cout << mas2[i] << " ";
        }

        cout << "\nYour 3rd array:\n";
        for (int i = 0; i < arraySize - divpos2; i++)
        {
            cout << mas3[i] << " ";
        }
        */




    }

    void display() //много логики сделать позже
    {
        if (arraySize == 0)
        {
            cout << "nothing entered, bye" << endl;
            return;
        }

        cout << "\nYour main array:\n";
        for (int i = 0; i < arraySize; i++)
        {
            cout << massiv[i] << " ";
        }

                cout << "\nYour 1st array:\n";
        for (int i = 0; i < divpos1; i++)
        {
            cout << mas1[i] << " ";
        }


        cout << "\nYour 2nd array:\n";
        for (int i = 0; i < divpos2 - divpos1; i++)
        {
            cout << mas2[i] << " ";
        }

        cout << "\nYour 3rd array:\n";
        for (int i = 0; i < arraySize - divpos2; i++)
        {
            cout << mas3[i] << " ";
        }

        int sumMain = 0;
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;

        int maxdif = 0;

        for (int i = 0; i < arraySize; i++)
        {
            sumMain=sumMain+massiv[i];
        }

        for (int i = 0; i < divpos1; i++)
        {
            sum1=sum1+mas1[i];
        }

        for (int i = 0; i < divpos2 - divpos1; i++)
        {
            sum2=sum2+mas2[i];
        }

        for (int i = 0; i < arraySize - divpos2; i++)
        {
            sum3=sum3+mas3[i];
        }
        cout << "\nsumMain = " << sumMain << ", sum1 = " << sum1 << ", sum2 = " << sum2 << ", sum3 = " << sum3 <<endl;


        int test1 = sum2-sum1;
        int test2 = sum3-sum1;

        int test3 = sum3-sum2;

        if (test1> test2 && test1 > test3)
        {
            cout << "max differ: " << test1;
        }
        if(test3> test2 && test3 > test1)
        {
            cout << "max differ: " << test3;
        }

        if(test2> test1 && test2 > test3)
        {
            cout << "max differ: " << test2;
        }

        /*
        int size1 = sizeof(mas1);
        int size2 = sizeof(mas2);
        int size3 = sizeof(mas3);


        cout << "\nYour 1st array:\n";
        for (int i = 0; i < size1; i++)
        {
            cout << mas1[i] << " ";
        }

        cout << "\nYour 2nd array:\n";
        for (int i = 0; i < size2; i++)
        {
            cout << mas2[i] << " ";
        }

        cout << "\nYour 3rd array:\n";
        for (int i = 0; i < size3; i++)
        {
            cout << mas3[i] << " ";
        }
        */

    }
};
int main()
{
    Parter test;
    test.creator();
    test.devider();
    test.display();
    return 0;
}
