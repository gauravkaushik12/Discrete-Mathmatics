#include<iostream>
using namespace std;

void bubble(int array[100], int size)
{
    int temp = 0, count= 0;
    
    for (int i = 0; i < size; i++)    
    {   
        count = 0;
        for (int j = 0; j < size-i-1; j++)
        {   
            count++;
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        cout << "\nNumber of comparisions in pass: " << count << " : ";
        for(int k= 0; k< size; k++)
            cout << array[k] << " ";
    }

    cout << "\nSorted array is: ";
    //print the sorted array
    for(int i= 0; i< size; i++)
        cout << array[i] << " ";
}

int main()
{
    int array[100],size = 0;

    cout << "Enter the size of the array: ";
    cin >> size;

    

    cout << "\nEnter the elements of the array: ";
    for(int i = 0; i < size; i++)
        cin >> array[i];
    
    bubble(array, size);

return 0;
}