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
