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
* https://leetcode-cn.com/problems/relative-ranks
* 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌
* 前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”
* （"Gold Medal", "Silver Medal", "Bronze Medal"）
* 注：
*     分数越高的选手，排名越靠前
* 
* 示例 1:
*     输入: [5, 4, 3, 2, 1]
*     输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
* 解释: 
*     前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌”
*     余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可
*/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res;
        map<int, int> score_rank; // map auto sort the key value
        string ranks[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for (int i=0; i<nums.size(); i++)
            score_rank[nums[i]] = i;

        // stable_sort(nums.begin(), nums.end());
        // map had auto sort the 'nums' by 'key'_value
        res.resize(nums.size());
        // for (int i=0; i<nums.size()-3; i++) { nums.size return unsigned int
        // for (int i=0; i<(int)nums.size()-3; i++) {
        //     res[score_rank[nums[i]]] = to_string(nums.size()-i);
        // }
        int i=0;
        for (map<int, int>::iterator it=score_rank.begin(); it!=score_rank.end(); it++) {
            res[score_rank[it->first]] = to_string(nums.size()-i);
            i++;
        }
        // for (int i=0; i<3&&i<nums.size(); i++) {
        //     res[score_rank[nums[nums.size()-1-i]]] = ranks[i];
        // }
        i = 0;
        for (map<int, int>::reverse_iterator rit=score_rank.rbegin(); i<3&&rit!=score_rank.rend(); rit++) {
            res[score_rank[rit->first]] = ranks[i++];
        }

        return res;
    }
};