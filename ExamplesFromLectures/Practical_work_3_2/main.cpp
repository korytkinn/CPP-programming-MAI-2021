#include <iostream>

using namespace std;

class A //���������� ������
{
    int x; //�������� ����������
public:
    int y; //�������� ����������
} /*����� ������ ����� ��������� �������*/;

int main()
{
    A ob1, ob2; //���������� ���� �������� ������ ������
    ob1.y=3;
    ob2.y=7;
    cout<<"ob1.y="<<ob1.y<<" ob2.y="<<ob2.y<<endl;

//    ob1.x=5;
    return 0;
}
