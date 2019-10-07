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

int main()
{
    int N, V, M;
    cin>>N>>V>>M;
	/*
		局部变量、数组必须自己初始化
		否则程序无法正确执行，不想全局变量会被自动初始化
		局部变量都是随机数
	*/
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