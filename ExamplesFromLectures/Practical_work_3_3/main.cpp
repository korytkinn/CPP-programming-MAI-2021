#include <iostream>

using namespace std;
class A //объ€вление класса A
{
    int x; //закрыта€ переменна€
public: //открыта€ область ниже
    void vv_x(int i) {x=i;} //метод ввода x
    int vozvr_x(){return x;} //метод возврата x
};
int main()
{
    A ob;
    ob.vv_x(5);
    cout<<" ob.x="<<ob.vozvr_x()<<endl;
    return 0;
}
