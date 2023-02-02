#include <iostream>

using namespace std;

int main()
{
    const int a=3;
    int*pA;
    // pA=&a; //на константу указатель сделать нельзя

    const int*pB;
    pB=&a; //указатель можно сделать, т.к. указатель константный
    // a=5;
    // *pB=5;
    pB=nullptr; //указание на ноль
    return 0;
}
