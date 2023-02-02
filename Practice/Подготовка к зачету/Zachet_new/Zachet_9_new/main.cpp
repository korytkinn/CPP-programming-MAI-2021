#include <iostream>

using namespace std;

int sqrt(int x)
{
    if(x == 1 || x == 0)
    {
        return x;
    }
    int i = 1;
    int result = 1;
    while (result <= x)
    {
        i++;
        result = i*i;
    }
    return i-1;
}

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
        if(x !=0 && y!=0)
        {
            for(int i=0; i<y;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    }
    void creator()
    {
        cout << "Enter matrix x and y sizes (int) >0." << endl;
        while(x <=0)
        {
            cout << "Enter (int) x>0: ";
            cin >> x;
            if(x<=0)
            {
                cout << "Wrong matrix x size = " << x << endl;
            }
        }
        while(y <=0)
        {
            cout << "Enter (int) y>0: ";
            cin >> y;
            if(y<=0)
            {
                cout << "Wrong matrix y size = " << y << endl;
            }
        }
        matrix = new double*[y];
        for(int i=0;i<y;i++)
        {
            matrix[i] = new double[x];
        }

        cout << "\nEnter matrix (double) elements.\n";
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
        if(matrix == nullptr)
        {
            cout << "\nDont have a matrix\n";
        } else
        {
            cout << "\nYour matrix:\n";
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    Dynmas(const Dynmas &ob1)
    {
        x = ob1.x;
        y = ob1.y;
        matrix = new double*[y];
        for(int i=0;i<y;i++)
        {
            matrix[i] = new double[x];
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                matrix[i][j] = ob1.matrix[i][j];
            }
        }
    }
    Dynmas& operator=(const Dynmas &ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }
        if(ob1.matrix != nullptr && x!=0 && y!=0)
        {
            for(int i=0;i<y;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            x=0;
            y=0;

            x=ob1.x;
            y=ob1.y;
            matrix = new double*[y];
            for(int i=0;i<y;i++)
            {
                matrix[i] = new double[x];
            }
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {
                    matrix[i][j] = ob1.matrix[i][j];
                }
            }
        }
    }
    Dynmas(Dynmas &&ob1)
    {
        if(ob1.matrix != nullptr && ob1.x !=0 && ob1.y !=0)
        {
        x = ob1.x;
        y = ob1.y;
        matrix = ob1.matrix;
        ob1.matrix = nullptr;
        ob1.x = 0;
        ob1.y = 0;
        }

    }
    Dynmas& operator=(Dynmas &&ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }
        for(int i=0;i<y; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        x=0;
        y=0;
        if(ob1.matrix!=nullptr && ob1.x !=0 && ob1.y !=0)
        {
        x = ob1.x;
        y = ob1.y;
        matrix = ob1.matrix;
        ob1.matrix = nullptr;
        ob1.x = 0;
        ob1.y = 0;
        }
    }
    Dynmas operator+(const Dynmas &ob1)
    {
        Dynmas ob3;
        int koren = sqrt(x*y+ob1.x*ob1.y);
        if(koren*koren == x*y+ob1.x*ob1.y)
        {
            ob3.x=koren;
            ob3.y=koren;
            ob3.matrix = new double*[ob3.y];
            for(int i=0;i<ob3.y;i++)
            {
                ob3.matrix[i] = new double[ob3.x];
            }

            for(int i=0;i<ob3.y;i++)
            {
                for(int j=0;j<ob3.x;j++)
                {
                    ob3.matrix[i][j]=0;
                }
            }

            double* array1 = new double[x*y];
            double* array2 = new double[ob1.x*ob1.y];

            int indikator = 0;
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {
                    array1[indikator]=matrix[i][j];
                    indikator++;
                }
            }

            indikator=0;
            for(int i=0;i<ob1.y;i++)
            {
                for(int j=0;j<ob1.x;j++)
                {
                    array2[indikator]=ob1.matrix[i][j];
                    indikator++;
                }
            }

            indikator=0;
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {
                    ob3.matrix[i][j] = array1[indikator];
                    indikator++;
                }
            }

            indikator=0;
            for(int i=y;i<ob3.y;i++)
            {
                for(int j=0;j<ob3.x;j++)
                {
                    ob3.matrix[i][j] = array2[indikator];
                    indikator++;
                }
            }
            return ob3;
        } else
        {
            int oldsize = x*y+ob1.x*ob1.y;
            int newx;
            int newy;
            int iteraciya = 0;

            if(x*y > ob1.x*ob1.y)
            {
                newx = ob1.x;
                newy = ob1.y;
            } else
            {
                newx = x;
                newy = y;
            }

            while(newx*newy <oldsize)
            {
                if(iteraciya % 2 == 0)
                {
                    newy++;
                    iteraciya++;
                } else
                {
                    newx++;
                    iteraciya++;
                }
            }

            ob3.x = newx;
            ob3.y = newy;
            ob3.matrix = new double*[ob3.y];
            for(int i=0;i<ob3.y;i++)
            {
                ob3.matrix[i]=new double[ob3.x];
            }
            for(int i=0;i<ob3.y;i++)
            {
                for(int j=0;j<ob3.x;j++)
                {
                    ob3.matrix[i][j] = 0;
                }
            }

            int indikator = 0;

            double* massiv = new double[x*y+ob1.x*ob1.y];

            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {
                    massiv[indikator] = matrix[i][j];
                    indikator++;
                }
            }
            for(int i=0;i<ob1.y;i++)
            {
                for(int j=0;j<ob1.x;j++)
                {
                    massiv[indikator] = ob1.matrix[i][j];
                    indikator++;
                }
            }
            indikator=0;
            for(int i=0;i<ob3.y;i++)
            {
                for(int j=0; j<ob3.x;j++)
                {
                    if(indikator == x*y+ob1.x*ob1.y)
                    {
                        return ob3;
                    }
                    ob3.matrix[i][j] = massiv[indikator];
                    indikator++;
                }
            }
            return ob3;

        }
    }

};

int main()
{
    Dynmas test1;
    Dynmas test2;
    test1.creator();
    test2.creator();
    Dynmas test3 = test1+test2;
    test3.display();
    return 0;
}
