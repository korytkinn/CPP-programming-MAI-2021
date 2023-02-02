#include <iostream>

using namespace std;

class A;
class B;

class A
{
    static const unsigned int Razmer{10};
    double Mas[Razmer];
public:
    A(): Mas{1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10}
    {
    }
    friend void SovmestniiVivod(const A&ob1, const B&ob2);
};
class B
{
    static const unsigned int Razmer{6};
    int Mas[Razmer];
public:
    B(): Mas{2,4,6,8,10,12}
    {
    }
    friend void SovmestniiVivod(const A&ob1, const B&ob2);
};

int main()
{
    A ob1;
    B ob2;
    SovmestniiVivod(ob1,ob2);
    return 0;
}

void SovmestniiVivod(const A&ob1, const B&ob2)
{
    double maks = ob1.Mas[0];
    double minimum = ob1.Mas[0];

    for(int i=0; i<ob1.Razmer;i++)
    {
        if(ob1.Mas[i]>maks)
        {
            maks = ob1.Mas[i];
        }
        if(ob1.Mas[i]<minimum)
        {
            minimum = ob1.Mas[i];
        }
    }

        for(int i=0; i<ob2.Razmer;i++)
    {
        if(ob2.Mas[i]>maks)
        {
            maks = ob2.Mas[i];
        }
        if(ob2.Mas[i]<minimum)
        {
            minimum = ob2.Mas[i];
        }
    }
    cout << "Minimum = " << minimum<<", Maximum = " << maks << endl;
/*
    const unsigned int Razmer = ob1.Razmer+ob2.Razmer;
    int Mas[Razmer];
    int buff;
    unsigned int j=0;
    for(unsigned int i = 0;i<ob1.Razmer;i++)
        Mas[j++]=ob1.Mas[i];
    for(unsigned int i = 0;i<ob2.Razmer;i++)
        Mas[j++]=ob2.Mas[i];
    for(unsigned int i = 0;i<Razmer-1;i++)
        for(unsigned int j=0; j< Razmer-1-i;j++)
            if(Mas[j]<Mas[j+1])
            {
                buff=Mas[j];
                Mas[j]=Mas[j+1];
                Mas[j+1]=buff;
            }
    cout<< " Rezyltat sovmesheniya i sortirovki:\n";
    for(unsigned int i =0;i<Razmer;i++)
        cout<<" " << Mas[i];
    cout<<endl;
    */
}
