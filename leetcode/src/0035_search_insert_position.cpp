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
* https://leetcode-cn.com/problems/search-insert-position
* 题目描述：
*     给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
*     如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
*     你可以假设数组中无重复元素。
* 
* 示例 1:
*     输入: [1,3,5,6], 5
*     输出: 2
* 
* 示例 2:
*     输入: [1,3,5,6], 2
*     输出: 1
* 
* 示例 3:
*     输入: [1,3,5,6], 7
*     输出: 4
* 
* 示例 4:
*     输入: [1,3,5,6], 0
*     输出: 0
* 
* 解题思路：
*     1. 最简单粗暴的方法就是逐个遍历，直到找到目标数字或者第一个
*        大于目标数的值，不过时间复杂度为 O(N)
*     2. 由于给定的数组是有序数组，所以可以使用二分法进行查找
*        这样时间复杂度就可以变成 O(logN)
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        
        int start = 0, end = nums.size() - 1;
        if (nums[start] > target)
            return 0;
        if (nums[end] < target)
            return end + 1;
        
        int mid;
        while (start < end) {
            /* 
                本来想优化一下，结果这句造成了死循环
                按理说有符号的正数不应该出现这种情况的呀！
                mid = start + (end - start) >> 1;
            */
            mid = start + (end - start) / 2;
            if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                return mid;
            }
        }
        
        if (nums[start] >= target)
            return start;
        return start + 1;
    }
};