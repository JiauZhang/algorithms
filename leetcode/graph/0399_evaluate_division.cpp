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
 *     1. 使用 unordered_map 统计不同变量的个数，并赋予 id
 *     2. 建立每个独立变量的所有边
 *     3. 起始变量设置为单位 1，广度优先遍历所有的边
 */

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> ids;
        int id = 0;
        for (auto eq: equations) {
            for (auto &s: eq) {
                if (!ids.count(s)) {
                    ids[s] = id++;
                }
            }
        }

        vector<vector<pair<int, double>>> edges(id);
        for (int i=0; i<equations.size(); i++) {
            auto &eq = equations[i];
            int idx = ids[eq[0]], idy = ids[eq[1]];
            edges[idx].emplace_back(make_pair(idy, values[i]));
            edges[idy].emplace_back(make_pair(idx, 1. / values[i]));
        }

        vector<double> rets;
        for (auto &q: queries) {
            if (ids.count(q[0]) && ids.count(q[1])) {
                int idx = ids[q[0]], idy = ids[q[1]];
                vector<double> buffer(id, -1.0);
                buffer[idx] = 1.;
                queue<int> qids;
                qids.push(idx);

                while (!qids.empty() && buffer[idy] < 0) {
                    int qid = qids.front();
                    qids.pop();

                    for (auto &e: edges[qid]) {
                        if (buffer[e.first] < 0) {
                            buffer[e.first] = e.second * buffer[qid];
                            qids.push(e.first);
                        }
                    }
                }

                rets.push_back(buffer[idy]);
            } else {
                rets.push_back(-1);
            }
        }

        return rets;
    }
};