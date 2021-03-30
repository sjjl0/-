
#include <iostream>

#include <cstdio>

#include <stack>

#include <string>

 

using namespace std;

 

/*

һ��Ҫ�ǵ������ʼ������Ļ����϶���Ҫһ���������泤�Ϳ�����ֵ��

�������Ȩ�صĻ����϶�����Ҫ�и������������ֵ��Ȩ��

*/

 

//���еĽڵ���Ŀ�����ֵ

const int MAX_CITY_NUM = 100;

//�ڵ�Ȩֵ�����ֵ

const int MAX_POLICY = 1e7;

//��ʼ��Ȩ�ؾ���

int map[MAX_CITY_NUM][MAX_CITY_NUM];

//Դ�㵽�����������̾�������

int dist[MAX_CITY_NUM];

//�±��ʾ��ǰ�ڵ�ֵ��Ȼ��ֵ����Ϊ�ϸ��ڵ�ֵ

int p[MAX_CITY_NUM];

//���еĽڵ���Ŀ���߶εĸ���

int n, m;

//�Ƿ���뼯��S,����ڼ���S����Ļ���ֵΪtrue,�����ڼ���S-V���棬ֵΪfalse;

bool flag[MAX_CITY_NUM];

 

 

//Dijkstra�㷨

void  dijkstra(int start)

{

	//��ʼ����Դ�������Ķ�����г�ʼ��

	for (int i = 1; i <= n; ++i) 

	{

		//�Ȱ�ǰ�ڵ㶼���ó�false

		flag[i] = false;

		//�ȰѺ�Դ�������һ��Ľ��г�ʼ�������û��Դ�������һ��Ļ�

		//������ΪȨ�ص����ֵ�����������������������жϣ����ֽڵ��Ȩ��

		//����Ϊ0���������������

		dist[i] = map[start][i];

		if (dist[i] != MAX_POLICY) 

		{

		  	//dist[i] = map[start][i];

			p[i] = start;

		}

		else

		{

			p[i] = -1;	

		}

	}

	flag[start] = true;

	dist[start] = 0;

	//һ��ʼ����������dist[i]����û�к�Դ�������ֵӦ����MAX_POLICY

	//Ȼ����Ҳ������p[i]�������û�з�ֵ�Ļ�Ӧ�ó�ʼ��Ϊ-1

	//Ȼ����Ҳ������dist[start]=0��Դ�㵽Դ���Ȩ����0



	//����s��������ֻ��Դ�㣬���ǽ�������Ҫ��s����������������Ķ��㣬

	for (int i = 1; i <= n; ++i)

	{

		//t��������ÿ���ҵ�����С�ڵ�Ȩ�أ�Ȼ��min_dist����ÿ�α�����С�Ľڵ�Ȩ�أ�Ȼ��ÿ�θ����������

		int min_dist = MAX_POLICY, t = start;

		//����V-S���������ҵ�dist[i]����Ȩ����С�����ݣ�Ȼ��Ѷ������s����	

		for (int j = 1; j <= n; j++) 

		{

			//������Ҫ�õ���С��dist[j]�������������ﲻ����!=��������<

			if (dist[j] < min_dist && !flag[j]) 

			{

				min_dist = dist[j];

				t = j;

			}	

		}

		//���Ƿ��ֳ����˳���ʱ��p[j]����ֻ��Դ���ֵ��-1,������ֵ������-1

		//����������Ҫ��ѭ����������ǣ������ȥ�ˣ�˵�������˳������û�н�ȥ

		//�����ʱ����t��֮ǰ����ʱ������ֵ��һ�������Ǿ�����ѭ��

		if (t == start) return;

		//�ҵ�֮��������Ҫ������flag[j]Ϊtrue

		flag[t] = true;

		//���뵽s����֮�����������Ȩ�ر���dist[i]����ҪС������Ҫ����dist[i]

    	for (int j = 1; j <= n; j++)

		{   //C++����false��ֵ��0,����-1,true��ֵ��1,�Ժ�һ����������

			if (map[t][j] < MAX_POLICY && !flag[j])

			{

				if (dist[j] > (dist[t] + map[t][j]))

				{

					//�����µĶ���Ȩ��

					dist[j] = dist[t] + map[t][j];

					//�ҵ�֮��Ҫ�ǵ�����֮ǰ�Ķ���

					p[j] = t;

				}

			}

		}

	}

}

 

//��ӡ��ÿ�������·��,����ֵ������ǰһ���ڵ��key

//����������Ҫ�õ�ջ���ص㣬�Ƚ����

void showProcess(int start)

{

	int value;

	stack<int> stack;

	for (int i = 1; i <= n; ++i)

	{

		value = p[i];

		std::cout << "Դ��"<< start << "��"<< i << "��·����"; 

		while (value != -1) 

		{

			stack.push(value);

			value = p[value];

		}

		while (!stack.empty())

		{

			//pop�����ǳ���ջ��û�з���ֵ,��ȡ��ջ��ֵ��Ȼ���ջ

			int node = stack.top();

			stack.pop();

			std::cout << node << "-";

		}

		std::cout  << i << "��̾���Ϊ" << dist[i] << std::endl;

	}

}



int main()

{

	//����u������v��Ȩ����w, Ȼ���������ʼ�ص���start;

	int u, v, w, start;

	std::cout << "��������еĽڵ����" << std::endl;

	std::cin >> n;

	if (n <= 0)

	{

		std::cout << "����ĳ��нڵ������ô���0" << std::endl;

		return -1;

	}

	std::cout << "���������֮����·�ĸ���" << std::endl;

	std::cin >> m;

	if (m <= 0) 

	{

		std::cout << "����ĳ���֮ǰ����·��������С��0" << std::endl;

		return -1;

	}

	//�ڽӾ�֤�ĳ�ʼ����Ĭ�϶�Ϊ���ֵ,ע�������±궼�Ǵ�1��ʼ

	for (int i = 1; i <= n; ++i) 

	{

		for (int j = 1; j <= n; ++j)

		{

			map[i][j] = MAX_POLICY;	

		}

	}

    std::cout << "��������ж��㵽���ж���֮ǰ��Ȩ��" << std::endl;

    //����Ҳ����ʹ��while(--m),��Ϊ���漰����i

	for (int i = 0; i < m; ++i) 

	{

		std::cin >> u >> v >> w;

		if (u > n || v > n) 

			std::cout << "������Ķ�������" << std::endl;

		//���2������һ�����㣬��ôȡ��С��

		map[u][v] = min(map[u][v], w);

	}

	std::cout << "������С����λ��" << std::endl;

	//��������ʼ�Ķ���

	std::cin >> start;

	if (start < 0 || start > n)

	{

		std::cout << "�������ʼ���ж�������" << std::endl;

		return 0;

	}

	dijkstra(start);

	std::cout << "С�����ڵ�λ�� " << start << std::endl;

	for (int i = 1; i <= n; ++i)

	{

		std::cout << "С��(" << start << ")Ҫȥ��λ����" << i;

		if (dist[i] == MAX_POLICY)

			std::cout << "��·�ɵ�" << std::endl;

		else

			std::cout << "��̾���Ϊ" << dist[i] << std::endl;

	}

	showProcess(start);

	return 0;	

}

