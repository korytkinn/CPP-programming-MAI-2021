#include <iostream>

using namespace std;

class Dynmas
{
    int* massiv1;
    int* massiv2;

    int razmer1;
    int razmer2;
public:
    Dynmas()
    {
        massiv1 = nullptr;
        massiv2 = nullptr;
        razmer1 = 0;
        razmer2 = 0;
    }
    ~Dynmas()
    {
        delete[] massiv1;
        delete[] massiv2;
    }

//    Dynmas(const Dynmas& ob); // копирование запрещено

//    Dynmas& operator=(const Dynmas& ob); // присваивание запрещено

    Dynmas(const Dynmas& ob) // копирование
    {
        razmer1 = ob.razmer1;
        razmer2 = ob.razmer2;

        massiv1 = new int[razmer1];
        massiv2 = new int[razmer2];

        for (int i = 0; i < razmer1; i++)
        {
            massiv1[i] = ob.massiv1[i];
        }

        for (int i = 0; i < razmer2; i++)
        {
            massiv2[i] = ob.massiv2[i];
        }
    }

    Dynmas& operator=(const Dynmas& ob)
    {
        if (this == &ob)
        {
            return *this;
        }

        razmer1 = ob.razmer1;
        razmer2 = ob.razmer2;

        massiv1 = new int[razmer1];
        massiv2 = new int[razmer2];

        for (int i = 0; i < razmer1; i++)
        {
            massiv1[i] = ob.massiv1[i];
        }

        for (int i = 0; i < razmer2; i++)
        {
            massiv2[i] = ob.massiv2[i];
        }

        return *this;
    }

    void creator()
    {
        while (razmer1 <= 0)
        {
            cout << "\nEnter 1st array size > 0 (int): ";
            cin >> razmer1;
            if (razmer1 <= 0)
            {
                cout << "\nWrong array size = " << razmer1 << endl;
            }
        }

        while (razmer2 <= 0)
        {
            cout << "\nEnter 2nd array size > 0 (int): ";
            cin >> razmer2;
            if (razmer2 <= 0)
            {
                cout << "\nWrong array size = " << razmer2 << endl;
            }
        }

        massiv1 = new int[razmer1];
        massiv2 = new int[razmer2];

        cout << "\nEnter (int) elements of 1st array." << endl;
        for (int i = 0; i < razmer1; i++)
        {
            cout << "Enter " << i + 1 << " element of " << razmer1 << ": ";
            cin >> massiv1[i];
        }

        cout << "\nEnter (int) elements of 2nd array." << endl;
        for (int i = 0; i < razmer2; i++)
        {
            cout << "Enter " << i + 1 << " element of " << razmer2 << ": ";
            cin >> massiv2[i];
        }


    }

    void display() const
    {
        if (razmer1 == 0)
        {
            cout << "\n1st array size = 0" << endl;
        }
        else
        {
            cout << "\n1st array:" << endl;
            for (int i = 0; i < razmer1; i++)
            {
                cout << massiv1[i] << " ";
            }
            cout << endl;
        }

        if (razmer2 == 0)
        {
            cout << "\n2nd array size = 0" << endl;
        }
        else
        {
            cout << "\n2nd array:" << endl;

            for (int i = 0; i < razmer2; i++)
            {
                cout << massiv2[i] << " ";
            }
            cout << endl;
        }
    }

    void finder()
    {
        int min = 0;
        int max = 0;

        min = massiv1[0];
        max = massiv1[0];
        for (int i = 0; i < razmer1; i++)
        {
            if (min > massiv1[i])
            {
                min = massiv1[i];
            }
            if (max < massiv1[i])
            {
                max = massiv1[i];
            }
        }

        for (int i = 0; i < razmer2; i++)
        {
            if (min > massiv2[i])
            {
                min = massiv2[i];
            }
            if (max < massiv2[i])
            {
                max = massiv2[i];
            }
        }

        cout << "\nMax = " << max << ", Min = " << min << endl;

    }
};

int main()
{
    Dynmas test1;
    test1.creator();
    test1.display();
    test1.finder();
}
