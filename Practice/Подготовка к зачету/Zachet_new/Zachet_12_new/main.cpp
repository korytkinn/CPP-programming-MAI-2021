#include <iostream>

using namespace std;

class Dynmas
{
    double** matrix;
    int x;
    int y;
    double number;
public:
    Dynmas()
    {
        matrix = nullptr;
        x=0;
        y=0;
        number = 0;
    }
    ~Dynmas()
    {
        if(matrix!=nullptr)
        {
            for(int i=0;i<y;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            x=0;
            y=0;
            number = 0;
        }
    }
    void creator(int _x, int _y, double _num)
    {
        x= _x;
        y= _y;
        number = _num;
        if(x == 0 || y==0)
        {
            matrix = nullptr;
            x=0;
            y=0;
        } else
        {
            matrix = new double*[y];
            for(int i=0;i<y;i++)
            {
                matrix[i] = new double[x];
            }
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {
                    matrix[i][j] = (i+1)*(j+1)*number;
                }
            }
        }
    }
    void display() const
    {
        if(matrix == nullptr && x==0 && y==0)
        {
            cout <<"\nDont have a matrix\n";
        } else
        {
            cout << "\nYour matrix:\n";
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {
                    cout << matrix[i][j] << "\t";
                }
                cout << endl;
            }
        }
    }
    double summer() const
    {
        if(matrix == nullptr)
        {
            return 0;
        } else
        {
            double sum = 0;
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<x;j++)
                {
                    sum+=matrix[i][j];
                }
            }
            return sum;
        }
    }
    Dynmas(const Dynmas &ob1)
    {
        if(ob1.matrix !=nullptr && ob1.x !=0 && ob1.y!=0)
        {
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
    Dynmas& operator=(const Dynmas &ob1)
    {
        if(this == &ob1)
        {
            return *this;
        }
        if(matrix != nullptr)
        {
            for(int i=0;i<y;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            x=0;
            y=0;
        }
        if(ob1.matrix !=nullptr && ob1.x !=0 && ob1.y!=0)
        {
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
        return *this;

    }
    Dynmas(Dynmas &&ob1)
    {
        if(ob1.matrix !=nullptr && ob1.x !=0 && ob1.y!=0)
        {
            x=ob1.x;
            y=ob1.y;
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
        if(matrix != nullptr)
        {
            for(int i=0;i<y;i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            x=0;
            y=0;
        }
        if(ob1.matrix !=nullptr && ob1.x !=0 && ob1.y!=0)
        {
            x=ob1.x;
            y=ob1.y;
            matrix = ob1.matrix;
            ob1.matrix = nullptr;
            ob1.x = 0;
            ob1.y = 0;
        }
        return *this;
    }

    friend void sortirovka(Dynmas *ob1, int raz);

};

void sortirovka(Dynmas *ob1, int raz)
{
    int N = raz;
    double sum1 = 0;
    double sum2 = 0;
    for(int i=0; i< N-1;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {
            for(int p=0;p<ob1[j].y;p++)
            {
                for(int q=0;q<ob1[j].x;q++)
                {
                    sum1+=ob1[j].matrix[p][q];
                }
            }

            for(int p=0;p<ob1[j+1].y;p++)
            {
                for(int q=0;q<ob1[j+1].x;q++)
                {
                    sum2+=ob1[j+1].matrix[p][q];
                }
            }
            if(sum1>sum2)
            {
                swap(ob1[j],ob1[j+1]);
            }
            sum1=0;
            sum2=0;
        }
    }
}

int main()
{
    Dynmas test1;
    test1.creator(5,3,7.7);
    test1.display();
    cout << "summa = " << test1.summer() << endl;

    int N = 0;
    while(N<=0)
    {
        cout << "Enter razmer massiva (int) N = ";
        cin >> N;
        if(N<=0)
        {
            cout << "Wrong N razmer = " << N << endl;
        }
    }
    Dynmas* test2 = new Dynmas[N];
    for(int i=0;i<N;i++)
    {
        test2[i].creator(N-i+1, N-i+2, N-i);
        test2[i].display();
    }
    sortirovka(test2,N);

    cout << "after sortirovka:\n";
    for(int i=0;i<N;i++)
    {
        test2[i].display();
    }

    return 0;
}
