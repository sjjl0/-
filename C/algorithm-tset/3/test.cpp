#include<iostream>
#include<algorithm>
using namespace std;
/*
f��ǰi����Ʒ,�����ݻ�0-V����Ӧ������ֵ
g��ǰi-1����Ʒ,�����ݻ�0-V����Ӧ������ֵ
q�������ݼ�����
*/
const int array_size = 20001;
int f[array_size], g[array_size], q[array_size], N, V, v, w, s;
int main() {
    cin >> N >> V;
    for (int i = 0; i < N; ++i) {
        cin >> v >> w >> s;
        copy(f, f + array_size, g);
        for (int j = 0; j < v; ++j) {
            int hh = 0, tt = -1;//�ֱ��ʾ���ס���β
            for (int k = j; k <= V; k += v) {
                if (hh <= tt && q[hh] + s * v < k)
                    ++hh; //ȡ������Ԫ�أ������ײ���ǰ�����з�Χ��һ�������ֵ���±�
                //���в�Ϊ���Ҷ�βԪ�ض�Ӧ��ֵ<=�²���Ԫ�ض�Ӧ��ֵ
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j)  / v * w)
                    --tt; //�޳�������һ�������õ���Ԫ��
                q[++tt] = k; //push��ֵ���±�
                if (hh <= tt) //���в�Ϊ��
                    f[k] = max(f[k], g[q[hh]] + (k - q[hh]) / v * w); //�����ֵ����һ��f[k]
            }
        }
    }
    cout << f[V];
    system("pause");
}
