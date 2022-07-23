#include<iostream>
using namespace std;


// prototype of function 1 to compute total number of leaf nodes
int compute(int, int);

int main(){
    
    int m, i;
    cout << "\nEnter the number of internal nodes: ";
    cin >> i;
    cout << "Enter the value of m: ";
    cin >> m;

    cout << "\nNumber of leaves are: " << compute(m, i) << endl;

return 0;
}

// function 1 to compute total number of leaf nodes
int compute(int m, int i){
    return (m-1)*i + 1;
}