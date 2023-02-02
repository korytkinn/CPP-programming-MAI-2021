#include <iostream>

using namespace std;

int sum(int a, int b)
{
    return a+b;
}

double sum(double a, int b)
{
    return a+b;
}

double sum(int a, double b)
{
    return a+b;
}

double sum(double a, double b)
{
    return a+b;
}


int main()
{
    int a=5, b = 15;
    double c = 11.8, d=21.7;

    cout << a << " + " << b << " = " << sum(a,b) <<endl;
    cout << a << " + " << c << " = " << sum(a,c) <<endl;
    cout << c << " + " << b << " = " << sum(c,b) <<endl;
    cout << c << " + " << d << " = " << sum(c,d) <<endl;

    return 0;
}
