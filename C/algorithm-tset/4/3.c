#include <stdio.h>
int f[210][210];//n*m
int arr[210][210];

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int solve(int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(i==0&&j==0)
				arr[i][j]=f[i][j];
			else
			{
				if(i==0)
					arr[i][j]=arr[i][j-1]+f[i][j];
				else
				{
					if(j==0)
						arr[i][j]=arr[i-1][j]+f[i][j];
					else
					{
						int temp=max(arr[i][j-1],arr[i-1][j]);
						arr[i][j]=temp+f[i][j];	
					}	
				} 
			}
		}
	}
	return arr[n-1][m-1];
}

int main()
{
	int i,j;
	int m,n;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&f[i][j]);
	int a;
	a=solve(n,m);
	printf("%d",a);
	system("pause"); 
}
