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

using namespace std;

void find_greateat_sum_of_subarray(int *numbers, int length)
{
	if (numbers && length>0) {
		int *max_begin, *max_end;
		int max_sum = 0x80000000;
		int *cur_max_begin, *cur_max_end;
		int cur_sum = 0;
		cur_max_begin = cur_max_end = numbers;
		int i = 0;
		while(i < length) {
			if (cur_sum <= 0) {
				cur_sum = numbers[i];
				cur_max_begin = numbers + i;
				cur_max_end = cur_max_begin;				
			} else {
				cur_sum += numbers[i];
				cur_max_end = numbers + i;
			}
			if (max_sum < cur_sum) {
				max_sum = cur_sum;
				max_begin = cur_max_begin;
				max_end = cur_max_end;
			}
			i++;
		}
		cout << "max sum: " << max_sum << endl;
		for (;max_begin<=max_end; max_begin++) {
			cout << *max_begin << ' ';
		}
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	int numbers_test1[8] = {1, -2, 3, 10, -4, 7, 2, -5};
	int numbers_test2[8] = {-5, -2, 3, -10, -4, 7, 2, -5};
	int numbers_test3[8] = {-5, -2, -3, -10, -4, -7, -2, -5};
	int numbers_test4[8] = {5, 2, 3, 10, 4, 7, 2, 5};
	find_greateat_sum_of_subarray(numbers_test1, 8);
	find_greateat_sum_of_subarray(numbers_test2, 8);
	find_greateat_sum_of_subarray(numbers_test3, 8);
	find_greateat_sum_of_subarray(numbers_test4, 8);
	
	return 0;	
}
