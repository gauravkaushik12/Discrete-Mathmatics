#include<iostream>
using namespace std;

void show(int value[], int n)
{
	for(int i=0; i<n; i++)
	    cout << " " << value[i] <<" ";
	cout << endl;
}

int combinations(int value[], int k, int n, int c)
{
	if(k == 0)
	{
		value[k]=c;
		show(value, n);
		return 0;
	}
	
    for(int i= 0; i <= c; i++)
	{
		value[k]=i;
		combinations(value, k-1, n, c-i);
	}
}
int main()
{
	int n, const_result;
	cout << "Enter value of n: ";
	cin >> n;
	int values[n];
	again: 
    cout << "Enter value of constant value C (positive and not more than 10): ";
	cin >> const_result;
	
    while(!(const_result >= 0 && const_result <= 10))
	{
		cout << "Error: C should be between 1 to 10!"<< endl;
		goto again;
	}

	cout << "\nAll possible soln for C = " << const_result << " and n=  " << n << " are:\n";
	combinations(values, n-1, n, const_result);

return 0;
}