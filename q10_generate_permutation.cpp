#include<iostream>
#include<string>
using namespace std;

void swap(char &x,char &y)
{
    char temp= x;
    x= y;
    y= temp;
}

void permutation(char num[],int l,int r)
{
    if(l==r)
        cout << num << " " ;

    else
    {
        for(int i= l; i<= r; i++)
        {
            swap(num[l],num[i]);
            permutation(num,l+1,r);
            swap(num[l],num[i]);
        }
    }
}

int main()  
{
    char num[20];
    int i, n;

    cout << "\nEnter the number of digits whose permutations you want to find (less than 20): ";
    cin >> n;
    while(n> 20)
    {
        cout << "\nEnter right number bruhh: ";
        cin>> n;
    }
    
    cout << "\nEnter digits: ";
    for(i= 0; i< n; i++)
    {
        cin >> num[i];
        while(!isdigit(num[i]))
        {
            cout << "\nEnter a digit bruhh: ";
            cin >> num[i];
        }
    }

    num[i]='\0';

    cout << "\nEntered set of digits is : ";
    for(i= 0; i< n; i++)
        cout << num[i]<<", ";

    cout << "\nAll permutations of without repetation {";
    for(i= 0 ; i< n; i++)
        cout << num[i] << " , ";
    cout << "\b\b} are: ";
    permutation(num,0,n-1);

    return 0;
}