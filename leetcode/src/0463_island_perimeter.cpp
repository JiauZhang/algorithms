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

/*
* https://leetcode-cn.com/problems/island-perimeter
* 题目描述：
* 	给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域
* 	网格中的格子水平和垂直方向相连（对角线方向不相连）
* 	整个网格被水完全包围，但其中恰好有一个岛屿
* 	或者说，一个或多个表示陆地的格子相连组成的岛屿
* 	岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）
* 	格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 
* 	计算这个岛屿的周长
* 	
* 示例 :
* 输入:
* 	[[0,1,0,0],
* 	 [1,1,1,0],
* 	 [0,1,0,0],
* 	 [1,1,0,0]]
* 输出: 
* 	16
* 
* 解题思路：
* 	由于岛屿中没有湖，又由于正方形是对称的，所以封闭多边形的边数一定
* 	是偶数个，所以只需要计算一半的行和列即可
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() <= 0)
            return 0;

        int res = 0;
        const int x = grid.size(), y = grid[0].size();
        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++) {
                if (grid[i][j]) {
                    // row
                    if (i == 0 || grid[i-1][j] == 0) {
                        res += 1;
                    }
                    // colomn
                    if (j == 0 || grid[i][j-1] == 0) {
                        res += 1;
                    }
                }
            }
        }

        return res << 1;
    }
};