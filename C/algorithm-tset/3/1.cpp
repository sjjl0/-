#include <stdio.h> 
#include <stdlib.h>
int a[200010];
int judge=0;

int max(int n,int *a)
{
	int i;
	int sum=-10000,b=0;
	for(i=0;i<n;i++)
	{
		if(b<0)
			b=a[i];
		else
			b=b+a[i];
		if(b>sum)
			sum=b;
	}
		return sum;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	judge=max(n,a);
	printf("%d",judge);
	//system("pause");
}
