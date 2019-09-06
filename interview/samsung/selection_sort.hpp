#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

/*
	O(N^2)
*/

void selection_sort(int nums[], int start, int end)
{
	if (start>=end)
		return;

	int min, index;
	for (int i=0; i<=end; i++) {
		min = nums[i];
		index = i;
		for (int j=i; j<=end; j++) {
			if (nums[j] < min) {
				min = nums[j];
				index = j;
			}
		}
		
		nums[index] = nums[i];
		nums[i] = min;
	}
}

#endif
