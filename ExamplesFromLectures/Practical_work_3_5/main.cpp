#include <iostream>

using namespace std;

class A
{
    int x;
public:
    void vvx(int i) {x=i;}
    int vozx(){return x;}
    A(){cout<<" Zarabotal konstryktor klassa A\n";} //возвращаемого типа нет, название как у типа класса, параметры могут быть только у конструктора
    ~A(){cout<<" Zarabotal destryktor klassa A\n";}
};
int main()
{
    A ob; //появилась надпись о том, что заработал конструктор
    //конструктор вызывается при создании объекта
    ob.vvx(5);
    cout<<" ob.x="<<ob.vozx()<<endl;
    return 0; //появилась надпись, что заработал деструктор
    //деструктор вызывается при уничтожении, когда программа выходит из области видимости.
}
