/*
* Copyright(c) 2021 Jiau Zhang
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
 * 解题思路：
 * 第一种：先排个子高
 *     排序第一关键字是身高，身高相同的情况下使用第二关键字的降序排列
 *     第二关键字之所以降序是因为需要先用第二关键字大的把其前边的空间确定下来
 *     这里使用的是 vector::insert 的方法，每次插入都从 begin 开始，而 begin 对应的是第一关键字最小的元素
 *     insert 时基于第二关键字确定插入位置，因为从大到小排序的，而当前数组中第一个又比没有插入的都大
 *     所以只需要根据第二个关键字就知道放哪里了，此方法的缺点就是 insert 会开辟新空间，比较慢
 * 第二种：先排低个子
 *     其实就是第一种的反向操作，不变的就是需要把第二关键字大的降序排，即第一关键字相同的情况下
 *     需要先访问第二关键字大的那个，因为需要用它来把空间确定下来
 *     最后就是从小到大访问，第二关键字是多少就留出多少个位置给比自己大的占用就行了
 */

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &x, vector<int> &y) {
            return x[0] > y[0] || (x[0] == y[0] && x[1] < y[1]);
        });

        vector<vector<int>> ret;
        for (auto &p: people) {
            ret.insert(ret.begin()+p[1], p);
        }

        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &x, vector<int> &y) {
            return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
        });
        // [[4,4],[5,2],[5,0],[6,1],[7,1],[7,0]]
        vector<vector<int>> ret(people.size());
        for (auto &p: people) {
            int count = p[1];
            for (int i=0; i<people.size(); i++) {
                if (ret[i].empty()) {
                    if (!count) {
                        ret[i] = p;
                        break;
                    } else {
                        count--;
                    }
                }
            }
        }

        return ret;
    }
};