#include <iostream>

using namespace std;
class Dynmas
{
    double* massiv;
    int razmer;
public:
    Dynmas()
    {
    massiv =nullptr;
    razmer=0;
    }
    ~Dynmas()
    {
    delete[] massiv;
    razmer = 0;
    }
    void creator()
    {
        cout << "Enter size = ";
        cin >> razmer;
        massiv = new double[razmer];
        for(int i=0;i<razmer;i++)
        {
            cout << "Enter element " << i+1 << ": ";
            cin >> massiv[i];
        }
    }
    void display() const
    {
        cout << "Your massiv:\n";
        for(int i=0;i<razmer;i++)
        {
            cout <<massiv[i] << " ";
        }
    }

    //перегрузка
    Dynmas(const Dynmas &ob1)
    {
        if(massiv !=nullptr && razmer !=0)
        {
        razmer = ob1.razmer;
        massiv = new double[razmer];
        for(int i=0; i<razmer;i++)
            {
            massiv[i] = ob1.massiv[i];
            }
        }
        cout << "\n konstryktor kopirovaniya porabotal\n";
    }
    Dynmas& operator=(const Dynmas &ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }
        delete[] massiv;
        razmer = 0;
        if(massiv !=nullptr && razmer !=0)
        {
        razmer = ob1.razmer;
        massiv = new double[razmer];
        for(int i=0; i<razmer;i++)
            {
            massiv[i] = ob1.massiv[i];
            }
        }
        cout << "\n operator= kopirovaniya porabotal\n";
        return *this;
    }
    Dynmas operator+(const Dynmas ob1)
    {
        if(razmer > ob1.razmer)
        {
            for(int i=0;i<ob1.razmer;i++)
            {
                massiv[i]+=ob1.massiv[i];
            }
        } else
        {
            for(int i=0;i<razmer;i++)
            {
                massiv[i]+=ob1.massiv[i];
            }
        }
        cout << "operator+ porabotal\n";
        return *this;
    }

    Dynmas operator++()
    {
        return *this;
    }
    Dynmas operator++(int)
    {
        Dynmas old(*this);
        for(int i=0;i<razmer;i++)
        {
            massiv[i]++;
        }
        return old;
    }

};
int main()
{
    Dynmas test1;
    test1.creator();
    test1.display();
    Dynmas test2;
    test2.creator();
    test2.display();

    Dynmas test3 = test1+test2;
    test3.display();
    cout << "\n++test3\n";
    ++test3;
    test3.display();

    cout << "\ntest3++\n";
    test3++;
    test3.display();
    return 0;
}
