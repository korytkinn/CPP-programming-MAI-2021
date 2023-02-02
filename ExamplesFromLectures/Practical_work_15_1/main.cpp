#include <iostream>

using namespace std;

int main()
{
    int a=5;
    int&ra=a;

//    int&rb=10; // не можем направить на временное выражение

//    int&rd=a+2; //не можем направить

    const int&re=12; //константную ссылку можем направить
    const int&rg=a-4;
    // на самом деле спецификатор const делает некоторые вещи статическими

    //попытаемся произвести изменения
//    re=a+10;
//    rg=3;
    //изменения выше категорически не приемлемы

    int&&rc=100;
    cout << "rc=" << rc << endl;
    rc++;
    cout << "rc=" << rc << endl;
    rc=50;
    cout << "rc=" << rc << endl;


    return 0;
}
