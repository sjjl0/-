#include <stdio.h>

int apple(m,n)//m��ƻ����n������
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
		int a;
		int c=m-n;//ÿ���������ٷ�һ�� 
		if(c<0)
			a=0;
		else
			a=apple(c,n);
		printf("%d\n",a);
	}
}

