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
        cout << "Start creating array.\n";
        while(razmer <=0)
        {
            cout << "Enter massiv size (int)>0: ";
            cin >> razmer;
            if(razmer <=0)
            {
                cout << "\nWrong massiv size = " << razmer << endl;
            }
        }
        massiv = new double[razmer];

        cout << "Enter massiv elements (double).\n";
        for(int i=0;i<razmer;i++)
        {
            cout << "Enter element [" << i+1 << "] of " << razmer << ": ";
            cin >> massiv[i];
        }
    }
    void display() const
    {
        if(massiv == nullptr && razmer == 0)
        {
            cout << "\nDont have an array\n";
        } else
        {
            cout << "Your array:\n";
            for(int i=0;i<razmer;i++)
            {
                cout << massiv[i] << " ";
            }
            cout << endl;
        }
    }
    Dynmas (const Dynmas &ob1);
    Dynmas& operator=(const Dynmas &ob1);

    int operator[](int index)
    {
        /*
        if(index<0 || index>razmer-1)
        {
            return 0;
        }
        */
        return massiv[index];
    }

};

int main()
{
    Dynmas test1;
    test1.creator();
    test1.display();
    cout << "test1[0] = " << test1[0] << endl;
    cout << "test1[10] = " << test1[10] << endl;

    return 0;
}
