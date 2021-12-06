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
 * 解题思路：
 * 本题的核心思路是把该问题转化为 0-1 背包问题，题目目标是把有限数组分成两份
 * 使得两个组合各自的和相等，所以如果有可能存在，那么只需要找到一个组合就行
 * 即在有限的可选物品中选择或不选择某个物品达到和为某个数，即背包问题
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, max_num = INT_MIN;
        for (auto n: nums) {
            sum += n;
            max_num = max(max_num, n);
        }
        
        int half = sum / 2;
        if ((sum & 0x01) || (max_num > half))
            return false;
        
        if (max_num == half)
            return true;
        
        vector<int> buffer(half+1, false);
        
        if (nums[0] <= half)
            buffer[nums[0]] = true;
        
        for (int i=1; i<nums.size(); i++) {
            for (int j=half; j>=nums[i]; j--) {
                if (!buffer[j])
                    buffer[j] = buffer[j-nums[i]];
            }
        }

        return buffer[half];
    }
};