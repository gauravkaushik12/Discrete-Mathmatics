#include <iostream>
#include <math.h>
using namespace std;


int compute(int[], int, int);

int main(){

    int degree= 0, x;
    char ch = 'y';
    
    while(ch == 'y'){
        cout << "Enter the degree of the polynomial: ";
        cin >> degree;
        cout << endl;
        
        int coeffs[degree];

        for(int i= degree; i>= 0; i--){
            cout << "Enter the coefficient of degree " << i << ": ";
            cin >> coeffs[i];
        }
        
        cout << endl;
        cout << "Polynomial: ";
        for(int i= degree; i>= 0; i--){
            
            if(coeffs[i] != 0){
                cout << "(" << coeffs[i] << "x^" << i << ")";
                
                if(i==0){
                    continue;
                }
                cout << " + ";
            }
            else{
                continue;
            }
        }

        cout << "\nEnter the value of x : ";
        cin >> x;

        cout << "\nValue of the polynomial is: " << compute(coeffs, degree, x);
        cout << "\n\nDo you wanna compute another polynomial? (y/n): ";
        cin >> ch;
    }

}

// function 1 to compute the value of polynomial
int compute(int coeffs[], int deg, int x){
    int sum= 0;
    for(int i= deg; i>= 0; i--){
        sum += (coeffs[i] * pow(x,i));
    }
    
return sum;
}