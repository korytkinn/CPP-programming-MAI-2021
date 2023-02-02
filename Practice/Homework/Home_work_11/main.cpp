#include <iostream>

using namespace std;

class Dynmas
{
    int* massiv;
    int razmer;
public:
    Dynmas()
    {
        razmer = 0;
        massiv = nullptr;
    }
    ~Dynmas()
    {
        delete[] massiv;
    }

    void creator()
    {
        cout << "Vvedite razmer massiva (Naturalnoe chislo): ";
        int user_razmer;
        cin >> user_razmer;
        if (user_razmer <= 0)
        {
            cout << "\nYour number " << user_razmer << " <= 0" << endl;
            creator();
        }
        razmer = user_razmer;
        massiv = new int[razmer];
        cout << "\nEnter " << razmer << " natural numbers:\n";
        for (int i = 0; i < razmer; i++)
        {
            cout << "Enter " << i << "number of " << razmer << ": ";
            cin >> massiv[i];
        }
    }
    void display()
    {
        cout << "\nYour massiv:\n";
        for (int i = 0; i < razmer; i++)
        {
            cout << massiv[i] << " ";
        }
    }
    //prefix
    Dynmas& operator--();


    //postfix
    Dynmas operator--(int x);

    Dynmas(const Dynmas& ob) //конструктор копирования
    {
        if (ob.massiv != nullptr && razmer != 0)
        {
            massiv = new int[ob.razmer];
            razmer = ob.razmer;
            for (int i = 0; i < ob.razmer; i++)
            {
                massiv[i] = ob.massiv[i];
            }
        }
    }

    Dynmas operator=(const Dynmas& ob) //operator=
    {
        if (this == &ob)
        {
            return *this;
        }
        delete[] massiv;
        massiv = nullptr;
        razmer = 0;
        if ((ob.massiv != nullptr) && (ob.razmer != 0))
        {
            massiv = new int[ob.razmer];
            razmer = ob.razmer;
            for (int i = 0; i < ob.razmer; i++)
            {
                massiv[i] = ob.massiv[i];
            }
        }
        cout << "\n Pereopredelennoe prisvoenie\n";
        return *this;
    }

};



int main()
{
    Dynmas test;
    test.creator();
    test.display();

    --test;
    test.display();

    test--;
    test.display();
}

Dynmas& Dynmas::operator--()
{
    cout << "--prefix" << endl;
    if (massiv == nullptr)
    {
        return *this;
    }
    for (int i = 0; i < razmer; i++)
    {
        --massiv[i];
    }
    return *this;
}

Dynmas Dynmas::operator--(int x)
{
    cout << "\n--postfix\n";
    if (massiv == nullptr)
    {
        return *this;
    }
    Dynmas ob(*this);
    for (int i = 0; i < razmer; i++)
    {
        --massiv[i];
    }
    return ob;
}
