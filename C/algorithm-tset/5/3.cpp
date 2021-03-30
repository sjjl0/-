#include <iostream>
#include <stack>
using namespace std;

const int MAX=1e7;
int map[2020][2020];//源点到各个顶点的最短具体数组
int dist[2020];//下标表示当前节点值，然后值保存为上个节点值
int p[2020];//城市的节点数目和线段的个数
int n, m;//是否加入集合S,如果在集合S里面的话，值为true,否则在集合S-V里面，值为false;
bool flag[2020];

//Dijkstra算法
void  dijkstra(int start)
{
	for(int i=1;i<=n;i++) 
	{
		flag[i] = false;
		
		dist[i] = map[start][i];
		if (dist[i] != MAX) 
		{
			p[i] = start;
		}
		else
		{
			p[i] = -1;	
		}
	}
	flag[start] = true;
	dist[start] = 0;

	for (int i = 1; i <= n; ++i)
	{
		int min_dist = MAX, t = start;

		for (int j = 1; j <= n; j++) 
		{
			if (dist[j] < min_dist && !flag[j]) 
			{
				min_dist = dist[j];
				t = j;
			}	
		}

		if (t == start) return;
		flag[t] = true;
    	for (int j = 1; j <= n; j++)
		{   
			if (map[t][j] < MAX && !flag[j])
			{
				if (dist[j] > (dist[t] + map[t][j]))
				{
					dist[j] = dist[t] + map[t][j];
					p[j] = t;
				}
			}
		}
	}
}

int main()
{
	//定点u到定点v的权重是w, 然后输入的起始地点是start;
	int u, v, w;
	int start=1;
	//std::cout << "请输入城市的节点个数" << std::endl;
	std::cin >> n;
	//std::cout << "请输入城市之间线路的个数" << std::endl;
	std::cin >> m;
	//邻接举证的初始化，默认都为最大值,注意这里下标都是从1开始
	for (int i = 1; i <= n; ++i) 
	{
		for (int j = 1; j <= n; ++j)
		{
			map[i][j] = MAX;	
		}
	}
    //std::cout << "请输入城市顶点到城市顶点之前的权重" << std::endl;
	for (int i = 0; i < m; ++i) 
	{
		std::cin >> u >> v >> w;
		map[u][v] = min(map[u][v], w);
		map[v][u]=map[u][v];
	}
	dijkstra(start);

		if (dist[n] == MAX)
			std::cout <<-1<< std::endl;
		else
			std::cout << dist[n] << std::endl;
	
	system("pause");
	return 0;	
}

