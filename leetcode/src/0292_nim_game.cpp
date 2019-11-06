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
* https://leetcode-cn.com/problems/nim-game
*     题目描述：
*     你和你的朋友，两个人一起玩 Nim 游戏：桌子上有一堆石头
*     每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者
*     你作为先手，你们是聪明人，每一步都是最优解
*     编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。
* 
* 示例:
*     输入: 4
*     输出: false 
* 解释: 
*     如果堆中有 4 块石头，那么你永远不会赢得比赛
*     因为无论你拿走 1 块、2 块 还是 3 块石头
*     最后一块石头总是会被你的朋友拿走
*/

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};