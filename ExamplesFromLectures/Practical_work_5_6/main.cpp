#include <iostream>

using namespace std;
//Передача параметров при множественном наследовании
class A{
    //Данные
public:
    A(int x) {}
};
class B{
    //Данные
public:
    B(int y) {}
};
class C: public A, public B {
    //Данные
    C(int z, int x, int y): A(x), B(y) {} //z для C, x для A, y для B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
