#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
struct D {
    int l,r;
    int d;
    D() {
        l=0,r=0,d=0;
    }
} x[1000010];
int f[1000010];

void init() 
{
	int i;
    for(i=1;i<=n;i++)
        f[i]=i;
}

int find(int t) 
{
    return f[t]==t?t:find(f[t]);
}

bool cmp(D a,D b) 
{
    return a.d<b.d;
}
int main () 
{
	int i,j;
    scanf("%d%d",&n,&m);
    init();
    int ans=0;
    for(i=1;i<=m;i++) 
	{
        int l,r;
        scanf("%d%d%d",&x[i].l,&x[i].r,&x[i].d);
    }
    sort(x+1,x+1+m,cmp);
    int k=0;
    bool t=0;
    for(i=1;i<=m;i++) 
	{
        int l=find(x[i].l);
        int r=find(x[i].r);
        if(r!=l)
		{
            k++;
            ans+=x[i].d;
            if(r>l)
				f[r]=l;
            else
				f[l]=r;
        }
        if(k==n-1)
		{
            t=1;
            break;
        }
    }
    if(t==0)
		printf("-1");
    else
		printf("%d",ans);
    system("pause"); 
}
