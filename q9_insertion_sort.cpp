#include<iostream>
using namespace std;

void insertion(int array[100],int size)
{
	int temp= 0, count= 0, j;

	for(int i=0; i< size; i++)
	{
       count= 0;
	   temp= array[i];
	   
       j= i-1;
	   while(count++,j>=0 && array[j]>temp)
       {
          array[j+1]=array[j];
          j--;
       }
        array[j+1]=temp;
		cout << "\nNumber of comparisons: " << count << " : ";
        for(int k= 0; k< size; k++)
            cout << " " << array[k];
	}

    cout << "\nSorted array is: ";
	for(int i=0;i< size; i++)
	    cout << array[i] << " ";
}


int main()
{
    int array[100], size;
	
    cout<<"Enter the size of the array: ";
	cin>>size;

    cout<<"Enter the array: ";
	for(int i= 0;i< size; i++)
        cin >> array[i];
	
	insertion(array,size);

return 0;
}