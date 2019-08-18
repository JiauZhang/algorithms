#include <iostream>

using namespace std;

int main()
{
    int N, V, M;
    cin>>N>>V>>M;

    int dp[V+1][M+1];
    for (int i=0; i<=V; i++) 
        for (int j=0; j<=M; j++)
            dp[i][j] = 0;
    
    for (int i=0; i<N; i++) {
        int v, m, w;
        cin>>v>>m>>w;
        /* 从大到小枚举 */
        for (int j=V; j>=v; j--) {
            for (int k=M; k>=m; k--) {
                dp[j][k] = max(dp[j][k], dp[j-v][k-m] + w);
            }
        }
    }
    
    cout << dp[V][M];
    
    return 0;
}