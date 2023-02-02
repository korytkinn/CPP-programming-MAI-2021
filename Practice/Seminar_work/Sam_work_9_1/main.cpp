#include <iostream>

using namespace std;

class Kolichestvo
{
    static int kolvo;
public:
    Kolichestvo()
    {
        kolvo++;
    }
/*
    Kolichestvo(const Kolichestvo &a)
    {
        kolvo++;
    }
    */
    ~Kolichestvo()
    {
        kolvo--;
    }
    static int Display()
    {
     cout << "Kolichestvo = " << kolvo << endl;
    }
};
int Kolichestvo::kolvo=0;

int main()
{
    Kolichestvo::Display(); // = 0
    Kolichestvo test;
    Kolichestvo *test2 = new Kolichestvo();
    test.Display(); // = 2

    delete test2;
    test.Display(); // = 1
    return 0;
}
