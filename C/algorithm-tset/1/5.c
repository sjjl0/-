#include <stdio.h>

int divide(int n,int m)
{
	if(m==1 || n==1)  
        return 1;  
    if(n<m)  
        return divide(n,n);  
    else if(n==m)  
        return divide(n,m-1)+1;  
    else  
        return divide(n-m,m)+divide(n,m-1);
}

int main(void)
{
	int n;//���ֵ��� 
	while(scanf("%d",&n)!=EOF)
	{
		int m=n;//mΪ�ɷֻ����������� 
		 int a;
		 a=divide(n,m);
		 printf("%d\n",a);
	}
	
}
