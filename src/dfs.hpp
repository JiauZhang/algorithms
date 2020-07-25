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
	Ϊ�˷�ֹ���ظ���·�����뽫�߹���·��Ϊ������ֱ���� 1 
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
			��һ�������У���Ϊ��ǰ��ѯ�Ѿ�������
			���Ա��β�ѯ�ۼӵĴ�������������ָ�ԭʼֵ 
		*/ 		 
		dfs_cur_step--;
		
		return;
	} 
	// ��ֹ���ظ���· 
	matrix[x][y] = -1;
	
	dfs(matrix, x+1, y, ex, ey);
	dfs(matrix, x-1, y, ex, ey);
	dfs(matrix, x, y+1, ex, ey);
	dfs(matrix, x, y-1, ex, ey);
	
	matrix[x][y] = 0;
	
	dfs_cur_step--;
}

#endif
