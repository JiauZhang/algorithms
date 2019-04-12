#include <iostream>

using namespace std;
//加法可以分解为二进制的 (异或，不进位加) + (位与，进位) 
int add_ops(int num1, int num2)
{
	int carry = 0;
	int sum = 0;
	
	do {
		//不进位加 
		sum = num1 ^ num2;
		//进位位
		carry = (num1 & num2) << 1;
		//进入下一个循环，如果有仅为则将进位与和相加 
		num1 = sum;
		num2 = carry; 
	} while (carry);
	
	return sum; 
}

void swap_ops(int a, int b)
{
	a = a + b; // a = a^b;
	b = a - b; // b = a^b;
	a = a - b; // a = a^b;
} 

int main(int argc, char **argv)
{
	cout << add_ops(10, 15) << endl;
	cout << add_ops(15, 13) << endl;
	cout << add_ops(66, 99) << endl;
	cout << add_ops(0, -99) << endl;
	cout << add_ops(-66, 99) << endl;
} 
