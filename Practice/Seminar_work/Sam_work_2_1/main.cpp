#include <iostream>

using namespace std;

int display(int A[]);

int main()
{
    int massiv[]={525,-777,123,444};
    display(massiv);
    return 0;
}

int display(int A[])
{
    for(int i=0;i<4;i++) {
        cout << "Array[" << i << "]= "  << A[i] << endl;
    }
    cout<< endl;
    return 0;
}
