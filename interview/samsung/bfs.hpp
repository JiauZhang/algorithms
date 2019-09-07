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

/*
	为了防止走重复的路，必须将走过的路置为，这里直接置 1 
*/

void do_bfs(MatInt &matrix, int x, int y, int ex, int ey)
{
	if (x>=matrix.size() || y>=matrix[0].size()
		|| x<0 || y<0 || matrix[x][y]
	)
		return;
		
	
}

void bfs(MatInt &matrix, int x, int y, int ex, int ey)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return;
	
	dq.push_back({x, y});
	//matrix[x][y] = -1;

	while (dq.size()) {
		struct position pos = dq.front();
		dq.pop_front();
		
		if (matrix[pos.x][pos.y])
			continue;
		
		bfs_cur_step++;
		if (x == ex && y == ey) {
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
		
		if (x_1>=0 && !matrix[x_1][y])
			dq.push_back({x_1, y});
		if (x_2<matrix.size() && !matrix[x_2][y])
			dq.push_back({x_2, y});
		if (y_1>=0 && !matrix[x][y_1])
			dq.push_back({x, y_1});
		if (y_2<matrix[0].size() && !matrix[x][y_2])
			dq.push_back({x, y_2});
	
		matrix[pos.x][pos.y] = bfs_cur_step;
		bfs_cur_step--;
	}
}

#endif
