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
https://leetcode-cn.com/problems/3sum
题目描述：
    给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c，使得 a + b + c = 0
    请你找出所有和为 0 且不重复的三元组，注意：答案中不可以包含重复的三元组

 解题思路：
    此题这能逐个情况遍历，可以加速的就是最后一个循环了，因为前两个数确定了之后就是查找第三个特定的数字
    当第一个数字固定时，第二个数字的增加会导致第三个数字逐渐变小，所以第三个数字不用每次都从末尾开始遍历
    另外还有一些可以提前终止的条件加快跳过不可能的组合
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (int i=0; i<nums.size(); i++) {
            if (i > 0)
                if (nums[i] == nums[i-1])
                    continue;
            // 此时肯定是无解的，因为第一个数字都是大于 0 的，那么三数之和必大于 0
            if (nums[i] > 0)
                break;

            int target_index = nums.size() - 1;
            for (int j=i+1; j<nums.size(); j++) {
                if (j > i+1 && nums[j] == nums[j-1])
                    continue;
                
                int target = -(nums[i] + nums[j]);
                // 由于三数之和等于零，所以前两数之和必定小于等于零，故第三个数必须大于等于零
                if (target < 0)
                    break;

                for (; target_index>=j+1; target_index--) {
                    if (nums[target_index] < target)
                        break;

                    if (nums[target_index] == target) {
                        if (target_index < nums.size() - 1 && nums[target_index] == nums[target_index+1])
                            continue;
                        res.push_back({nums[i], nums[j], nums[target_index]});
                        break;
                    }
                }
            }
        }

        return res;
    }
};