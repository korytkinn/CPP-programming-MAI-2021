#include <iostream>

using namespace std;

const int K=10;

void ZapMas (int (&M)[K]);
//void ZapMas (int (&M)[10]);
void VivMas (int (&M)[K]);
//void VivMas (int (&M)[10]);
int main()
{
//    int Mas[10];
    int Mas[K];
    ZapMas(Mas);
    VivMas(Mas);
    return 0;
}
void ZapMas (int (&M)[K])
{
    M[0]=0;
    M[1]=1;
    for(int i=2;i<K; i++)
        M[i]=M[i-1]+M[i-2];
}
void VivMas (int (&M)[K]) //массив передается как const, т.к. не подразумевается его изменение.
{
    cout<<" Massiv: ";
    for(int i=0; i<K; i++)
        cout<<M[i]<<" ";
    cout<<endl;

    cout<<sizeof(M)<<endl;
}
