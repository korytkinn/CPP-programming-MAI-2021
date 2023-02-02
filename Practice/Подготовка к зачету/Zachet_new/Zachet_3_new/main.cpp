#include <iostream>

using namespace std;

class Dynmas
{
    protected:
    double* massiv1 = nullptr;
    double* massiv2 = nullptr;
    int razmer1 = 0;
    int razmer2 = 0;
public:
    Dynmas(int size1, int size2, double num1, double num2)
    {
        razmer1 = size1;
        razmer2 = size2;
        double number1 = num1;
        double number2 = num2;

        massiv1= new double[razmer1];
        massiv2= new double[razmer2];
        for(int i=0;i<razmer1;i++)
        {
            massiv1[i] = number1;
        }

        for(int i=0;i<razmer2;i++)
        {
            massiv2[i] = number2;
        }
    }
    void display() const
    {
        if(massiv1 == nullptr)
        {
            cout << "\nDont have 1st array" << endl;
        } else
        {
            cout << "\n1st massiv:" << endl;
            for(int i=0;i<razmer1;i++)
            {
                cout << massiv1[i] << " ";
            }
            cout << endl;
        }

        if(massiv2 == nullptr)
        {
            cout << "\nDont have 2nd array" << endl;
        } else
        {
            cout << "\n2nd massiv:" << endl;
            for(int i=0;i<razmer2;i++)
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
        massiv1 = new double[razmer1];
        massiv2 = new double[razmer2];

        for(int i=0;i<razmer1;i++)
        {
            massiv1[i] = ob1.massiv1[i];
        }
        for(int i=0;i<razmer2;i++)
        {
            massiv2[i] = ob1.massiv2[i];
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
        massiv1 = new double[razmer1];
        massiv2 = new double[razmer2];

        for(int i=0;i<razmer1;i++)
        {
            massiv1[i] = ob1.massiv1[i];
        }
        for(int i=0;i<razmer2;i++)
        {
            massiv2[i] = ob1.massiv2[i];
        }
    }
};

class Naslednik: public Dynmas
{
    int sum1 = 0;
    int sum2 = 0;

    double temp1=0;
    double temp2=0;

public:
    Naslednik(int size1, int size2, double num1, double num2): Dynmas(size1, size2, num1, num2)
    {

    }
    void summer()
    {
        for(int i=0;i<razmer1;i++)
        {
            temp1+=massiv1[i];
        }
        for(int i=0;i<razmer2;i++)
        {
            temp2+=massiv2[i];
        }

        sum1 = (int)temp1;
        sum2 = (int)temp2;

        if(temp1-sum1 >=0.5)
        {
            sum1++;
        }
        if(temp2-sum2 >=0.5)
        {
            sum2++;
        }
        cout << "Sum of elements of 1st massiv = " << sum1 << endl;
        cout << "Sum of elements of 2nd massiv = " << sum2 << endl;
    }
};

int main()
{
    Dynmas test1(5,10,3.3,4.4);
    test1.display();

    Dynmas test2 = test1;
    test2.display();

    Dynmas test3(test2);
    test3.display();

    cout << "\nNaslednik:\n";
    Naslednik test4(3,4,5.7,7.7);
    test4.display();
    test4.summer();
    return 0;
}
