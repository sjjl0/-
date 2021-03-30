#include <iostream>
#include <algorithm>
using namespace std;
struct A{
	int begin;
	int end;
}a[100100];

bool cmp(A x,A y)
{
	if(x.end==y.end)
		return x.begin>y.begin;
	return x.end<y.end;
}

int main()
{
	int T,t;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		int n;
		int ans=1;
		scanf("%d",&n);
		int i,j;
		for(i=0;i<n;i++)
		{
			cin>>a[i].begin>>a[i].end;
		}
		sort(a,a+n,cmp);
		int last=a[0].end;
		for(i=0;i<n;i++)
		{
			if(last<=a[i].begin)
			{
				ans++;
				last=a[i].end;
			}
		}
		printf("%d\n",ans);
	} 
	system("pause");
 } 
