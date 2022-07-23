#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class set
{
    int *ar;
    int size;
    public:
    set()
    {
        size=10;
        ar=new int[size];
    }
    void input();
    void display();
    void setunion(set &a,set &b);
    void unique();
    void intersection(set &a,set &b);
    int ismember(int e);
    int subset(set &b);
    void complement(set &a);
    void cartesian(set &a);
    void symdif(set &a, set &b);
    void diff(set &a, set &b);
};
  
void set::input()
{
	cin>>size;
	ar=new int[size];
	cout<<"enter the array elements"<<endl;
	for(int i=0;i<size;i++)
	cin>>ar[i];
}

void set::display()
{
    cout<<"the given set is {";
    for(int i=0;i<size;i++)
    {
        if(i==0)
            cout<<ar[i];
        else 
            cout<<","<<ar[i];
    }
    cout<<"}";
    cout<<endl;
}

void set::setunion(set &a,set &b)
{
 	int i=0,j=0,k=0;
	while(i<a.size && j<b.size) 
	{
        if(a.ar[i]<b.ar[j])
			ar[k++]=a.ar[i++];
		else
			ar[k++]=b.ar[j++];
	}
    
    while(i<a.size) 
	{
		ar[k++]=a.ar[i++];
    }
    
    while(j<b.size)
    {
		ar[k++]=b.ar[j++];
	}
    
    size=a.size+b.size;
}

void set::unique()
{    
    int i,j,l;
    for(i=0;i<size;++i)
    for(j=i+1;j<size;)
    {
        if(ar[i]==ar[j])
        {
            for(l=j;l<size-1;++l)
                ar[l]=ar[l+1];
                --size;
		}
        else
            ++j;
    }
}

void set::intersection(set &a,set &b)
{
	size=0;
	for(int i=0;i<a.size;i++)
    {
        for(int j=0;j<b.size;j++)
        {
            if(a.ar[i]==b.ar[j])
            {
                ar[size]=a.ar[i];
                size++;
            }
        }
    } 
}    
 
int set::subset(set &b)
{
    int i=0,j=0;
    for(i=0;i<b.size;i++)  
    {
        for(j=0;j<size;j++)
        {
            if(b.ar[i]==ar[i])
            break;
        }
        if(j==size)
            return 0;
    }     
    return 1;
}

void set::complement(set &a)
{ 
    int x[10]={1,2,3,4,5,6,7,8,9,10};
    int p[20],ctr=0;
    for(int i=0;i<a.size;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(x[j]==a.ar[i])
            {
                i++;
                continue;
            }
            else
            {
                p[ctr]=x[j];
                ctr++;
            }
        }
    }
    cout<<"complement is {";
    for(int i=0;i<ctr;i++)
    {
        if(i==0)
            cout<<p[i];
        else
            cout<<","<<p[i];
    }
}

void set::cartesian(set &b)
{
    cout<<"{";
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<b.size;j++)
            cout<<"("<<ar[i]<<","<<b.ar[j]<<")"<<",";
    }
    cout<<"}";
}

void set::symdif(set &a, set &b)
{
    int c=0; int p[10];int flag;
    for(int i=0;i<a.size;i++)
    {
        flag=0;
        for(int j=0;j<b.size;j++)
        {
            if(a.ar[i]==b.ar[j])
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            p[c]=a.ar[i];
            c++;
        }
    }
    for(int k=0;k<b.size;k++)
    {
        flag=0;
        for(int h=0;h<a.size;h++)
        {
            if(b.ar[k]==a.ar[h])
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            p[c]=b.ar[k];
            c++;
        }
    }
    cout<<"The symmetric differnce is "<<"{";
    for(int f=0;f<c;f++)
    cout<<p[f]<<",";
    cout<<"}";
}

void set::diff(set &a, set &b)
{
    int c=0; int p[10];int flag;
    for(int i=0;i<a.size;i++)
    {
        flag=0;
        for(int j=0;j<b.size;j++)
        {
            if(a.ar[i]==b.ar[j])
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            p[c]=a.ar[i];
            c++;
        }
    }
    cout<<"The differnce is "<<"{";
    for(int f=0;f<c;f++)
    cout<<p[f]<<",";
    cout<<"}";
}

int main()
{
    set a;
    set b;
    set c;
    set d;
    set e;
    set f;
    set g;
    set h;

    int ch,ch2,ch3;
    char ch1;
    cout<<"enter the size of Ist array"<<endl;
    a.input();
    a.unique();
    a.display();
    cout<<"enter the size of IInd array"<<endl;
    b.input();
    b.unique();
    b.display();
    do
    {
    cout<<endl<<"Enter your choice"<<endl;
    cout<<"1.Union"<<endl<<"2.Intersection"<<endl<<"3.subset"<<endl<<"4.Complement"<<endl<<"5.cartesian product"<<endl<<"6.Symmetric differnce"<<endl<<"7.Differnce"<<endl<<"8.exit"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: c.setunion(a,b);
                c.unique();
                c.display();
                break;
        case 2: d.intersection(a,b);
                d.display();
                break; 
        case 3: if(b.subset(a))
                    cout<<"A is Subset of B"<<endl;
                else
                    if(a.subset(b))
                        cout<<"B is subset of A"<<endl;
                    else
                        cout<<"A and B are not subset of each other"<<endl;
                break;
        case 4: cout<<"what you want to find complement of 1)A or 2)B"<<endl;
                cin>>ch2;
                if(ch2==1)
                    e.complement(a);
                else
                    if(ch2==2)
                    {
                        e.complement(b);
                    }
                    else
                        cout<<"wrong choice";      
                break; 
        case 5: cout<<"The cartesian product is ";
                a.cartesian(b);
                break;
        case 6: f.symdif(a,b);
                break;
        case 7: cout<<"Enter your choice "<<"1.A-B"<<endl<<"B-A"<<endl;
                cin>>ch3;
                if(ch3==1)
                {
                    g.diff(a,b);
                }
                else if(ch3==2)
                {
                    h.diff(b,a);
                }
                else 
                    cout<<"Wrong choice ";
                break;
        default:cout<<"wrong choice";
                break;
    }

    cout<<"Do you want to continue Y/N "<<endl;
    cin>>ch1;
    }while((ch1=='y')||(ch1=='Y'));
    return 0;
}
