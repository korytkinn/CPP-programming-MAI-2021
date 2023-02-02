#include <iostream>

using namespace std;

class Matrix
{
    int massiv[3][4];
    int x=3,y=4;
    int number=0;

    public:
    Matrix(int parametr) //конструктор
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<4;j++)
            massiv[i][j]=parametr;
    }


    void display()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<4;j++)
            {
            cout<< massiv[i][j] << " ";
            if(j==3)
                cout<<endl;
            }
    }
    void changer()
    {
        cout<<"Enter stroka number (from 1 to 3): ";
        cin >> x;
        cout<<"\nEnter stolbets number (from 1 to 4): ";
        cin >> y;

        if(x>3 || x<1 || y>4 || y<1)
        {
            cout<<"\nWrong number!\n";
            changer();
            return;
        }

        cout<<"Enter new int: ";
        cin >> number;
        massiv[x-1][y-1]=number;
    }

};

int main()
{
    Matrix A(5);
    A.display();
    A.changer();
    A.display();
//    cout << "Hello world!" << endl;

    return 0;
}
