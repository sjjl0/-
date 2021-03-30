#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x,int y)
{
	return x<y;
}

int main()
{
	int T,t;
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		int i,j;
		int n,a[100010];
		cin>>n;
		for(i=0;i<n;i++)
		{
			int x;
			cin>>x;
			a[i]=x;
		}
		int sum=0;
		int k=n;
		for(i=0;i<n-1;i++)
        {
        	sort(a,a+k,cmp);
        	sum=sum+a[0]+a[1];
        	a[0]=a[0]+a[1];
        	for(j=1;j<n-1;j++)
        	{
        		a[j]=a[j+1];
			}
			k--;
		}
		cout<<sum<<endl;
	} 
	system("pause");
}
