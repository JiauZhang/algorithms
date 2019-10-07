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
#include <cstdlib>

using namespace std;

int random_in_range(int start, int end)
{
	if(start==end) {
		return start;
	} else {
		int index = rand()%(end-start) + start;	
		return index;	
	}
}

template <typename T>
void swap(T* v1, T* v2)
{
	T temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

int partition(int data[], int length, int start, int end)
{
	if(data==NULL || length<=0 || start<0 || end>=length) {
		return false;
	}	
	
	int index = random_in_range(start, end);
	swap<int>(&data[index], &data[end]);
	int small = start-1;
	for(index=start; index<end; ++index) {
		if(data[index]<data[end]) {
			++small;
			if(small!=index) {
				swap<int>(&data[index], &data[small]);
			}
		}
	}
	++small;
	swap<int>(&data[small], &data[end]);
	
	return small;
}

bool inline check_input(int *numbers, int length)
{
	if (!numbers || length <= 0)
		return false;
	return true;
}

bool check_more_than_half(int *numbers, int length, int number)
{
	int count = 0;
	for (int i=0; i<length; i++) {
		if (numbers[i] == number)
			count++;
	}
	if ((count * 2) > length)
		return true;
	return false;
}
//此方法会改变原数组的顺序 
int find_more_than_half_number_partition(int *numbers, int length)
{
	if (check_input(numbers, length)) {
		int start = 0;
		int end = length - 1;
		int middle = length >> 1;
		// start、end 为数组对应的 offset 
		int index = partition(numbers, length, start, end);
		while (index != middle) {
			if (index < middle) {
				start = index + 1;
				index = partition(numbers, length, start, end);
			} else {
				end = index - 1;
				index = partition(numbers, length, start, end);
			}
		}
		int res = numbers[middle];
		if (check_more_than_half(numbers, length, res))
			return res;
		else 
			return -1; 
	}
}
//此方法仅读取数组，不会改变原数组的顺序 
int find_more_than_halt_number_loop(int *numbers, int length)
{
	if (check_input(numbers, length)) {
		int res = numbers[0];
		int count = 1;
		for (int i=1; i<length; i++) {
			if (count == 0) {
				res = numbers[i];
				count = 1;
			} else if (res == numbers[i]) {
				count++;
			} else {
				count--;
			}				
		}
		if (check_more_than_half(numbers, length, res))
			return res;
		else 
			return -1; 
	}
}

int main(int argc, char** argv)
{
	int  numbers_test1[7] = {6, 8, 5, 5, 5, 5, 3};
	int  numbers_test2[7] = {6, 8, 0, 5, 5, 0, 3};
	int res = find_more_than_half_number_partition(numbers_test1, 7);
	cout << res << endl;
	res = find_more_than_half_number_partition(numbers_test2, 7);
	cout << res << endl;
	res = find_more_than_halt_number_loop(numbers_test1, 7);
	cout << res << endl;
	res = find_more_than_halt_number_loop(numbers_test2, 7);
	cout << res << endl;
	
	return 0;	
}
