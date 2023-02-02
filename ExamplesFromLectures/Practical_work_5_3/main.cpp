#include <iostream>

using namespace std;
class A;
class B;
class C;
class D;

class A{
    public:
    A(){cout<<"konstryktor classa A\n"<<endl;};
    ~A(){cout<<"destryktor classa A\n"<<endl;};
    void display()
    {
    cout<< "hello"<< endl;
    }
};

class B{
    public:
    B(){cout<<"konstryktor classa B\n"<<endl;};
    ~B(){cout<<"destryktor classa B\n"<<endl;};
        void display() {
    cout<< "hello"<< endl;}
};

class C{
    public:
    C(){cout<<"konstryktor classa C\n"<<endl;};
    ~C(){cout<<"destryktor classa C\n"<<endl;};
        void display() {
    cout<< "hello"<< endl;}
};

class D: public A, public B, public C{
    public:
    D(){cout<<"konstryktor classa D\n"<<endl;};
    ~D(){cout<<"destryktor classa D\n"<<endl;};
        void display() {
    cout<< "hello"<< endl;}
};

int main()
{
    A ob1;
    B ob2;
    C ob3;
    D ob4;

    return 0;
}
