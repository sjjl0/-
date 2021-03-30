#include <stdio.h>
#include <math.h>

static int k=1;

int move(char src,int n,char dst)
{
    printf("step %d: %d From %c To %c\n",k,n,src,dst);
    k++;
    return 0;
}

int hanoi(int n,char x,char y,char z)
{
    if(n==1)
        move(x,1,z);
    else
    {
        hanoi(n-1,x,z,y);
        move(x,n,z);
        hanoi(n-1,y,x,z);
    }
    return 0;
}

int main(void)
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int x='A',y='B',z='C';
		int num=pow(2,n)-1;
		printf("%d\n",num);
		hanoi(n,x,y,z);
		k=1;
	}
}
