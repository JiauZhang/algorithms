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
* https://leetcode-cn.com/problems/pascals-triangle-ii
* 题目描述：
*     给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行
*     
*     0               1
*     1             1   1
*     2           1   2   1
*     3         1   3   3   1
*     4       1   4   6   4   1
*     5     1   5  10   10  5   1
*     6   1   6  15   20  15   6   1
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return {1};
        
        vector<int> rows[2];
        bool flag = true;
        rows[0] = {1, 1};

        if (rowIndex == 1)
            return rows[0];

        for (int i=2; i<=rowIndex; i++) {
            rows[flag].push_back(1);
            for (int j=1; j<i; j++) {
                rows[flag].push_back(rows[!flag][j-1] + rows[!flag][j]);
            }
            rows[flag].push_back(1);
            flag = !flag;
            rows[flag].clear();
        }

        return rows[!flag];
    }
};