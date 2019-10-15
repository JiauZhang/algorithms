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
* https://leetcode-cn.com/problems/merge-sorted-array
* 题目描述：
*     给定两个有序整数数组 nums1 和 nums2，
*     将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
* 
* 说明:
*     初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
*     你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）
*     来保存 nums2 中的元素。
* 
* 示例:
*     输入:
*     nums1 = [1,2,3,0,0,0], m = 3
*     nums2 = [2,5,6],       n = 3
*     输出: [1,2,2,3,5,6]、
* 
* 解题思路：
*     该题合并两个有序数组思路其实很简单的，按大小取数即可
*     稍微需要注意的就是该题要求需要使用原始数组存储排好序
*     的数据，所以需要从后往前进行合并！
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int index = m+n-1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[index--] = nums1[i--];
            } else {
                nums1[index--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[index--] = nums2[j--];
        }
    }
};