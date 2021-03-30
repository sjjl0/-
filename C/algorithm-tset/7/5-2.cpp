#include <stdio.h>
#include <string.h>
#define Max(a, b) a > b ? a : b
const int MAX = 45;
long long weight[MAX], value[MAX], sw[MAX], sv[MAX];
long long W, n, ans;
//i��ʾ��ǰȡ����n-i����cnt ��ʾ��ǰ����value�� w��ǰ����ʣ��Ŀռ� 
void dfs(int i, long long cnt, long long w)
{
    if (i == 0)//ȡ����� 
    {
        ans = Max(ans, cnt);
        return;
    }
    if (w == 0 || cnt + sv[i] < ans)//���������ߵ�ǰ�ܵļ������ǰi�����ܼ�ֵС�ڵ�ǰ����value���ⲽ�Ǽ�֦ 
        return ;
    if (w >= sw[i])//��Ϊ�Ǵ��������ҵģ�����ֻҪ��ǰ������װ��ǰi���ĺͣ�������ʱһ�������� 
    {
        cnt += sv[i];
        ans = Max(ans, cnt);
        w = 0;
        return ; 
    }
    if (w > weight[i])//��������״̬ 
        dfs(i - 1, cnt + value[i], w - weight[i]);//�൱��01�����е�����״̬ 
    dfs(i - 1, cnt, w);
} 
int main()
{
    while (~scanf("%d %lld", &n, &W))
    { 
        memset(sw, 0, sizeof(weight));
        memset(sv, 0, sizeof(value));
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld %lld", &weight[i], &value[i]);
            sw[i] = sw[i - 1] + weight[i];
            sv[i] = sv[i - 1] + value[i];
        }
        dfs(n, 0, W);
        printf("%lld\n", ans);
    }
    
    return 0;
}
