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
* https://leetcode-cn.com/problems/majority-element
* 题目描述：
*     给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊n/2⌋ 的元素。
*     你可以假设数组是非空的，并且给定的数组总是存在众数。
* 
* 示例 1:
*     输入: [3,2,3]
*     输出: 3
* 
* 示例 2:
*     输入: [2,2,1,1,1,2,2]
*     输出: 2
* 
* 解题思路：
*     1. 由于众数是出现次数多余 n/2 的，所以可以使用计数方式来找到它
*        即遇到相同的数就 ++ 操作，遇到不同的数就 -- 操作即可
*     2. 每次计数归零后，重新选取新的数字，因为众数的特性
*        所以最后选择的一定还是众数本身
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() <= 0)
            return -1;
        
        int num = 0, count = 0;
        for (int i=0; i<nums.size(); i++) {
            if (count == 0) {
                count++;
                num = nums[i];
            } else if (num == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        
        return num;
    }
};