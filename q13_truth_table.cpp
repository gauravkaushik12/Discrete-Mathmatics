#include <iostream>
#include <iomanip>

using namespace std;

void conj(bool arrx[], bool arry[]){
    char arrConj[4];
    for(int i=0;i<4;++i){
        if(arrx[i] && arry[i]){
            arrConj[i]='T';
        }else{
            arrConj[i]='F';
        }
    }

    cout<<boolalpha;
    for(int i=0;i<4;++i){
        cout<<arrx[i]<<"         "<<arry[i]<<"         "<<arrConj[i]<<endl;
    }


}
void dis_conjunction(bool arrx[], bool arry[]){
    char arrdConj[4];
    for(int i=0;i<4;++i){
        if(arrx[i] || arry[i]){
            arrdConj[i]='T';
        }else{
            arrdConj[i]='F';
        }
    }

    cout<<boolalpha;
    for(int i=0;i<4;++i){
        cout<<arrx[i]<<"         "<<arry[i]<<"         "<<arrdConj[i]<<endl;
    }


}
void XOR(bool arrx[], bool arry[]){
    char tt[4];
    for(int i=0;i<4;++i){
        if(arrx[i] != arry[i]){
            tt[i]='T';
        }else{
            tt[i]='F';
        }
    }

    cout<<boolalpha;
    for(int i=0;i<4;++i){
        cout<<arrx[i]<<"         "<<arry[i]<<"         "<<tt[i]<<endl;
    }
}
void cond(bool arrx[], bool arry[]){
    char tt[4];
    for(int i=0;i<4;++i){
        if(arrx[i]==true && arry[i]==false){
            tt[i]='F';
        }else{
            tt[i]='T';
        }
    }
    cout<<boolalpha;
    for(int i=0;i<4;++i){
        cout<<arrx[i]<<"         "<<arry[i]<<"         "<<tt[i]<<endl;
    }



}
void bicond(bool arrx[], bool arry[]){
    char tt[4];
    for(int i=0;i<4;++i){
        if(arrx[i]== arry[i]){
            tt[i]='T';
        }else{
            tt[i]='F';
        }
    }
    cout<<boolalpha;
    for(int i=0;i<4;++i){
        cout<<arrx[i]<<"         "<<arry[i]<<"         "<<tt[i]<<endl;
    }
}
void XNOR(bool arrx[], bool arry[]){
    char tt[4];
    for(int i=0;i<4;++i){
        if(arrx[i] == arry[i]){
            tt[i]='T';
        }else{
            tt[i]='F';
        }
    }

    cout<<boolalpha;
    for(int i=0;i<4;++i){
        cout<<arrx[i]<<"         "<<arry[i]<<"         "<<tt[i]<<endl;
    }
}

void NEGATION(bool arrx[]){
    cout<<"negation of p "<<endl;
    char tt[4];
    for(int i=0;i<4;++i){
        if(!arrx[i]){
            tt[i]='T';
        }else
            tt[i]='F';

    }

    cout<<boolalpha;
    for(int i=0;i<4;++i){
          cout<<arrx[i]<<"                "<<tt[i]<<endl;
    }
}
void NAND(bool arrx[], bool arry[]){
    char arrConj[4];
    for(int i=0;i<4;++i){
        if(!(arrx[i] && arry[i])){
            arrConj[i]='T';
        }else{
            arrConj[i]='F';
        }
    }

    cout<<boolalpha;
    for(int i=0;i<4;++i){
        cout<<arrx[i]<<"         "<<arry[i]<<"         "<<arrConj[i]<<endl;
    }

}
void NOR(bool arrx[], bool arry[]){
    char arrdConj[4];
    for(int i=0;i<4;++i){
        if(!(arrx[i] || arry[i])){
            arrdConj[i]='T';
        }else{
            arrdConj[i]='F';
        }
    }
    cout<<boolalpha;
    for(int i=0;i<4;++i){
        cout<<arrx[i]<<"         "<<arry[i]<<"         "<<arrdConj[i]<<endl;
    }
}


int main()
{
    cout << "enter 't' for TRUE and 'f' for FALSE"<<endl;
    char xx,yy;
    bool arrx[4];
    bool arry[4];
    for(int i=0;i<4;++i){
            cin >> xx >> yy;
        if(xx=='t'){
            arrx[i]=true;
        }else{
            arrx[i]=false;
        }
        if(yy=='t'){
            arry[i]=true;
        }else{
            arry[i]=false;
        }
    }
    cout<<"1.CONJUNCTION"<<endl;
    cout<<"2.DISCONJUNCTION"<<endl;
    cout<<"3.XOR"<<endl;
    cout<<"4.CONDITIONAL"<<endl;
    cout<<"5.Bi-CONDITIONAL"<<endl;
    cout<<"6.XNOR"<<endl;
    cout<<"7.NEGATION"<<endl;
    cout<<"8.NAND"<<endl;
    cout<<"9.NOR"<<endl;

    cout<<"enter a choice  : ";
    int a=0;
    cin>>a;

    switch(a){
        case 1 :cout<<"CONJUNCTION--------------------------------------"<<endl;
                conj(arrx,arry);
                break;
        case 2 :cout<<"DISCONJUNCTION--------------------------------------"<<endl;
                dis_conjunction(arrx,arry);
                break;
        case 3 :cout<<"XOR--------------------------------------"<<endl;
                XOR(arrx,arry);
                break;
        case 4 :cout<<"CONDITIONAL--------------------------------------"<<endl;
                cond(arrx,arry);
                break;
        case 5 :cout<<"Bi-CONDITIONAL--------------------------------------"<<endl;
                bicond(arrx,arry);
                break;
        case 6 :cout<<"XNOR--------------------------------------"<<endl;
                XNOR(arrx,arry);
                break;
        case 7 : cout<<"NEGATION--------------------------------------"<<endl;
                NEGATION(arrx);
                break;
        case 8 : cout<<"NAND--------------------------------------"<<endl;
                NAND(arrx,arry);
                break;
        case 9 :cout<<"NOR--------------------------------------"<<endl;
                NOR(arrx,arry);
                break;
        default :cout<<"INVALID INPUT-----------------------"<<endl;


    }


    return 0;
}
