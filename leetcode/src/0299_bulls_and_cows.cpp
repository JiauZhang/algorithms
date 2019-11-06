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
* https://leetcode-cn.com/problems/bulls-and-cows
* 题目描述：
*     你正在和你的朋友玩 猜数字（Bulls and Cows）游戏
*     你写下一个数字让你的朋友猜。每次他猜测后，你给他一个提示
*     告诉他有多少位数字和确切位置都猜对了（称为“Bulls”, 公牛）
*     有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）
*     你的朋友将会根据提示继续猜，直到猜出秘密数字
*     请写出一个根据秘密数字和朋友的猜测数返回提示的函数
*     用 A 表示公牛，用 B 表示奶牛
*     请注意秘密数字和朋友的猜测数都可能含有重复数字
* 
* 示例 1:
*     输入: secret = "1807", guess = "7810"
*     输出: "1A3B"
* 解释:
*     3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
* 
* 示例 2:
*     输入: secret = "1123", guess = "0111"
*     输出: "1A1B"
* 解释:
*     数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
* 
* 说明:
*     你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。
* 
* 解题思路：
*     根据题意建立映射即可
*/

class Solution {
public:
    string getHint(string secret, string guess) {        
        const char base = '0';
        int count = 0;
        string res;
        int shash[10] = {0};
        int ghash[10] = {0};
        for (int i=0; i<secret.size(); i++) {
            if (secret[i] == guess[i]) {
                count++;
            } else { /* skip belong to 'A' */
                shash[secret[i]-base]++;
                ghash[guess[i]-base]++;
            }
        }
        res += to_string(count); res += 'A';

        count = 0;
        for (int i=0; i<10; i++) {
            count += min(shash[i], ghash[i]);
        }
        res += to_string(count); res += 'B';

        return res;
    }
};