#include <iostream>

using namespace std;

class Unite
{
    int* massiv = nullptr;
    int razmer = 0;

public:
//    Unite(const Unite& ob); //копирование запрещено
//    Unite& operator=(const Unite& ob); //Присваивание запрещено

    Unite()
    {
    massiv = nullptr;
    razmer = 0;
    }

    Unite(int x_user, int number_user) //если пользовать хочет заполнить одним числом весь массив
    {
        razmer = x_user;
        int number = number_user;

        massiv = new int[razmer];
        for (int i = 0; i < razmer; i++)
        {
            massiv[i] = number;
        }
    }
    ~Unite()
    {
        delete[] massiv;
    }


    Unite(const Unite& ob1) // конструктор копирования
    {
        if ((ob1.massiv != nullptr) && (ob1.razmer != 0))
        {
            massiv = new int[ob1.razmer];
            razmer = ob1.razmer;
            for (int i = 0; i < ob1.razmer; i++)
            {
                massiv[i] = ob1.massiv[i];
            }
        }
    }

    Unite& operator=(const Unite& ob1)
    {
        if (this == &ob1)
        {
            return *this;
        }
        delete[] massiv;
        massiv = nullptr;
        razmer = 0;

        if ((ob1.massiv != nullptr) && (ob1.razmer != 0))
        {
            massiv = new int[ob1.razmer];
            razmer = ob1.razmer;
            for (int i = 0; i < ob1.razmer; i++)
            {
                massiv[i] = ob1.massiv[i];
            }
        }
        return *this;
    }

void creator()
{
    cout << "Enter array size: ";
    cin >> razmer;
    massiv = new int[razmer];
    cout << "Enter " << razmer << "elements:" << endl;
    for(int i =0; i< razmer;i++)
    {
        cin >> massiv[i];
    }
}
void display()
    {
        cout << "Your array:" << endl;
    for(int i =0; i<razmer;i++)
    {
        cout << massiv[i] << " ";
    }
    cout << endl;
    }
    friend Unite operator+(Unite&ob1, Unite&ob2);
};
Unite operator+(Unite&ob1, Unite&ob2)
{
    Unite ob3;
    int* massivNew = nullptr;
int newSize = 0;
if(ob1.razmer > ob2.razmer) //берем меньший, чтобы суммировать только те, которые значат
{
    newSize = ob2.razmer;
    massivNew = new int[ob1.razmer];
    ob3.razmer = ob1.razmer;
    ob3.massiv = massivNew;

    for(int i=0; i<ob1.razmer;i++) //забиваем бОльшим массивом
    {
        ob3.massiv[i]=ob1.massiv[i];
    }

} else {
    newSize = ob1.razmer;
    massivNew = new int[ob2.razmer];
    ob3.razmer = ob2.razmer;
    ob3.massiv = massivNew;

        for(int i=0; i<ob2.razmer;i++) //забиваем бОльшим массивом
    {
        ob3.massiv[i]=ob2.massiv[i];
    }
}


for(int i=0; i< newSize; i++) //заполняем суммой
{
    ob3.massiv[i]= ob1.massiv[i] + ob2.massiv[i];
}


return ob3;
}

int main()
{
    Unite ob1;
    ob1.creator();
    ob1.display();

    Unite ob2(5, 5);
    ob2.display();

    Unite ob3(10, 10);

    ob3 = ob1 + ob2;
    ob3.display();

    return 0;
}
