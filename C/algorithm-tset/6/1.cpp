#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int r;//����ռ�� 
	int o;//���ռ�� 
}a[100100];

int cmp(node a, node b)
{
    return a.r-a.o>b.r-b.o;//���ͷſռ�Ӵ�С���� 
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
        if(ans<pre+a[i].r)//����С��֮ǰ�Ĵ洢+����ռ�� 
            ans=pre+a[i].r;//�������д洢 
        pre+=a[i].o;//�洢 
    }
    printf("%d",ans);

    system("pause");
}

