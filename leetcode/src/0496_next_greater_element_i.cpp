/*
* Copyright(c) 2020 Jiau Zhang
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
https://leetcode-cn.com/problems/next-greater-element-i
题目描述：
    给定两个没有重复元素的数组 nums1 和 nums2
    其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2
    中的下一个比其大的值
    nums1 中数字 x 的下一个更大元素是指 x 在 nums2
    中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1

示例 1:
    输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
    输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字
    因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1

示例 2:
    输入: nums1 = [2,4], nums2 = [1,2,3,4].
    输出: [3,-1]
解释:
    对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1

解题思路：
    因为每个元素需要找到其右方的第一个比其大的值，为了降低算法复杂度
    应该想办法实现第一个比其大的值的快速查找，最朴素的做法就是对num[i]
    检查其前方比其小的，然后记录即可，对于已经找到匹配的为了避免再次查询
    可以使用一个数组标识出来，但是算法复杂度比较大，所以这里使用栈来维护
    未匹配的数，最后得到的一个结果就是单调栈，有匹配的直接从栈中弹出即可
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (!nums1.size() || !nums2.size())
            return {};

        map<int, int> data;
        stack<int> st;
        for (int i=0; i<nums2.size(); i++) {
            while (!st.empty() && st.top()<nums2[i]) {
                data[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }
        
        while (!st.empty()) {
            data[st.top()] = -1;
            st.pop();
        }

        vector<int> res;
        for (auto n: nums1) {
            res.push_back(data[n]);
        }

        return res;
    }
};