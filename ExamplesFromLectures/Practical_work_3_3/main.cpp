#include <iostream>

using namespace std;
class A //���������� ������ A
{
    int x; //�������� ����������
public: //�������� ������� ����
    void vv_x(int i) {x=i;} //����� ����� x
    int vozvr_x(){return x;} //����� �������� x
};
int main()
{
    A ob;
    ob.vv_x(5);
    cout<<" ob.x="<<ob.vozvr_x()<<endl;
    return 0;
}
