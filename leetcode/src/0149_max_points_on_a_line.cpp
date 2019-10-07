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

/**
 * Given n points on a 2D plane, 
 * find the maximum number of points 
 * that lie on the same straight line.
 * 
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 
解题思路：
    暴力法遍历每个点，需要注意的问题有：
    1. 第二层循环要判断不能再和自己进行比较，即 if (i != j)
    2. 每个点和其他所有的点匹配，分三种情况：
        2.1 重合点
        2.2 垂直点
        2.3 正常斜率点
       除了重复点之外，每种情况情况之后都要进行max操作
       也可以完成一次遍历之后统一比较map和垂直中的情况
       这里的dup计数是公用的，因为都属于points[i]，所以在
       返回到外层循环时需要把dup的数加上
 
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int size = points.size();
        
        if (size == 0)
            return 0;
        
        if (size == 1)
            return 1;
        
        /*  */
        int ret = 0;
        for (int i=0; i<size; i++) {
            int cur_max = 1;
            int dup = 0;
            int vertical = 0;
            map<double, int> slope;
            
            for (int j=0; j<size; j++) {
                if (i != j) {
                    // 必须用double型，否则计算的斜率不准确
                    /*
                    int dx = points[i].x - points[j].x;
                    int dy = points[i].y - points[j].y;
                    */
                    double dx = points[i].x - points[j].x;
                    double dy = points[i].y - points[j].y;
                    
                    if (dx == 0 && dy == 0) { /* 记录与points[i]重合的点的数量 */
                        dup++;  
                    } else if (dx == 0) { /* 记录斜率无法表示，即垂直状态的点数量 */
                        if (vertical == 0) /* 这一步需要注意，当第一次计数时不是 ++ */
                            vertical = 2;  /* 而是直接等于 2 ，因为这个直线上有了两个点 */
                        else
                            vertical++;
                        cur_max = max(cur_max, vertical);                    
                    } else { /* 记录正常斜率上的点个数，使用map将斜率和点数联系在一起 */
                        double k = dy/dx;
                        if (slope[k] == 0)
                            slope[k] = 2;
                        else
                            slope[k]++;
                        cur_max = max(cur_max, slope[k]);
                    }                
                }
            }            
            ret = max(ret, cur_max+dup);
        }        
        return ret;
    }
};