/*
* Copyright(c) 2021 Jiau Zhang
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
https://leetcode-cn.com/problems/next-permutation
题目描述：
    实现获取 下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）
    如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）,必须原地修改，只允许使用额外常数空间

 解题思路：
    核心思想是按字典序升序排列时，排列的最大值一定是较大的数往左边放，较小的数往右边放，即升序排列
    当给定一个组合时，一定是 [num_1, ..., num_m, |  max_1, max_2, max_3, ..., max_n]
    那个这个组合的下一个排列就应该是把 num_m 换成最接近它且大于它的那个数
    所以解题思路就是：先找到分界点，然后在 max_1, ..., max_n 中找出第一个大于 num_m 的数，并交换它们
    最后反转右半部分子序列使其最小即可
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        
        for (int i=nums.size()-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                int temp = nums[i];

                for (int j=nums.size()-1; j>=i; j--) {
                    if (nums[i] < nums[j]) {
                        nums[i] = nums[j];
                        nums[j] = temp;
                        break;
                    }
                }

                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }

        reverse(nums.begin(), nums.end());
    }
};