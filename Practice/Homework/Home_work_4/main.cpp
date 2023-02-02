#include <iostream>

using namespace std;

class Parter
{
    //    int* massiv = new int[arraySize]; // не нужно

    int arraySize = 0;
    int* massiv; // оригинальный массив, на время тестирования выключим
    int partsCount = 0;

    int** indikatorArray;
    int maxPartIndikator = 0;
    int deltaIndikator = 0;

    //    int arraySize = 11;
    //    int arraySize = 5;
    //    int arraySize = 8;
    //    int massiv[11] = { 10,1,2,1,2,1,2,1,2,5,5 };
    //    int massiv[11] = { 5,2,6,1,7 };
    //    int massiv[8] = { 5,4,9,3,231,3,2,1 };



//    int* mas1;
//    int* mas2;
//    int* mas3;

        long long combininations(int n, int k)
    {
        long long Up = 1;

        for (int i = n - k + 1; i <= n; i++)
        {
            Up *= i;
        }
        for (int V = 1; V <= k; V++)
        {
            Up /= V;
        }
        return Up;
    }

    // Алгоритм комбинации - функциий

    bool NextSet(int* a, int n, int m)
    {
        int k = m;
        for (int i = k - 1; i >= 0; --i)
            if (a[i] < n - k + i + 1)
            {
                ++a[i];
                for (int j = i + 1; j < k; ++j)
                    a[j] = a[j - 1] + 1;
                return true;
            }
        return false;
    }
    void adder(int* a, int n, int indikator, int** indixes, int smeshenie)
    {
        for (int i = 0; i < n; i++)
            indixes[smeshenie + indikator][i] = a[i];
        //        cout << a[i] << " ";
    //    cout << endl;
    }

    void algoritm(int** indixes, int smeshenie, int k)
    {
        int n, m, * a;
        //        cout << "N = ";
        //        cin >> n;
        n = arraySize;
        //        cout << "M = ";
        //        cin >> m;
        m = k;
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        int indikator = 0;
        adder(a, m, indikator, indixes, smeshenie);
        indikator++;
        if (n >= m)
        {
            while (NextSet(a, n, m))
            {
                //                adder(a, m);
                adder(a, m, indikator, indixes, smeshenie);
                indikator++;
            }
        }



        /*
        // arraySize - сколько чисел юзер ввел

        int* masWork = new int[razmerGroup]; //группа размера razmerGroup


        for (int i = 0; i < razmerGroup; i++)
        {
            masWork[i] = i+1; // забили индексами подряд от 1 до razmergroup
        }

        int sochetanie = combininations(arraySize, razmerGroup);


        for (int i = 0; i < sochetanie; i++)
        {
            for (int j = 0; j < razmerGroup; j++)
            {
                indixes[smeshenie + i][j] = masWork[j];
            }

            if (masWork[razmerGroup - 1] < arraySize - razmerGroup + (razmerGroup - 1))
            {
                masWork[razmerGroup - 1]++;
            }
        }

        */
    }

    void adder2(int* a, int n, int* indixes) // функция для одномерного массива
    {
        for (int i = 0; i < n; i++)
            indixes[i] = a[i];

        //        cout << a[i] << " ";
    //    cout << endl;
    }


    //    void algoritm2(int* sochetaniya, int combinations, int partsCount, int** finalArray, int maxPart, int** indixes) // функция для одномерного массива
    void algoritm2(int* sochetaniya, int combinations, int** finalArray, int maxPart, int** indixes) // функция для одномерного массива
    {
        int n, m, * a;
        //        cout << "N = ";
        //        cin >> n;
        n = combinations;
        //        cout << "M = ";
        //        cin >> m;
        m = partsCount;
        a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = i + 1;

        adder2(a, m, sochetaniya); // уникальные индексы строк здесь

        //забиваем finalArray первой и второй строкой из массива indixes
        cout << "final array FIRST\n";
        for (int i = 0; i < partsCount; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                finalArray[i][j] = indixes[i][j];
                cout << finalArray[i][j] << " ";
            }
        }

