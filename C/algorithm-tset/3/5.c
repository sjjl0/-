#include<stdio.h> 
int summon[1010];//��Ҫ��ħ�� V���
int magic[1010];//���ṩħ�� W��ֵ 
int N;//Ӣ������ n ��Ʒ���� 
int V;//ħ������ s totle ������� 
int K;//������ 
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
