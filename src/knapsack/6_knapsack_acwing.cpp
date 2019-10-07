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
#include <vector>

using namespace std;

struct Good {
    int s;
    int v, w;
};

int main()
{
    int N, V;
    cin>>N>>V;
    
    int dp[V+1];
    for (int i=0; i<=V; i++) dp[i] = 0;
    
    vector<Good> goods;
    /* 拆包 */
    for (int i=0; i<N; i++) {
        int s, v, w;
        cin>>v>>w>>s;
        
        if (s == -1) {
            goods.push_back({-1, v, w});
        } else if (s == 0) {
            goods.push_back({0, v, w});
        } else {
            for (int k=1; k<=s; k=k<<1) {
                s -= k;
                goods.push_back({-1, k*v, k*w});
            }
            
            if (s>0)
                goods.push_back({-1, s*v, s*w});
        }
    }
    
    for (auto gd: goods) {
		/* 01背包问题 */
        if (gd.s == -1) {
            for (int i=V; i>=gd.v; i--)
                dp[i] = max(dp[i], dp[i-gd.v] + gd.w);
        } else {
		/* 完全背包问题 */
            for (int i=gd.v; i<=V; i++)
                dp[i] = max(dp[i], dp[i-gd.v] + gd.w);
        }
    }
    
    cout << dp[V];
    
    return 0;
}