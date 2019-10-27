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
* https://leetcode-cn.com/problems/house-robber
* 题目描述：
*     你是一个专业的小偷，计划偷窃沿街的房屋
*     每间房内都藏有一定的现金
*     影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统
*     如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
* 
*     给定一个代表每个房屋存放金额的非负整数数组
*     计算你在不触动警报装置的情况下，能够偷窃到的最高金额
* 
* 示例 1:
*     输入: [1,2,3,1]
*     输出: 4
* 解释: 
*     偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)
*     偷窃到的最高金额 = 1 + 3 = 4
* 
* 示例 2:
*     输入: [2,7,9,3,1]
*     输出: 12
* 解释: 
*     偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)
*     接着偷窃 5 号房屋 (金额 = 1)
*     偷窃到的最高金额 = 2 + 9 + 1 = 12
* 
* 解题思路：
*     第一种：暴力求解，计算所有的可能情况，然后求出最大值
*     第二种：动态规划，每个房间偷或不偷，重要的是价值最大
*             关键是找到状态转移方程，根据偷窃规则可得：
*             dp[i] = max(dp[i-1], dp[i-2]+nums[i])
*             有了这个状态转移方程之后就简单了，具体见程序
*             还有一个小的可优化的地方，其实可以不用向程序中
*             给出的使用 dp 数组，其实两个 临时变量即可解决
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        int *dp = new int[nums.size()+1];
        dp[0] = 0; dp[1] = nums[0];

        for (int i=2; i<=nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }

        return dp[nums.size()];
    }
};