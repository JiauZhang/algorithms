/*
 * 题目描述:
 *     输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 * 
 * 解题思路：
 *     通过 位与 操作判断是否为 1
 *     如果对输入数据进行移位操作，则会出现死循环
 *     因为：负数在 右移位 时，负号标志符 1 会往下传递
 *           所以只能定义一个无符号整数 1 左移位来完成算法
 *     
 *     另一种方法：
 *         01101100 - 1 = 01101011
 *         01101100 & 01101011 = 01101000
 *         可以看出减 1 操作会把原数中的最后一个 1 变成 0
 *         再进行与操作后就会变成把原数最后一个 1 抹去了！！！
 * 
 */

/* 方法一 */
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         
         unsigned int flag = 1;
         while (flag) {
             if (n & flag)
                 count++;
             flag <<= 1;
         }
         
         return count;
     }
};

/* 方法二 */
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         
         while (n) {
             count++;
             n &= (n-1);
         }
         
         return count;
     }
};