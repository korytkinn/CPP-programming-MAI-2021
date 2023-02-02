#include <iostream>
#include <utility> //файл для move, но можно и без него

using namespace std;

class DinMas
{
    int* Mas;
    int RazMas;

public:
    DinMas(const DinMas& ob) {

        if ((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = new int[ob.RazMas];
            RazMas = ob.RazMas;
            for (int i = 0; i < ob.RazMas; i++) {
                Mas[i] = ob.Mas[i];
            }
        }
        cout << "\n Konstryktor kopirovaniya\n";
    }

    DinMas(DinMas&& ob) //конструктор перемещения
    {
        if ((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = ob.Mas;
            RazMas = ob.RazMas;
            ob.Mas = nullptr; //чтобы он не  указывал туда, а то получается 2 владельца у памяти.
            ob.RazMas = 0; //чтобы он не  указывал туда, а то получается 2 владельца у памяти.
        }
        cout << "\n Konstryktor kopirovaniya\n";
    }

    DinMas& operator=(DinMas&& ob) // присваивание перемещением
    {
        if (this == &ob)
            return *this;
        delete[]Mas;
        Mas = nullptr;
        RazMas = 0;
        if ((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = ob.Mas;
            RazMas = ob.RazMas;
            ob.Mas = nullptr;
            ob.RazMas = 0;
        }
        cout << "\n Pereopredelennoe prisvoenie peremesheniem\n";
        return *this;
    }

    DinMas& operator=(const DinMas& ob) { //оператор присвоения копированием
        if (this == &ob)
            return *this;
        delete[]Mas;
        Mas = nullptr;
        RazMas = 0;
        if ((ob.Mas != nullptr) && (ob.RazMas != 0)) {
            Mas = new int[ob.RazMas];
            RazMas = ob.RazMas;
            for (int i = 0; i < ob.RazMas; i++) {
                Mas[i] = ob.Mas[i];
            }
        }
        cout << "\n Pereopredelennoe prisvoenie\n";
        return *this;
    }

    DinMas(int k, int m) : Mas{ nullptr }, RazMas{ 0 }
    {
        if (k < 1)
        {
            return;
        }
        RazMas = k;
        Mas = new int[RazMas];
        for (int i = 0; i < RazMas; i++)
        {
            Mas[i] = m;
        }
        cout << "\n Konstryktor s parametrami porabotal\n";
    }

    DinMas() {
        RazMas = 0;
        Mas = nullptr;
        cout << "\n Konstryktor porabotal\n";
    }

    ~DinMas() {
        delete[]Mas;
        cout << "\n Destryktor porabotal\n";
    }

    void Create() {
        cout << " Vvedite razmer (natyralnoe chislo) : ";
        int t;
        cin >> t;
        if (t <= 0) {
            return;
        }
        RazMas = t;
        Mas = new int[RazMas];
        cout << " Vvodite celie chisla : \n";
        for (int i = 0; i < RazMas; i++) {
            cin >> Mas[i];
        }
    }

    void Show() const {
        cout << " Vivod massiva : ";
        for (int i = 0; i < RazMas; i++) {
            cout << " " << Mas[i];
        }
        cout << "\n Adress nachala massiva: " << Mas << endl;
    }


    // НОВОЕ на практической работе 13.1
    DinMas operator-() const
    {
        cout << "Ynarnii minus nachinaet raboty\n";
        DinMas ob(*this); //после этого действия ob.Razmas == RazMas
        for (int i = 0; i < ob.RazMas; i++)
        {
            ob.Mas[i] = -ob.Mas[i];
        }
        cout << "Ynarnii minus zakanchivaet raboty\n";

        return ob;
    }

    DinMas operator+() const
    {
        return *this;
    }

    friend bool operator==(const DinMas& ob1, const DinMas& ob2);
    friend bool operator!=(const DinMas& ob1, const DinMas& ob2);

    void setter(const DinMas& ob1)
    {
        RazMas = ob1.RazMas;
        Mas = new int[RazMas];
        for (int i = 0; i < RazMas; i++)
        {
            Mas[i] = ob1.Mas[i];
        }
    }

    int getter()
    {
        return RazMas;
    }

};
bool operator==(const DinMas& ob1, const DinMas& ob2)
{
    // равенство двух объектов, если элементы массивов
    // динамических между собой равны. и длины равны
    if ((ob1.Mas == nullptr) && (ob2.Mas == nullptr))
    {
        return true;
    }
    if (ob1.RazMas != ob2.RazMas)
    {
        return false;
    }
    bool flag = true;
    for (int i = 0; i < ob1.RazMas; i++)
    {
        if (ob1.Mas[i] != ob2.Mas[i])
        {
            flag = false;
        }
    }
    return flag;
}

bool operator!=(const DinMas& ob1, const DinMas& ob2)
{
    return !(ob1 == ob2);
}

void obmen_kopirovaniem(DinMas& a, DinMas& b)
{
    DinMas c{ a };
    a = b;
    b = c;
}

void obmen_peremesheniem(DinMas& a, DinMas& b)
{
    DinMas c = move(a);
    a = move(b);
    b = move(c);
}

int main()
{
    DinMas ob1(1, 10);
    cout << "ob1(1,10) : \n";
    ob1.Show();

    DinMas ob2(2, 20);
    cout << "ob2(2,20) : \n";
    ob2.Show();

    DinMas& ob3(ob1); //динамически инициализируем ....
    cout << "ob3(ob1) : \n"; // ob3 стал псевдонимом ob1, один адрес в памяти
    ob3.Show();

    DinMas&& ob4(DinMas(4, 40)); // по сути вызвали конструктор, который инициализировал объект (4,40). Объект без имени - анонимный
    // по сути создание анонимного объекта

    cout << "ob4(DinMas(4,40)) : \n";
    ob4.Show();

    //    DinMas&&ob5(5,5);
    //    DinMas&&ob6(ob2);

    const DinMas& ob7(DinMas(7, 70));
    cout << "ob7(DinMas(7, 70)) : \n";

    ob7.Show();

    ob4 = DinMas(9, 90);
    cout << "ob4 = DinMas(9, 90) : \n";
    ob4.Show();

    return 0;
}
