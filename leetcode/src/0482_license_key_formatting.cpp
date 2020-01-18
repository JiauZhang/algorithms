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
* https://leetcode-cn.com/problems/license-key-formatting
* 题目描述：
*     给定一个密钥字符串S，只包含字母，数字以及 '-'（破折号）
*     N 个 '-' 将字符串分成了 N+1 组。给定一个数字 K，重新格式化字符串
*     除了第一个分组以外，每个分组要包含 K 个字符，第一个分组至少要包含 1 个字符
*     两个分组之间用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母
*     给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化
* 
* 示例 1：
*     输入：S = "5F3Z-2e-9-w", K = 4
*     输出："5F3Z-2E9W"
* 解释：
*     字符串 S 被分成了两个部分，每部分 4 个字符；
*     注意，两个额外的破折号需要删掉。
* 
* 示例 2：
*     输入：S = "2-5g-3-J", K = 2
*     输出："2-5G-3J"
* 解释：
*     字符串 S 被分成了 3 个部分，按照前面的规则描述
*     第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符
* 
* 解题思路：
*     首先第一步是格式化字符串，将小写字母变成大写，剔除 '-'
*     然后根据 K 计算最后的字符串长度，最后等间隔添加 '-' 即可
*/

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int left = 0, right = 0;
        while (right < S.size()) {
            if (S[right] == '-') {
                right++;
                continue;
            }

            char temp;
            if (S[right] >= 'a' && S[right] <= 'z') {
                temp = S[right] - 'a' + 'A';
            } else {
                temp = S[right];
            }

            S[left] = temp;
            left++;
            right++;
        }

        int str_size = (left - 1) / K + left;
        S.resize(str_size);
        int count = 0; left--;
        for (int i=str_size-1; i>=0; i--) {
            if (count == K) {
                S[i] = '-';
                count = 0;
            } else {
                S[i] = S[left];
                left--;
                count++;
            }
        }
        
        return S;
    }
};