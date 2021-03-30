#include <iostream>
#include <cstring>
using namespace std;
int n;
int a[10];
int b[10];//判断 
int full(int it,int num);

int main () {
    cin>>n;
    memset(b,0,sizeof(b));
    
    for(int i=1; i<=n; i++)
	    full(i,1);
}

int full(int next,int num) //下一个数、栈深 
{
    a[num]=next;
    b[next]=1;
    if(num==n) 
	{
        for(int j=1; j<=n; j++) 
		{
            cout<<a[j];
        }
        printf("\n");
    } else {
        for(int i=1; i<=n; i++) 
		{
            if(b[i]==1)
				continue;
            else 
				full(i,num+1);
        }
    }
    b[next]=0;
}
