#include<stdio.h>
#include<math.h>
#include <cstdlib> 

int map[10010][10010]={0};///map[i][j]Ϊ0��ʾi, j����֮�䲻ͨ��Ϊ1��ʾ��һ��·
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
	v[b]=1;//��Ǳ����ʹ� 
	stack[top++]=b;
	for(i=1;i<=n;i++){
		if(!v[i]&&map[b][i])
			solve(i);
	}
	v[b]=0;//ɾ����� 
	top--;	
}

int main()
{
    int i,x,y;
    scanf("%d %d %d %d",&n,&m,&start,&end);//n�Ƕ�������m�Ǳ���,start��㣬end�յ� 
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

