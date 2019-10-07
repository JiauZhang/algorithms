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
 *题目：
 *    二维数组中的查找
 *
 *题目描述：
 *    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 *    每一列都按照从上到下递增的顺序排序。请完成一个函数，
 *    输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *
 *解题思路：
 *   因为数组是有序的，所以采用对角顺序比较数据大小，这样一次就可以排除一行
 *
 */

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int x = array.size();
        int y = array[0].size();
        
        for (int i=0; i<x; i++) {
            for (int j=y-1; j>=0; j--) {
                if (target > array[i][j])
                    break;
                if (target == array[i][j])
                    return true;
                if (j == 0)
                    return false;
            }
        }        
        return false;
    }
};