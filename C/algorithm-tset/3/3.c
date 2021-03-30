#include <stdio.h> 
#include <stdlib.h>
int judge=0;
int a[100010];

int max(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}

int s(int n,int *a) 
{
	int i,j;          
    if (n<=0)
        return 0;
    int array[n];
    for(i=0;i<n;i++)
    	array[i]=1;
    int res=array[0];
    for (i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        	if(a[i]>a[j])
        		array[i]=max(array[i],1+array[j]);
        res=max(res,array[i]);
    }
    return res;
}

int main()
{
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	judge=s(n,a);
	printf("%d",judge);
	system("pause");
}
