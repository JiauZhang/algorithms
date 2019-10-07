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

#ifndef __BFS_HPP__
#define __BFS_HPP__

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define MatInt vector<vector<int>>
#define MatBool vector<vector<bool>>

int bfs_step = 666666;
int bfs_cur_step = 0;

struct position {
	int x;
	int y;
};

deque<position> dq;

struct Step {
	int x, y;
	int step;
}; 

deque<Step> dq_v2;

/*
	为了防止走重复的路，必须将走过的路置为，这里直接置 1 
*/

void bfs(MatInt &matrix, int x, int y, int ex, int ey)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return;
	
	dq.push_back({x, y});

	while (dq.size()) {
		bfs_cur_step++;
		
		int n = dq.size();
		while (n) {
			n--;
			
			struct position pos = dq.front();
			dq.pop_front();
				
			if (pos.x == ex && pos.y == ey) {
				if (bfs_cur_step<bfs_step) {
					cout << "step: " << bfs_cur_step << endl;
					bfs_step = bfs_cur_step;
				}
				bfs_cur_step--;
				continue;
			}
		
			int x_1 = pos.x - 1;
			int x_2 = pos.x + 1;
			int y_1 = pos.y - 1;
			int y_2 = pos.y + 1;
			
			if (x_1>=0 && !matrix[x_1][pos.y]) {
				dq.push_back({x_1, pos.y});
				matrix[x_1][pos.y] = -1;
			}
			
			if (x_2<matrix.size() && !matrix[x_2][pos.y]){
				dq.push_back({x_2, pos.y});
				matrix[x_2][pos.y] = -1;
			}
				
			if (y_1>=0 && !matrix[pos.x][y_1]) {
				dq.push_back({pos.x, y_1});
				matrix[pos.x][y_1] = -1;
			}
				
			if (y_2<matrix[0].size() && !matrix[pos.x][y_2]) {
				dq.push_back({pos.x, y_2});
				matrix[pos.x][y_2] = -1;
			}				
				
			matrix[pos.x][pos.y] = bfs_cur_step;
		} 	
	}
}

void bfs_v2(MatInt &matrix, int x, int y, int ex, int ey)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return;
	
	dq_v2.push_back({x, y, 0});

	while (dq_v2.size()) {		
		int posx = dq_v2.front().x;
		int posy = dq_v2.front().y;
		int step = dq_v2.front().step;
		dq_v2.pop_front();
			
		if (posx == ex && posy == ey) {
			if (bfs_cur_step<bfs_step) {
				// cout << "step: " << bfs_cur_step << endl;
				cout << "step: " << step << endl;
				bfs_step = bfs_cur_step;
			}
			bfs_cur_step--;
			continue;
		}
	
		int x_1 = posx - 1;
		int x_2 = posx + 1;
		int y_1 = posy - 1;
		int y_2 = posy + 1;
		
		if (x_1>=0 && !matrix[x_1][posy]) {
			dq_v2.push_back({x_1, posy, step+1});
			matrix[x_1][posy] = step+1;
		}
		
		if (x_2<matrix.size() && !matrix[x_2][posy]){
			dq_v2.push_back({x_2, posy, step+1});
			matrix[x_2][posy] = step+1;
		}
			
		if (y_1>=0 && !matrix[posx][y_1]) {
			dq_v2.push_back({posx, y_1, step+1});
			matrix[posx][y_1] = step+1;
		}
			
		if (y_2<matrix[0].size() && !matrix[posx][y_2]) {
			dq_v2.push_back({posx, y_2, step+1});
			matrix[posx][y_2] = step+1;
		}				
			
		matrix[posx][posy] = step;
	}
}

#endif
