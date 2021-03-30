#include<stdio.h> 
int summon[1010];//需要的魔力 V体积
int magic[1010];//可提供魔力 W价值 
int N;//英灵数量 n 物品总数 
int V;//魔力总量 s totle 背包体积 
int K;//最大输出 
int ccc[1010][1010];

int max(int a,int b)
{
	return a>b?a:b;
}

int s(int *magic,int *summon,int n,int v)
{
	int i,j,temp1,temp2;
	for(i=1;i<=n;i++)
	{
		for(j=v;j>=summon[i];j--)
			ccc[i][j]=max(ccc[i-1][j],ccc[i-1][j-summon[i]]+magic[i]);
		for(j=summon[i]-1;j>=0;j--)
			ccc[i][j]=ccc[i-1][j];
	}
	printf("%d\n",ccc[n][v]);
}

int main()
{
	int i,j,T;
	int t;
	scanf("%d",&t);
	for(T=0;T<t;T++)
	{
		scanf("%d %d",&N,&V);
		for(i=1;i<=N;i++)
			scanf("%d",&magic[i]);
		for(i=1;i<=N;i++)
			scanf("%d",&summon[i]);
		
		s(magic,summon,N,V);
	}
    system("pause");
}
