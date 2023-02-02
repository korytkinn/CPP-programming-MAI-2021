#include <iostream>

using namespace std;

class Dynmas
{
    double* massiv;
    int razmer;
public:
    Dynmas()
    {
        massiv = nullptr;
        razmer = 0;
    }
    ~Dynmas()
    {
        delete[] massiv;
        razmer = 0;
    }
    void creator()
    {
        while(razmer<=0)
        {
            cout << "Enter massiv razmer (int) >0: ";
            cin >> razmer;
            if(razmer <=0)
            {
                cout << "\nWrong massiv razmer = " << razmer << endl;
            }
        }
        massiv = new double[razmer];

        cout << "\nEnter massiv elements (double).\n";
        for(int i=0; i<razmer;i++)
        {
            cout << "Enter element [" << i+1 << "] of " << razmer << ": ";
            cin >> massiv[i];
        }
    }
    void display() const
    {
        if(massiv == nullptr && razmer == 0)
        {
            cout << "\nDont have massiv\n";
        } else
        {
            cout << "\nYour massiv:\n";
            for(int i=0;i<razmer;i++)
            {
                cout << massiv[i] << " ";
            }
            cout << endl;
        }
    }
    Dynmas (const Dynmas &ob1);
    Dynmas& operator=(const Dynmas &ob1);
    Dynmas (Dynmas &&ob1)
    {
        if((ob1.massiv != nullptr) & (ob1.razmer !=0))
        {
        razmer = ob1.razmer;
        massiv = ob1.massiv;
        ob1.massiv = nullptr;
        ob1.razmer = 0;
        }
    }
    Dynmas& operator=(Dynmas &&ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }
        delete[] massiv;
        massiv = nullptr;
        razmer = 0;
        if((ob1.massiv != nullptr) & (ob1.razmer !=0))
        {
        razmer = ob1.razmer;
        massiv = ob1.massiv;
        ob1.massiv = nullptr;
        ob1.razmer = 0;
        }
    }

    Dynmas& operator+=(const int &x)
    {
        if(x == 0)
        {
            return *this;
        }
        if(massiv != nullptr && razmer !=0)
        {
            for(int i=0;i<razmer;i++)
            {
                massiv[i]+=x;
            }
        }
        return *this;
    }
    Dynmas& operator+=(const double &x)
    {
        if(x == 0)
        {
            return *this;
        }
        if(massiv != nullptr && razmer !=0)
        {
            for(int i=0;i<razmer;i++)
            {
                massiv[i]+=x;
            }
        }
        return *this;
    }
};

void peremeshenie(Dynmas &a, Dynmas &b)
{
    /*
    Dynmas c = move(a);
    a = move(b);
    b = move(c);
    */
    swap(a,b);
}

int main()
{
    Dynmas test1;
    test1.creator();
    /*
    test1.display();
    test1+=5;
    test1.display();
    test1+=11.3;
    test1.display();
*/
    Dynmas test2;
    test2.creator();
    test1.display();
    test2.display();
    peremeshenie(test1, test2);
    test1.display();
    test2.display();

    return 0;
}
