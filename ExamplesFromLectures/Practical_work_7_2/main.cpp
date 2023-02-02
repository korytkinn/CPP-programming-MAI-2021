#include <iostream>

using namespace std;

const int K=10;

class DinMas
{
    int*Mas;
    int RazMas;
public:
    DinMas& operator=(const DinMas &ob);
    DinMas(int x);
    ~DinMas();
    void Show();
};
int main()
{
    DinMas Massiv1(1), Massiv2(2);
    cout<<"\n Massive1:\n";
    Massiv1.Show();
    cout<<"\n Massive2:\n";
    Massiv2.Show();
    Massiv2=Massiv1;
//    cout<<"\n Posle Massiv2=Massiv1:\n";
    cout<<"\n Massive1:\n";
    Massiv1.Show();
    cout<<"\n Massive2:\n";
    Massiv2.Show();
    return 0;
}
DinMas& DinMas::operator=(const DinMas &ob)
{
    if(this==&ob)
        return *this;
    for(int i=0;i<RazMas;i++)
        Mas[i]=ob.Mas[i];
    cout<<"\n Pereopredelennoe prisvoenie\n";
    return *this;
}
DinMas::DinMas(int x)
{
    RazMas = K;
    Mas=new int[RazMas];
    for(int i =0; i< RazMas; i++)
        Mas[i]=x;
}
DinMas::~DinMas()
{
    delete[]Mas;
    Mas=nullptr;
    cout<<"\n Destryktor porabotal\n";
}
void DinMas::Show()
{
    for(int i=0; i<RazMas; i++)
        cout<<" "<<Mas[i];
    cout<<"\n Adress nachala massiva: "<<Mas<<endl;
}
