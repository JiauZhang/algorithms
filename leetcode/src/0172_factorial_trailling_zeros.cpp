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
* https://leetcode-cn.com/problems/factorial-trailing-zeroes
* 给定一个整数 n，返回 n! 结果尾数中零的数量
* 
* 示例 1:
*     输入: 3
*     输出: 0
*     解释: 3! = 6, 尾数中没有零
* 
* 示例 2:
*     输入: 5
*     输出: 1
*     解释: 5! = 120, 尾数中有 1 个零
* 
* 说明: 
*     你算法的时间复杂度应为O(logn)
*     
* 解题思路：
*     最直接的解法就是先求出 n! 等于多少
*     然后计算尾数中零的数量，该方法的复杂度为 O(n)
*     如果想实现复杂度为 O(logn)
*     必须另想方法，既然我们要计算尾数中的零的个数
*     等价于我们要计算 n! 中含有多少个 10 这个因子
*     再进一步的说，10 = 2 * 5，这两个因子已无法再分解了
*     原问题再次等价于计算 n! 中含有多少对 (2, 5) 因子
*     很显然，在 n! = 1*2*3*4*5*6*...*(n-1)*n 中
*     2 这个因子出现的次数肯定 >= 5 出现的次数
*     故原问题又等价于计算 n! 中因子 5 出现的次数
*     而所有可能出现在含有 5 的数如下：
*     5^1, 5^2, 5^3, 5^4, 5^5..., 5^max_exp
*     所以该题的解就是计算如下结果：
*     (n/5^1 + n/5^2 + n/5^3 + n/5^4 + n/5^5 + ... + n/5^max_exp)
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int max_exp = log(n) / log(5);
        int res = 0;
        
        for (int i=0; i<max_exp; i++) {
            int temp = n / 5;
            res += temp;
            n = temp;
        }

        return res;
    }
};