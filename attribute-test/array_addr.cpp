#include <iostream>

using namespace std;

int main()
{
	int test_a[5] = {1, 2, 3, 4, 5};
	int test_b[5] = {6, 7, 8, 9, 10};
	// 数组名就是指针 
	cout << "test_a addr: " << test_a << endl;
	cout << "test_b addr: " << test_b << endl;	
	// 对数组名取地址还是只想数组的指针 
	cout << "&test_a addr: " << &test_a << endl;
	cout << "&test_b addr: " << &test_b << endl;
	// 对数组指针取指针之后 + 1, 得到的是一个数组总字节数大小的偏移
	// 这说明 取地址符 改变了数组名的性质，使其变成了一个数组类型的指针 
	cout << "&test_a + 1 addr: " << &test_a + 1 << endl;
	cout << "&test_b + 1 addr: " << &test_b + 1 << endl;
	
	return 0;
}
