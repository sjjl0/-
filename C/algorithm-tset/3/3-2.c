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
    int dp[n];
    for(i=0;i<n;i++)
    	dp[i]=1;
    int count[n];
    for(i=0;i<n;i++)
    	count[i]=1;
    	
    int res=0;
    int maxlen=0;
    
    for (i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
        	if(a[j]<a[i])
        	{
        		if(dp[j]+1>dp[i])
        		{
        			count[i]=count[j];
        			dp[i]=dp[j]+1;
				}
				else if(dp[j]+1==dp[i])
					count[i]+=count[j];
			}	
		}   
		maxlen=max(maxlen,dp[i]);
    }
    for(i=0;i<n;i++)
    	if(dp[i]==maxlen)
    		res+=count[i];
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
