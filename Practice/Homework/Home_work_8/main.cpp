#include <iostream>
using namespace std;

class Sorter
{
    double massiv[36];
    double** matrix;
    double deltaBest = 2147483647;
    double xSum = 0;
    double ySum = 0;

//    double numbers20[20];
//    double numbers12[12];

    long long combininations(int n, int k)
    {
        long long update = 1;

        int* devides = new int[k];
        for (int i = 1; i <= k; i++)
        {
            devides[i - 1] = i;
        }

        for (int i = n - k + 1; i <= n; i++)
        {
            update *= i;
            for (int j = 0; j < k; j++)
            {
                if (devides[j] != 0 && update % devides[j] == 0)
                {
                    update /= devides[j];
                    devides[j] = 0;
                }
            }
        }
        delete[] devides;
        return update;
    }
    /*
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
}*/

    unsigned int min(unsigned int a, unsigned int b)
    {
        if (a > b)
        {
            return b;
        }
        else return a;
    }

    unsigned int* firstIndixes(unsigned int number) //в точности функция algoritm для первого набора
    {
        unsigned int* indixesFirst = new unsigned int[number];
        for (int i = 0; i < number; i++)
        {
            indixesFirst[i] = i + 1;
        }
        return indixesFirst;
    }

    double deltaCalculator(unsigned int* x_indixes, unsigned int* y_indixes, unsigned int* unusedIndixes, unsigned int xNumbers, unsigned int yNumbers)
    {
        double result = 0;
        for (int i = 0; i < xNumbers; i++)
        {
            result += massiv[x_indixes[i] - 1];
        }
        for (int i = 0; i < yNumbers; i++)
        {
            result -= massiv[unusedIndixes[y_indixes[i] - 1] - 1];
        }
        return abs(result);
    }

