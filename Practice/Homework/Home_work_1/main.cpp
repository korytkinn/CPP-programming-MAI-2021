#include <iostream>

using namespace std;

void input(int massiv[]);
void adder(int aMassiv[], int bMassiv[]);

int main()
{
//    int aMassiv[10] = { 1000,123,15,25,16,78,99,85,45,10 };
    int aMassiv[10];
    int bMassiv[20];
    input(aMassiv);
    adder(aMassiv, bMassiv);


    return 0;
}

void input(int massiv[])
{
    cout << "Please, enter 10 int elements (first array):" << endl;
    for (int i = 0; i < 10; i++)
        cin >> massiv[i];
}

void adder(int aMassiv[], int bMassiv[])
{
    for (int i = 0; i < 10; i++)
    {
        int sumChet = 0;
        int sumNechet = 0;
        while (aMassiv[i] != 0)
        {
            int current = aMassiv[i] % 10; // берем крайнюю правую цифру
            if (current % 2 == 0) //если остаток от делени€ на 2 = 0, то прибавл€ем к сумме четных
            {
                sumChet = sumChet + current;
            }
            if (current % 2 != 0) //если остаток от делени€ на 2 != 0, то прибавл€ем к сумме Ќ≈четных
            {
                sumNechet = sumNechet + current;
            }
            aMassiv[i] /= 10;

        }
        bMassiv[2*i] = sumNechet;
        bMassiv[2*i + 1] = sumChet;

    }


    cout << "\nSecond array with new 20 elements:" << endl;
    for (int m = 0; m < 20; m++)
    {
        cout << bMassiv[m] << " ";
    }

 //   cout << "\n\nEach first - sumNechet;\nEach second - sumChet.";
}
