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

int main(int argc, char **argv)
{
	int numbers[5] = {5, 15, 26, 30, 49};

	Test(numbers[0]);
	Test(numbers[1]);
	Test(numbers[2]);
	Test(numbers[3]);
	Test(numbers[4]);

	int num_idx = getUglyNumber(5);
	cout << "num_idx: " << num_idx << endl;

	return 0;
}
