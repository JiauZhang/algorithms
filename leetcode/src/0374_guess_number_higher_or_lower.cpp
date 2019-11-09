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
* https://leetcode-cn.com/problems/guess-number-higher-or-lower
* 题目描述：
*     我们正在玩一个猜数字游戏。 游戏规则如下：
*     我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字
*     每次你猜错了，我会告诉你这个数字是大了还是小了
*     你调用一个预先定义好的接口 guess(int num)
*     它会返回 3 个可能的结果（-1，1 或 0）：
*         -1 : 我的数字比较小
*          1 : 我的数字比较大
*          0 : 恭喜！你猜对了！
* 
* 示例 :
*     输入: n = 10, pick = 6
*     输出: 6
* 
* 解题思路：直接二分法搞定
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right-left) / 2;
            int g = guess(mid);
            if (g == -1)
                right = mid - 1;
            else if (g == 1)
                left = mid + 1;
            else
                return mid;
        }

        return left;
    }
};