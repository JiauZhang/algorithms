#ifndef __DFS_HPP__
#define __DFS_HPP__

#include <iostream>
#include <vector>

using namespace std;

#define MatInt vector<vector<int>>
#define MatBool vector<vector<bool>>

int dfs_step = 666666;
int dfs_cur_step = 0;

/*
	为了防止走重复的路，必须将走过的路置为，这里直接置 1 
*/

void dfs(MatInt &matrix, int x, int y, int ex, int ey)
{
	if (matrix.size() == 0 || matrix[0].size() == 0)
		return;
	
	if (x>=matrix.size() || y>=matrix[0].size()
		|| x<0 || y<0 || matrix[x][y]
	)
		return;
	
	dfs_cur_step++;
	if ((x == ex) && (y == ey)) {
		if (dfs_cur_step < dfs_step) {
			cout << "step: " << dfs_cur_step << endl;
			dfs_step = dfs_cur_step;
		}
		/* 
			这一步必须有，因为当前查询已经返回了
			所以本次查询累加的次数必须减掉，恢复原始值 
		*/ 		 
		dfs_cur_step--;
		
		return;
	} 
	// 防止走重复的路 
	matrix[x][y] = -1;
	
	dfs(matrix, x+1, y, ex, ey);
	dfs(matrix, x-1, y, ex, ey);
	dfs(matrix, x, y+1, ex, ey);
	dfs(matrix, x, y-1, ex, ey);
	
	matrix[x][y] = 0;
	
	dfs_cur_step--;
}

#endif
