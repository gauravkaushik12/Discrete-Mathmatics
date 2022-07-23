#include <iostream>
using namespace std;

int calcMoves(int);      // prototype of function 1 to compute number of moves

int main(){
	int d;

	cout<<"\nEnter the number of discs: ";
	cin>>d;
	
    cout<<"\nNumber of moves required to make Tower of Hanoi: "<< calcMoves(d) << endl;
}

int calcMoves(int d){
	if(d==1)
	    return 1;                       // base case
	else 
	    return 2*calcMoves(d-1)+1;       // recursive call
}