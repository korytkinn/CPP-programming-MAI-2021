#include <iostream>

using namespace std;

class Dynmas
{
    int* massiv1;
    int* massiv2;
    int razmer1;
    int razmer2;
public:
    Dynmas()
    {
        massiv1 = nullptr;
        massiv2 = nullptr;
        razmer1 = 0;
        razmer2 = 0;
    }
    ~Dynmas()
    {
        delete[] massiv1;
        delete[] massiv2;
        razmer1 = 0;
        razmer2 = 0;
    }
    void creator()
    {
        cout << "Enter array sizes (int) >0." << endl;
        while(razmer1<=0)
        {
            cout << "Enter 1st array (int)size = ";
            cin >> razmer1;
            if(razmer1<=0)
            {
                cout << "Wrong 1st array size = " << razmer1 << endl;
            }
        }

        while(razmer2<=0)
        {
            cout << "Enter 2nd array (int)size = ";
            cin >> razmer2;
            if(razmer2<=0)
            {
                cout << "Wrong 2nd array size = " << razmer2 << endl;
            }
        }

        massiv1 = new int[razmer1];
        massiv2 = new int[razmer2];

        cout << "\nEnter (int) elements of arrays." << endl;

        cout << "\nEnter 1st array (int) elements." << endl;
        for(int i=0; i<razmer1; i++)
        {
            cout << "Enter (int) element [" << i+1 << "] of " << razmer1 << ": ";
            cin >> massiv1[i];
        }

        cout << "\nEnter 2nd array (int) elements." << endl;
        for(int i=0; i<razmer2; i++)
        {
            cout << "Enter (int) element [" << i+1 << "] of " << razmer2 << ": ";
            cin >> massiv2[i];
        }

    }
    void display() const
    {
        if(massiv1 == nullptr && razmer1 == 0)
        {
            cout << "\nDont have 1st array\n";
        } else
        {
            cout << "\n1st array:\n";
            for(int i=0; i<razmer1;i++)
            {
                cout << massiv1[i] << " ";
            }
            cout << endl;
        }

        if(massiv2 == nullptr && razmer2 == 0)
        {
        cout << "\nDont have 2nd array\n";
        } else
        {
            cout << "\n2nd array:\n";
            for(int i=0; i<razmer2;i++)
            {
                cout << massiv2[i] << " ";
            }
            cout << endl;
        }

    }

    Dynmas (const Dynmas &ob1)
    {
        razmer1 = ob1.razmer1;
        razmer2 = ob1.razmer2;

        massiv1 = new int[razmer1];
        massiv2 = new int[razmer2];

        for(int i=0;i<razmer1;i++)
        {
            massiv1[i]=ob1.massiv1[i];
        }

        for(int i=0;i<razmer2;i++)
        {
            massiv2[i]=ob1.massiv2[i];
        }
    }
    Dynmas& operator=(const Dynmas &ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }

        razmer1 = ob1.razmer1;
        razmer2 = ob1.razmer2;

        massiv1 = new int[razmer1];
        massiv2 = new int[razmer2];

        for(int i=0;i<razmer1;i++)
        {
            massiv1[i]=ob1.massiv1[i];
        }

        for(int i=0;i<razmer2;i++)
        {
            massiv2[i]=ob1.massiv2[i];
        }
    }

    void maxmin()
    {
        int maximum;
        int minimum;

        maximum = massiv1[0];
        minimum = massiv1[0];

        for(int i=0;i<razmer1;i++)
        {
            if(massiv1[i]>maximum)
            {
                maximum = massiv1[i];
            }
            if(massiv1[i]<minimum)
            {
                minimum = massiv1[i];
            }
        }

        for(int i=0;i<razmer2;i++)
        {
            if(massiv2[i]>maximum)
            {
                maximum = massiv2[i];
            }
            if(massiv2[i]<minimum)
            {
                minimum = massiv2[i];
            }
        }
        cout << "maximum = " << maximum << ", minimum = " << minimum <<endl;

    }

};

int main()
{
    Dynmas test1;
    test1.creator();
    test1.display();

    Dynmas test2 = test1;
    test2.display();

    Dynmas test3(test2);
    test3.display();
    test3.maxmin();
    return 0;
}
