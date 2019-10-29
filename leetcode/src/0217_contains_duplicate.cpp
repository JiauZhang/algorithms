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
* https://leetcode-cn.com/problems/contains-duplicate
* 题目描述：
*     给定一个整数数组，判断是否存在重复元素
* 
* 如果任何值在数组中出现至少两次，函数返回 true
* 如果数组中每个元素都不相同，则返回 false
* 
* 示例 1:
*     输入: [1,2,3,1]
*     输出: true
* 
* 示例 2:
*     输入: [1,2,3,4]
*     输出: false
* 
* 示例 3:
*     输入: [1,1,1,3,3,4,3,2,4,2]
*     输出: true
* 
* 解题思路：
*     第一种：暴力法 O(n)
*     第二种：先排序，然后检查相邻的数是否相等即可 O(nlogn)
*     第三种：哈希表，如代码所示
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i=0; i<nums.size(); i++) {
            hash[nums[i]] = i;
        }

        return hash.size() != nums.size();
    }
};