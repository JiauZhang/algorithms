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
* https://leetcode-cn.com/problems/count-primes
* 题目描述：
*     统计所有小于非负整数 n 的质数的数量。
* 
* 示例:
*     输入: 10
*     输出: 4
* 解释: 
*     小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
* 
* 解题思路：
*     非质数一定由质数因子构成，所以可以通过某个质数的 2倍、3倍...
*     来排除非质数，由于合数至少含有两个数，故只需要遍历到 i*i<n
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;

        vector<bool> flags(n);
        int res = n-2;
        for (int i=2; i<n; i++) flags[i] = true;
        /* 避免重复计算 */
        for (int i=2; i*i<n; i++) {
            if (flags[i]) {
                /* 避免重复计算 */
                for (int j=i*i; j<n; j+=i) {
                    /* 避免重复计算 */
                    if (flags[j]) {
                        flags[j] = false;
                        res--;
                    }
                                       
                }
            }
        }
        /*
        res = 0;
        for (int i=2; i<n; i++) if (flags[i]) res++;
        */
        return res;
    }
};