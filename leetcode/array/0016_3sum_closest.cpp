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
https://leetcode-cn.com/problems/3sum-closest
题目描述：
    给定一个包括 n 个整数的数组 nums 和 一个目标值 target,找出 nums 中的三个整数
    使得它们的和与 target 最接近，返回这三个数的和。假定每组输入只存在唯一答案

 解题思路：
    思路与三数之和类似，只不过记录的是最接近 target 的结果而已
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = -1e4;

        for (int i=0; i<nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            
            int j=i+1, k=nums.size()-1;
            while (j < k) {
            // 去掉这个重复组合的判断之后反而更快了，看来条件分支对速度影响不小
            //    if (j > i+1 && nums[j] == nums[j-1]) {
            //        j++;
            //        continue;
            //    }

                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return sum;
                
                if (abs(closest - target) > abs(sum - target))
                    closest = sum;
                
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return closest;
    }
};