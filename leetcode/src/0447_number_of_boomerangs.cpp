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
* https://leetcode-cn.com/problems/number-of-boomerangs
* 题目描述：
*     给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k)
*     其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）
*     找到所有回旋镖的数量。你可以假设 n 最大为 500
*     所有点的坐标在闭区间 [-10000, 10000] 中
* 
* 示例:
* 输入:
*     [[0,0],[1,0],[2,0]]
* 输出:
*     2
* 解释:
*     两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
* 
* 解题思路：
*     遍历计算一个点与其他点的距离，并统计相同距离的数量，同时计算结果
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int num=0;
        int dis=0;
        unordered_map<int,int> n;
        bool flag[500][500] = {false};
        int dis_buffer[500][500];
        for(int i=0;i<points.size();++i){
            n.clear();
            for(int j=0;j<points.size();++j){
                if(i!=j){
                    // 节省重复计算部分，因为(i, j)之间的距离与(j, i)之间的距离相等
                    if (!flag[j][i]){
                        dis=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                        dis_buffer[i][j] = dis;
                        flag[i][j] = true;
                    } else {
                        dis = dis_buffer[j][i];
                    }
                    //同长度线段计数
                    n[dis]++;
                    if (n[dis]>1)
                        //一次加入等长线段,增加2*(n-1)个回旋镖
                        num+=2*(n[dis]-1);
                }
            }
        }
        return num;
    }
};