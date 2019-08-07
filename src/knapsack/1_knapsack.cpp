#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	0-1 ±≥∞¸Œ Ã‚ 
*/

// total weight
#define W (18)
// total stuff
#define N (7)

int table[N+1][W+1] = {0};

int value[N+1] = {0, 12, 10, 8, 11, 14, 7, 9};
int weight[N+1] = {0, 4, 6, 5, 7, 3, 1, 6};

void knapsack_stuff()
{
	int k, w;
	
	for (k=1; k<=N; k++) {
		for (w=1; w<=W; w++) {
			if (weight[k] > w) {
				table[k][w] = table[k-1][w];
			} else {
				int value1 = table[k-1][w-weight[k]] + value[k];
				int value2 = table[k-1][w];
				
				if (value1 > value2) {
					table[k][w] = value1;
				} else {
					table[k][w] = value2;
				}
			}
		}
	}
}

void knapsack_weight()
{
	int k, w;
	
	for (w=1; w<=W; w++) {
		for (k=1; k<=N; k++) {
			if (weight[k] > w) {
				table[k][w] = table[k-1][w];
			} else {
				int value1 = table[k-1][w-weight[k]] + value[k];
				int value2 = table[k-1][w];
				
				if (value1 > value2) {
					table[k][w] = value1;
				} else {
					table[k][w] = value2;
				}
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
	knapsack_stuff();
	cout << "knapsack stuff first" << endl;	
	show_table();
	
	reset_table();
	
	knapsack_weight();
	cout << "knapsack weight first" << endl;
	show_table();
	
	show_track();
	reset_table();
	
	knapsack_optimization();
	cout << "knapsack optimization" << endl;
	show_table();
	
	return 0;
}
