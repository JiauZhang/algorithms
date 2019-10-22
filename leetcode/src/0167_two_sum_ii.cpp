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
* https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted
* 题目描述：
*     给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
*     函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
* 
* 说明:
*     返回的下标值（index1 和 index2）不是从零开始的。
*     你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
* 
* 示例:
*     输入: numbers = [2, 7, 11, 15], target = 9
*     输出: [1,2]
*     解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
* 
* 解题思路：
*     因为数组是有序的，so...看代码理解吧~
*     另一种方法就是二分法
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() == 0)
            return {};

        int head = 0, tail = numbers.size() - 1;
        while (head < tail) {
            if (numbers[head] + numbers[tail] > target)
                tail--;
            else if (numbers[head] + numbers[tail] < target)
                head++;
            else
                return {head+1, tail+1};
        }

        return {};
    }
};