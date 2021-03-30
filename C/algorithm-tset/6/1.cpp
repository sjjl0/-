#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int r;//计算占用 
	int o;//结果占用 
}a[100100];

int cmp(node a, node b)
{
    return a.r-a.o>b.r-b.o;//可释放空间从大到小排序 
}

int main()
{
    int n;
    int i,j;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].r,&a[i].o);    	
	}
    sort(a+1,a+1+n,cmp);// 
    int ans=0;
	int pre=0;
	for(i=1;i<=n;i++)
    {
        if(ans<pre+a[i].r)//可用小于之前的存储+运行占用 
            ans=pre+a[i].r;//扩大运行存储 
        pre+=a[i].o;//存储 
    }
    printf("%d",ans);

    system("pause");
}

