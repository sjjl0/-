#include<cstdio>
#include<iostream>
#include<cmath>
 
using namespace std;
int n,l;
int x; 
int maxx=0,minn=0;
 
int main()
{
    int T,t;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
    scanf("%d%d",&l,&n);
for(int i=1;i<=n;i++)
{
scanf("%d",&x);
maxx+=max(0,max(x,l-x+1)-maxx);
minn+=max(0,min(x,l-x+1)-minn);
}
printf("%d %d\n",minn,maxx);
	}
    
    system("pause");
}
