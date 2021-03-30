#include <stdio.h> 
#include <stdlib.h>
int a[111];
int c[111][111];
int judge;

int Min(int n,int *a) 
{
	int d,i,j,k;
    for(i=1;i<=n;i++)
        c[i][i]=0;
    for(d=1;d<=n-1;d++)
	{
		for(i=1;i<=n-d;i++)
		{
			j=i+d;
			int temp=100000000; 
			for(k=i+1;k<=j;k++)
				if(temp>(c[i][k-1]+c[k][j]+a[i]*a[k]*a[j+1]))
					temp=c[i][k-1]+c[k][j]+a[i]*a[k]*a[j+1];
			c[i][j]=temp;
		}
	}   
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n+1;i++)
		scanf("%d",&a[i]);
	
	Min(n,a);
	judge=c[1][n];
	printf("%d",judge);
	system("pause");
}
