#include <iostream>
#include <utility> //файл для move, но можно и без него

using namespace std;

class DinMas
{
    int*Mas;
    int RazMas;

public:
    DinMas(const DinMas &ob){

        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=new int[ob.RazMas];
           RazMas=ob.RazMas;
           for(int i=0; i<ob.RazMas; i++){
               Mas[i]=ob.Mas[i];
           }
        }
        cout<<"\n Konstryktor kopirovaniya\n";
    }

    DinMas(DinMas&&ob) //конструктор перемещения
    {
        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=ob.Mas;
           RazMas=ob.RazMas;
           ob.Mas = nullptr; //чтобы он не  указывал туда, а то получается 2 владельца у памяти.
           ob.RazMas=0; //чтобы он не  указывал туда, а то получается 2 владельца у памяти.
        }
        cout<<"\n Konstryktor kopirovaniya\n";
    }

    DinMas& operator=(DinMas&&ob) // присваивание перемещением
    {
        if(this==&ob)
            return *this;
        delete[]Mas;
        Mas=nullptr;
        RazMas=0;
        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=ob.Mas;
           RazMas=ob.RazMas;
           ob.Mas = nullptr;
           ob.RazMas=0;
        }
        cout<<"\n Pereopredelennoe prisvoenie\n";
        return *this;
    }

    DinMas&operator=(const DinMas &ob){ //оператор присвоения копированием
        if(this==&ob)
           return *this;
        delete[]Mas;
        Mas=nullptr;
        RazMas=0;
        if((ob.Mas!=nullptr)&&(ob.RazMas!=0)){
           Mas=new int[ob.RazMas];
           RazMas=ob.RazMas;
           for(int i=0; i<ob.RazMas; i++){
               Mas[i]=ob.Mas[i];
           }
        }
        cout<<"\n Pereopredelennoe prisvoenie\n";
        return *this;
    }

    DinMas(int k, int m): Mas{nullptr}, RazMas{0}
    {
        if(k<1)
        {
            return;
        }
        RazMas=k;
        Mas = new int[RazMas];
        for(int i=0; i<RazMas;i++)
        {
            Mas[i]=m;
        }
        cout << "\n Konstryktor s parametrami porabotal\n";
    }

    DinMas(){
        RazMas=0;
        Mas=nullptr;
        cout<<"\n Konstryktor porabotal\n";
    }

    ~DinMas(){
        delete[]Mas;
        cout<<"\n Destryktor porabotal\n";
    }

    void Create(){
        cout<<" Vvedite razmer (natyralnoe chislo) : ";
        int t;
        cin>>t;
        if(t<=0){
            return;
        }
        RazMas=t;
        Mas=new int[RazMas];
        cout<<" Vvodite celie chisla : \n";
        for(int i=0; i<RazMas; i++){
            cin>>Mas[i];
        }
    }

    void Show() {
        cout<<" Vivod massiva : ";
        for(int i=0; i<RazMas; i++){
            cout<<" "<<Mas[i];
        }
        cout<<"\n Adress nachala massiva: "<<Mas<<endl;
    }


    // НОВОЕ на практической работе 13.1
    DinMas operator-() const
    {
        cout << "Ynarnii minus nachinaet raboty\n";
        DinMas ob(*this); //после этого действия ob.Razmas == RazMas
        for(int i=0; i<ob.RazMas; i++)
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

    friend bool operator==(const DinMas &ob1, const DinMas &ob2);
    friend bool operator!=(const DinMas &ob1, const DinMas &ob2);

    void setter(const DinMas &ob1)
    {
        RazMas = ob1.RazMas;
        Mas = new int[RazMas];
        for(int i=0;i<RazMas;i++)
        {
            Mas[i]=ob1.Mas[i];
        }
    }

    int getter()
    {
        return RazMas;
    }

};
    bool operator==(const DinMas &ob1, const DinMas &ob2)
    {
        // равенство двух объектов, если элементы массивов
        // динамических между собой равны. и длины равны
        if((ob1.Mas==nullptr) && (ob2.Mas == nullptr))
        {
            return true;
        }
        if(ob1.RazMas != ob2.RazMas)
        {
            return false;
        }
        bool flag = true;
        for(int i=0; i<ob1.RazMas; i++)
        {
            if(ob1.Mas[i] != ob2.Mas[i])
            {
                flag = false;
            }
        }
        return flag;
    }

    bool operator!=(const DinMas &ob1, const DinMas &ob2)
    {
        return !(ob1==ob2);
    }

    void obmen_kopirovaniem(DinMas&a, DinMas&b)
    {
        DinMas c{a};
        a=b;
        b=c;
    }

    void obmen_peremesheniem(DinMas &a, DinMas &b)
    {
        DinMas c = move(a);
        a = move(b);
        b = move(c);
    }

int main()
{
    const int KOL=10;
    DinMas Massiv[KOL]={DinMas(1,1),DinMas(2,2),DinMas(3,3),DinMas(4,4),
    DinMas(5,5),DinMas(6,6),DinMas(7,7),DinMas(8,8),
    DinMas(9,9),DinMas(10,10)};
    cout << "\n Vivod massivov:\n\n";
    for(int i=0; i<KOL; i++)
    {
        Massiv[i].Show();
        cout<<endl;
    }

    obmen_kopirovaniem(Massiv[0],Massiv[9]);

    cout << "\n Vivod massivov:\n\n";
    for(int i=0; i<KOL; i++)
    {
        Massiv[i].Show();
        cout<<endl;
    }

    cout << "RABOTAEM"<<endl;

		for (int i = 0; i < KOL-1; i++)
		{
			for (int j = 0; j < KOL-i-1; j++)
			{
//				int karman;
				if (Massiv[j].getter() < Massiv[j+1].getter())
				{
				    obmen_kopirovaniem(Massiv[j],Massiv[j+1]);
				}
			}
		}


    cout << "\n Vivod massivov:\n\n";
    for(int i=0; i<KOL; i++)
    {
        Massiv[i].Show();
        cout<<endl;
    }

    cout << "\nRABOTAEM PEREMESHENIEM\n";
    obmen_peremesheniem(Massiv[1],Massiv[8]);
    cout << "\n Vivod massivov:\n\n";
    for(int i=0; i<KOL; i++)
    {
        Massiv[i].Show();
        cout<<endl;
    }

    return 0;
}
