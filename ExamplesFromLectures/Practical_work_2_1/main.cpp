#include <iostream>

using namespace std;
void ZapMas (int *M, const int K);
void VivMas (const int *M, const int K);
int main()
{
    const int K=10;
    int Mas[K];
    ZapMas(Mas,K);
    VivMas(Mas,K);

//    VivMas(Mas,K); // ��� ��� ���������
    for(int i=0; i<10;i++) {
        cout<<Mas[i]<<" ";
    }

    return 0;
}
void ZapMas (int *M, const int K)
{
    M[0]=0;
    M[1]=1;
    for(int i=2;i<K; i++)
        M[i]=M[i-1]+M[i-2];
}
void VivMas (const int *M, const int K) //������ ���������� ��� const, �.�. �� ��������������� ��� ���������.
{
    M++; //������� ���������
//    M[1]=1000; //����� ������, �.�. ������ ��������� �� ������������� ���������
    cout<<" Massiv: ";
    for(int i=0; i<K; i++)
        cout<<M[i]<<" ";
    cout<<endl;
}
