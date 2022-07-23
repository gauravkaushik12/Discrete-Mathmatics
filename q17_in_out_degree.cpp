#include<iostream>
using namespace std;

// prototype for function-1 to calculate in-degree
int calc_indegree(int[][10], int, int);
// prototype for function-2 to calculate out-degree
int calc_outdegree(int[][10], int, int);

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
            notboolean: cin >> matrix[i][j];

            if(matrix[i][j] != 0 && matrix[i][j] != 1){
                cout << "Please enter either 0 or 1 : " << endl;
                goto notboolean;
            }
        }
    }

    for(int i= 0; i< v; i++){
            cout << "In-degree of " << i << " is: " << calc_indegree(matrix, v, i) << endl;
            cout << "Out-degree of " << i << " is: " << calc_outdegree(matrix, v, i) << endl;
    }

    return 0;
}

// function-1 to check for completeness
int calc_indegree(int g[10][10], int n, int v){
    int count= 0;
    for(int i= 0; i< n; i++){
        if(g[v][i] == 1)
            count++;
    }

return count;
}

// function-1 to check for completeness
int calc_outdegree(int g[10][10], int n, int v){
    int count= 0;
    for(int i= 0; i< n; i++){
        if(g[i][v] == 1)
            count++;
    }

return count;
}