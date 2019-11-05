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
* https://leetcode-cn.com/problems/first-bad-version
* 题目描述：
*     你是产品经理，目前正在带领一个团队开发新的产品
*     不幸的是，你的产品的最新版本没有通过质量检测
*     由于每个版本都是基于之前的版本开发的
*     所以错误的版本之后的所有版本都是错的
*     假设你有 n 个版本 [1, 2, ..., n]
*     你想找出导致之后所有版本出错的第一个错误的版本
*     你可以通过调用 bool isBadVersion(version) 接口
*     来判断版本号 version 是否在单元测试中出错
*     实现一个函数来查找第一个错误的版本
*     你应该尽量减少对调用 API 的次数
* 
* 示例:
*     给定 n = 5，并且 version = 4 是第一个错误的版本
*     调用 isBadVersion(3) -> false
*     调用 isBadVersion(5) -> true
*     调用 isBadVersion(4) -> true
*     所以，4 是第一个错误的版本
* 
* 解题思路：
*     二分法即可
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            bool bad = isBadVersion(mid);
            if (bad)
                right = mid;
            else
                left = mid + 1;
        }

        return right;
    }
};