#include <iostream>

using namespace std;
class Sorter
{
    // ��������� �������
    //int arraySize = 0;
    //int realSize = 0;

    int* massiv;
    int* massivSecond; //���� ������ ��������� ���������� ���������
//    int rowCount, columnCount;
    int MassiveLength = 0;
    int MassivePosition = 0;
    int number = 999;
    int oldSize = 2;

    const int Jump = 2;

    int** matrix;
    int rowCount, columnCount;

    int maxPartIndikator = 0;
    int deltaIndikator = 0;
    int partsCount = 2;

    int* stroka1;
    int* stroka2;

//public:

int mySqrt(int x)
{
    // ����
    if (x == 0 || x == 1)
    return x;

    // �������� � 1, ������� ��� ����� ��
    // i*i ������ ��� ����� x
    int i = 1, result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return i - 1;
}


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

    // �������� ���������� - ��������

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
        //�������� ����� �����
        int zeroCount = rowCount * columnCount - MassiveLength; // ����� ����� � �������
        //        cout << "\nChislo nuley v matrix = " << zeroCount << endl;
        //
                //������ ��������, ��� ����� ����� � ������� = ����� ����� � ���� ����������
        int zeroIndikator = 0; //��������� ���������� ����� � ���� ����������
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
        if (zeroIndikator > zeroCount) //���������� false, ���� ����� ����� � ������� � � ���� ���������� �� �������
        {
            //            return false;
            return false; // ������ ��� ���� ���������� �����, ���� ���� �� ������� �� ������� ��� �������! (��� 5 ������)
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


        //�������� ��, ��� ���� ������� ������ �������� (�� ����� ������)
        int sameIndikator = 0; //��������� ����� ��������� �����
        for (int i = 0; i < columnCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                if (a1[i] == a2[j])
                {
                    sameIndikator++;
                    if (sameIndikator > 1)
                    {
                        return false;
                    }
                }
            }
        }
        if (sameIndikator == 0) //���� ��������� ����� >1 ��� = 0, �� ���������� false
        {
            return false;
        }

        //�������� �����������
        // �� ������ ��������� rowCount � columnCount
        int razmer1 = 0;
        int razmer2 = 0;
        for (int i = 0; i < rowCount; i++) // �������� �� �������
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
        if (razmer1 > rowCount || razmer2 > rowCount)
        {
            return false;
        }

        razmer1 = 0;
        razmer2 = 0;
        for (int i = 0; i < columnCount; i++) // �������� �� ��������
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
        if (razmer1 > columnCount || razmer2 > columnCount)
        {
            return false;
        }
        //����� �������� �����������

        //��������� ������� ��������� �� ������� ������� � ����� ��������
        for (int i = 0; i < columnCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                if (a1[i] == a2[j])
                {
                    int karman1, karman2;
                    karman1 = a1[0]; //��������� 0-� �������
                    karman2 = a2[0]; //��������� 0-� �������

                    a1[0] = a1[i];
                    a2[0] = a2[j];

                    a1[i] = karman1;
                    a2[j] = karman2;

                    i = columnCount;
                    break;
                }
            }
        }
        return true;
    }

    int deltaCalculator(int* a1, int* a2, int maxPart) // �����������
    {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < maxPart; i++)
        {
            if (a1[i] - 1 >= 0)
            {
                sum1 = sum1 + massiv[a1[i] - 1];
            }
            if (a2[i] - 1 >= 0)
            {
                sum2 = sum2 + massiv[a2[i] - 1];
            }
        }
        if (sum1 > sum2)
        {
            return sum1 - sum2;
        }
        if (sum2 > sum1)
        {
            return sum2 - sum1;
        }
        return 0;
    }

    public:

    void display() //����� ������ ������� �����
    {
        //��� �����
        cout << "\nReal array: " << endl;
        for (int i = 0; i < rowCount; i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                cout << matrix[i][j] << " "; // ������� ������
                //cout << finalArray[i][j] << " "; // ������� ������
            }
            cout << endl;
        }
        cout << endl;
        cout << "delta = " << deltaIndikator << endl;
    }

    void creator()
    {
        massiv = new int[oldSize]; //������ ������ �������

        for (int i = 0; i < oldSize; i++) //�������� ������
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

            if (MassivePosition == oldSize) // �������� ���������� �������
            {
                massivSecond = new int[oldSize + Jump]; //������ ������ �������

                for (int i = oldSize; i < oldSize + Jump; i++) //�������� ����� ������
                {
                    massivSecond[i] = 0;
                }

                for (int i = 0; i < oldSize; i++) //�������� ��������
                {
                    massivSecond[i] = massiv[i];
                }
                delete[] massiv;

                massiv = massivSecond; //����� ���������
                oldSize += Jump;
            }
        }
        MassiveLength = MassivePosition;
        for (int i = 0; i < MassiveLength; i++)
        {
            cout << massiv[i] << " ";
        }
        cout << endl;


        // ���������� ������ �������, ����� ����� ������� �� ����� ��������� ������

