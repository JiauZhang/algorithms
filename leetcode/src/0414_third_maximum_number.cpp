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
* https://leetcode-cn.com/problems/third-maximum-number
* 题目描述：
*     给定一个非空数组，返回此数组中第三大的数。如果不存在
*     则返回数组中最大的数。要求算法时间复杂度必须是O(n)
* 
* 示例 1:
*     输入: [3, 2, 1]
*     输出: 1
* 解释: 
*     第三大的数是 1
* 
* 示例 2:
*     输入: [1, 2]
*     输出: 2
* 解释: 
*     第三大的数不存在, 所以返回最大的数 2 
* 
* 示例 3:
*     输入: [2, 2, 3, 1]
*     输出: 1
* 解释: 
*     注意，要求返回第三大的数，是指第三大且唯一出现的数
*     存在两个值为2的数，它们都排第二
* 
* 解题思路：
*     这里使用 set 数据结构，总的复杂度为 N*log3 约等于 N
*     程序中有两个 for 循环，但是仅执行 N 此，第一个循环
*     首先将 set 填充满足至少有三个元素，如果此时数组还有剩余
*     则第二个 for 循环会继续插入，并保持 set 的大小始终维持
*     大小为 3，这里利用了 set 的自带属性，其中的数是从小到大
*     自动排序的，具体见程序
*/

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        /* map's key and set's value are incremental */
        set<int> maxes;
        int index = 0;
        for (; index<nums.size(); index++) {
            maxes.insert(nums[index]);
            if (maxes.size() == 3)
                break;
        }
        /* this 'if' is redundant! */
        // if (++index < nums.size()) {
        index++;
        for (; index<nums.size(); index++) {
            maxes.insert(nums[index]);
            if (maxes.size() > 3)
                maxes.erase(maxes.begin());            
        }
        // }

        if (maxes.size() == 3)
            return *maxes.begin();
        else
            return *maxes.rbegin();
    }
};