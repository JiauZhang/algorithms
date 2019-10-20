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
* https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
* 题目描述：
*     给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格
*     设计一个算法来计算你所能获取的最大利润
*     你可以尽可能地完成更多的交易（多次买卖一支股票）
* 
* 注意：
*     你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
* 
* 示例 1:
* 输入: [7,1,5,3,6,4]
* 输出: 7
* 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出
*       这笔交易所能获得利润 = 5-1 = 4 
*       随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）
*       的时候卖出, 这笔交易所能获得利润 = 6-3 = 3
* 
* 示例 2:
*     输入: [1,2,3,4,5]
*     输出: 4
*     解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）
*           的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
*           注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出
*           因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票
* 
* 示例 3:
*     输入: [7,6,4,3,1]
*     输出: 0
*     解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
* 
* 解题思路：
*     该题目是不限制交易次数的，所以最大盈利就是只要能够产生收益
*     就进行一次交易，此时利益最大
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;

        int max = 0;
        for (int i=0; i<prices.size()-1; i++) {
            if (prices[i+1] > prices[i])
                max += (prices[i+1] - prices[i]);
        }

        return max;
    }
};