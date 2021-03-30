#include <iostream>
#include <math.h>
using namespace std;

bool place(int k, int *X)
{

    int i;
    i=1;
    while(i<k)
    {
       if((X[i]==X[k])||(abs(X[i]-X[k])==abs(i-k)))
           return false;
       i++;
    }
    return true;
}

void Nqueens(int n,int *X)
{
    int k,sum=0;
    X[1]=0;
    k=1;
    while(k>0)
    {
       X[k]=X[k]+1;

       while((X[k]<=n)&&(!place(k, X)))
           X[k]=X[k]+1;

       if(X[k]<=n)
           if(k==n)
           {
              sum++;
           }
           else
           {
              k=k+1;
              X[k]=0;
           }
           else
              k=k-1;
     }
     cout<<sum<<endl;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int *x;
		int X[n];
    	Nqueens(n,X);
	}
}
