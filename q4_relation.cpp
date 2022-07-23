#include<iostream>
using namespace std;


class Relation{
    private:
            int** arr;
            int size;
            int* set;
    
    public:
            Relation(){
                arr=NULL;
                size=0;
            }

            void set_size();                //prototype of function_1 to initialize the size of the set
            void enter();                   //prototype of function_2 to get the elememts of the set and relation
            void show_matrix();             //prototype of function_3 to print the relation matrix
            bool reflexive();               //prototype of function_4 to check if the relation is reflexive
            bool symmetric();               //prototype of function_5 to check if the relation is symmetric
            bool transitive();              //prototype of function_6 to check if the relation is transitive
            bool anti_symmetric();          //prototype of function_7 to check if the relation is anti-symmetric
            bool equivalence();             //prototype of function_8 to check if the relation is equivalence
            bool partial_order();           //prototype of function_9 to check if the relation is partial order
};

void Relation:: set_size(){                 //function_1 to initialize the size of the set
    cout << "Enter number of elements in the set: ";
    cin >> size;
    
    set=new int[size];
    
    cout << "Enter elements of the set: ";
    for(int i=0;i<size;i++)
        cin >> set[i];

    arr=new int*[size];

    for(int i=0;i<size;i++)
        arr[i]=new int[size];
    
    for(int i=0;i<size;i++)    //initalizing matrix with zero at all positions.
        for(int j=0;j<size;j++)
            arr[i][j]=0;
}

void Relation:: enter(){                    //function_2 to get the elememts of the set and relation
    int a,b,i,num;
    
    cout << "Enter the number of elements in the relation: " << endl;
    cin >> num;

    for(int i =0;i<num;i++)
    {
        cout << "Enter pair number " << (i+1) << " respectively" << std:: endl;
        cin >> a >> b;

        int p,q;
        
        for(int m= 0; m< size; m++){
            if(a==set[m])
                p=m;
            if(b==set[m])
                q=m;	
        }
        arr[p][q]= 1;
    }
    show_matrix();
}

void Relation:: show_matrix(){              //function_3 to print the relation matrix
    cout << endl << "The Relation matrix is: " << endl;
    for(int i= 0; i< size+1; i++){
        for(int j= 0; j< size+1; j++){
            if(i==0 && j==0)
                cout << "  ";
            else if(i==0)
                cout << set[j-1] << " ";
            else if(j==0)
                cout << set[i-1] << " ";
            else
                cout << arr[i-1][j-1] << " ";
            }
        cout << endl;
    }
}

bool Relation:: reflexive(){                //function_4 to check if the relation is reflexive
    for(int i= 0; i< size; i++){
        if(arr[i][i] != 1)
            return false;
    }
    return true;
}

bool Relation:: symmetric(){                //function_5 to check if the relation is symmetric
    for(int i= 0; i< size; i++){
        for(int j= 0; j< size; j++){
            if(arr[i][j]==1 && arr[j][i]!=1)
                return false;
        }
    }
    return true;
}

bool Relation:: transitive(){               //function_6 to check if the relation is transitive
    for(int i= 0; i< size; i++){
        for(int j= 0; j< size; j++){
            if(arr[i][j] == 1){
                for(int k= 0; k< size; k++){
                    if(arr[j][k]==1 && arr[i][k]==0)
                        return false;
                }
            }
        }
    }
    return true;
}

bool Relation:: anti_symmetric(){           //function_7 to check if the relation is anti-symmetric
    for(int i= 0; i< size; i++){
        for(int j= 0; j< size; j++){
            if((arr[i][j]==1 && arr[j][i]==1) && i!=j)
                return false;
        }
    }
    return true;
}

bool Relation:: equivalence(){              //function_8 to check if the relation is equivalence
    return (this->reflexive() && this->symmetric() && this->transitive());
}

bool Relation:: partial_order(){            //function_9 to check if the relation is partial order
    return (this->reflexive() && this->anti_symmetric() && this->transitive()); 
}

// main
int main(){
    int choice;
    char ch;
    bool T=true;
    Relation r;

    r.set_size();
    r.enter();

    do
    {
        cout << "\nCheck if Relation is:\n";
        cout << "\n1.Equivalence\t2.Partial Order\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1  :   if(r.equivalence())
                            cout << "\nThe relation is equivalence";
                        else
                            cout << "\nThe relation is not equivalence";
                        break;


            case 2  :   if(r.partial_order())
                            cout << "\nThe relation is Partial Order";
                        else
                            cout << "\nThe relation is not Partial Order";
                        break;
        
            default:    cout << "\nWrong choice..!";
                        break;
        }
        cout << "\n\ndo you want to continue Y/N : ";
        cin >> ch;
    }while (ch== 'y' || ch == 'Y');

return 0;
}