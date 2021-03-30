#include <stdio.h>
int r[10010];
int o[10010];
int a[10010];

int main()
{
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&r[i],&o[i]);
		a[i]=r[i]-o[i];
	 } 
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				temp=r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
				temp=o[j];
				o[j]=o[j+1];
				o[j+1]=temp;
			}
		}
	int ans=0,pre=0;
	for(i=0;i<n;i++)
    {
        if(ans<pre+r[i])//可用小于之前的存储+运行占用 
            ans=pre+r[i];//扩大运行存储 
        pre+=o[i];//存储 
    }
    printf("%d",ans);

    system("pause");
	
}
