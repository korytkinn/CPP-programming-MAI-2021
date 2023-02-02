#include <iostream>

using namespace std;

class A //объ€вление класса
{
    int x; //закрыта€ переменна€
public:
    int y; //открыта€ переменна€
} /*здесь внутри можно объ€вл€ть объекты*/;

int main()
{
    A ob1, ob2; //объ€вление двух объектов одного класса
    ob1.y=3;
    ob2.y=7;
    cout<<"ob1.y="<<ob1.y<<" ob2.y="<<ob2.y<<endl;

//    ob1.x=5;
    return 0;
}
