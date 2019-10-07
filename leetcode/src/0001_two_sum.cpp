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
 https://leetcode-cn.com/problems/two-sum
 给定一个整数数组 nums 和一个目标值 target，
     请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
     你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 
 示例: 
     给定 nums = [2, 7, 11, 15], target = 9 
     因为 nums[0] + nums[1] = 2 + 7 = 9
     所以返回 [0, 1]
     
 解题思路：
     1. 最简单的方法就是暴力搜索了，两个嵌套循环就搞定了
     2. 为了降低复杂度，努力的方向就是在有了第一个数之后
        如何快速的判断是否有另一个数存在，这里就可以看出其实是一种映射
     3. 映射方式可以使用 map、hash table 等，而 hash table 更快
        所以这里使用 unordered_map，因为其底层实现就是 hash table
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> data;
        construct_map(nums, data);
        
        int i=0;
        vector<int> res;
        while (i < nums.size()) {
            /*
                这里是不对的，两个数的和不一定月假越大，比如负数！
                if (nums[i] > target) {
                    i++;
                    continue;
                }
            */
            int left = target - nums[i];
            if (data.count(left) && data[left] != i) {
                res.push_back(i);
                res.push_back(data[left]);
                break;
            }  
            
            i++;
        }
        
        return res;
    }
    
    void construct_map(vector<int> &nums, unordered_map<int, int> &data) {
        int i = 0;
        while (i < nums.size()) {
            data[nums[i]] = i;
            i++;
        }
    }
};