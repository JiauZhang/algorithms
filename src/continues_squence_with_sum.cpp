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

void printRange(int small, int big)
{
	cout << "squence: " << endl;
	while(small<=big) {
		cout << small++ << ' ';
	}
	cout << endl;
}

void findNumbersWithSum(int sum)
{	
	int small = 1;
	int big = 2;
	int end = (sum + 1) / 2;
	int curSum = small + big;
	
	while (small < end) {
		if (curSum == sum) {
			printRange(small, big);
			big++;
			curSum += big;
		}
		
		if (curSum > sum) {
			curSum -= small;
			small++;
		}
		
		if (curSum < sum) {
			big++;
			curSum += big;
		}
	}
	
}

int main(int argc, char **argv)
{
	cout << "Test 1: " << endl;
	findNumbersWithSum(0);
	
	cout << "Test 2: " << endl;
	findNumbersWithSum(1);
	
	cout << "Test 3: " << endl;
	findNumbersWithSum(3);
	
	cout << "Test 4: " << endl;
	findNumbersWithSum(15);
	
	cout << "Test 5: " << endl;
	findNumbersWithSum(30);
	
	return 0;
}
