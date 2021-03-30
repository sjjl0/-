#include<iostream>
#include<algorithm>
using namespace std;
int f[10010];
int g[10010];
int q[10010];

int max(int a,int b)
{
	return a>b?a:b;
}

int bag(int n,int v,int *summon,int *magic,int *cnt)
{
}

int main()
{
	int T;
	scanf("%d",&T);
	int t;
	for(t=0;t<T;t++)
	{
		int n,v;
		scanf("%d %d",&n,&v);//物品种类与背包体积
		int i,j;
		int summon[10010];//物品体积
		int magic[10010];//物品价值
		int cnt[10010];//物品数量 

		for(i=0;i<n;i++)
			scanf("%d",&magic[i]);
		for(i=0;i<n;i++)
			scanf("%d",&summon[i]);
		for(i=0;i<n;i++)
			scanf("%d",&cnt[i]);
		
		printf("%d",f[v]);
	}
	system("pause");
}