        int arrayRazmer = 0;
        //проверка на то, что колво чисел совпадет с колвом введенным пользователем
        for (int i = 0; i < partsCount; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                if (finalArray[i][j] != 0)
                {
                    arrayRazmer++;
                }
            }
        }
        cout << "arrayRazmer" << arrayRazmer << endl;

        //ПРОВЕРКУ здесь выключаем, по сути позднее проверим. нам нужны только начальные данные
        /*
        //проверка что колво чисел в массиве совпадает с колвом введеным пользователем
        if (arrayRazmer == arraySize)
        {
            cout << "\nYes, razmer sovpadaet\n";
        }
        else
        {
            cout << "\nNo, razmer ne sovpadaet\n";
        }
        */


        // считаем сумму элементов, присваеваем максу и мину

        int maximum = 0;
        int minimum = 0;

        int delta = 999; // int max value

        // присваиваем начальные значения max и min, чтобы дальше было с чем работать
        maximum = summer(finalArray[0], maxPart);
        minimum = maximum;

        cout << "delta = " << delta << endl;
        cout << "maximum = " << maximum << endl;
        cout << "minimum = " << minimum << endl;


        int sumWorks = 0;

        /*
         for (int i = 1; i < partsCount; i++) // строка
         {
             sumWorks = summer(finalArray, i, maxPart);
             if (sumWorks > maximum)
             {
                 maximum = sumWorks;
             }
             if (sumWorks < minimum)
             {
                 minimum = sumWorks;
             }
         }


         // считаем дельту как разность max & min
         //delta = maximum - minimum;
         delta = 999;
         cout << "delta = " << delta << endl;
         cout << "maximum = " << maximum << endl;
         cout << "minimum = " << minimum << endl;
         */

         //        cout << sochetaniya[0] << " " << sochetaniya[1] << endl;


                        // Работа с финальным масивом - запоминающим


        if (n >= m)
        {
            while (NextSet(a, n, m))
            {
                adder2(a, m, sochetaniya); // уникальные индексы строк здесь
                //cout << sochetaniya[0] << " " << sochetaniya[1] << endl;

                /*cout << "Sochetania\n";
                for(int v=0;v<partsCount;v++)
                {
                    cout << sochetaniya[v]<<" ";
                }
                cout << endl;*/
                //забиваем finalArray строками из индексов массива sochetaniya
                //cout << "final array SECOND\n";
                for (int i = 0; i < partsCount; i++)
                {
                    for (int j = 0; j < maxPart; j++)
                    {
                        finalArray[i][j] = indixes[sochetaniya[i] - 1][j];
                        //cout << finalArray[i][j] << " "; // выводит массив
                    }
                    // cout << endl;
                }
                // cout << endl;



                 // здесь логика проверки чисел на валидность, дальше поиск максимума и нимимума, затем дельты

                arrayRazmer = 0;
                //проверка на то, что колво чисел совпадет с колвом введенным пользователем
                for (int i = 0; i < partsCount; i++)
                {
                    for (int j = 0; j < maxPart; j++)
                    {
                        if (finalArray[i][j] != 0)
                        {
                            arrayRazmer++;
                        }
                    }
                }
                //cout << arrayRazmer;
                //cout << endl;




                //                cout << "arrayRazmer" << arrayRazmer << endl;

                                //проверка что колво чисел в массиве совпадает с колвом введеным пользователем
                if (arrayRazmer == arraySize)
                {
//                    cout << "\nYes, razmer sovpadaet\n";
                    //Размер совпал, можем работать дальше.



                    // нужно проверить, что все индексы уникальные

                    if (flag(finalArray, maxPart) == true)
                    {


                        //                        cout << "flag == true\n";
                        //cout << "error\n";
                        continue; // идем в while дальше искать.


                    }
                    else // Хорошо, все числа индексов УНИКАЛЬНЫ
                    {
                        // можем работать с массивом
                        cout << "\nVse 4isla unikalnie\n";

                        //забиваем finalArray строками из индексов массива sochetaniya
                        cout << "\nfinal array THIRD\n";
                        for (int i = 0; i < partsCount; i++)
                        {
                            for (int j = 0; j < maxPart; j++)
                            {
                                if (sochetaniya[i] - 1 >= 0) {
                                    cout << finalArray[i][j] << " "; // выводит массив
                                }
                            }
                            cout << endl;
                        }
                        cout << endl;
                        cout << "Working\n";
                        // ТЕПЕРЬ работаем с максимум, минимум, дельтой

                        sumWorks = summer(finalArray[0], maxPart);
                        maximum = sumWorks;
                        minimum = sumWorks;

                        //                        sumWorks = summer(finalArray, 2, maxPart);
                        for (int i = 0; i < partsCount; i++) // строка
                        {
                            sumWorks = summer(finalArray[i], maxPart);
                            cout << "\nSumworks THIRD = " << sumWorks << endl;
                            if (sumWorks > maximum)
                            {
                                maximum = sumWorks;
                            }
                            if (sumWorks < minimum)
                            {
                                minimum = sumWorks;
                            }
                            cout << endl << sumWorks;
                        }

                        // считаем дельту как разность max & min


                        int deltaTest = maximum - minimum;
                        if (deltaTest < delta)
                        {
                            for (int i = 0; i < partsCount; i++)
                            {
                                for (int j = 0; j < maxPart; j++)
                                {
                                    indikatorArray[i][j] = finalArray[i][j];
                                    //cout << "indikator = " << indikatorArray[i][j];
                                }
                            }
                            delta = deltaTest;
                            deltaIndikator = deltaTest;
                        }
                        cout << "delta = " << delta << endl;
                        cout << "maximum = " << maximum << endl;
                        cout << "minimum = " << minimum << endl;

                        //для теста
                        cout << "\nReal array: " << endl;
                        for (int i = 0; i < partsCount; i++)
                        {
                            for (int j = 0; j < maxPart; j++)
                            {
                                if (finalArray[i][j] != 0)
                                {
                                    cout << massiv[finalArray[i][j] - 1] << " "; // выводит массив
                                    //cout << finalArray[i][j] << " "; // выводит массив
                                }

                            }
                            cout << endl;
                        }
                        cout << endl;



                        //delta = maximum - minimum;

                    //delta = maximum - minimum;
                    //cout << "delta = " << delta << endl;
                    //cout << "maximum = " << maximum << endl;
                    //cout << "minimum = " << minimum << endl;
                    }


                }
                else
                {
                    continue;
                }

            }
        }
    }


    bool flag(int** finalArray, int maxPart)
    {

        for (int i = 0; i < partsCount; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                for (int p = i; p < partsCount; p++)
                {
                    for (int q = 0; q < maxPart; q++)
                    {
                        //                        if (finalArray[i][j] != finalArray[p][q] && (i == p && j != q) || (i != p))
                        if (finalArray[i][j] == finalArray[p][q] && ((i == p && j != q) || (i != p)) && finalArray[i][j] > 0)
                        {
//                            cout << "i=" << i << " j=" << j << " p=" << p << " q=" << q << endl;
                            return true;
                        }
                        else
                        {
                            // ничего не делаем
                            //return true;
                        }
                    }
                }
            }
        }
        return false;
    }


    int summer(int* massiv2, int maxPart)
    {
        int sum = 0;
        for (int i = 0; i < maxPart; i++)
        {
            //sum = sum + massiv[index][i];
//            cout << "znachenie = " << massiv2[index][i] << endl; // для теста
//            cout << "znachenie = " << massiv[massiv2[index][i] - 1] << endl; // для теста
            if (massiv2[i] - 1 >= 0) {
                sum = sum + massiv[massiv2[i] - 1];
            }
        }
        return sum;
    }




