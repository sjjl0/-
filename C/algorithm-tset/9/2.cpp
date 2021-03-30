#include <iostream>
#include <cstring>
#include<queue>
using namespace std;

int n,m;
int T;
char s[100][100];
int dis[4][2]= 
{ 
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};
struct d {
    int x,y;
};

int a,b;
int ans=0;
int check(int x,int y)
{
    if(s[x][y]=='.')
        return 1;
	else
        return 0;
}

void f(int x,int y)
{
    queue<d> q;
    d begin,next;
    begin.x=x;
    begin.y=y;
    ans=1;
    q.push(begin);
    while(!q.empty()) 
	{
        begin=q.front();
        q.pop();
        for(int i=0; i<4; i++)
		{
            next.x=begin.x+dis[i][1];
            next.y=begin.y+dis[i][0];
            if(check(next.x,next.y)==1)
			{
                s[next.x][next.y]='#';
                q.push(next);
                ans++;
            }
        }
    }
}

int main()
{
    scanf("%d",&T);
    for(int i=0;i<T;i++)
	{
        scanf("%d %d",&m,&n);
        memset(s,'#',sizeof(s));

        for(int i=1; i<=n; i++) 
		{
            for(int j=1; j<=m; j++) 
			{
                cin>>s[i][j];
                if(s[i][j]=='@')
				{
                    a=i,b=j;
                }
            }
        }
        f(a,b);

        printf("%d\n",ans);
    }
    
    system("pause"); 
}
