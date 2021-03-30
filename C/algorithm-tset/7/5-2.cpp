#include <stdio.h>
#include <string.h>
#define Max(a, b) a > b ? a : b
const int MAX = 45;
long long weight[MAX], value[MAX], sw[MAX], sv[MAX];
long long W, n, ans;
//i表示当前取到第n-i个，cnt 表示当前的总value， w当前背包剩余的空间 
void dfs(int i, long long cnt, long long w)
{
    if (i == 0)//取到最后 
    {
        ans = Max(ans, cnt);
        return;
    }
    if (w == 0 || cnt + sv[i] < ans)//背包满或者当前总的加上这个前i个的总价值小于当前的总value，这步是剪枝 
        return ;
    if (w >= sw[i])//因为是从上往下找的，所以只要当前容量能装下前i个的和，所以这时一定是最大的 
    {
        cnt += sv[i];
        ans = Max(ans, cnt);
        w = 0;
        return ; 
    }
    if (w > weight[i])//深搜两种状态 
        dfs(i - 1, cnt + value[i], w - weight[i]);//相当于01背包中的两种状态 
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
