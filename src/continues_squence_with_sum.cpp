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
