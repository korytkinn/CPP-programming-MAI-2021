#include <iostream>
using namespace std;

const int K=10;

class DinMas
{
    int*Mas;
    int RazMas;
public:
    DinMas(const DinMas &ob); //копирование запрещено
    DinMas& operator=(const DinMas &ob); //Присваивание запрещено
    DinMas(int x)
    {
        RazMas = K;
        Mas = new int[RazMas];
        for(int i=0; i<RazMas;i++)
            Mas[i]=x;
    }
    ~DinMas()
    {
        delete[]Mas;
    }
    void Show()
    {
        for(int i =0;i<RazMas;i++)
            cout<<" "<<Mas[i];
    }
};

int main()
{
    DinMas Massiv1(1), Massiv2(2);
    cout<<"\n Massive1:\n";
    Massiv1.Show();
    cout<<"\n Massive2:\n";
    Massiv2.Show();

    //DinMas Massiv3=Massiv1; //Попытка копирования
    //Massiv2=Massiv1;        //Попытка присвоения

    //Massiv1=Massiv1+Massiv2; //Попытка сложения
    return 0;
}
