#include <iostream>

using namespace std;

class Dynmas
{
    int* massiv = nullptr;
    int razmer = 0;
    int number = 0;
public:
    Dynmas()
    {
        massiv = nullptr;
        razmer = 0;
        number = 0;
    }
    Dynmas(int raz, int num)
    {
        if(raz<=0)
        {
            massiv = nullptr;
            razmer = 0;
        } else
        {
            razmer = raz;
            number = num;
            massiv = new int[razmer];
            for(int i=0;i<razmer;i++)
            {
                massiv[i] = i*number;
            }
        }
    }
    void display() const
    {
        if(massiv == nullptr && razmer == 0)
        {
            cout << "\nDont have massiv\n";
        } else
        {
            cout << "Your massiv:\n";
            for(int i=0;i<razmer;i++)
            {
                cout << massiv[i] << "\t";
            }
            cout << endl;
        }
    }
    Dynmas (const Dynmas &ob1)
    {
        razmer = ob1.razmer;
        number = ob1.number;
        massiv = new int[razmer];
        for(int i=0;i<razmer;i++)
        {
            massiv[i] = ob1.massiv[i];
        }
    }
    Dynmas& operator=(const Dynmas &ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }
        delete[] massiv;
        razmer = 0;
        number = 0;
        if(ob1.massiv != nullptr && ob1.razmer !=0)
        {
            razmer = ob1.razmer;
            number = ob1.number;
            massiv = new int[razmer];
            for(int i=0;i<razmer;i++)
            {
                massiv[i] = ob1.massiv[i];
            }
        }
    }
    Dynmas (Dynmas &&ob1)
    {
        if(ob1.massiv != nullptr && ob1.razmer !=0)
        {
            massiv = ob1.massiv;
            razmer = ob1.razmer;
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
        razmer = 0;
        if(ob1.massiv != nullptr && ob1.razmer !=0)
        {
            massiv = ob1.massiv;
            razmer = ob1.razmer;
            ob1.massiv = nullptr;
            ob1.razmer = 0;
        }
        return *this;
    }
};

void sdvig(Dynmas *ob1,int num, int kolvo)
{
    int N = num;
    int x = kolvo;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            swap(ob1[j+1], ob1[j]);
        }
    }
}

int main()
{
    Dynmas test1(5,4);
    test1.display();

    int N = 0;
    while(N<=0)
    {
    cout << "Enter kolvo objectov N (int) = ";
    cin >> N;
    if(N<=0)
    {
        cout << "\nWrong N = " << N << endl;
    }
    }
    Dynmas* test3 = new Dynmas[N];
    for(int i=0;i<N;i++)
    {
        test3[i] = Dynmas(i+1, i+2);
        test3[i].display();
    }
    sdvig(test3,N,5);
    cout << "\nafter sdvig:\n";
    for(int i=0;i<N;i++)
    {
        test3[i].display();
    }

    return 0;
}
