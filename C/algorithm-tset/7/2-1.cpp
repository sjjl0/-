#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

int main(){
    int T,t;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
    	int n,i,j,ans=0;
    	scanf("%d",&n);//n个 
    	int w[n];
    	for(i=0;i<n;i++)
		{
    	    scanf("%d",&w[i]);
    	}
    	for(i=0;i<n-1;i++)
		{
    	    qsort(w,n,sizeof(w[0]),cmp);//每次进行排序，找最小的两个 
    	    w[i+1]+=w[i];
    	    ans+=w[i+1];//加上此次花费 
    	}
    	printf("%d\n",ans);
	}
    system("pause");
} 
