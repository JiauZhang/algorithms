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

#include "quick_sort.hpp"
#include "selection_sort.hpp"

using namespace std;

int main()
{
#define LENGTH 15
	
	int nums[LENGTH] = {5, 3, 2, 7, 3, 6, 0, 5, 10, 1, -5, 15, -15, 11, 8};

	//quick_sort(nums, 0, LENGTH-1);	
	selection_sort(nums, 0, LENGTH-1);
	
	for (int i=0; i<LENGTH; i++)
		cout << nums[i] << ' ';

	cout << endl;
	
	return 0;
} 
