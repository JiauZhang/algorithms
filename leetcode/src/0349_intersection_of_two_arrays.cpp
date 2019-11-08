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
* https://leetcode-cn.com/problems/intersection-of-two-arrays
* 题目描述：
*     给定两个数组，编写一个函数来计算它们的交集
* 
* 示例 1:
*     输入: nums1 = [1,2,2,1], nums2 = [2,2]
*     输出: [2]
* 
* 示例 2:
*     输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
*     输出: [9,4]
* 
* 说明:
*     输出结果中的每个元素一定是唯一的。
*     我们可以不考虑输出结果的顺序。
* 
* 解题思路：
*     因为要找相同，最简单的就是暴力法，优化的方向就是
*     如何快速查询和使用尽量少的查询次数
*     快速查询使用：set，其内部是红黑树
*     减少查询次数的做法就是用较小的 set 去查询另一个 set
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0)
            return {};

        set<int> snums1(nums1.begin(), nums1.end());
        set<int> snums2(nums2.begin(), nums2.end());

        vector<int> res;
        if (snums1.size() < snums2.size()) {            
            intersection(snums1, snums2, res);          
        } else {
            intersection(snums2, snums1, res);  
        }

        return res;
    }

    void intersection(set<int> &s1, set<int> &s2, vector<int> &ins) {
        set<int>::iterator it = s1.begin();
        for (; it!=s1.end(); it++) {
            if (s2.count(*it))
                ins.push_back(*it);
        }
    }
};