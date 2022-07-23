#include<iostream>
#include<math.h>
using namespace std;

class Set                       //class 'set'
{
    private:
            int size;                           //integer variable storing the size/cardinality of the set
            int* set;
    
    public:
            Set()
            {
                size= 0;
                set= new int[size];
            }

            void set_size();                    //prototype of function_1 to initialize the size of the set
            void get_elements();                //prototype of function_2 to get the elememts of the set
            void showset();                     //prototype of function_4 to print the elements of the set
            int cardinality();                  //prototype of function_5 to return the cardinality of the set
            bool is_member(int);                //prototype of function_6 to check if the passes element is present in the set
            void power_set();                   //prototypr of function_7 to print the power set of the set

};                                  //end of class 'set'

void Set::set_size()                //function_1 to initialize the size of the set
{   
    again: cin >> size;
    if(size== 0)
        goto again;
    else
        set = new int[size];
}

void Set::get_elements()            //function_2 to get the elememts of the set
{
    for(int i= 0; i< size; i++)
        cin >> set[i];
}


void Set::showset()                    //function_4 to print the elements of the set
{
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(set[i]==set[j]){
                while(j<size){
                    set[j]=set[j+1];
                    j++;
                }
                --size;
            }
            else continue;
        }
    }
    cout << "set is {";
    for(int i=0;i<size;i++){
        cout << set[i] << " ";
    }
    cout << "}";
}

int Set::cardinality()              //function_4 to print the elements of the set
{    
return size;
}

bool Set::is_member(int elem)       //function_6 to check if the passes element is present in the set
{
    for(int i= 0; i< size; i++)
    {
        if(set[i] == elem)        //duplicate found...returning to main
            return true;
    }
return false;
}

void Set::power_set()               //function_7 to print the power set of the set
{
    int psize = pow(2, cardinality());

    cout << "{";
    for(int i= 0; i< psize; i++)
    {
        cout << "{";
        
        for(int j= 0; j< size; j++){
        
            if(i & (1 << j)){
                cout << set[j] << ",";
            }
        }
        cout << "\b" << "} ";
    }
}

int main()                          //main function
{   
    Set A;
    
    cout << "Enter the size of the array: ";
    A.set_size();                   //reading size of the set

    cout << "\nEnter the elements of the arrray:\n";
    A.get_elements();               //reading elements of the set
    A.showset();

    int choice;
    char ch= 'y';
    
    do
    {
    cout <<"\n1. Show Cardinality of set\n2. Check if an element is present in the set\n3. Print power set of the set";
    cout <<"\nEnter you choice: ";
    cin >> choice;                   //reading choice from the user

    switch ((choice))
    {
        case 1  :   cout <<"\nCardinality of the setn is: " << A.cardinality();   //calling function_5
                    break;

        case 2  :   cout <<"\nEnter the element: ";
                    cin >> choice;

                    if(A.is_member(choice))             //calling function_6
                        cout <<"\nElement is present.";
                    else
                        cout <<"\nElement is not present";
                    break;

        case 3  :   cout << "\nPower set is: { ";
                    A.power_set();                      //calling function_7
                    cout <<" }";
                    break;
        
        default :   cout <<"\nWrong Choice!!!";
    }
    cout << "\nChoose again? ";
    cin >> ch;
    }while (ch== 'y' || ch == 'Y');   

return 0;
}                                       //end of main function    