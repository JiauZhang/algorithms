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
 * 题目描述：
 *     输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
 *     例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
 *     则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
 * 
 * 解题思路：
 *     使用对角的两个坐标来指示待打印的行和列，这里选用 top-left 和 bottom-right
 *     注意事项：
 *     1. 打印时注意行和列衔接处的元素，切勿重复打印
 *     2. 每打印完一圈，这对坐标缩小矩形一个单位
 *     3. 循环条件就是还有可打印的元素，即 while (top<=bottom && left<=right)
 *     4. 打印完 top 和 right 之后，应该判断是否存在 top == bottom 或者
 *        right == left ，如果有那说明仅剩这一行或一列数据了，可以break了
 * 
 */

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int x = matrix.size();
        int y = matrix[0].size();
        
        vector<int> res;
        if (x == 0 || y == 0)
            return res;
        
        if (x == 1)
            return matrix[0];
        
        int top = 0, left = 0;
        int bottom = x - 1, right = y - 1;
        while (top<=bottom && left<=right) {
            for (int i=left; i<=right; i++)
                res.push_back(matrix[top][i]);
            for (int i=top+1; i<=bottom; i++)
                res.push_back(matrix[i][right]);
            if (top == bottom) break;
            for (int i=right-1; i>=left; i--)
                res.push_back(matrix[bottom][i]);
            if (left == right) break;
            for (int i=bottom-1; i>=top+1; i--)
                res.push_back(matrix[i][left]);
            top++; left++;
            right--; bottom--;
        }
        
        return res;
    }
    
};