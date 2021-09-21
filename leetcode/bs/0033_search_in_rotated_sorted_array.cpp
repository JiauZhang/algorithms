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
https://leetcode-cn.com/problems/search-in-rotated-sorted-array
题目描述：
    整数数组 nums 按升序排列，数组中的值 互不相同，在传递给函数之前
    nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转
    使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）
    例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2]，给你旋转后的数组 nums 
    和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1

 解题思路：
    由于是旋转后的数组，所以需要分别判断 mid 处在那个子数组中，这里不是使用 left 和 right 来判断了
    因为这两个值一直在变，不可靠，所以使用 0 和 nums.size()-1 这两个来判断 mid 所处的位置
    之后就是根据 target 所处位置移动 left 和 right
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return nums[0] == target ? 0: -1;
        
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (nums[mid] == target)
                return mid;
            
            if (nums[0] <= nums[mid]) {
                if (target >= nums[0] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (target <= nums[nums.size()-1] && target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};