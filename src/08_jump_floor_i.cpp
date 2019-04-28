/*
 * 题目描述：
 *      一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 *      求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 * 
 * 解题思路：
 *     当n=1时，仅有 1 中跳法
 *     当n=2时，有两种跳法，1+1 或者 2
 *     这里只是起始条件和斐波那契数列有点不同而已
 *     推广到当有 n 个台阶时，调到当前台阶有两种方式：
 *     1. 从上个台阶跳 1 个台阶到达的，即在 n-1 处跳过来的
 *     2. 从上个台阶跳 2 个台阶到达的，即在 n-2 处跳过来的
 *     因此，调到第 n 个台阶的总方法数为 f(n-1) + f(n-2)
 * 
*/

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 0)
           return 0;
        
       if (number == 1)
           return 1;
       
       if (number == 2)
           return 2;
       
       int f_n_1 = 2;
       int f_n_2 = 1;
       int f_n = 0;
       for (int i=3; i<=number; i++) {
           f_n = f_n_1 + f_n_2;
           f_n_2 = f_n_1;
           f_n_1 = f_n;
       }
        
       return f_n;
    }
};