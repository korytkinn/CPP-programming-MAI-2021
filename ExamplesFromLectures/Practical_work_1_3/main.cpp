#include <iostream>

using namespace std;
void f1(int a, double b);
void f2(int &a, double &b);

int main()
{
    int x=3;
    double y=4.5;
    f1(x,y);
    cout<<" x="<<x<<" y="<<y<<endl;
    f2(x,y);
    cout<<" x="<<x<<" y="<<y<<endl;
    return 0;
}
void f1(int a, double b)
{
    cout<<" a="<<a<<" b="<<b<<endl;
    cout<<" Vvedite celoe chislo: ";
    cin>>a;
    cout<<" Vvedite celoe chislo: ";
    cin>>b;
}

void f2(int &a, double &b)
{
    cout<<" a="<<a<<" b="<<b<<endl;
    cout<<" Vvedite celoe chislo: ";
    cin>>a;
    cout<<" Vvedite celoe chislo: ";
    cin>>b;
}

//первый случай-  передача копированием
//второе случае - управление памятью, изменяем во всей программе

