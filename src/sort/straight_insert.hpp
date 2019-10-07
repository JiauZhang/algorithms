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
class StraightInsertSort {
public:
	StraightInsertSort() {}
	~StraightInsertSort() {}
	
	static void sort(Dtype *data, int length);
};

template <typename Dtype>
void StraightInsertSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	for (int i=1; i<length; i++) {
		if (data[i] < data[i-1]) {
			Dtype temp = data[i];
			/*
			for (int j=i-1; j>=0; j--) {
				if (temp < data[j])
					data[j+1] = data[j];
				else {
					data[j+1] = temp;
					break;
				}
			}
			*/
			int j = i;
			// 当需要把temp换到头部时，此时无法执行 else分支
			// 必须把最后的交换放在尾部完成 
			for (; j>0; j--) {
				if (temp < data[j-1])
					data[j] = data[j-1];
				else
					break;
			}
			data[j] = temp;			
		}
	}
}
