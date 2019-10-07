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
class BubbleSort {
public:
	BubbleSort() {}
	~BubbleSort() {}
	
	static void sort(Dtype *data, int length);
};

template <typename Dtype>
void BubbleSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	int end = length;
	for (int i=0; i<length; i++) {
		for (int j=1; j<end; j++) {
			if (data[j-1] > data[j]) {
				Dtype temp = data[j-1];
				data[j-1] = data[j];
				data[j] = temp;
			}
		}
		end--;
	}
}
