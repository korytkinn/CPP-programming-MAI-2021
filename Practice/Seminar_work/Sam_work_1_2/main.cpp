#include <iostream>

using namespace std;

int main()
{
    int num;
//    cout <<" x="<<x<<" &x="<<&x<<endl;
    int* pA=&num;
    int* pB=&num;
    int* pC=&num;

    *pA = 10;
    cout<<"*pA="<<*pA<<" pA="<<pA<<" num= "<<num<<endl;

    *pB = 144;
    cout<<"*pB="<<*pB<<" pB="<<pB<<" num= "<<num<<endl;

    *pC = 200;
    cout<<"*pC="<<*pC<<" pC="<<pC<<" num= "<<num<<endl;
//    pA=&x;
//    cout<<" pA="<<pA<<" *pA="<<*pA<<endl;
//    int** pC=nullptr;
//    pC=&pA;
//    cout<<" pC="<<pC<<" *pC="<<*pC<<" **pC="<<**pC<<endl;
    return 0;
}