public:

    Parter()
    {
        massiv = nullptr;

    }

    ~Parter()
    {
        delete[]massiv;

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

        cout << "Na skolko chastei razdelit massiv: ";
        cin >> partsCount;
    }



    void devider()
    {
        int maxPart = arraySize - partsCount + 1; // максимальное число элементов в группе
//        maxPartIndikator = maxPart;
        /*if (arraySize % maxPart != 0)
        {
            maxPart++;
        }*/
        cout << "Maxpart = " << maxPart << endl;

        maxPartIndikator = maxPart;


        int combinations = 0;
        for (int i = 1; i <= maxPart; i++)
        {
            combinations = combinations + combininations(arraySize, i);
            cout << combininations(arraySize, i) << endl;
        }
        cout << "Chislo kombinatsiy: " << combinations << endl;

        // объявление двумерного динамического массива на ** элементов:
        int** indixes = new int* [combinations]; // combinations строки в массиве
        for (int count = 0; count < combinations; count++)
            indixes[count] = new int[maxPart]; // и maxPart столбцов


        // зануляем массив
        for (int i = 0; i < combinations; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                indixes[i][j] = 0;
            }
        }


        //забиваем массив

        int realComby = 0; // суммируются сочетания, чтобы отступать от уже забитых чисел
        for (int i = 0; i <= partsCount; i++)
        {
            //            int k = 0;
            int comby = 0;

            if (i != 0)
            {
                comby = combininations(arraySize, maxPart - i + 1);
            }
            realComby = realComby + comby;
            cout << "comby=" << comby << endl;
            algoritm(indixes, realComby, maxPart - i);
            //            k++;
        }

        // Окей, массив забили. теперь нужна еще логика!!!



        /*
        * работает схема
        algoritm(indixes, 0, maxPart);
        cout << "\nmaxpart = " << maxPart << endl;
        algoritm(indixes, 10, maxPart-1);
        cout << "\nmaxpart = " << maxPart-1 << endl;

        algoritm(indixes, 20, maxPart-2);
        cout << "\nmaxpart = " << maxPart-2 << endl;
        */


        for (int i = 0; i < combinations; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                cout << indixes[i][j] << " ";
            }
            cout << "\n";
        }

        // теперь одномерный массив заполняю сочетаниями
        int* sochetaniya;
        sochetaniya = new int[partsCount]; //задаем размер массива


        int** finalArray = new int* [partsCount]; // combinations строки в массиве
        for (int count = 0; count < partsCount; count++)
            finalArray[count] = new int[maxPart]; // и maxPart столбцов


        // зануляем массив
        for (int i = 0; i < partsCount; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                finalArray[i][j] = 0;
            }
        }


        indikatorArray = new int* [partsCount]; // combinations строки в массиве
        for (int count = 0; count < partsCount; count++)
            indikatorArray[count] = new int[maxPart]; // и maxPart столбцов


        // зануляем массив
        for (int i = 0; i < partsCount; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                indikatorArray[i][j] = 0;
            }
        }

        // работаем
        /*
//      int realComby = 0; // суммируются сочетания, чтобы отступать от уже забитых чисел
        int operations = combininations(combinations, partsCount);
        for (int i = 0; i <= operations; i++)
        {
//            int comby = 0;

//            if (i != 0)
//            {
//                comby = combininations(arraySize, maxPart - i + 1);
//            }
//            realComby = realComby + comby;
//            cout << "comby=" << comby << endl;
            algoritm2(sochetaniya, combinations, partsCount);
//            cout << sochetaniya[0] << " " << sochetaniya[1] << endl;
        }
        */
        //        algoritm2(sochetaniya, combinations, partsCount, finalArray, maxPart, indixes);
        algoritm2(sochetaniya, combinations, finalArray, maxPart, indixes);




    }

    void display() //много логики сделать позже
    {
        //для теста
        cout << "\nResult: " << endl;
        for (int i = 0; i < partsCount; i++)
        {
            for (int j = 0; j < maxPartIndikator; j++)
            {
                if (indikatorArray[i][j] != 0)
                {
                    cout << massiv[indikatorArray[i][j] - 1] << " "; // выводит массив
                    //cout << finalArray[i][j] << " "; // выводит массив

                }

            }
            cout << endl;
        }
        cout << endl;
        cout << "delta = " << deltaIndikator << endl;
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
