#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int len,n,x;
int mn,mx;

int main()
{
    int T,t;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
    	int a,b;
    	scanf("%d",&a);
    	len=a;
    	len++;
    
    	scanf("%d",&b);
    	n=b;
    	for(int i=1;i<=n;i++)
    	{
    		int c;
        	scanf("%d",&c);
        	x=c;
        	mn=max(mn,min(x,len-x));
        	mx=max(mx,max(x,len-x));
    	}
    	printf("%d %d\n",mn,mx);
	}
    
    system("pause");
}
