#include <iostream>

using namespace std;
class A;
class B;
class C;
class D;
class E;
class A
{
    //���� ������
};
class B: public A{ //B -����������� ����� �� ������ A
// ���� ������
};
class C: public B{ //� - ����������� ����� �� ������ B
// ���� ������
};
class D{
// ���� ������
};
class E: public A, public D { // E - ����������� ����� ��
// ���� ������ // ������ A � ������ D
};

int main()
{
    return 0;
}
