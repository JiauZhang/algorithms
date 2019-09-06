#ifndef __QUICK_SORT_HPP__
#define __QUICK_SORT_HPP__

/*
	O(NlogN)
*/

void quick_sort(int nums[], int start, int end)
{
	if (start>=end)
		return;

	int left = start, right = end;
	int ref = nums[start];	
	while (left<right) {
		while (left<right && nums[right]>=ref)
			right--;
		nums[left] = nums[right];
		
		while (left<right && nums[left]<=ref)
			left++;
		nums[right] = nums[left];
	}
	
	nums[left] = ref;
	quick_sort(nums, start, left-1);
	quick_sort(nums, left+1, end);
}

#endif
