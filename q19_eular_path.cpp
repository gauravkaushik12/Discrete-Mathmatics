#include <iostream>
using namespace std;


class graph
{
    private:
            int v= 10;              // variable storing number of vertices
            int matrix[10][10];     // adjacency matrix of the graph

    public:
            graph();
            void getvertices();             // prototype of function 1 to get vertices of matrix
            void get_edges();               // prototype of function 2 to get edges and filling them in adjacency matrix
            void display();                 // protptype of function 3 to display the matrix
            void check_for_eular();         // prototype of functino 4 to check for eular path
};

int main(){

    graph g;
    int n;
    g.getvertices();
    cout << "\nEnter the number of edges present in the graph: ";
    cin >> n;

    for (int i= 0; i< n; i++){
        cout << "Enter edge" << i + 1 << ": ";
        g.get_edges();
    }

    g.display();

    try{
        g.check_for_eular();
    }
    catch(const char* message){
        cout << message << endl;
    }

return 0;
}

// constructor
graph:: graph(){
    for(int i= 0; i< v; i++){
        for(int j= 0; j< v; j++){
            matrix[i][j] = 0;
        }
    }
}

// function 1 to get vertices of matrix
void graph:: getvertices(){

    wrong_v: cout << "Enter the number of vertices in the graph (not more than 10): ";
    cin >> v;

    if(v > 10 || v < 0){
        cout << "\nEnter positive value of v not more than 10.";
        goto wrong_v;
    }
}

// function 2 to get edges and filling them in adjacency matrix
void graph:: get_edges(){
    int edge[2];
    
    for (int i= 0; i< 2; i++){
        again:  cin >> edge[i];
        
        if (edge[i] > v){
            cout << "\n\tError: Edge Overflow!";
            goto again;
        }
    }

    matrix[edge[0] - 1][edge[1] - 1] = 1;
    matrix[edge[1] - 1][edge[0] - 1] = 1;
}

// function 3 to display the matrix
void graph:: display(){

    cout << "\nAdjency matrix:\n";
    for(int i= 0; i< v; i++){
        cout << endl << "\t\t\t";
        for(int j= 0; j< v; j++){
            cout << matrix[i][j] << " ";
            }
        }
    cout << endl;
}

// functino 4 to check for eular path
void graph:: check_for_eular(){
	int count;
	int oddVertex= 0;

	for(int i= 0; i< v; i++){
		count= 0;
		for(int j= 0; j< v; j++){
			if(matrix[i][j] == 1){
				count++;
			}
		}
		if(count % 2){
			oddVertex++;
		}
	}

	if(oddVertex > 2){
		throw "Graph is not an Eular graph.";
	}
	if(oddVertex == 2){
		throw "Graph has an Eular path";
	}
	throw "Graph has an Eular circuit.";
}