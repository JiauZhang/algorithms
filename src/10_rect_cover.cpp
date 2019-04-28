/*
 * 题目描述
 *     我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 *     请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * 
 * 解题思路：
 *     当n=1时，覆盖方法有 1 种，竖着放
 *     当n=2时，覆盖方法有 2 种，两个竖着放或者两个横着放
 *     当n=3时，覆盖方法有 3 中，当第三个为竖着放时，前边的两个随便放
 *                               当第三个横着放时，第二个也被覆盖了，
 *                               所以只剩第一个是自由的了
 *     即 f(3) = f(2) + f(1)
 *     推广成 n 后变成：
 *         f(n) = f(n-1) + f(n-2)
 * 
 */

class Solution {
public:
    int rectCover(int number) {
        if (number<=0)
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