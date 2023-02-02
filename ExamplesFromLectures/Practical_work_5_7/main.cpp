#include <iostream>

using namespace std;
//Передача параметров при многоуровневому наследовании
class A{
    //Данные
public:
    A(int x) {}
};
class B: public A{
    //Данные
public:
    B(int x, int y): A(x) {} // x для A, y для B
};
class C: public B {
    //Данные
    C(int z, int x, int y): B(y,x) {} // z для C, x и y для B
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
