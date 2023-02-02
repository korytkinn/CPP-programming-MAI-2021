#include <iostream>

using namespace std;

int sqrt(int x)
{
    if(x==0 || x==1)
    {
        return x;
    }
    int i = 1;
    int result = 1;
    while(result <=x)
    {
        i++;
        result = i*i;
    }
    return i-1
}

class Parent
{
public:
    int m_id;
    Parent(int id=0)
    {
        m_id = id;
        cout << "Parent\n";
    }
    int getid() const
    {
        return m_id;
    }
};

class Child: public Parent
{
public:
    double m_value;

    Child(double value=0.0, int id=0): Parent(id)
    {
        m_value = value;
        cout << "Child\n";
    }
    double getValue() const
    {
        return m_value;
    }
};

int main()
{
    cout << "Inicializaciya Parent:\n";
    Parent dParent;

    cout << "Inicializaciya Child:\n";
    Child dChild;
    return 0;
}
