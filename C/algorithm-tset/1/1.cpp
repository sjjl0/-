#include <iostream>
using namespace std;

int deep=0;
int a[25];

int main(void)
{
	int n;
	cin>>n;
	int i;
	int x,y;
	for(i=1;i<=n;i++)
	{
		a[i]=1;
	}
	for(i=0;i<n-1;i++)
	{
		cin>>x>>y;
		a[y]=a[x]+1;
		if(deep<a[y])
			deep=a[y];
	}
	printf("%d\n",deep);
	system("pause");
	
 } 
