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

	return (num == 1) ? true : false;
}

int main(int argc, char **argv)
{
	cout << isUglyNumber(12) << endl;
	return 0;
}
