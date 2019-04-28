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

