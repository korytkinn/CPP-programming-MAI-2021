#include <iostream>

using namespace std;

class DM
{
    int*Mas; //указатель создан, чтобы по нему 1
    //из методов выделял дин память
    int K; // размер массива
public:
    DM(){Mas=nullptr; K=0;} //конструктор инициализирует данные нулями
    ~DM(){delete[]Mas;} //деструктор освобождает память
};
int main()
{
    return 0;
}
