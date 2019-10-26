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
* https://leetcode-cn.com/problems/reverse-bits
* 题目描述：
*     颠倒给定的 32 位无符号整数的二进制位
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if (n == 0)
            return 0;
        
        uint32_t res = 0x00;
        for (int i=0; i<32; i++) {
            if (n & (0x01 << i)) {
                res |= (0x01 << (31-i));
            }
        }

        return res;
    }
};