    void clearIndixes(unsigned int numbers, unsigned int* indixes)
    {
        for (int i = 0; i < numbers; i++)
        {
            indixes[i] = i + 1;
        }
    }
    void copyIndex(unsigned int* startPoint, unsigned int* endPoint, unsigned int size)
    {
        for (int i = 0; i < size; i++)
        {
            endPoint[i] = startPoint[i];
        }
    }
    void copyIndex(unsigned int* startPoint, unsigned int* endPoint, unsigned int size, unsigned int* unusedIndixes)
    {
        for (int i = 0; i < size; i++)
        {
            endPoint[i] = unusedIndixes[startPoint[i] - 1];
        }
    }
    void getComby(unsigned int numbers, unsigned int* indixes, int& i, unsigned int size)
    {
        while (i >= 0)
        {
            if (indixes[i] < size - numbers + i + 1)
            {
                indixes[i]++;
            }
            else
            {
                i--;
                continue;
            }
            for (int p = i + 1; p < numbers; p++)
            {
                indixes[p] = indixes[p - 1] + 1;
            }
            if (i < numbers - 1)
            {
                i = numbers - 1;
            }
            return;
        }
    }


public:
    Sorter()
    {
        matrix = new double* [6];
        for (int i = 0; i < 6; i++)
        {
            matrix[i] = new double[6];
            for (int j = 0; j < 6; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    ~Sorter()
    {
        for (int i = 0; i < 6; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void creator()
    {
        cout << "Enter 36 numbers:" << endl;
        for (int i = 0; i < 36; i++)
        {
            cin >> massiv[i];
        }
    }

    void display()
    {

        //вывод матрицы
        for (int y = 0; y < 6; y++)
        {
            for (int x = 0; x < 6; x++)
            {
                cout << matrix[y][x] << "\t";
            }
            cout << endl;
        }

        //вывод дельты
        cout << "\ndeltaBest = " << deltaBest << endl;

        cout << "xSum = " << xSum << ", ySum = " << ySum << endl;
    }




    void calculator()
    {
        cout << "\nCalculator start working!\n";
        int xNumbers = 20;
        int yNumbers = 12;

        //число комбинаций
        long long xCombinations = combininations(36, xNumbers);
        long long yCombinations = combininations(16, yNumbers);

        int x_i = xNumbers - 1;
        int y_i = yNumbers - 1;

        //забиваем первым сочитанием
        unsigned int* x_indixes = firstIndixes(xNumbers);
        unsigned int* y_indixes = firstIndixes(yNumbers);

        unsigned int* bestX = new unsigned int[xNumbers];
        unsigned int* bestY = new unsigned int[yNumbers];
        double deltaIndikator = 0;

        unsigned int unusedIndixes[16];
        unsigned int g = 1; //просто индекс

        unsigned long long xLong = 0;
        unsigned int currentXmax = 0;

        while (xLong < xCombinations)
        {
            currentXmax = min(4294967295, xCombinations - currentXmax);
            for (unsigned int x = 0; x < currentXmax; x++)
            {
                y_i = yNumbers - 1;

                g = 1;
                for (int k = 0; k < 16; k++)
                {
                    for (int p = 0; p < xNumbers; p++)
                    {
                        if (g == x_indixes[p])
                        {
                            g++;
                            p = -1;
                            continue;
                        }
                    }
                    unusedIndixes[k] = g;
                    g++;
                }
                clearIndixes(yNumbers, y_indixes);

                for (int y = 0; y < yCombinations; y++)
                {
                    deltaIndikator = deltaCalculator(x_indixes, y_indixes, unusedIndixes, xNumbers, yNumbers);
                    if (deltaIndikator < deltaBest)
                    {
                        cout << "\npreview_Updated delta = " << deltaIndikator << endl;
                        copyIndex(x_indixes, bestX, xNumbers);
                        copyIndex(y_indixes, bestY, yNumbers, unusedIndixes);
                        deltaBest = deltaIndikator;

                        if (deltaBest == 0)
                        {
                            x = xCombinations;
                            xLong = xCombinations;
//                            cout << "\nStart breaking!\n";
                            break;
                        }
                    }


                    getComby(yNumbers, y_indixes, y_i, 16);
                }
                getComby(xNumbers, x_indixes, x_i, 36);
            }
            currentXmax += 4294967295;
        }

        for (int i = 0; i < xNumbers; i++)
        {
            xSum += massiv[bestX[i] - 1];
        }

        for (int i = 0; i < yNumbers; i++)
        {
            ySum += massiv[bestY[i] - 1];


        }

        //забиваем матрицу
        for (int i = 0; i < 6; i++)
        {
            matrix[0][i] = massiv[bestX[i] - 1];
        }
        for (int i = 6; i < 11; i++)
        {
            matrix[i-5][5] = massiv[bestX[i] - 1];
        }
        for (int i = 11; i < 16; i++)
        {
            matrix[5][15-i] = massiv[bestX[i] - 1];
        }
        for (int i = 16; i < 20; i++)
        {
            matrix[20-i][0] = massiv[bestX[i] - 1];
        }

        for (int i = 0; i < 4; i++)
        {
            matrix[1][i + 1] = massiv[bestY[i] - 1];
        }
        for (int i = 4; i < 7; i++)
        {
            matrix[i - 3 + 1][4] = massiv[bestY[i] - 1];
        }
        for (int i = 7; i < 10; i++)
        {
            matrix[4][9-i+1] = massiv[bestY[i] - 1];
        }
        for (int i = 10; i < 12; i++)
        {
            matrix[11-i+2][1] = massiv[bestY[i] - 1];
        }

        int lastIndex = 1;
        for (int y = 2; y < 4; y++)
        {
            for (int x = 2; x < 4; x++)
            {
                bool found = false;
                for (int i = 0; i < xNumbers; i++)
                {
                    if (lastIndex == bestX[i])
                    {
                        lastIndex++;
                        i = -1;
                    }
                }
                for (int i = 0; i < yNumbers; i++)
                {
                    if (lastIndex == bestY[i])
                    {
                        lastIndex++;
                        i = -1;
                        found = true;
                    }
                }
                if (found)
                {
                    x--;
                    continue;
                }
                matrix[y][x] = massiv[lastIndex - 1];
                lastIndex++;
            }
        }
//        int indixes20[20];
//        int indixes12[12];

//        int numbers16[16];

    }

};


int main()
{
    Sorter test;
    test.creator();
    test.calculator();
    test.display();
}
