#include <iostream>
using namespace std;


int func1(int);         //prototype of function 1 to compute recursive relation T(n-1)+n
int func2(int);         //prototype of function 2 to compute recursive relation T(n-1)+n*2
int func3(int);         //prototype of function 3 to compute recursive relation 2*T(n/2)+n

// man function
int main()
{
    char ch = 'y';
    do{
        cout << "1. To calculate the recurssive relation T(n-1)+n";
        cout << "\n2. To calculate the recurssive relation T(n-1)+n*2";
        cout << "\n3. To calculate the recurssive relation 2*T(n/2)+n";
        
        int choice, n;
        
        cout << "\nEnter your choice: ";
        cin >> choice;
        cout << "\nEnter the value of n: ";
        cin >> n;

        if(choice == 1){
            cout << "\nOutput is given by: " << func1(n) << endl;
        }
        else if(choice == 2){
            cout << "\nOutput is given by: "<< func2(n) << endl;
        }
        else{
            cout << "\nOutput is given by: " << func3(n) << endl;
        }
        cout << "\nDo you want to calculate another? (Y/y) ";
        cin >> ch;

    }while(ch == 'y' || ch== 'Y');

}

int func1(int n){
	if(n==0)
	    return 1;
	else
	{
        cout << "\n" << "T(" << n-1 << ")" << "+" << n << " = " << n << endl;
        return func1(n-1)+n;
    }
}

int func2(int n){
	if(n==0)
	    return 1;
	else{
        cout << "\n" << "T(" << n-1 << ")" << "+" << n*2 << " = " << n*2 << endl;
        return func2(n-1)+n*2;
    }
}

int func3(int n){
	if(n==1)
	    return 1;
	else
	{
        cout << "\n" << "2*T(" << n/2 << ")+" << n << " = " << 2*n << endl;
        return 2*func3(n/2)+n;
    }
}