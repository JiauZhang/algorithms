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
 https://leetcode-cn.com/problems/container-with-most-water
 题目描述：
    给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)
    在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)
    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水

 解题思路：
    根据题意，容器大小由最小边和两个边的距离共同决定，于是从两边开始查找
    即先把两边的距离做的最大，然后再移动短的边，因为假如移动长的边
    那么最终的容积必定会减小，而移动短的边是肯能减小也可能增加
    这就是贪婪算法！
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max, temp;
        
        max = min(height[left], height[right]) * right;

        while (left < right) {
            if (height[right] > height[left]) {
                temp = height[left] * (right - left);
                left++;
            } else {
                temp = height[right] * (right - left);
                right--;
            }                
            
            if (max < temp)
                max = temp;
        }

        return max;
    }
};