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
