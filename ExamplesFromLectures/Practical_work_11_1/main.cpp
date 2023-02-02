#include <iostream>

using namespace std;

class intX
{
    int x;
public:
    friend intX operator+(intX&ob1, intX&ob2); //передаем аргумент по ссылке
};
intX operator+(intX&ob1, intX&ob2)
{
//    return intX(ob1.x+ob2.x);
    intX ob3;
    ob3.x = ob1.x+ob2.x;
    return ob3;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
