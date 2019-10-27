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
* https://leetcode-cn.com/problems/happy-number
* 题目描述：
*     编写一个算法来判断一个数是不是“快乐数”
* 
*     一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和
*     然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1
*     那么这个数就是快乐数
* 
* 示例: 
*     输入: 19
*     输出: true
* 解释: 
*     12 + 92 = 82
*     82 + 22 = 68
*     62 + 82 = 100
*     12 + 02 + 02 = 1
* 
* 解题思路：
*     根据题意可知，该检测方法可能陷入无限循环，故需要有检测
*     无限循环的机制，即检测有些数已经出现过了，这里可以使用
*     unordered_map 实现，其他的就很简单了，见示例代码
*/

class Solution {
public:
    bool isHappy(int n) {
        if (n == 0)
            return false;

        if (n == 1)
            return true;        
        
        unordered_map<int, int> hash;
        return do_is_happy(n, hash);
    }

    bool do_is_happy(int &n, unordered_map<int, int> &hash) {
        static int lut[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

        if (hash.count(n))
            return false;
        hash[n] = 1;

        int res = 0;
        while (n) {
            res += lut[n%10];
            n /= 10;
        }

        if (res == 1)
            return true;
        
        n = res;
        return do_is_happy(n, hash);
    }
};