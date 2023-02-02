#include <iostream>

using namespace std;

int main()
{
        int n=16, i, j;
//    cout << "Hello world!" << endl;
//    int numbers[16];
    int numbers[] = {-888,777,1000, 5532, 1, 22, -53, 8, 9,10,11,-12,13,14,-15,16};

    cout << "Before sort:" <<endl;
        for(i=0;i<16; i++) {
        cout<< numbers[i] << " ";
    }
/*    for(int i = 0; i < 16; i++)
    {
        cin >> numbers[i];
    }
    */
//    int minimum = numbers[0];
//    int temp = 0;


    for(i = 0 ; i < n - 1; i++) {
       // сравниваем два соседних элемента.
       for(j = 0 ; j < n - i - 1 ; j++) {
           if(numbers[j] > numbers[j+1]) {
              // если они идут в неправильном порядке, то
              //  меняем их местами.
              int tmp = numbers[j];
              numbers[j] = numbers[j+1] ;
              numbers[j+1] = tmp;
           }
        }
    }
    cout << "\nAfter sort:" <<endl;

    for(i=0;i<16; i++) {
        cout<< numbers[i] << " ";
    }
    cout << endl << endl;
    //предыдущая версия сортировки
//    for(int i = 0; i < 15; i++)
//    {
//    if(numbers[i]>numbers[i+1]) {
//            temp=numbers[i];
//        numbers[i]=numbers[i+1];
//        numbers[i+1]=temp;
//    }
//    }



    int massiv[4][4];
    int index = 0;
    int k = 3;

    //заполняем двумерный массив
        for(i = 0; i< 4; i=i+2) //строка
        for(j = 0; j< 4; j++) //столбец
        {
        massiv[i][j]=numbers[i*4+j];
        massiv[i+1][3-j]=numbers[(i+1)*4+j];
        }


    //вывод массива в консоль
        for(int i = 0; i< 4; i++) //stroka
        {
        for(int j = 0; j< 4; j++) // stolbets
        {
        cout << massiv[i][j] << " ";
        if(j == 3) {
            cout << "\n";
        }
        }
    }



//        for(int i = 0; i < 16; i++)
//    {
 //       cout << numbers[i] << " ";
 //   }



    return 0;
}
