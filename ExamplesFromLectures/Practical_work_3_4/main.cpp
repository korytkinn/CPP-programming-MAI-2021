#include <iostream>

using namespace std;

class A
{
    int x, y;
public:
    void vvx(int i) {x=i;}
    void vvy(int i) {y=i;}
    int vozx(){return x;}
    int vozy(){return y;}
};
int main()
{
    A ob;
    ob.vvx(5);
    ob.vvy(10);
    cout<<" ob.x="<<ob.vozx();
    cout<<" ob.y="<<ob.vozy();
    return 0;
}
