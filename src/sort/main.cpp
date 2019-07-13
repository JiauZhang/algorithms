#include <iostream>

#include "bubble.hpp"
#include "quick.hpp"
#include "straight_insert.hpp"
#include "shell.hpp"
#include "straight_select.hpp"
#include "heap.hpp"
#include "merge.hpp"

/*	复杂度：					时间复杂度   空间复杂度 
	交换排序： 
		冒泡排序(Bubble Sort):    O(n^2)，      O(1) 
		快速排序(Quick Sort):     O(nlogn)     O(nlogn)
	插入排序：
		直接插入排序(Straight Insert Sort): O(n^2)    O(1) 
		shell排序(Shell's Sort): O(N^1.3)    O(1)
	选择排序：
		直接选择(Straight Select Sort)   O(n^2)    O(1)
		堆排序(Heap Sort):     O(nlogn)     O(1) 
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
	/* nums = 13 会出错，为何？ */
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
	
	MergeSort<int>::sort(data, nums);
	showme(data, nums);
	
	return 0;
}
