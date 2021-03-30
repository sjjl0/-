#include <iostream>
#include <algorithm>
#include <cstdio>
#define Max(a,b) a>b?a:b
#define INF 10000000000000000
using namespace std;
typedef long long LL;
const int MAX = 100;
LL weight[MAX], value[MAX];
LL W;
pair<LL, LL> ps[1 << (MAX / 2)];
int n;
void slove()
{
    //ö��ǰ�벿�� 
    int n2 = n / 2;
    for (int i = 0; i < 1 << n2; i++)//ǰ�벿�ֵ�ö������Ϊ 2^(n/2); 
    {
        LL sw = 0, sv = 0;
        //ÿ�ֽ��ѡȡ�ض��ļ�ֵ������(i.e һ��2����������һ���������������ѡ��ѡ��һ����ѡ�ڶ�������ѡ) 
        for (int j = 0; j < n2; j++)
        {
            if (i >> j & 1)
            {
                sw += weight[j];
                sv += value[j];
            }
        }
        ps[i] = make_pair(sw, sv);//���뵽ps������ 
    }
    //��ps���� 
    sort(ps, ps + (1 << n2));
    //ps ȥ�� 
    int m = 1;
    for (int i = 1; i < 1 << n2; i++)
        if (ps[m - 1].second < ps[i].second)
            ps[m++] = ps[i];
    LL res = 0;//������ 
    //ö�ٺ�벿�֣� �����ҵ����Ž� 
    for (int i = 0; i < 1 << (n - n2); i++)//ͬ��ö�ٵ��ܸ��� 
    {
        LL sw = 0, sv = 0;
        for (int j = 0; j < n - n2; j++)//��ǰ�벿�ֵ�һ�� 
        {
            if (i >> j & 1)
            {
                sw += weight[n2 + j];
                sv += value[n2 + j];
            }
        }
        if (sw <= W)//�Ӹ��ж��������ֵ��ֻ��С�ڱ���������ʱ�� 
        {
            LL tv = (lower_bound(ps, ps + m, make_pair(W - sw, INF)) - 1)->second;//�ҵ�ǰ�벿�ֶ�Ӧ��value 
            res = Max(res, sv + tv); 
        }
    }
    printf("%lld\n", res);
}

int main()
{
	scanf("%d %lld", &n, &W); 
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &weight[i], &value[i]);
    slove();
    
}
