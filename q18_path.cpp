#include <iostream>
using namespace std;


class graph
{
    private:
            int v= 10;              // variable storing number of vertices
            int matrix[10][10];     // adjacency matrix of the graph
			int result[10][10];

    public:
            graph();
            void getvertices();			// prototype of function 1 to get vertices of matrix
            void get_edges();			// prototype of function 2 to get edges and filling them in adjacency matrix
            void display();				// protptype of function 3 to display the matrix
            void power();				// prototype of function 4 to calculte power of matrix
            int path(int, int, int);	// prototype of function 5 to compute number of paths between source and destination of given length 
};

//main 
int main(){

    graph g;
	int edges, length, source, destination;
	char choice1= 'y', choice2= 'y';
    g.getvertices();
    
	do{
		
		cout << "\nEnter the number of edges present in the graph: ";
    	cin >> edges;

		for (int i= 0; i< edges; i++){
			cout << "Enter edge" << i + 1 << ": ";
			g.get_edges();
		}

		g.display();

		do{

			cout << "\nEnter source and destination: ";
			cin >> source;
			cin >> destination;
		
			cout << "\nEnter the length of the path: ";
			cin >> length;
			
			cout << "\nNumber of paths:\n" << g.path(source, destination, length);
			cout << "\nWant to compute with new source, destination and path length? ";
			cin >> choice1;
		
		}while(choice1== 'y' || choice1== 'Y');
		
		cout << "\nWant to compute with new matrix? ";
		cin >> choice2;

	}while(choice2== 'y'|| choice2== 'Y');

return 0;
 
}

// constructor
graph:: graph(){
    for(int i= 0; i< v; i++){
        for(int j= 0; j< v; j++){
            matrix[i][j] = 0;
			result[i][j] = 0;
        }
    }
}

// function 1 to initiaize matrix
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
        
		if(edge[i] > v){
			cout << "\n\tError: Edge Overflow!";
			goto again;
		}
		else if(edge[i] < 1){
			cout << "\n\tError: Enter a natural number!";
		}
    }

    matrix[edge[0] - 1][edge[1] - 1] = 1;
    result[edge[0] - 1][edge[1] - 1] = 1;

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

// function 4 to calculte power of matrix
void graph:: power(){
	
	int mul[v][v];
	
	for(int i= 0; i< v; i++){
		for(int j= 0; j< v; j++){
			mul[i][j]=0;
		}
	}

	for(int i= 0; i< v; i++){
		for(int j= 0; j< v; j++){
			for(int k= 0; k< v; k++){
				
				mul[i][j] += result[i][k] * matrix[k][j];
			}
		}
	}
	
	for(int i= 0; i< v; i++){
		for(int j= 0; j< v; j++){
			result[i][j]=mul[i][j];
		}
	}

	for(int i= 0; i< v; i++){
		for(int j= 0; j< v; j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
		cout << endl;
}

// function 5 to compute number of paths between source and destination of given length 
int graph:: path(int source, int destination, int length){

	for(int i= 0; i< length-1; i++){
		power();
	}
    cout << endl << source << destination;
	
return result[source][destination];
}