//        int realSize = 0;
        /*for (int i = 0; i < oldSize; i++) //������� ����� ���������
        {
            //            cout << massiv[i] << " ";
            if (massiv[i] != 0)
            {
                realSize++;
            }
        }*/
        //realSize = indikator;
        cout << "\nReal size: " << MassiveLength << endl;

//        int sizeSqrt = sqrt(MassiveLength); // ��.������ �� ����� ������� ��������
        int sizeSqrt = mySqrt(MassiveLength); // ��.������ �� ����� �������
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

        //����� ��� �������� +1 ������, ���� ��� ��� �� ������� ���� ��� ���������
        matrix = new int* [rowCount]; // rowCount ������ � �������
        for (int count = 0; count < (rowCount); count++)
            matrix[count] = new int[columnCount]; // � columnCount ��������


        // �������� ������
        for (int i = 0; i < (rowCount); i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                matrix[i][j] = 0;
            }
        }


        // ��������� ������ �������, ������ ����� ����������� �������� �� ����������� �������
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

        // ����� ���������� ������� � ������� ��� �����!!!!!!!!!!
        for (int i = 0; i < (rowCount); i++)
        {
            for (int j = 0; j < columnCount; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    } // ����� ������� creator

    void devider()
    {
        int deltaBest = 2147483647;
        //        int partsCount = 2;

        int maxPart = columnCount;
        if (rowCount > maxPart)
        {
            maxPart = rowCount;
        }

        cout << "Maxpart = " << maxPart << endl;

        //maxPartIndikator = maxPart;

        int combinations = 0;
        for (int i = 1; i <= maxPart; i++)
        {
            combinations = combinations + combininations(MassiveLength, i);
            cout << combininations(MassiveLength, i) << endl;
        }
        cout << "Chislo kombinatsiy: " << combinations << endl;


        // ���������� ���������� ������������� ������� �� ** ���������:
        int** indixes = new int* [combinations]; // combinations ������ � �������
        for (int count = 0; count < combinations; count++)
            indixes[count] = new int[maxPart]; // � maxPart ��������


        // �������� ������
        for (int i = 0; i < combinations; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                indixes[i][j] = 0;
            }
        }

        //�������� ������, �� �������� � ��������


        int realComby = 0; // ����������� ���������, ����� ��������� �� ��� ������� �����
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


        // ����, ������ ������. ������ ����� ��� ������!!!

        //������ ����� ���� ���������� � �������
        /*for (int i = 0; i < combinations; i++)
        {
            for (int j = 0; j < maxPart; j++)
            {
                cout << indixes[i][j] << " ";
            }
            cout << "\n";
        }*/
        stroka1 = new int[maxPart]; //������ ������ �������
        stroka2 = new int[maxPart]; //������ ������ �������
        //������� ���� �������� � ��� �����
        for (int i = 0; i < combinations - 1; i++)
        {
            for (int j = i + 1; j < combinations; j++)
            {
                int* a1 = indixes[i];
                int* a2 = indixes[j];
                if (check(a1, a2, maxPart) == true)
                {
                    int delta = deltaCalculator(a1, a2, maxPart);

                    if (delta < deltaBest)
                    {
                        cout << "Up" << i << ", Delta = " << delta << endl;
                        deltaBest = delta;
                        deltaIndikator = delta;

                        //�������� ����� ������ � ������� (����������)

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
        } // ����� ����� ��������


        //����� ��� �����
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



        // ����� ���� �� ����� �������� ������ �������, ������ ������ ��������. columnCount rowCount

        // ������, ���� columnCount == rowCount
        /*if (columnCount == rowCount)
        {
            for (int i = 0; i < columnCount; i++)
            {
                if (stroka1[i] != 0)
                {
                    matrix[0][i] = massiv[stroka1[i] - 1]; // �������� ������ ������
                }
                else
                {
                    matrix[0][i] = 0; // �������� ������ ������
                }
                if (stroka2[i] != 0)
                {
                    matrix[i][0] = massiv[stroka2[i] - 1]; //�������� ������ �������
                }
                else
                {
                    matrix[i][0] = 0; //�������� ������ �������
                }

            }
        }*/

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
                matrix[0][i] = massiv[stroka1[i] - 1]; // �������� ������ ������
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
                matrix[i][0] = massiv[stroka2[i] - 1]; // �������� ������ ������
            }
            else
            {
                matrix[i][0] = 0;
            }
        }


        //�������� ������ ������� �������� ������� ����������� �������.

        int* blockedIndixes;
        int BlockedLength = rowCount + columnCount - 1;
        blockedIndixes = new int[BlockedLength]; //������ ������ �������
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
        //������ �������� ����������� ������� ������� �������� ������� columnCount == rowCount

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
                matrix[i][j] = massiv[Index - 1]; //�������� ������ �������
                cout << "matrix new = " << matrix[i][j] << endl;
                Index++;
            }
        }




    } //����� ������� devider





};


int main()
{
    Sorter test;
    test.creator();
    test.devider();
    test.display();

}
