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
题目：
    给定一个非负整数数组，你最初位于数组的第一个位置。
    数组中的每个元素代表你在该位置可以跳跃的最大长度。
    判断你是否能够到达最后一个位置。

示例 1:
    输入: [2,3,1,1,4]
    输出: true
    解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。

示例 2:
    输入: [3,2,1,0,4]
    输出: false
    解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0，
          所以你永远不可能到达最后一个位置。

*/

/*
    动态规划(DP)方法，复杂度 O(n^2)
    解题思路：
        1. 该问题要解决的是最后一个元素是否可达，故需要判断最后一个元素
           前边可达的元素是否可达最后一个元素
        2. 由此问题变为从 第 1 个元素开始扫描，判断当前元素是否可达
           直到扫描完整个数组
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        
        bool can[nums.size()];
        can[0] = true;
        
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                // 判断当前元素前方所有的元素是否有可达到当前元素的
                if (can[j] && j+nums[j]>=i) {
                    can[i] = true;
                    break;
                }
            }
        }
        
        return can[nums.size()-1];
    }
};

/*
    贪婪算法(Greedy Algorithm), 时间复杂度 O(n)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        
        int reach = 0;
        for (int i=0; i<nums.size(); i++) {
            // 第一个条件表示当前点不可达，即前方元素的最远可达无法到达该元素
            // 第二个条件为最后一个元素可达
            if (i > reach || reach >= nums.size() - 1)
                break;
            
            reach = max(reach, i+nums[i]);
        }
        
        return reach >= nums.size() - 1;
    }
};