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

#include <iostream>
#include <vector>

#include "dfs.hpp"
#include "bfs.hpp"

using namespace std;

void show_matrix(MatInt &matrix)
{
	for (auto x: matrix) {
		for (auto y: x) {
			cout << y << ' ';
		}
		cout << endl;
	}
}

int main()
{
	MatInt matrix = {
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 0 }, 
		{ 1, 1, 0, 1, 0, 1, 1, 0 }, 
		{ 0, 0, 0, 1, 0, 0, 1, 1 }, 
		{ 0, 0, 1, 1, 0, 0, 0, 0 }, 
		{ 0, 0, 0, 0, 0, 1, 0, 0 }, 
		{ 0, 0, 0, 0, 0, 1, 0, 0 }
	};
	
	show_matrix(matrix);
	
	cout << "dfs:" << endl;
	dfs(matrix, 2, matrix[0].size()-1, matrix.size()-1, matrix[0].size()-1);
	
	//cout << "bfs:" << endl;
	//bfs(matrix, 2, matrix[0].size()-1, matrix.size()-1, matrix[0].size()-1);
	//show_matrix(matrix);
	
	cout << "bfs_v2:" << endl;
	bfs_v2(matrix, 2, matrix[0].size()-1, matrix.size()-1, matrix[0].size()-1);
	show_matrix(matrix);
	
	return 0;
}
