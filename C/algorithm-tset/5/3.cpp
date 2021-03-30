#include <iostream>
#include <stack>
using namespace std;

const int MAX=1e7;
int map[2020][2020];//Դ�㵽�����������̾�������
int dist[2020];//�±��ʾ��ǰ�ڵ�ֵ��Ȼ��ֵ����Ϊ�ϸ��ڵ�ֵ
int p[2020];//���еĽڵ���Ŀ���߶εĸ���
int n, m;//�Ƿ���뼯��S,����ڼ���S����Ļ���ֵΪtrue,�����ڼ���S-V���棬ֵΪfalse;
bool flag[2020];

//Dijkstra�㷨
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
	//����u������v��Ȩ����w, Ȼ���������ʼ�ص���start;
	int u, v, w;
	int start=1;
	//std::cout << "��������еĽڵ����" << std::endl;
	std::cin >> n;
	//std::cout << "���������֮����·�ĸ���" << std::endl;
	std::cin >> m;
	//�ڽӾ�֤�ĳ�ʼ����Ĭ�϶�Ϊ���ֵ,ע�������±궼�Ǵ�1��ʼ
	for (int i = 1; i <= n; ++i) 
	{
		for (int j = 1; j <= n; ++j)
		{
			map[i][j] = MAX;	
		}
	}
    //std::cout << "��������ж��㵽���ж���֮ǰ��Ȩ��" << std::endl;
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

