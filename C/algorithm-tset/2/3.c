#include <stdio.h> 
#include <stdlib.h>
int gett(int l,int mid,int r,int *a,int *b)
{
	int i,j,k;
	i=l;	j=mid+1;	k=l;	
	while(i<=mid&&j<=r)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=r)
		b[k++]=a[j++];
	for(i=l;i<=r;i++)
		a[i]=b[i];
}

int solve(int l,int r,int *a,int *b)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		solve(l,mid,a,b);
		solve(mid+1,r,a,b);
		gett(l,mid,r,a,b);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{	
		int i;	
		int a[n],b[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);

		solve(0,n-1,a,b);
		
		for(i=0;i<n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}
