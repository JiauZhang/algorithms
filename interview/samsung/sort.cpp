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
