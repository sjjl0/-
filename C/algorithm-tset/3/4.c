#include<stdio.h>
int judge;
int c[1010][1010];
int b[1010][1010];
int x[1010];
int y[1010];

void length(int *x,int *y,int m,int n)
{
	int i,j;
	for (i=0;i<=m;i++)
		c[i][0]=0;
	for (j=0;j<=n;j++)
		c[0][j]=0;
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (x[i]==y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=-1;
			}
			else if (c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i - 1][j];
				b[i][j]=-2;
			}
			else
			{
				c[i][j]=c[i][j - 1];
				b[i][j]=-3;
			}
		}
	}
}

int ju(int *x,int i,int j)
{
	if (i == 0 || j == 0)
		return 0;
	if (b[i][j]==-1)
	{
		ju(x,i-1,j-1);
		judge++;
	}
	else if(b[i][j]==-2)
		ju(x,i-1,j);
	else
		ju(x,i,j-1);

}


int main()
{
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(i=1;i<=n;i++)
		scanf("%d",&y[i]);
	length(x,y,n,n);
	ju(x,n,n);
	printf("%d",judge);
    system("pause");
}
