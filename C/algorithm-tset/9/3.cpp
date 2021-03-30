#include <iostream>
#include <queue>
using namespace std;
//n是坐标轴长度,A是起点.B是终点
int n=1000000,A,B;
int step;
bool vis[1000000];
struct node{
    int k;
    int step;
    node(int kk,int sstep)
	{
        k=kk;
        step=sstep;
    }
};
int bfs()
{
    queue<node> q;
    q.push(node(A,0));
    vis[A]=true;
    while(!q.empty())
	{
        node x=q.front();
        q.pop();
        if(x.k==B){
            return x.step;
        }
        if(x.k+1<=n && !vis[x.k+1]){
            q.push(node(x.k+1, x.step+1));
            vis[x.k+1]=true;
        }
        if(x.k-1>=0 && !vis[x.k-1]){
            q.push(node(x.k-1,x.step+1));
            vis[x.k-1]=true;
        }
        if(x.k*2<=n && !vis[x.k*2]){
            q.push(node(x.k*2,x.step+1));
            vis[x.k*2]=true;
        }
    }
    return -1;
}
int main()
{
    int T;
	cin>>T;
    for(int i=0;i<T;i++)
    {
    	cin>>A>>B;
    	cout<<bfs();	
	}
    system("pause"); 
}
