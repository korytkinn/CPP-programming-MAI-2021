#include <iostream>

using namespace std;
class A
{
public:
    A(){cout<<" Vizvan konstryktor klassa A\n";}
    ~A(){cout<<" Vizvan destryktor klassa A\n";}
};
class B
{
    int z;
public:
    B(int x) {cout<<" Vizvan konstryktor klassa B\n";
    z=x;}
    ~B() {cout<<" Vizvan destryktor klassa B\n";
    cout<<" z="<<z<<endl;}
};
int main()
{
    A ob;
    B ob2(10);
    cout << "Hello world!" << endl;
    return 0;
}
