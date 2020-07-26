/*
* Copyright(c) 2020 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* SPDX-License-Identifier: GPL
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        unordered_map<int, int> hash;
        for (auto n: nums)
            hash[n]++;

        int res = 0;
        for (unordered_map<int, int>::iterator it=hash.begin(); it!=hash.end(); it++) {
            if (k) {
                int diff = it->first - k;
                if (hash.count(diff))
                    res += 1;
            } else if (it->second > 1){
                res += 1;
            }
        }

        return res;
    }
};