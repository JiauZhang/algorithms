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
 *     大家都知道斐波那契数列，现在要求输入一个整数n，
 *     请你输出斐波那契数列的第n项（从0开始，第0项为0）。
 * 
*/

/* 递归方法----效率低，内存占用大 */
class Solution {
public:
    int Fibonacci(int n) {
       if (n <= 0)
           return 0;
        
       if (n == 1)
           return 1;
        
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
};

/* 循环方法----效率高，避免了递归中的重复计算 */
class Solution {
public:
    int Fibonacci(int n) {
       if (n <= 0)
           return 0;
        
       if (n == 1)
           return 1;
       
       int f_n_1 = 1;
       int f_n_2 = 0;
       int f_n = 0;
       for (int i=2; i<=n; i++) {
           f_n = f_n_1 + f_n_2;
           f_n_2 = f_n_1;
           f_n_1 = f_n;
       }
        
       return f_n;
    }
};

