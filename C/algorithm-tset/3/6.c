#include<stdio.h> 
int N;//��װ���� n
int V;//����������� s totle
int K;//������ 
int dp[1000];

struct Suit
{
	float weight;//��װ���� W
	int beauty;//�Ȼ�� V 
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
