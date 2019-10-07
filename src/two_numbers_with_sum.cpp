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

bool findNumbersWithSum(int *data, int length, int sum, int *num1, int *num2)
{	
	int *head = data, *tail = data + length -1;
	
	while (head < tail) {
		if (*head + *tail < sum)
			head++;
		else if (*head + *tail > sum)
			tail--;
		else if (*head + *tail == sum) {
			*num1 = *head;
			*num2 = *tail;
			return true;
		}			
	}
	
	return false;
}

int main(int argc, char **argv)
{
	int data[] = {1, 2, 4, 6, 8, 9, 11};
	int num1, num2;
	bool success = findNumbersWithSum(data, 7, 14, &num1, &num2);
	cout << "success: " << success << endl;
	if (success)
		cout << "num1: " << num1 << " num2: " << num2 << endl;
	
	return 0;
}
