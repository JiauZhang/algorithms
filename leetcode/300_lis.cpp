#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
void solution_1(vector<int> &array)
{
	if (array.size() == 0)
		return;
	
	// 记录对应位置的 序列长度，初始化为 1，因为至少包含自己 
	vector<int> lis(array.size());
	vector<vector<int> > lis_array(array.size()); 	
	for (int i=0; i<array.size(); i++) {
		lis[i] = 1;
		vector<int> temp;
		temp.push_back(array[i]);
		lis_array[i] = temp;
	}
	// 遍历每个元素 
	for (int i=0; i<array.size(); i++) {
		for (int j=0; j<i; j++) {
			// 基于第 i 个元素前边已经算出排序数量的
			// 找出与当前元素组成排序的最大排序数 
			if (array[j] < array[i]) {
				/*
				lis[i] = max(lis[i], lis[j]+1);
				*/
				
				if (lis[i] < lis[j]+1) {
					lis_array[i].clear();
					lis_array[i] = lis_array[j];
					lis_array[i].push_back(array[i]);
					lis[i] = lis[j]+1;
				}
				
			}
		}
	}
	
	int index = 1;
	for (int i=0; i<array.size(); i++) {
		if (lis[i] > lis[index])
			index = i;
	}
	
	cout << "max lis: " << lis[index] << endl;
	cout << "sequence:\n";
	
	for (int i=0; i<lis_array[index].size(); i++) {
		cout << lis_array[index][i] << ' ';
	}
	
	cout << endl;
}


// O(nlogn)
void solution_2(vector<int> &array)
{
	if (array.size() == 0)
		return;
	
	// 错误的语法，这样 temp 的 size 直接就非零了，在push_back的时候是从
	// size 之后开始的 	
	//vector<int> temp(array.size() / 2);
	vector<int> temp; 
	temp.push_back(array[0]);
	for (int i=0; i<array.size(); i++) {
		if (array[i] > temp.back()) {
			temp.push_back(array[i]);
		} else {
			auto it = lower_bound(temp.begin(),temp.end(), array[i]);
			*it = array[i];
		}
	}
	
	cout << "solution 2: " << temp.size() << endl;
}

int main(int argc, char **argv)
{
	vector<int> array;
	
	array.push_back(7);
	array.push_back(1);
	array.push_back(5);
	array.push_back(4);
	array.push_back(3);
	array.push_back(2);
	array.push_back(9);
	array.push_back(6);
	array.push_back(8);
	array.push_back(10);
	array.push_back(17);
	array.push_back(11);
	array.push_back(55);
	array.push_back(54);
	array.push_back(13);
	array.push_back(24);
	array.push_back(29);
	array.push_back(56);
	array.push_back(18);
	array.push_back(11);
	
	solution_1(array);
	solution_2(array);
	
	return 0;
} 
