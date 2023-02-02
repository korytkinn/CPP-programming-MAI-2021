#include <iostream>

using namespace std;
class Sorter
{
    // приватная область
    //int arraySize = 0;
    //int realSize = 0;

    double* massiv;
    double* massivSecond; //если старый заполнили элементами полностью
//    int rowCount, columnCount;
    int MassiveLength = 0;
    int MassivePosition = 0;
//    int number = 999;
    double number = 999;
    int oldSize = 2;

    const int Jump = 2;

    double** matrix;
    int rowCount, columnCount;

    int maxPartIndikator = 0;
    double deltaIndikator = 0;
    int partsCount = 2;

    int* stroka1;
    int* stroka2;

public:

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
        n = MassiveLength;
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
    }

    bool check(int* a1, int* a2, int maxPart)
    {

        /*
        //проверяю ЧИСЛО НУЛЕЙ
        int zeroCount = rowCount * columnCount - MassiveLength; // число нулей в матрице
        //        cout << "\nChislo nuley v matrix = " << zeroCount << endl;
        //
                //Теперь проверим, что число нулей в матрице = число нулей в двух сочетаниях
        int zeroIndikator = 0; //индикатор количества нулей в двух сочетаниях
        for (int i = 0; i < maxPart; i++)
        {
            //            if (a1[i] == 0)
            if (a1[i] == 0)
            {
                zeroIndikator++;
            }
            //            if (a2[i] == 0)
            if (a2[i] == 0)
            {
                zeroIndikator++;
            }
        }



        zeroIndikator -= maxPart - columnCount;
        //cout << "\nReal zeroCount = " << zeroCount << ", zeroIndikator = " << zeroIndikator << endl;
        if (zeroIndikator > zeroCount) //возвращаем false, если число нулей в матрице и в двух сочетаниях не совпало
        {
            //            return false;
            return false;
        }

        for (int i = columnCount; i < maxPart; i++)
        {
            bool error = false;
            if (a1[i] != 0)
            {
                error = true;
            }
            //            if (a2[i] == 0)
            if (a2[i] != 0 && error)
            {
                return false;
            }
        }
        */


        //проверяю то, что один элемент должен совпасть (не более ОДНОГО)
        int sameIndikator = 0; //индикатор числа совпавших чисел
        for (int i = 0; i < columnCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                if ((a1[i] != 0) && a1[i] == a2[j])
                {
                    return false;
                }
            }
        }

        //проверяю размерность
        // не должно превышать rowCount и columnCount
        int razmer1 = 0;
        int razmer2 = 0;
        for (int i = 0; i < rowCount; i++) // проверка по строкам
        {
            if (a1[i] != 0)
            {
                razmer1++;
            }
            if (a2[i] != 0)
            {
                razmer2++;
            }
        }
        if (razmer1 + razmer2 != MassiveLength)
        {
            return false;
        }
        //конец проверки размерности

        /*
        //совпавший элемент перемещаю на нулевую позицию в обоих массивах
        for (int i = 0; i < columnCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                if (a1[i] == a2[j])
                {
                    int karman1, karman2;
                    karman1 = a1[0]; //запомнили 0-й элемент
                    karman2 = a2[0]; //запомнили 0-й элемент

                    a1[0] = a1[i];
                    a2[0] = a2[j];

                    a1[i] = karman1;
                    a2[j] = karman2;

                    i = columnCount;
                    break;
                }
            }
        }
        */
        return true;
    }

    double deltaCalculator(int* a1, int* a2, int maxPart) // калькулятор
    {
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < maxPart; i++)
        {
            if (a1[i] - 1 >= 0)
            {
                sum1 = sum1 + massiv[a1[i] - 1] - (int)massiv[a1[i] - 1];
            }
            if (a2[i] - 1 >= 0)
            {
                sum2 = sum2 + massiv[a2[i] - 1] - (int)massiv[a2[i] - 1];
            }
        }

        sum1 -= (int)sum1;
        sum2 -= (int)sum2;
        if (sum1 >= sum2)
        {
            return sum1;
//            return sum1 - sum2;
        }
        else
        {
            return sum2;
        }
    }

    void display() //много логики сделать позже
    {
        //для теста
        cout << "\nResult array: " << endl;
        for (int i = 0; i < rowCount; i++)
        {
                if (stroka1[i] > 0)
                {
                    cout << massiv[stroka1[i] - 1] << " "; // забиваем строку первую
                }
                else
                {
                    cout << " 0 ";
                }
        }
        cout << endl;
        for (int i = 0; i < rowCount; i++)
        {
            if (stroka2[i] > 0)
            {
                cout << massiv[stroka2[i] - 1] << " "; // забиваем строку первую
            }
            else
            {
                cout << " 0 ";
            }
        }

        cout << "\ndelta = " << deltaIndikator << endl;
    }

    void creator()
    {
        massiv = new double[oldSize]; //задаем размер массива

        for (int i = 0; i < oldSize; i++) //зануляем массив
        {
            massiv[i] = 0;
        }


        cout << "\nEnter int elements: ";
        while (number != 0)
        {
            cin >> number;

            if (number == 0)
                break;


            massiv[MassivePosition] = number;
            MassivePosition++;

            if (MassivePosition == oldSize) // достигли заполнения массива
            {
                massivSecond = new double[oldSize + Jump]; //задаем размер массива

                for (int i = oldSize; i < oldSize + Jump; i++) //зануляем новый массив
                {
                    massivSecond[i] = 0;
                }

                for (int i = 0; i < oldSize; i++) //копируем элементы
                {
                    massivSecond[i] = massiv[i];
                }
                delete[] massiv;

                massiv = massivSecond; //смена указателя
                oldSize += Jump;
            }
        }
        MassiveLength = MassivePosition;
        for (int i = 0; i < MassiveLength; i++)
        {
            cout << massiv[i] << " ";
        }
        cout << endl;


        // одномерный массив создали, тепеь нужно сделать из этого двумерный массив


        cout << "\nReal size: " << MassiveLength << endl;

        //NEW LOGIC
        rowCount = MassiveLength-1;
        columnCount = MassiveLength-1;

        /*
        int sizeSqrt = sqrt(MassiveLength); // кв.корень из длины массива
        rowCount = sizeSqrt;
        columnCount = sizeSqrt;
        if (rowCount == 1)
        {
            rowCount++;
        }
        if (columnCount == 1)
        {
            columnCount++;
        }
        cout << "sizeSqrt = " << sizeSqrt << endl;
        while (rowCount * columnCount < MassiveLength) {
            rowCount = rowCount + 1;
        }
        */


        //можно еще добавить +1 строке, если все еще не хватает мест для элементов
        matrix = new double* [rowCount]; // rowCount строки в массиве
        for (int count = 0; count < (rowCount); count++)
            matrix[count] = new double[columnCount]; // и columnCount столбцов


        // зануляем массив
        for (int i = 0; i < (rowCount); i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                matrix[i][j] = 0;
            }
        }


        // двумерный массив создали, теперь нужно скопировать элементы из одномерного массива
        int p = 0;
        for (int i = 0; i < (rowCount); i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                if (p < MassiveLength)
                {
                    matrix[i][j] = massiv[p];
                    p++;
                }
                else
                {
                    break;
                }
            }
        }

        // вывод двумерного массива в консоль ДЛЯ ТЕСТА!!!!!!!!!!
        for (int i = 0; i < (rowCount); i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    } // конец функции creator

    void devider()
    {
        double deltaBest = 2147483647;
        //        int partsCount = 2;

        //NEW LOGIC
        int maxPart = MassiveLength-1;


        /*
        if (rowCount > maxPart)
        {
            maxPart = rowCount;
        }
        */

        cout << "Maxpart = " << maxPart << endl;

        //maxPartIndikator = maxPart;

        int combinations = 0;
        for (int i = 1; i <= maxPart; i++)
        {
            combinations = combinations + combininations(MassiveLength, i);
            cout << combininations(MassiveLength, i) << endl;
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

        //забиваем массив, ОТ БОЛЬШЕГО К МЕНЬШЕМУ


        int realComby = 0; // суммируются сочетания, чтобы отступать от уже забитых чисел
        for (int i = 1; i <= maxPart; i++)
        {
            //            int k = 0;
            int comby = 0;

            comby = combininations(MassiveLength, i);

            cout << "comby=" << comby << endl;
            algoritm(indixes, realComby, i);
            realComby = realComby + comby;

            //            k++;
        }


        // Окей, массив забили. теперь нужна еще логика!!!

        //просто вывод всех комбинаций в консоль
        for (int i = 0; i < combinations; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                if (indixes[i][j] != 0)
                {
                    cout << massiv[indixes[i][j] - 1] << " "; // забиваем строку первую
                }
            }
            cout << endl;
        }






        stroka1 = new int[maxPart]; //задаем размер массива
        stroka2 = new int[maxPart]; //задаем размер массива
        //запуска цикл проверок и так далее
        for (int i = 0; i < combinations - 1; i++)
        {
            for (int j = i + 1; j < combinations; j++)
            {
                int* a1 = indixes[i];
                int* a2 = indixes[j];
                if (check(a1, a2, maxPart) == true)
                {
                    double delta = deltaCalculator(a1, a2, maxPart);
                    cout << "Up" << i << ", Delta = " << delta << endl;
                    if (delta < deltaBest)
                    {

                        deltaBest = delta;
                        deltaIndikator = delta;

                        //копируем новые строки в массивы (запоминаем)

                        for (int p = 0; p < maxPart; p++)
                        {
                            stroka1[p] = indixes[i][p];
                            stroka2[p] = indixes[j][p];
                        }
                    }
                    if (delta == 0)
                    {
                        i = combinations;
                        break;
                    }
                }
            }
        } // конец цикла проверок


        //ВЫВОД ДЛЯ ТЕСТА
        cout << "\nStroka1  = ";
        for (int i = 0; i < maxPart; i++)
        {
            //            cout << stroka1[i] << " ";

            cout << stroka1[i] << " ";

        }
        cout << "\nStroka2  = ";
        for (int i = 0; i < maxPart; i++)
        {
            cout << stroka2[i] << " ";

        }



        /*
        int zeroCount = 0;
        for (int i = columnCount; i < maxPart; i++)
        {
            if (stroka1[i] == 0)
            {
                zeroCount++;
            }
        }
        if (rowCount - columnCount != zeroCount)
        {
            int* s1 = stroka1;
            stroka1 = stroka2;
            stroka2 = s1;
        }

        for (int i = 0; i < columnCount; i++)
        {
            if (stroka1[i] > 0)
            {
                matrix[0][i] = massiv[stroka1[i] - 1]; // забиваем строку первую
            }
            else
            {
                matrix[0][i] = 0;
            }
        }
        for (int i = 0; i < rowCount; i++)
        {
            if (stroka2[i] != 0)
            {
                matrix[i][0] = massiv[stroka2[i] - 1]; // забиваем строку первую
            }
            else
            {
                matrix[i][0] = 0;
            }
        }
        */

        //Осталось забить матрицу меньшего размера оставшимися числами.

        /*

        int* blockedIndixes;
//        int BlockedLength = rowCount + columnCount - 1;
        int BlockedLength = rowCount + columnCount - 1;
        blockedIndixes = new int[BlockedLength]; //задаем размер массива
        for (int i = 0; i < columnCount; i++)
        {
            blockedIndixes[i] = stroka1[i];
        }
        for (int i = 1; i < rowCount; i++)
        {
            blockedIndixes[i + columnCount - 1] = stroka2[i];
        }

        cout << "Blocked indixes = ";
        for (int i = 0; i < BlockedLength; i++)
        {
            cout << blockedIndixes[i] << " ";
        }
        //Теперь забиваем оставшимися числами матрицу меньшего размера columnCount == rowCount

        int Index = 1;
        for (int i = 1; i < rowCount; i++)
        {
            for (int j = 1; j < columnCount; j++)
            {
                for (int m = 0; m < BlockedLength; m++)
                {
                    if (Index == blockedIndixes[m])
                    {
                        Index++;
                        m = -1;
                        continue;
                    }
                }
                matrix[i][j] = massiv[Index - 1]; //забиваем первый столбец
                cout << "matrix new = " << matrix[i][j] << endl;
                Index++;
            }
        }

        */


    } //конец функции devider





};


int main()
{
    Sorter test;
    test.creator();
    test.devider();
    test.display();

}
