#include <iostream>

using namespace std;

class Dynmas
{
    double* massiv1;
    double* massiv2;
    double* massiv3;
    int razmer1;
    int razmer2;
    int razmer3;
public:
    Dynmas()
    {
        massiv1 = nullptr;
        massiv2 = nullptr;
        massiv3 = nullptr;
        razmer1 = 0;
        razmer2 = 0;
        razmer3 = 0;
    }
    ~Dynmas()
    {
        delete[] massiv1;
        delete[] massiv2;
        delete[] massiv3;
        razmer1 = 0;
        razmer2 = 0;
        razmer3 = 0;
    }
    void creator()
    {
        while(razmer1 <=0)
        {
            cout << "Enter 1st array size (int) >0: ";
            cin >> razmer1;
            if(razmer1<=0)
            {
                cout <<"Wrong 1st massiv size = " << razmer1 << endl;
            }
        }
        while(razmer2 <=0)
        {
            cout << "Enter 2nd array size (int) >0: ";
            cin >> razmer2;
            if(razmer2<=0)
            {
                cout <<"Wrong 2nd massiv size = " << razmer2 << endl;
            }
        }
        while(razmer3 <=0)
        {
            cout << "Enter 3rd array size (int) >0: ";
            cin >> razmer3;
            if(razmer3<=0)
            {
                cout <<"Wrong 3rd massiv size = " << razmer3 << endl;
            }
        }
        massiv1 = new double[razmer1];
        massiv2 = new double[razmer2];
        massiv3 = new double[razmer3];

        cout << "Enter 1st massiv elements (double).\n";
        for(int i=0;i<razmer1;i++)
        {
            cout << "Enter element [" << i+1 <<"] of " << razmer1 << ": ";
            cin >> massiv1[i];
        }

        cout << "Enter 2nd massiv elements (double).\n";
        for(int i=0;i<razmer2;i++)
        {
            cout << "Enter element ["<< i+1 <<"] of " << razmer2 << ": ";
            cin >> massiv2[i];
        }

        cout << "Enter 3rd massiv elements (double).\n";
        for(int i=0;i<razmer3;i++)
        {
            cout << "Enter element ["<< i+1 <<"] of " << razmer3 << ": ";
            cin >> massiv3[i];
        }

    }
    void display() const
    {
        if(massiv1 == nullptr && razmer1 == 0)
        {
            cout << "\nDont have 1st massiv\n";
        } else
        {
            cout << "\n1st massiv:\n";
            for(int i=0; i<razmer1;i++)
            {
                cout << massiv1[i] << "\t";
            }
        }

        if(massiv2 == nullptr && razmer2 == 0)
        {
            cout << "\nDont have 2nd massiv\n";
        } else
        {
            cout << "\n2nd massiv:\n";
            for(int i=0; i<razmer2;i++)
            {
                cout << massiv2[i] << "\t";
            }
        }

        if(massiv3 == nullptr && razmer3 == 0)
        {
            cout << "\nDont have 3rd massiv\n";
        } else
        {
            cout << "\n3rd massiv:\n";
            for(int i=0; i<razmer3;i++)
            {
                cout << massiv3[i] << "\t";
            }
        }

    }
    Dynmas (const Dynmas&ob1);
    Dynmas& operator=(const Dynmas&ob1);
    Dynmas (Dynmas&&ob1)
    {
        if((ob1.massiv1 !=nullptr)&&(ob1.razmer1 !=0))
        {
        massiv1 = ob1.massiv1;
        razmer1 = ob1.razmer1;
        ob1.massiv1 = nullptr;
        ob1.razmer1 = 0;
        }

        if((ob1.massiv2 !=nullptr)&&(ob1.razmer2 !=0))
        {
        massiv2 = ob1.massiv2;
        razmer2 = ob1.razmer2;
        ob1.massiv2 = nullptr;
        ob1.razmer2 = 0;
        }

        if((ob1.massiv3 !=nullptr)&&(ob1.razmer3 !=0))
        {
        massiv3 = ob1.massiv3;
        razmer3 = ob1.razmer3;
        ob1.massiv3 = nullptr;
        ob1.razmer3 = 0;
        }
    }
    Dynmas& operator=(Dynmas&&ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }
        delete[] massiv1;
        delete[] massiv2;
        delete[] massiv3;
        massiv1 = nullptr;
        massiv2 = nullptr;
        massiv3 = nullptr;
        razmer1 = 0;
        razmer2 = 0;
        razmer3 = 0;

        if((ob1.massiv1 !=nullptr)&&(ob1.razmer1 !=0))
        {
        massiv1 = ob1.massiv1;
        razmer1 = ob1.razmer1;
        ob1.massiv1 = nullptr;
        ob1.razmer1 = 0;
        }

        if((ob1.massiv2 !=nullptr)&&(ob1.razmer2 !=0))
        {
        massiv2 = ob1.massiv2;
        razmer2 = ob1.razmer2;
        ob1.massiv2 = nullptr;
        ob1.razmer2 = 0;
        }

        if((ob1.massiv3 !=nullptr)&&(ob1.razmer3 !=0))
        {
        massiv3 = ob1.massiv3;
        razmer3 = ob1.razmer3;
        ob1.massiv3 = nullptr;
        ob1.razmer3 = 0;
        }

        return *this;
    }

    double operator()(int massiv, int element)
    {
        if(massiv >3 || massiv <1)
        {
            return 0;
        }
        if(massiv == 1 && (element >0 && element <= razmer1))
           {
               return massiv1[element];
           } else
            {
                return 0;
            }

        if(massiv == 2 && (element >0 && element <= razmer2))
           {
               return massiv2[element];
           } else
            {
                return 0;
            }

        if(massiv == 3 && (element >0 && element <= razmer3))
           {
               return massiv3[element];
           } else
            {
                return 0;
            }
    }
};

int main()
{
    Dynmas test1;
    test1.creator();
    test1.display();
    cout << test1(5,3) << endl;
    cout << test1(1,1) << endl;
    return 0;
}
