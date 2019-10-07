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

class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && i-dq.front()>=k)
                dq.pop_front();
                
            while (!dq.empty() && nums[dq.back()]<=nums[i])
                dq.pop_back();
                
            dq.push_back(i);
            
            if (i>=k-1)
                res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};