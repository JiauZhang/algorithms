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

bool verify_sequence_of_bst(int sequence[], int length)
{
	if (sequence && length > 0) {
		if (length <= 2)
			return true;
		int root_value = sequence[length-1];
		int index_left = 0;
		//找到第一个 ＞ root_value 的值 
		while (sequence[index_left] < root_value && index_left < length-1)
			index_left++;
		
		int index_right = index_left;
		//检查右子树是否全部满足 > root_value	
		while(index_right < length-1) {
			if (sequence[index_right] < root_value)
				return false;
			index_right++;
		}
		
		bool left = true;
		if (index_left > 0) 
			left = verify_sequence_of_bst(sequence, index_left);
		
		bool right = true;
		if (index_left < length - 1)
			right = verify_sequence_of_bst(sequence + index_left, length - 1 - index_left);
		
		return (left && right);
	} else {
		return false;
	}
}

void test(int sequence[], int length)
{
	bool res = verify_sequence_of_bst(sequence, length);
	cout << (res==1?"是":"否") << endl;	
}

int main(int argc, char** argv)
{
	int sequence_test1[7] = {5, 7, 6, 9, 11, 10, 8};
	int sequence_test2[4] = {7, 4, 6, 5};
	
	test(sequence_test1, 7);
	test(sequence_test2, 4);
	
	return 0;
}
