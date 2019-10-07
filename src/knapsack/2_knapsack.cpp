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
#include <algorithm>

using namespace std;

/*
	完全背包问题 
*/

// total weight
#define W (18)
// total stuff
#define N (7)

int table[N+1][W+1] = {0};

int value[N+1] = {0, 12, 10, 8, 11, 14, 7, 9};
int weight[N+1] = {0, 4, 6, 5, 7, 3, 1, 6};

void knapsack()
{
	int n, w;
	
	for (n=1; n<=N; n++) {
		for (w=1; w<=W; w++) {
		// for (w=weight[n]; w<=W; w++) {
			//int k = weight[n] / w;
			/*
			if (weight[n] <= w) {
				table[n][w] = max(table[n-1][w-weight[n]] + value[n], table[n-1][w]);
			} else {
				table[n][w] = table[n-1][w];
			}
			*/
			
			table[n][w] = table[n-1][w];
			if (weight[n] <= w) {
				table[n][w] = max(table[n-1][w-weight[n]] + value[n], table[n][w]);
			}		
		}
	}
}
void knapsack_optimization()
{
	int k, w;
	
	for (k=1; k<=N; k++) {
		for (w=W; w>=1; w--) {
			if (weight[k] > w) {
				table[0][w] = table[0][w];
			} else {
				int value1 = table[0][w-weight[k]] + value[k];
				int value2 = table[0][w];
				
				if (value1 > value2) {
					table[0][w] = value1;
				} else {
					table[0][w] = value2;
				}
			}
		}
	}
}

void show_table()
{
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=W; j++) {
			cout << ' ' << table[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << endl;
}

void show_track()
{
	vector<pair<int, int>> track;
	int i=N, j=W;
	cout << "track is: ";
	while (i>0) {
		if (table[i][j] == table[i-1][j]) {
			i--;
		} else {
			track.push_back(make_pair(i, j));
			int w = weight[i];
			j -= w;
			i--;
		}
	}
	
	for (int i=0; i<track.size(); i++) {
		cout << track[i].first << ' ';
	}
	
	cout << endl;
}

void reset_table()
{
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=W; j++) {
			table[i][j] = 0;
		}
	}	
}

int main()
{
	knapsack();
	cout << "knapsack stuff first" << endl;	
	show_table();
	
	reset_table();
	
	knapsack_optimization();
	cout << "knapsack optimization" << endl;
	show_table();
	
	return 0;
}
