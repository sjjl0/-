#include <stdio.h>
int point[1010][1010];
int judge[1010];
int retu=0;
int sum=0;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);//n点，m边 
	int x[m+10];//x结点 
	int y[m+10];//y结点 
	int c[m+10];//权值c.
	int i,j,temp;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			point[i][j]=0;
	for(i=1;i<=n;i++)
		judge[i]=0;
	for(i=1;i<=m;i++)
	{
		point[x[i]][y[i]]=c[i];
		point[y[i]][x[i]]=c[i];
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
		{
			judge[i]+=point[i][j];
		} 
	for(i=2;i<=n;i++)
		if(judge[i]==0)
			retu=-1;
	for(i=2;i<=n;i++)
	{
		temp=1000;
		for(j=1;j<i;j++)
		{
			if(point[i][j]<temp&&point[i][j]!=0)
				temp=point;
		}
		if(temp==1000)
			temp=0;
		sum+=temp;	
	}
	if(judge==-1)
		printf("%d",judge);
	else
		printf("%d",sum);
	system("pause");	
} 
