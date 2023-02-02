#include <iostream>
using namespace std;

class Integral {
    int a, b;
    double h;
    double integralRes = 0;
    int n;

    double integral(double x)
    {
        return ((x*x/ 100) + 1);
    }

public:

    void creator()
    {
        cout << "Enter a = ";
        cin >> a;
        cout << "\nEnter b = ";
        cin >> b;
        cout << "\nEnter h = ";
        cin >> h;
    }

    void calculator()
    {
        double fParts = 0;
        for (double i = a+h; i < b; i=i+h)
        {
            fParts = fParts + integral(i);
        }

        integralRes = h * ((integral(a) + integral(b)) / 2 + fParts);
    }

    void display()
    {
        cout << "\nIntegral x^2/100+1 from " << a << " to " << b << " with h = " << h << " equal " << integralRes << endl;
    }

};


int main()
{
    Integral test;
    test.creator();
    test.calculator();
    test.display();
}
