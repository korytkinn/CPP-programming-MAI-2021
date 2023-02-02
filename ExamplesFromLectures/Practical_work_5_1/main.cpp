#include <iostream>

using namespace std;
class A;
class B;
class A{
    int xa;
public:
    A(){cout<<" Konstryktor classa A\n";}
    ~A(){cout<<" Destryktor classa A\n";}
    void vvod_xa(int i){xa=i;}
    int vivod_xa(){return xa;}
};
class B: public A{ // класс B наследует класс A
    int xb;
public:
    B(){cout<<" Konstryktor classa B\n";}
    ~B(){cout<<" Destryktor classa B\n";}
    void vvod_xb(int i){xb=i;}
    int vivod_xb(){return xb;}
};
int main()
{
    B ob;
    ob.vvod_xb(1);
    cout<<" ob.xb=" << ob.vivod_xb()<<endl;
    ob.vvod_xa(2);
    cout<<" ob.xa=" << ob.vivod_xa()<<endl;
    return 0;
}
