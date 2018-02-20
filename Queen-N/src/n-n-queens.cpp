//============================================================================
// Name        : n-n-queens.cpp
// Author      : Navid Saboori
// Version     :
// Copyright   : Sky2464
// Description : N Queens in a N*N board in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int col)
{
for(int i=0;i<col;i++)
{
if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false;
}
return true;
}

bool backtrack(int &col)
{
    col--;
    if(col==-1)
    {
    return false;
    }
    return true;
}

void print(int q[],int m)
{
static int count=0;
cout<<++count<<endl<<endl;
int i;
for(i=0;i<m;i++)
{
cout<<q[i]<<"  ";
}
cout<<endl<<endl;
}


int main()
{
int n;
    cout<<"enter the number of queens:"<<endl;
    cin>>n;
    for(int m=1;m<=n;m++)
    {
        int *q=new int [m];
        q[0]=0;
        int c=1;
        bool from_backtrack=false;
        int count=0;
        bool a,b;
        while(true)
        {
                a = true;
                b = true;
            while(c<m)
            {
                if(!from_backtrack)
                {
                    q[c]=-1;
                }
                from_backtrack=false;
                while(q[c]<m)
                {
                    q[c]++;
                    while(q[c]==m)
                    {
                        a = backtrack(c);
                        if(a==false)
                            break;
                        q[c]++;
                    }
                    if(a==false)
                        break;
                    if(ok(q,c))
                    {
                        break;
                    }
                }
                                if(a==false)
                                    break;
                c++;
            }
            bool b = backtrack(c);
            if(a==false || b == false)
                break;
            count++;
            from_backtrack=true;
        }
        delete []q;
        cout<<m<<". There are "<<count<<" solutions to the "<<m<<" queens problem."<<endl;
    }
    return 0;
}
