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
    //枚举前半部分 
    int n2 = n / 2;
    for (int i = 0; i < 1 << n2; i++)//前半部分的枚举总数为 2^(n/2); 
    {
        LL sw = 0, sv = 0;
        //每种结果选取特定的价值和重量(i.e 一共2个东西，就一共四种情况，都不选，选第一个，选第二个，都选) 
        for (int j = 0; j < n2; j++)
        {
            if (i >> j & 1)
            {
                sw += weight[j];
                sv += value[j];
            }
        }
        ps[i] = make_pair(sw, sv);//加入到ps数组中 
    }
    //对ps排序 
    sort(ps, ps + (1 << n2));
    //ps 去重 
    int m = 1;
    for (int i = 1; i < 1 << n2; i++)
        if (ps[m - 1].second < ps[i].second)
            ps[m++] = ps[i];
    LL res = 0;//保存结果 
    //枚举后半部分， 并且找到最优解 
    for (int i = 0; i < 1 << (n - n2); i++)//同样枚举的总个数 
    {
        LL sw = 0, sv = 0;
        for (int j = 0; j < n - n2; j++)//和前半部分的一样 
        {
            if (i >> j & 1)
            {
                sw += weight[n2 + j];
                sv += value[n2 + j];
            }
        }
        if (sw <= W)//加个判断求解最大价值，只有小于背包容量的时候 
        {
            LL tv = (lower_bound(ps, ps + m, make_pair(W - sw, INF)) - 1)->second;//找到前半部分对应的value 
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
