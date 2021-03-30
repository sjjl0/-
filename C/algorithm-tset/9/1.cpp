#include<stdio.h>
#include<math.h>
#include <cstdlib> 

int map[10010][10010]={0};///map[i][j]为0表示i, j两点之间不通，为1表示有一条路
int stack[10010],v[10010]={0},top=0,m,n,start,end;
int ans[10010],z=100000000;

void solve(int b)
{
	int i;
	int num;
	if(b==end){
		for(i=0;i<top;i++)
			num++;
		if(num<z)
			z=num;
		return;
	}
	v[b]=1;//标记被访问过 
	stack[top++]=b;
	for(i=1;i<=n;i++){
		if(!v[i]&&map[b][i])
			solve(i);
	}
	v[b]=0;//删除标记 
	top--;	
}

int main()
{
    int i,x,y;
    scanf("%d %d %d %d",&n,&m,&start,&end);//n是顶点数，m是边数,start起点，end终点 
    for(i=1; i<=m; i++) 
	{
        scanf("%d %d", &x,&y);
        map[x][y] = 1;
		map[y][x] = 1; 
    }

    solve(start);
    printf("%d",z-1);
    system("pause");
    
}

