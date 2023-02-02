#include <iostream>

using namespace std;
void f1(const int *const M, const int K)
{
//  M++;
    for(int i=0; i<K;i++)
        cout<<" "<<M[i];
    cout<<endl;
//  M[0]=12345;
}
int main()
{
    const int K=3;
    int Mas[K]={10,20,30};
//  Mas++;
    cout<<" Adres massiva Mas: "<<Mas<<endl;
    f1(Mas,K);
    for(int i=0; i<K; i++)
        cout<<" "<<Mas[i];
    cout<<endl;
    return 0;
}
