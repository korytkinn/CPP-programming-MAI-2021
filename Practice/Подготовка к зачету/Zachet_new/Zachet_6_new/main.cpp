#include <iostream>

using namespace std;

class Dynmas
{
    double** matrix;
    int x;
    int y;
public:
    Dynmas()
    {
        matrix = nullptr;
        x=0;
        y=0;
    }
    ~Dynmas()
    {
        for(int i=0;i<y;i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        x=0;
        y=0;
    }
    void creator()
    {
        cout << "Enter matrix (int) sizes >0.\n";
        while(x<=0)
        {
            cout<<"Enter size of (int) x = ";
            cin >> x;
            if(x<=0)
            {
                cout << "\nWrong size of x = " << x << endl;
            }
        }

        while(y<=0)
        {
            cout<<"Enter size of (int) y = ";
            cin >> y;
            if(y<=0)
            {
                cout << "\nWrong size of y = " << y << endl;
            }
        }

        matrix = new double*[y];
        for(int i=0;i<y;i++)
        {
            matrix[i] = new double[x];
        }

        cout << "\nEnter matrix elements (double).\n";
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                cout << "Enter element [" << i+1 << "][" << j+1 << "]: ";
                cin >> matrix[i][j];
            }
        }

    }
    void display() const
    {
        if(matrix == nullptr && x ==0 && y == 0)
        {
            cout << "\nDont have a matrix\n";
        } else
        {
            cout << "\nYour matrix:\n";
            for(int i=0; i<y; i++)
            {
                for(int j=0; j<x;j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    Dynmas (const Dynmas &ob1)
    {
        x=ob1.x;
        y=ob1.y;
        matrix = new double*[y];
        for(int i=0;i<y;i++)
        {
            matrix[i]=new double[x];
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                matrix[i][j]=ob1.matrix[i][j];
            }
        }
    }
    Dynmas& operator=(const Dynmas &ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }
                x=ob1.x;
        y=ob1.y;
        matrix = new double*[y];
        for(int i=0;i<y;i++)
        {
            matrix[i]=new double[x];
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                matrix[i][j]=ob1.matrix[i][j];
            }
        }
        return *this;
    }

    friend Dynmas operator*(const Dynmas &ob1, const Dynmas &ob2);

};

Dynmas operator*(const Dynmas &ob1, const Dynmas &ob2)
{
    Dynmas ob3;
    if(ob1.x != ob2.y)
    {
        return ob3;
    }
    ob3.x = ob2.x;
    ob3.y = ob1.y;
    ob3.matrix = new double*[ob3.y];
    for(int i=0;i<ob3.y;i++)
    {
        ob3.matrix[i] = new double [ob3.x];
    }
    for(int i=0;i<ob3.y;i++)
    {
        for(int j=0;j<ob3.x;j++)
        {
            for(int k=0;k<ob3.y; k++)
            {
                ob3.matrix[i][j]+=ob1.matrix[i][k]*ob2.matrix[k][j];
            }

        }
    }
    return ob3;
}

int main()
{
    Dynmas test1;
    test1.creator();
    test1.display();
    Dynmas test2;
    test2.creator();
    test2.display();
    Dynmas test3;
    test3 = test1*test2;
    test3.display();
    return 0;
}
