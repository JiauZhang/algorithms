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
* https://leetcode-cn.com/problems/remove-element
* 题目描述：
*     给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，
*     返回移除后数组的新长度。
*     不要使用额外的数组空间，你必须在原地修改输入数组
*     并在使用 O(1) 额外空间的条件下完成。
*     元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
* 
* 示例 1:
*     给定 nums = [3,2,2,3], val = 3,
*     函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
*     你不需要考虑数组中超出新长度后面的元素。
* 
* 示例 2:
*     给定 nums = [0,1,2,2,3,0,4,2], val = 2,
*     函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
*     注意这五个元素可为任意顺序。
* 
* 注：
*     你不需要考虑数组中超出新长度后面的元素。
* 
* 解题思路：
*     1. 解题思路与题目 0026_remove_duplicates_from_sorted_array 类似
*        不同的是这里需要覆盖的是指定数字，同样需要双指针
*     2. 注意指针的含义即可
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        
        int head = 0, tail = 0;
        while (tail < nums.size()) {
            if (nums[tail] == val) {
                tail++;
            } else {
                if (head < tail) {
                    nums[head] = nums[tail];
                }
                head++;
                tail++;
            }
        }
        
        nums.resize(head);
        
        return head;
    }
};