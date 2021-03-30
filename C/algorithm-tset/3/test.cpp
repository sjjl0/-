#include<iostream>
#include<algorithm>
using namespace std;
/*
f：前i个物品,背包容积0-V，对应的最大价值
g：前i-1个物品,背包容积0-V，对应的最大价值
q：单调递减队列
*/
const int array_size = 20001;
int f[array_size], g[array_size], q[array_size], N, V, v, w, s;
int main() {
    cin >> N >> V;
    for (int i = 0; i < N; ++i) {
        cin >> v >> w >> s;
        copy(f, f + array_size, g);
        for (int j = 0; j < v; ++j) {
            int hh = 0, tt = -1;//分别表示队首、队尾
            for (int k = j; k <= V; k += v) {
                if (hh <= tt && q[hh] + s * v < k)
                    ++hh; //取出队首元素，队列首部当前子序列范围内一定是最大值的下标
                //队列不为空且队尾元素对应的值<=新插入元素对应的值
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j)  / v * w)
                    --tt; //剔除队列中一定不会用到的元素
                q[++tt] = k; //push新值的下标
                if (hh <= tt) //队列不为空
                    f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w); //用最大值更新一下f[k]
            }
        }
    }
    cout << f[V];
    system("pause");
}
