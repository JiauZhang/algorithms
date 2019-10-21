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
* https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
* 题目描述：
*     给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格
*     如果你最多只允许完成一笔交易（即买入和卖出一支股票）
*     设计一个算法来计算你所能获取的最大利润
*     注意你不能在买入股票前卖出股票
* 
* 示例 1:
*     输入: [7,1,5,3,6,4]
*     输出: 5
*     解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）
*           的时候卖出，最大利润 = 6-1 = 5
*           注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格
* 
* 示例 2:
*     输入: [7,6,4,3,1]
*     输出: 0
*     解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
* 
* 解题思路：
*     首先遍历数组是从左往右的，即先买入后卖出的顺序
*     然后对每一个价格首先判断是否是小于当前最小值
*     即判断当前价格是否适合卖出，如果不小于，则适合卖出
*     然后检查是否产生了最大效益
*     如果小于，即产生了新的最小值，则更新最小值即可
*     
* 另一种解题思路：
*     详情请参考：https://leetcode-cn.com/problems/
*     best-time-to-buy-and-sell-stock/solution/
*     121-mai-mai-gu-piao-de-zui-jia-shi-ji-dp-7-xing-ji/
*     该方法的核心思想是
*     区间和可以转换成求差的问题，求差问题，也可以转换成区间和的问题
*     所以该问题就可以转化为最大连续子区间和的问题
*     
* 可能的疑问：
*     为什么现在的最小值一定比后边的某个较小值和一个较大值
*     产生的利润更大，这是因为如果某个较小值能和后边的
*     一个较大值产生利润，那么当前的最小值产生的利润一定
*     比这个较小值更大
*/

/* 第一种解题思路 */
class Solution_1 {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;
        for (int i=0; i<prices.size(); i++) {
            if (min > prices[i])
                min = prices[i];
            else if (prices[i] - min > max)
                max = prices[i] - min;
        }

        return max;
    }
};
/* 问题转化为最大连续子数组的和 */
class Solution_2 {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0, sum = 0;
        for (int i=1; i<prices.size(); i++) {
            if (sum < 0) {
                sum = prices[i] - prices[i-1];
            } else {
                sum += (prices[i] - prices[i-1]);
            }

            if (sum > max)
                max = sum;
        }        

        return max;
    }
};