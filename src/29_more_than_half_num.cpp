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

题目描述
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
    例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
    超过数组长度的一半，因此输出2。如果不存在则输出0。

解题思路：
    ...

*/

// 由于有一个数出现次数超过一半，那么把这个数看做是 1，而其他数看做 -1
// 则总和一定是 > 0的，所以记录 为 1 时候的数，一定可以记录下超过一半的那一个
// 因为其他的都会被 1 抵消掉
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0)
            return 0;
        
        
        int res = numbers[0];
        int times = 1;
        
        for (int i=1; i<numbers.size(); i++) {
            if (res != numbers[i]) {
                if (times == 0) {
                    res = numbers[i];
                    times = 1;
                } else {
                    times--;
                }
            } else {
                times++;
            }
        }

        
        int count = 0;
        for (int i=0; i<numbers.size(); i++) {
            if (numbers[i] == res)
                count++;
        }
        
        if (count << 1 <= numbers.size())
            return 0;
        
        return res;
    }
}

// 不怎么好的方法
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size() == 0)
            return 0;
        
        int middle = numbers.size() >> 1;
        
        int index = partition(numbers, 0, numbers.size() - 1);
        int start = 0, end = numbers.size() - 1;
        while (index != middle) {
            if (index > middle) {
                end = index - 1;
                index = partition(numbers, start, end);
            }                
            else {
                start = index + 1;
                index = partition(numbers, start, end);
            }                
        }
        
        int count = 0;
        for (int i=0; i<numbers.size(); i++) {
            if (numbers[i] == numbers[middle])
                count++;
        }
        
        if (count << 1 <= numbers.size())
            return 0;
        
        return numbers[middle];
    }
    
    /*
        快排的思想是：随机取出一个数，然后把它交换到数组最后
        然后一个指针指向比该数小的，所以初始值 为 start - 1
        遇到比它小的数时，指针向前一个单位，即执行了比它大的一个
        然后把前方的小的 swap 过来即可
        最后 small++ , swap 把选中的那个数放中间，返回中间值 index
    */
    int partition(vector<int> &nums, int start, int end) {
        /*
            您的代码已保存
            浮点错误:您的程序运行时发生浮点错误，比如遇到了除以 0 的情况
            case通过率为0.00%
        */
        // 求余操作 % 也需要运行除法运算才能得到，所以必须检查分母是否为零
        if (start == end)
            return start;
        // 这里需要绝对索引值，因此必须加上 start 偏移
        int index = rand()%(end-start) + start;        
        swap(nums[index], nums[end]);
        
        int small = start - 1;
        for (index = start; index<end; index++) {
            if (nums[index] < nums[end]) {
                small++;
                swap(nums[small], nums[index]);
            }
        }
        
        small++;
        swap(nums[small], nums[end]);
        
        return small;
    }
    
    void swap(int &num1, int &num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
};