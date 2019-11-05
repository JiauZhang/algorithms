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
* https://leetcode-cn.com/problems/move-zeroes
* 题目描述：
*     给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾
*     同时保持非零元素的相对顺序
* 
* 示例:
*     输入: [0,1,0,3,12]
*     输出: [1,3,12,0,0]
* 
* 说明:
*     必须在原数组上操作，不能拷贝额外的数组。
*     尽量减少操作次数。
* 
* 解题思路：
*     把不同类型的数组分离的题，典型做法就是双指针
*     但此题如果用双指针操作就不符合要求了，题目要求保持
*     非零数原来的顺序，所以必须对双指针方法进行修改
*     由于最后操作完成后的结果是末尾全是零，所以我们可以
*     不必关心零的存在，只需要把非零数字向左紧密排列即可
*     最后再把数组中剩余的元素全部填充为零即可
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int head = 0, tail = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[tail]) {
                nums[head] = nums[tail];
                head++;
            }     
            tail++;
        }

        for (int i=head; i<nums.size(); i++)
            nums[i] = 0;
    }
};