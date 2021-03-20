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

#include "bubble.hpp"
#include "quick.hpp"
#include "straight_insert.hpp"
#include "shell.hpp"
#include "straight_select.hpp"
#include "heap.hpp"
#include "merge.hpp"
#include "sort_link.hpp"

/*	���Ӷȣ�					ʱ�临�Ӷ�   �ռ临�Ӷ� 
	�������� 
		ð������(Bubble Sort):    O(n^2)��      O(1) 
		��������(Quick Sort):     O(nlogn)     O(nlogn)
	��������
		ֱ�Ӳ�������(Straight Insert Sort): O(n^2)    O(1) 
		shell����(Shell's Sort): O(N^1.3)    O(1)
	ѡ������
		ֱ��ѡ��(Straight Select Sort)   O(n^2)    O(1)
		������(Heap Sort):     O(nlogn)     O(1) 
*/

void showme(int *data, int length)
{
	for (int i=0; i<length; i++) {
		std::cout << data[i] << ' ';
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) 
{
	int data[17] = {6, 6, 38, 1, 9, -1, 6, 8, 4, 7, 9, 66, -5, 11, 64, 22, 44};
	const int nums = 9;
	//BubbleSort<int>::sort(data, nums);
	//showme(data, nums);
	/* nums = 13 �����Ϊ�Σ� */
	//QuickSort<int>::sort(data, nums);
	//showme(data, nums);
	
	//StraightInsertSort<int>::sort(data, nums);
	//showme(data, nums);
	
	//ShellSort<int>::sort(data, nums);
	//showme(data, nums);
	
	//StraightSelectSort<int>::sort(data, nums);
	//showme(data, nums);
	
	//HeapSort<int>::sort(data, nums);
	//showme(data, nums);
	
	// MergeSort<int>::sort(data, nums);
	// showme(data, nums);
	
	qsort_main();
	
	return 0;
}
