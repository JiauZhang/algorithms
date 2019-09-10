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
