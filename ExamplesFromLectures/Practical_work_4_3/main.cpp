#include <iostream>

using namespace std;

class DM
{
    int*Mas; //��������� ������, ����� �� ���� 1
    //�� ������� ������� ��� ������
    int K; // ������ �������
public:
    DM(){Mas=nullptr; K=0;} //����������� �������������� ������ ������
    ~DM(){delete[]Mas;} //���������� ����������� ������
};
int main()
{
    return 0;
}
