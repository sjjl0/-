#include<stdio.h> 
int N;//套装总数 n
int V;//背包最大载重 s totle
int K;//最大输出 
int dp[1000];

struct Suit
{
	float weight;//套装重量 W
	int beauty;//魅惑度 V 
}list[100];

int max(int a,int b)
{
	return a>b?a:b;
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
			scanf("%d",&list[i].beauty);//W
		for(i=1;i<=N;i++)
			scanf("%f",&list[i].weight);//V
		 
		for(i=0;i<=V;i++) 
			dp[i] = 0;
        for(i=1;i<=N;i++)
        {
            for(j=V;j>=list[i].w;j--)
            {
                dp[j] = max(dp[j], dp[j - list[i].w] + list[i].v);
            }
        }
        printf("%d\n", dp[s]);
	}
    system("pause");
}
