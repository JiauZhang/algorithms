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
* https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
* 题目描述：
*     给定两个数组，编写一个函数来计算它们的交集
* 
* 示例 1:
*     输入: nums1 = [1,2,2,1], nums2 = [2,2]
*     输出: [2,2]
* 
* 示例 2:
*     输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
*     输出: [4,9]
* 
* 说明：
*     输出结果中每个元素出现的次数
*     应与元素在两个数组中出现的次数一致
*     我们可以不考虑输出结果的顺序
* 
* 进阶:
*     如果给定的数组已经排好序呢？你将如何优化你的算法？
*     如果 nums1 的大小比 nums2 小很多，哪种方法更优？
*     如果 nums2 的元素存储在磁盘上，磁盘内存是有限的
*     并且你不能一次加载所有的元素到内存中，你该怎么办？
* 
* 解题思路：
*     与题目 0349_intersection_of_two_arrays 类似
*     只不过这里使用的是 map 并且记录某个数出现的次数
*     其他都类似，具体见代码
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (!nums1.size() || !nums2.size())
            return {};

        map<int, int> m1, m2;
        make_map(nums1, m1);
        make_map(nums2, m2);

        vector<int> res;
        if (m1.size() < m2.size())
            intersect(m1, m2, res);
        else
            intersect(m2, m1, res);

        return res;   
    }

    void make_map(vector<int> &n, map<int, int> &m) {
        for (int i=0; i<n.size(); i++) {
            if (m.count(n[i]))
                m[n[i]]++;
            else
                m[n[i]] = 1;
        }
    }

    void intersect(map<int, int> &m1, map<int, int> &m2, vector<int> &ins) {
        /*        
        for (int i=0; i<m1.size(); i++) {  
            map_var[key_value], m1[i] is wrong usage!!!         
            if (m2.count(m1[i])) {
                int count = min(m2[m1[i]], m1[m1[i]]);
                for (int j=0; j<count; j++)
                    ins.push_back(m1[i]);
            }
        }
        */

        for (auto it=m1.begin(); it!=m1.end(); it++) {
            if (m2.count(it->first)) {
                int count = min(m2[it->first], it->second);
                for (int j=0; j<count; j++)
                    ins.emplace_back(it->first);
            }
        }
    }
};