#include <iostream>

using namespace std;
class A;
class B;
class C;
class D;
class E;
class A
{
    //тело класса
};
class B: public A{ //B -производный класс от класса A
// тело класса
};
class C: public B{ //С - производный класс от класса B
// тело класса
};
class D{
// тело класса
};
class E: public A, public D { // E - производный класс от
// тела класса // класса A и класса D
};

int main()
{
    return 0;
}
