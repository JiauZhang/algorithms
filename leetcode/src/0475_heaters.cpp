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
* https://leetcode-cn.com/problems/heaters
* 题目描述：
*     冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖
*     现在，给出位于一条水平线上的房屋和供暖器的位置
*     找到可以覆盖所有房屋的最小加热半径
*     所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径
* 
* 说明:
*     给出的房屋和供暖器的数目是非负数且不会超过 25000
*     给出的房屋和供暖器的位置均是非负数且不会超过10^9
*     只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖
*     所有供暖器都遵循你的半径标准，加热的半径也一样
* 
* 示例 1:
*     输入: [1,2,3],[2]
*     输出: 1
* 解释: 
*     仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖
* 
* 示例 2:
*     输入: [1,2,3,4],[1,4]
*     输出: 1
* 解释: 
*     在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖
* 
* 解题思路：
*     要想覆盖每个房屋，则某个房屋两边的必须有一个能够覆盖住该房屋
*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        const int house_size = houses.size(), heater_size = heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        heaters.push_back(INT_MAX);

        int r = 0,i = 0;
        // 处理只有一侧有供暖器的房屋
        if(houses[0]<heaters[0]){
            r = heaters[0] - houses[0];
            // 所有房屋均在第一个供暖器左侧
            if(houses[house_size-1]<=heaters[0])
                return r;
            // 跳过第一个供暖器左侧的房屋
            while(houses[++i]<heaters[0]);
        }

        for(int j=0;i<house_size&&j<heater_size;++i){
            // 当第 i 个房屋不在第 j 和第 j+1 个供暖器之间时
            while(houses[i]<heaters[j]||houses[i]>heaters[j+1])++j;
            // 第 j 和第 j+1 个供暖器间的第 i 个房屋需要满足的条件
            r = max(r,min(houses[i]-heaters[j],heaters[j+1]-houses[i]));
        }
        
        return r;
    }
};