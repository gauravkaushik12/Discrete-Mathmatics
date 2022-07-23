#include<iostream>
using namespace std;


// prototype for function-1 to check for completeness
void iscomplete(int g[10][10], int n);

// main
int main(){

    int matrix[10][10];
    int v;

    wrong_v: cout << "Enter the number of vertices in the graph (not more than 10): ";
    cin >> v;

    if(v > 10 || v < 0){
        cout << "\nEnter positive value of v not more than 10.";
        goto wrong_v;
    }

    cout << "\nFill the adjency matrix (0 or 1 only):\n";
    for(int i= 0; i< v; i++){
        cout << endl << "\t\t\t\t\t";
        for(int j= 0; j< v; j++){
            notbinary: 
            cin >> matrix[i][j];

            if(matrix[i][j] != 0 && matrix[i][j] != 1){
                cout << "Please enter either 0 or 1 : " << endl;
                goto notbinary;
            }
        }
    }

    try{
        iscomplete(matrix, v);
    }
    catch(const char* message){
        cout << message << endl;
    }

    return 0;
}

// function-1 to check for completeness
void iscomplete(int g[10][10], int n){

    for(int i= 0; i< n; i++){
        for(int j= 0; j< n; j++){
            // checking for self-loop & incompleteness
            if(i == j && g[i][j] == 1)
                throw "Graph is Incomplete : self-loop found";
            else if(i != j && g[i][j] == 0)
                throw "Graph is Incomplete : edge not found";
        }
    }
    cout << "Graph is Complete!" << endl;
}