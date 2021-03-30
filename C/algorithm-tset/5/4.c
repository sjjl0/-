#include <stdio.h>

int sort(int *w,int n)
{
	int i, j;
	int tmp;
	for(i=0;i<n;i++)
	{
		for (j=0;j<n-1-i;j++)
		{
			if(w[j]>w[j + 1])
			{
				tmp=w[j];
				w[j]=w[j+1];
				w[j+1]=tmp;
			}
		}
	}
}

int main()
{
	int n,m;//人数、上限,
	scanf("%d %d",&n,&m);
	int i,j;
	int count=0;
	int w[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&w[i]);
	}
	sort(w,n);
	for(i=0,j=n-1;i<=j;)
	{
		if(w[i]+w[j]<=m)
		{
			i++;
			j--;
			count++;
		}
		else
		{
			count++;
			j--;	
		}
	}
	printf("%d",count);
	system("pause");
 } 
