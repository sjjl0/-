#include <stdio.h>

int apple(m,n)//m个苹果、n个盘子
{
	if(m==0||n==1)
		return 1;
	if(n>m)
		return apple(m,m);
	else
		return apple(m,n-1)+apple(m-n,n);
 } 

int main(void)
{
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		int a=apple(m,n);
		printf("%d\n",a);
	}
}
