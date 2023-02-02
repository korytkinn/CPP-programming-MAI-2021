#include <iostream>
using namespace std;

class A
{
    int x;
    static int y;

public:
    //конструкторов деструкторов в этом примере касаться не будем, чтобы не усложнять
    void show_x() { cout<<" x="<<x<<endl;}
    void static show_y() { cout<<" y="<<y<<endl;}
    void set_x(int t) {x=t;}
    void static set_y(int t) {y=t;}

};
int A::y=-1;
int main()
{
    //статическими членами можно пользоваться без объявления объектов класса
    //если не делаем явную инициализацию A::y=**, то статические данные инициализируются нулем

    A::show_y();
    A::set_y(999);
    A::show_y();


    A ob1, ob2;
    ob1.set_x(1);
    ob1.set_y(10);
    ob1.show_x();
    ob1.show_y();

    ob2.set_x(2);
    ob2.set_y(20);
    ob2.show_x();
    ob2.show_y();
    ob1.show_y(); // вывод переменной y, видим что она =20,

    return 0;
}
