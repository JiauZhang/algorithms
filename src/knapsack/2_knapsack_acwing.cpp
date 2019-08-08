#include <iostream>

/*
	完全背包问题 
*/ 

using namespace std; 

int knapsack_2d(int N, int V, int v[], int w[])
{
    int dp[N+1][V+1] = {0};
    /* 必须自己初始化，定义处无法实现清零操作 */
    for (int i=0; i<=N; i++) dp[i][0] = 0;
    for (int i=0; i<=V; i++) dp[0][i] = 0;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=V; j++) {
            /* 不选第 i 个的情况 */
            dp[i][j] = dp[i-1][j];
            int iter = j / v[i];
            /* 选择第 i 个 k 次 */
            for (int k=1; k<=iter; k++)  {
                /* 这个 if 就没必要了，因为 k 已经限制了这种可能 */
                //if (v[i] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k*v[i]]+k*w[i]);
                //}
            }
        }
    }
    
    return dp[N][V];
}

int knapsack_1d_v1(int N, int V, int v[], int w[])
{
    int dp[V+1] = {0};
    
    for (int i=1; i<=N; i++) {
        for (int j=V; j>=1; j--) {
            int iter = j / v[i];
            for (int k=1; k<=iter; k++) {
                // if (v[i] <= j) {
                    dp[j] = max(dp[j], dp[j-k*v[i]]+k*w[i]);
                // }
            }
        }
    }
    
    return dp[V];
}

/*
    v2 算法分析
    区别于 0-1 背包问题，现在可以无限次选
    f[i][j] --> -->
    当选第 i 件物品时，选择次数有 0, 1, 2, ..., k 且 k*v[i] <= j
    对应的总价值分别涉及到 f[i-1][j], f[i-1][j-v[i]], f[i-1][j-2*v[i]], ..., f[i-1][j-k*v[i]]
    分析对应的行中索引值 j, j-v[i], j-2*v[i], ..., j-k*v[i]
    由于 k*v[i] <= j，所以索引值范围是 j 到 0 之间的数据
    当 dp 表降维为 一维时，涉及到的总价值为 f[j], f[j-v[i]], f[j-2*v[i]], ..., f[j-k*v[i]]
    同样的，此时涉及的索引值范围是 j 到 0 之间的数据，即从当前点到 0 之间的数据
    当我们使用 v1 版本时，从右到左 更新正是出于这个原因
    dp 长度对应的是不同容量，即从 0, 1, 2, ..., V
    现在已知的是，由于是一维 dp，所以当我们不取第 i 个物品时，当前价值就等于当前值，不需要更新
    假设现在物品容量为 v[i], 则容量从 0,1, ..., v[i]-1 之间数据都保持不变，因为背包容量不够用
    当容量为 v[i] 时，这时就有了两种情况：取和不取
    即每次涉及到取和不取是以 v[i] 为间隔出现的，其中0, v[i], 2*v[i], ..., V记录的就是第 i 个
    物品在总容量为 V 的情况下取不同次数的 总价值
*/

int knapsack_1d_v2(int N, int V, int v[], int w[])
{
    int dp[V+1] = {0};
    
    for (int i=1; i<=N; i++) {
        for (int j=v[i]; j<=V; j++) {
            dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    
    return dp[V];
}

int main()
{
    int N, V;
    cin>>N>>V;
    
    int v[N+1], w[N+1];
    
    v[0] = w[0] = 0;
    for (int i=1; i<=N; i++)
        cin>>v[i]>>w[i];
    
    // int res = knapsack_1d_v1(N, V, v, w);
    int res = knapsack_1d_v2(N, V, v, w);
    // int res = knapsack_2d(N, V, v, w);    

    cout << res;
    
    return 0;
}
