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
* https://leetcode-cn.com/problems/pascals-triangle
* 示例:
*     输入: 5
*     输出:
*     [
*          [1],
*         [1,1],
*        [1,2,1],
*       [1,3,3,1],
*      [1,4,6,4,1]
*     ]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0)
            return {};

        vector<vector<int>> res;
        res.resize(numRows);

        vector<int> one;
        one.push_back(1);
        res[0] = one;

        if (numRows == 1) {
            return res;
        }

        vector<int> two;
        two.push_back(1);
        two.push_back(1);
        res[1] = two;

        for (int i=2; i<numRows; i++) {
            res[i].resize(i+1);
            res[i][0] = 1;
            for (int j=1; j<i; j++) {
                res[i][j] =  res[i-1][j-1] + res[i-1][j];
            }
            res[i][i] = 1;
        }

        return res;
    }
};