#include <iostream>

using namespace std;

class Dynmas
{
protected:
    double* massiv;
    int razmer;
    double number;
public:
    Dynmas()
    {
        massiv = nullptr;
        razmer = 0;
        number = 0;
    }
    Dynmas(int _size, double _num)
    {
        razmer = _size;
        number = _num;
        if(razmer <=0)
        {
            massiv = nullptr;
            razmer = 0;
        } else
        {
            massiv = new double[razmer];
            for(int i=0;i<razmer;i++)
            {
                massiv[i] = number*i;
            }
        }
    }
    void display() const
    {
        if(massiv == nullptr && razmer == 0)
        {
            cout <<"\nDont have massiv\n";
        } else
        {
            cout << "\nYour massiv:\n";
            for(int i=0;i<razmer;i++)
            {
                cout << massiv[i] << "\t";
            }
        }
    }
    Dynmas (const Dynmas &ob1);
    Dynmas& operator=(const Dynmas &ob1);
    Dynmas (Dynmas &&ob1);
    Dynmas& operator=(Dynmas &&ob1);
};

class Naslednik: public Dynmas
{
private:

static int kolvo;
int id;
public:
    Naslednik()
    {
        id = kolvo++;
    }
    ~Naslednik()
    {
        id = kolvo--;
    }
    Naslednik(int raz, double num): Dynmas(raz, num)
    {
        id = kolvo++;
    }
    double operator[](const int index)
    {
        if(index <=0 || index > razmer)
        {
            return 0;
        } else
        {
            return massiv[index];
        }
    }
        int get_id() const
    {
        return id;
    }
};
int Naslednik::kolvo=1;
int main()
{
    Dynmas test1(5,3.5);
    test1.display();

    Naslednik test2(4,5.7);
    Naslednik test3(5,8.7);
    Naslednik test4(6,4.7);
//    test2.display();
//    cout << "\ntest2[3] =" << test2[3];
    cout <<"\nkolvo = " << test2.get_id() << endl;
    cout <<"\nkolvo = " << test3.get_id() << endl;
    cout <<"\nkolvo = " << test4.get_id() << endl;
//    Naslednik test3(5,6.6);
//        cout <<"\nkolvo = " << test3.get_id() << endl;
//    cout << test2.get_id() << endl;
    return 0;
}
