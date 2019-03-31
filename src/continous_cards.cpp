#include <iostream>
#include <algorithm>

using namespace std;

void printNums(int *num, int length)
{
	cout << "nums: ";
	int i=0;
	while (length>0) {
		cout << *(num+i) << ' ';
		length--;
		i++;
	}
	cout << endl;
}

int compare(const void *arg1, const void *arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}

bool isContinous(int *num, int length)
{
	if (!num || length<1)
		return false;
		
	qsort(num, length, sizeof(int), compare);
	printNums(num, length);
	
	int numOfZero = 0;
	int numOfGap = 0;
//统计可用的 0 的个数，然后统计需要填充的空缺	
	for (int i=0; i<length&&num[i]==0; i++)
		numOfZero++;
		
	int small = numOfZero;
	int big = small + 1;
	
	while (big<length) {
		if (num[small]==num[big])
			return false;
			
		numOfGap += num[big] - num[small] - 1;
		small++;
		big++;
	}
	
	return (numOfGap > numOfZero) ? false : true;
}

int main(int argc, char **argv)
{
	int num1[7] = {1, 6, 8, 6, 7, 3, 9};
	cout << isContinous(num1, 7) << endl;
	int num2[7] = {1, 0, 3, 5, 7, 4, 8};
	cout << isContinous(num2, 7) << endl;
	int num3[7] = {1, 0, 3, 5, 7, 4, 6};
	cout << isContinous(num3, 7) << endl;
	
	return 0;
}
