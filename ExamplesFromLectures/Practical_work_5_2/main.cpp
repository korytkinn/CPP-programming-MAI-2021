#include <iostream>

// мсфмн ондопюбхрэ щрн!!!!!!!!!!!!!!


using namespace std;
class A;
class B;
class C;
class D;

class A{
    A(){cout<<"konstryktor classa A\n"<<endl;};
    ~A(){cout<<"destryktor classa A\n"<<endl;};
};

class B: public A{
    B(){cout<<"konstryktor classa B\n"<<endl;};
    ~B(){cout<<"destryktor classa B\n"<<endl;};
};

class C: public B {
    C(){cout<<"konstryktor classa C\n"<<endl;};
    ~C(){cout<<"destryktor classa C\n"<<endl;};
};

class D: public C {
    D(){cout<<"konstryktor classa D\n"<<endl;};
    ~D(){cout<<"destryktor classa D\n"<<endl;};
};

int main()
{
    A ob1;
    B ob2;
    C ob3;
    D ob4;
    return 0;
}
