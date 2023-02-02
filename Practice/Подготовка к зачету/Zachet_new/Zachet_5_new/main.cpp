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
        cout << "Enter arrays sizes (int) > 0." << endl;

        while(razmer1<=0)
        {
            cout << "Enter 1st array size = ";
            cin >> razmer1;
            if(razmer1<=0)
            {
                cout << "\nWrong 1st array size = " << razmer1 << endl;
            }
        }

        while(razmer2<=0)
        {
            cout << "Enter 2nd array size = ";
            cin >> razmer2;
            if(razmer2<=0)
            {
                cout << "\nWrong 2nd array size = " << razmer2 << endl;
            }
        }

        while(razmer3<=0)
        {
            cout << "Enter 3rd array size = ";
            cin >> razmer3;
            if(razmer3<=0)
            {
                cout << "\nWrong 3rd array size = " << razmer3 << endl;
            }
        }

        massiv1 = new double[razmer1];
        massiv2 = new double[razmer2];
        massiv3 = new double[razmer3];

        cout << "\nEnter 1st array elements (double)." << endl;
        for(int i=0; i<razmer1;i++)
        {
            cout << "Enter element [" << i+1 << "] of " << razmer1 << ": ";
            cin >> massiv1[i];
        }

        cout << "\nEnter 2nd array elements (double)." << endl;
        for(int i=0; i<razmer2;i++)
        {
            cout << "Enter element [" << i+1 << "] of " << razmer2 << ": ";
            cin >> massiv2[i];
        }

        cout << "\nEnter 3rd array elements (double)." << endl;
        for(int i=0; i<razmer3;i++)
        {
            cout << "Enter element [" << i+1 << "] of " << razmer3 << ": ";
            cin >> massiv3[i];
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
            cout <<endl;
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
            cout <<endl;
        }

        if(massiv3 == nullptr && razmer3 == 0)
        {
            cout << "\nDont have 3rd array\n";
        } else
        {
            cout << "\n3rd array:\n";
            for(int i=0; i<razmer3;i++)
            {
                cout << massiv3[i] << " ";
            }
            cout <<endl;
        }
    }
    Dynmas (const Dynmas &ob1)
    {
        razmer1 = ob1.razmer1;
        razmer2 = ob1.razmer2;
        razmer3 = ob1.razmer3;

        massiv1 = new double[razmer1];
        massiv2 = new double[razmer2];
        massiv3 = new double[razmer3];

        for(int i=0;i<razmer1;i++)
        {
            massiv1[i] = ob1.massiv1[i];
        }
        for(int i=0;i<razmer2;i++)
        {
            massiv2[i] = ob1.massiv2[i];
        }
        for(int i=0;i<razmer3;i++)
        {
            massiv3[i] = ob1.massiv3[i];
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
        razmer3 = ob1.razmer3;

        massiv1 = new double[razmer1];
        massiv2 = new double[razmer2];
        massiv3 = new double[razmer3];

        for(int i=0;i<razmer1;i++)
        {
            massiv1[i] = ob1.massiv1[i];
        }
        for(int i=0;i<razmer2;i++)
        {
            massiv2[i] = ob1.massiv2[i];
        }
        for(int i=0;i<razmer3;i++)
        {
            massiv3[i] = ob1.massiv3[i];
        }
    }

    void srednee()
    {
        double srednee1 = 0;
        double srednee2 = 0;
        double srednee3 = 0;
        for(int i=0;i<razmer1;i++)
        {
            srednee1+=massiv1[i];
        }
        for(int i=0;i<razmer2;i++)
        {
            srednee2+=massiv2[i];
        }
        for(int i=0;i<razmer3;i++)
        {
            srednee3+=massiv3[i];
        }

        srednee1/=razmer1;
        srednee2/=razmer2;
        srednee3/=razmer3;

        if(srednee1 > srednee2 && srednee1 >= srednee3)
        {
            cout << "\nsrednee1 = " << srednee1 << endl;
            cout << "\n1st array:\n";
            for(int i=0; i<razmer1;i++)
            {
                cout << massiv1[i] << " ";
            }
            cout <<endl;
        }
        if(srednee2 > srednee1 && srednee2 >= srednee3)
        {
            cout << "\nsrednee2 = " << srednee2 << endl;
            cout << "\n2nd array:\n";
            for(int i=0; i<razmer2;i++)
            {
                cout << massiv2[i] << " ";
            }
            cout <<endl;
        }
        if(srednee3 > srednee1 && srednee3 >= srednee2)
        {
            cout << "\nsrednee3 = " << srednee3 << endl;
            cout << "\n3rd array:\n";
            for(int i=0; i<razmer3;i++)
            {
                cout << massiv3[i] << " ";
            }
            cout <<endl;
        }
        if(srednee1 == srednee2 && srednee2 == srednee3)
        {
            cout << "\nsrednee1 = " << srednee1 << endl;
            cout << "\nsrednee2 = " << srednee2 << endl;
            cout << "\nsrednee3 = " << srednee3 << endl;
            display();

        }

    }

};

int main()
{
    Dynmas test1;
    test1.creator();
    test1.display();
    test1.srednee();
    return 0;
}
