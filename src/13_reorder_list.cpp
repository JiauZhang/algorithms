/*
 * 题目描述：
 *     输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 *     使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
 *     并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 * 
 * 解题思路：
 *     使用两个指针，慢指针遇到偶数时停止，快指针遇到奇数时检查是否需要交换数据
 *     如果不需要则继续往前走
 * 
 */

class Solution {
public:
    void shift(vector<int> &vec, int start, int end) {
        while (start < end) {
            vec[end] = vec[end-1];
            end--;
        }
    }
    
    
    void reOrderArray(vector<int> &array) {
        int array_size = array.size();
        int left = 0;
        int right = 0;
        
        while (left<array_size && right<array_size) {
            if ((array[right] & 0x01)) { 
                   if (right>left) {
                       int temp = array[right];
                       shift(array, left, right);
                       array[left] = temp;
                       //right++;
                       /* 
                       不应该直接赋值，因为有可能中间隔着多个偶数，
                       直接赋值会跳过部分偶数，因为一次仅交换一个奇数到前方
                       所以left只能 ++ ！
                       */
                       //left = right;
                       left++;
                   } else {
                       right++;
                   }
            } else {
                right++;
            }
            
            if (array[left] & 0x01) {
                left++;
            }
        }
    }
};