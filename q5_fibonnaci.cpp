#include<iostream>
using namespace std;

int fibonnaci(int n)
{
    if (n <= 1)
        return n;
    else
        return (fibonnaci(n-1) + fibonnaci(n-2));
}

int main()
{
    int n;

    again: cout << "\nEnter the value of n: ";
    cin >> n;
    
    if(n <= 0)
    {   
        cout << "n should be a greater than 0.";
        goto again;
    }
    
    cout << "Fibonnaci Series is: ";
    for(int i= 0; i< n; i++)
        cout << fibonnaci(i) << " ";
    return 0;
}