/*
* Copyright(c) 2020 Jiau Zhang
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
* https://leetcode-cn.com/problems/construct-the-rectangle
* 题目描述：
*     作为一位web开发者， 懂得怎样去规划一个页面的尺寸是很重要的
*     现给定一个具体的矩形页面面积，你的任务是设计一个长度为 L 和宽度为 W
*     且满足以下要求的矩形的页面。要求：
*     1. 你设计的矩形页面必须等于给定的目标面积
*     2. 宽度 W 不应大于长度 L，换言之，要求 L >= W
*     3. 长度 L 和宽度 W 之间的差距应当尽可能小
*     你需要按顺序输出你设计的页面的长度 L 和宽度 W
* 
* 示例：
*     输入: 4
*     输出: [2, 2]
* 解释: 
*     目标面积是 4， 所有可能的构造方案有 [1,4], [2,2], [4,1]
*     但是根据要求2，[1,4] 不符合要求; 根据要求3，[2,2] 比 [4,1] 更能符合要求
*     所以输出长度 L 为 2， 宽度 W 为 2
* 
* 解题思路：
*     从示例可以看出，最优解应该尽量接近正方形，因此从面积的平方根开始遍历
*/

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int width = sqrt(area);        

        while (width >= 1) {
            if (area % width == 0)
                break;
            
            width--;
        }

        return {area/width, width};
    }
};