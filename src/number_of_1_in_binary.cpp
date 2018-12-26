#include <iostream>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debug(number) print_binary(number)
#else
#define debug(number)
#endif

void print_binary(int number)
{
	cout << '[' << number << "]: "; 
	unsigned int flag = 0x80000000, count = 0;
	while(count<32) {
		if(number&flag) {
			cout << '1';
		} else {
			cout << '0';
		}
  		 	
		flag = flag >> 1;
		count++;
	}
	cout << endl;
}
//传入 负数 时会陷入死循环 
int numbers_in_binary_v1(int number)
{
	int count = 0;
	while(number) {
		if(number&0x01) {
			count++;
		}
		number = number >> 1;
	}
	
	return count;
}

int numbers_in_binary_v2(int number)
{
	int res = 0, count = 0;
	int flag = 0x01;
	while(count<32) {
		if(number&flag)
			res++;
		flag = flag << 1;
	}
	
	return res;
}
//通过 -1 然后通过与原数据为与操作，把最右边的 1 去掉 
int numbers_in_binary_v3(int number)
{
	int res = 0;
	while(number) {
		res++;
		debug(number-1);
		debug(-1);
		number = (number-1) & number;
		debug(number);
	}
	
	return res;
}

int main(int argc, char** argv)
{
	signed int test = 0x80000002;
	//当数字为负数时，最高位的负数标识位 1 会传递下去，为了保持负数，最高位还会置 1
	//所有检查其中的 1 的个数需要通过外部移动标志位来完成，否则会陷入死循环 
	debug(test);
	debug(test>>1);
	debug(test>>5);
	
	cout << numbers_in_binary_v3(test);
	
	return 0;
}
