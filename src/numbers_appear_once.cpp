#include <iostream>

using namespace std;

void find_numbers_appear_once(int *data, int length, int *num1, int *num2)
{
	if (!data)
		return;
	//求出两个只出现一次的数的异或结果，因为它俩不同，所以异或一定不为零	
	int temp = 0;
	for (int i=0; i<length; i++) {
		temp ^= *(data+i);
	}
	//找出第一个bit为1的位，这个位的这两个数的二进制表示一定不同 
	int index = 0;
	while ((temp & 0x01 == 0) && (index < 8 * sizeof(int))) {
		temp >>= 1;
		index++;
	}
	//以此对数组进行分组，因为要求空间复杂度为O(1)，所以变分组边使用 
	for (int i=0; i<length; i++) {
		if (*(data+i) & (1 << index))
			*num1 ^= *(data+i);
		else
			*num2 ^= *(data+i);
	}
}

int main(int argc, char **argv)
{
	int data[] = {1,1,2,2,3,5,5,4,6,6};
	int num1 = 0, num2 = 0;
	find_numbers_appear_once(data, 10, &num1, &num2);
	cout << "num1: " << num1 << "\nnum2: " << num2 << endl;
	
	return 0;
}
