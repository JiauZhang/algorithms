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
