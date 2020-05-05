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
* https://leetcode-cn.com/problems/detect-capital
* 给定一个单词，你需要判断单词的大写使用是否正确
* 
* 我们定义，在以下情况时，单词的大写用法是正确的
*     全部字母都是大写，比如"USA"
*     单词中所有字母都不是大写，比如"leetcode"
*     如果单词不只含有一个字母，只有首字母大写， 比如 "Google"
* 否则，我们定义这个单词没有正确使用大写字母。
* 
* 示例 1:
*     输入: "USA"
*     输出: True
* 
* 示例 2:
*     输入: "FlaG"
*     输出: False
*/