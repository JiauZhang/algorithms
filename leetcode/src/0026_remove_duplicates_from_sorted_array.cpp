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
* https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
* 题目描述：
*     给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，
*     返回移除后数组的新长度。
*     不要使用额外的数组空间，你必须在原地修改输入数组
*     并在使用 O(1) 额外空间的条件下完成。
* 
* 示例 1:
* 给定数组 nums = [1,1,2], 
*     函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
*     你不需要考虑数组中超出新长度后面的元素。
* 
* 示例 2:
*     给定 nums = [0,0,1,1,1,2,2,3,3,4],
*     函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
* 
* 注：
*     你不需要考虑数组中超出新长度后面的元素。
* 
* 解题思路：
*     1. 题目的意思其实就是将不同的数字向前紧密排列，因此涉及到下一个新的数字
*        放在哪里，即需要一个索引值指定，还需要知道最新的数字在哪里，即又需要
*        一个索引值
*     2. 因此使用两个索引值，相同时一个前移、一个不动；
*        遇到不同时，前边的指针前移并将新的数字复制过来，然后走的快的
*        指针继续前移，如此反复即可
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        int head = 0, tail = 0;
        while (tail < nums.size()) {
            if (nums[head] == nums[tail]) {
                tail++;
            } else {
                head++;
                if (head < tail) {
                    nums[head] = nums[tail];
                    tail++;
                }
            }
        }
        
        nums.resize(head+1);
        
        return head+1;
    }
};