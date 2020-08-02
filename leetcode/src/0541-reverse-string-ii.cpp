/*
 * Copyright(c) 2020 Jiau Zhang
 * For more information see <https://github.com/JiauZhang/algorithms>
 * 
 * SPDX-License-Identifier: GPL
 */

/*
 * 解题思路：首先根据题意对数组以 k 为单位进行划分
 * 仅对第奇数个 k 的单位内的数组进行翻转
 * 另外就是需要检查边界，因为可能最后一个 k 会超过字符串最大长度
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        if (k<=0 || s.size()<=1)
            return s;

        bool flag = true;
        for (int i=0; i<s.size(); i+=k) {
            if (flag) {
                int start = i;
                int end = i+k;
                end = end > s.size() ? s.size() : end;
                swap(s, start, end);
            }

            flag = !flag;
        }

        return s;
    }

    void swap(string &s, int start, int end) {
        for (int i=0; i<(end-start)/2; i++) {
            int left = start+i;
            int right = end - 1 - i;
            unsigned char c = s[left];
            s[left] = s[right];
            s[right] = c;
        }
    }
};