#include <iostream>

using namespace std;

int main()
{
    int razmer;
    int* massiv;

    cout << "Enter array size(int) = ";
    cin >> razmer;

    massiv = new int[razmer];

    for(int i=0; i<razmer;i++)
    {
        cout << "Enter " << i+1 << "element of " << razmer << ": ";
        cin >> massiv[i];
    }
    for(int i=0; i<razmer;i++)
    {
        cout << massiv[i] << " ";
    }
    cout << endl;

    for(int i=0;i<razmer;i++)
    {
        for(int j=0; j<razmer;j++)
        {
            if(massiv[i]>massiv[j])
            {
                int temp = massiv[i];
                massiv[i] = massiv[j];
                massiv[j] = temp;
            }
        }
    }

    for(int i=0; i<razmer;i++)
    {
        cout << massiv[i] << " ";
    }
    return 0;
}
