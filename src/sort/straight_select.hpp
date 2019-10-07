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

template <typename Dtype>
class StraightSelectSort {
public:
	StraightSelectSort() {}
	~StraightSelectSort() {}
	
	static void sort(Dtype *data, int length);
};

template <typename Dtype>
void StraightSelectSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	Dtype min;
	int start = 0, min_index;
	while (start < length) {
		min = data[start];
		min_index = start;
		for (int i=start; i<length; i++) {
			if (min > data[i]) {
				min = data[i];
				min_index = i;
			}
		}
		if (start != min_index) {
			Dtype temp = data[start];
			data[start] = min;
			data[min_index] = temp;
		}
		start++;
	}	
}
