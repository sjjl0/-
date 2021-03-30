#include <stdio.h> 
#include <stdlib.h>

int number=0;
int temp[100011];

void solve(int a[],int l,int r)
{
    if(l>=r) 
		return;
    int mid=l+r>>1;
    int i,j,k;
    solve(a,l,mid);
	solve(a,mid+1,r);    
	i=l;
	j=mid+1;
    k=0;
    while(i<=mid&&j<=r)
        if(a[i]<=a[j]) 
			temp[k++]=a[i++];
        else
        {
            temp[k++]=a[j++];
            number+=mid-i+1;
        }
    while(i<=mid) 
		temp[k++]=a[i++];
    while(j<=r) 
		temp[k++]=a[j++];
    for(i=l,j=0;i<=r;i++,j++) //
		a[i]=temp[j];
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{		
		int i,j;
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int l,r;
		l=0;	r=n-1;
		solve(a,l,r);
		printf("%d\n",number);
		number=0;
	}
}
