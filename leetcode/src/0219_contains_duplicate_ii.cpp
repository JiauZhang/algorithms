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
* https://leetcode-cn.com/problems/contains-duplicate-ii
* 题目描述：
*     给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j
*     使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k
* 
* 示例 1:
*     输入: nums = [1,2,3,1], k = 3
*     输出: true
* 
* 示例 2:
*     输入: nums = [1,0,1,1], k = 1
*     输出: true
* 
* 示例 3:
*     输入: nums = [1,2,3,1,2,3], k = 2
*     输出: false
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); i++) {
            if (hash.count(nums[i]) && i - hash[nums[i]] <= k) {
                return true;
            } else {
                hash[nums[i]] = i;
            }
        }

        return false;
    }
};