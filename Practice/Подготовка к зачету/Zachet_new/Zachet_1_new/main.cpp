#include <iostream>

using namespace std;

class Dynmas
{
    int* massiv;
    int razmer;
public:
    static int kolvo;

    Dynmas()
    {
        massiv = nullptr;
        razmer = 0;
        kolvo++;
    }
    ~Dynmas()
    {
        delete[] massiv;
        razmer = 0;
        kolvo--;
    }
    void creator()
    {
        while(razmer <=0)
        {
            cout << "Enter massiv razmer (int) >0: ";
            cin >> razmer;
            if(razmer<=0)
            {
                cout << "Wrong massiv razmer = " << razmer << endl;
            }
        }
        massiv = new int[razmer];

        cout << "Enter massiv (int) elements." << endl;
        for(int i=0; i<razmer;i++)
        {
            cout << "Enter (int)element [" << i+1 << "] of " << razmer << ": ";
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
            cout << "\nYour massiv:\n";
            for(int i=0; i<razmer;i++)
            {
                cout << massiv[i] << " ";
            }
            cout << endl;
        }
    }

    void sdvig(int n)
    {
        for(int i=0; i<n;i++)
        {
            int karman = massiv[0];
            for(int j=0; j<razmer;j++)
            {
                massiv[j]=massiv[j+1];
            }
            massiv[razmer-1]=karman;
        }
    }


};
int Dynmas::kolvo = 0;
int main()
{
    Dynmas test1;
    test1.creator();
    test1.display();
    cout << Dynmas::kolvo;

    test1.sdvig(3);
    test1.display();
    return 0;
}
