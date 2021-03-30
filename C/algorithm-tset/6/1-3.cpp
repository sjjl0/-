#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int a,b;
} s[100100];
int cmp(node u,node v)
{
    return u.b>v.b;
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&x,&y);
        s[i].a=x;
        s[i].b=x-y;
    }
    sort(s,s+n,cmp);
    int sum=s[0].a;
    int ans=s[0].a;
    for(int i=0; i<n; i++)
    {
        if(sum<s[i].a)
        {
            ans+=s[i].a-sum;
            sum=s[i].a;
        }
        sum=sum-s[i].a+s[i].b;
    }
    printf("%d\n",ans);
    return 0;
}
