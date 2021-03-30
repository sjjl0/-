#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int g[1010][1010],dis[1010];
bool st[1010];

void prim()
{
	int i,j;
    memset(dis,0x3f,sizeof(dis));
    int res=0;
    for(i=0;i<n;i++)
	{
        int t=-1;
        for(j=1;j<=n;j++)
		{
            if(!st[j]&&(t==-1||dis[t]>dis[j]))
                t=j;
        }
        if(i)res+=dis[t];
        for(int j=1;j<=n;j++)
            dis[j]=min(dis[j],g[t][j]);
        st[t]=true;
    }
    cout<<res<<endl;
}

int main()
{
	int i,j;
    cin>>n>>m;
    memset(g,0x3f,sizeof(g));
    
    for(i=0;i<m;i++)
	{
		int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=min(g[a][b],c);
    }
    prim();
    system("pause");
}
