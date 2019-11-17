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
* https://leetcode-cn.com/problems/binary-watch
* 题目描述：
*     二进制手表顶部有 4 个 LED 代表小时（0-11）
*     底部的 6 个 LED 代表分钟（0-59）
*     每个 LED 代表一个 0 或 1，最低位在右侧
*     例如，上面的二进制手表读取 “3:25”
*     给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间
* 
* 案例:
* 输入: 
*     n = 1
* 返回: 
*     ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02",
*     "0:04", "0:08", "0:16", "0:32"] 
* 
* 注意事项:
*     输出的顺序没有要求
*     小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”
*     分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的
*     应为 “10:02”
* 
* 解题思路：
*     该题本质上是一个组合问题，只要找出所有的组合再解码成时间即可
*/

class Solution {
public:
    const static unsigned int length = 10;
    const int elements[length] = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    const int decodes[length] = {
        1, 2, 4, 8, 1, 2, 4, 8, 16, 32
    };

    vector<string> readBinaryWatch(int num) {
        if (num <= 0)
            return {"0:00"};

        vector<int> comb; comb.resize(num);
        vector<string> res;
        combination(res, comb, 0, 0, num);

        return res;
    }

    void combination(vector<string> &s, vector<int> &c, int level, int begin, int num) {   
        if (level == num) {
            decode(s, c);
            return;
        }

        for (int i=begin; i<=length-num+level; i++) {
            c[level] = elements[i];
            combination(s, c, level+1, i+1, num);
        }
    }

    void decode(vector<string> &s, vector<int> &c) {
        int hour = 0, minute = 0;
        for (int i=0; i<c.size(); i++) {
            if (c[i] < 4)
                hour += decodes[c[i]];
            else
                minute += decodes[c[i]];
        }

        if (hour>11 || minute>59)
            return;
        
        string time(to_string(hour));
        time += ':';
        if (minute < 10)
            time += '0';
        time += to_string(minute);

        s.push_back(time);
    }

};