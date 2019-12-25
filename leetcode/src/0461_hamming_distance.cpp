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
* https://leetcode-cn.com/problems/hamming-distance
* 题目描述：
* 	两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目
* 	给出两个整数 x 和 y，计算它们之间的汉明距离
* 
* 注意：
* 	0 ≤ x, y < 231
* 
* 示例:
* 	输入: x = 1, y = 4
* 	输出: 2
* 解释:
* 	1   (0 0 0 1)
* 	4   (0 1 0 0)
* 		   ↑   ↑
* 	上面的箭头指出了对应二进制位不同的位置
* 
* 解题思路：
* 	先对两个数异或操作，这样结果中就记录了不同的位数，然后就是计算
* 	二进制数值 1 的个数的问题了，具体如代码所示
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xy = x^y;
        int res = 0;
        while (xy) {
            res += 1;
            xy &= (xy - 1);
        }

        return res;
    }
};