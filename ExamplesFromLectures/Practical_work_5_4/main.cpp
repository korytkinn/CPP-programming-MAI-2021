#include <iostream>

using namespace std;
//Передача параметра в родительский конструктор

//Синтаксис передачи параметра через конструктор наследник
//базовому конструктуру (возможно ошибка в формулировке, но первая окей)
class A{
    //Данные
public:
    A(int x) {}

};
class B: public A {
    //Данные
public:
    B(int x): A(x){}
    };
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
