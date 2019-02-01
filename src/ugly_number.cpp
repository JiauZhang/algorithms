#include <iostream>

using namespace std;

bool isUglyNumber(int num)
{
	while (num%2 == 0)
		num /= 2;
	while (num%3 == 0)
		num /= 3;
	while (num%5 == 0)
		num /= 5;
	
	//cout << "num = " << num << endl;
	return (num == 1) ? true : false;
}

void Test(int num)
{
	//从输出可以看出，这句代码先执行函数isUglyNumber
	cout << "number = " << num << "-->" \
	     << "is ugly: " << isUglyNumber(num) << endl;
}

int getUglyNumber(int index)
{
	if (index <= 0)
		return -1;

	int count = 0;
	int num = 0;
	while (count < index) {
		++num;
		if (isUglyNumber(num))
			count++;
	}

	return num;
}

int min(int num1, int num2, int num3)
{
	int temp = (num1 > num2) ? num2 : num1;
	temp = (temp < num3) ? temp : num3;

	return temp;
}
//此方法速度比较快，但是浪费内存，用空间换时间
int _getUglyNumber_(int index)
{
	if (index <= 0)
		return -1;

	int *ugly_numbers = new int[index];
	int *f2 = ugly_numbers;
	int *f3 = ugly_numbers;
	int *f5 = ugly_numbers;
	ugly_numbers[0] = 1;
	int next_ugly_number = 1;

	while (next_ugly_number < index) {
		ugly_numbers[next_ugly_number] = min(*f2*2, *f3*3, *f5*5);
		while (*f2*2 <= ugly_numbers[next_ugly_number])
			f2++;
		while (*f3*3 <= ugly_numbers[next_ugly_number])
			f3++;
		while (*f5*5 <= ugly_numbers[next_ugly_number])
			f5++;

		next_ugly_number++;
	}
	
	delete[] ugly_numbers;
	return ugly_numbers[index-1];
}

int main(int argc, char **argv)
{
	int numbers[5] = {5, 15, 26, 30, 49};

	Test(numbers[0]);
	Test(numbers[1]);
	Test(numbers[2]);
	Test(numbers[3]);
	Test(numbers[4]);

	int num_idx = getUglyNumber(5);
	cout << "getUglyNumber num_idx: " << num_idx << endl;

	num_idx = _getUglyNumber_(5);
	cout << "_getUglyNumber_ num_idx: " << num_idx << endl;

	num_idx = getUglyNumber(25);
	cout << "getUglyNumber num_idx: " << num_idx << endl;

	num_idx = _getUglyNumber_(25);
	cout << "_getUglyNumber_ num_idx: " << num_idx << endl;

	return 0;
}
