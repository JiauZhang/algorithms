/*
* Copyright(c) 2020 Jiau Zhang
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
* https://leetcode-cn.com/problems/number-complement
* 题目描述：
*     给定一个正整数，输出它的补数。补数是对该数的二进制表示取反
* 
* 注意:
*     给定的整数保证在32位带符号整数的范围内。
*     你可以假定二进制数不包含前导零位。
* 
* 示例 1:
*     输入: 5
*     输出: 2
* 解释: 
*     5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2
* 
* 示例 2:
*     输入: 1
*     输出: 0
* 解释: 
*     1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0
* 
* 解题思路：
*     通过示例可以看出，只对左边第一个 1 及其之后的二进制位进行取反
*     因此需要对第一个 1 之前的数保持不变，即保持为零
*/

class Solution {
public:
    int findComplement(int num) {
        unsigned int temp = num;
        int mask = 0x00;
        while (temp) {
            mask = (mask << 1) | 0x01;
            temp >>= 1;
        }

        return (~num) & mask;
    }
};