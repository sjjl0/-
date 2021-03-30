#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int w;//肉重 
	int d;//美味度
	float p;//美味密度   
}a[100100];

float cmp(node a, node b)
{
    return a.p>b.p;//美味密度从大到小排序 
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].d,&a[i].w);
		float p1=(float)a[i].d/a[i].w;
		a[i].p=p1;
	}
	sort(a,a+n,cmp);
	float ans=0.000;
	
//	for(i=0;i<n;i++)
//		printf("%d %d %f\n",a[i].d,a[i].w,a[i].p);
		
	int judge=0;//拿了几个整的 
	int wsum=0;//拿整的已拿 
	while(wsum<m)
	{
		if(wsum+a[judge].w<=m)
		{
			wsum+=a[judge].w;
			ans+=(float)a[judge].d;
			judge++;
		}
		else
			break;
	}
	
	//printf("%d %d\n",wsum,judge);
	//printf("%f\n",ans);
	
	int wempty=m-wsum;
	float l=a[judge].p*wempty;
	ans+=l;
	
	printf("%.3f",ans);
//	system("pause");
}
