/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>

using namespace std;

/*
	0-1 背包问题 
*/ 

int knapsack_2d(int N, int V, int v[], int w[])
{
    int dp[N+1][V+1] = {0};
    /* 必须自己初始化，定义处无法实现清零操作 */
    for (int i=0; i<=N; i++) dp[i][0] = 0;
    for (int i=0; i<=V; i++) dp[0][i] = 0;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=V; j++) {
            dp[i][j] = dp[i-1][j];
            if (v[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-v[i]]+w[i]);
            }
        }
    }
    
    return dp[N][V];
}

int knapsack_1d(int N, int V, int v[], int w[])
{
    int dp[V+1] = {0};
    
    for (int i=1; i<=N; i++) {
        for (int j=V; j>=1; j--) {
            if (v[i] <= j) {
                dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
            }
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
    
    // int res = knapsack_1d(N, V, v, w);
    
    int res = knapsack_2d(N, V, v, w);    

    cout << res;
    
    return 0;
}
