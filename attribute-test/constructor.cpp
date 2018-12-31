#include <iostream>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debug(numbers, length) print_numbers(numbers, length)
#else
#define debug(numbers, length)
#endif

class constructor
{
public:
	int value;
	constructor(): value(10) {}
};
//又把 main 写错 ~ ~ ~ ~ ~ ~ ~ 
//错误提示：18 undefined reference to `WinMain@16' 
int main(int argc, char** argv)
{
	constructor* ctr = new constructor[5];
	char* ch = new char[5];
	cout << ctr->value << ' ';
	//第一种访问方法 
	for(int i=0; i<5; i++) {
		//ctr是作为数组名来用的，ctr[i]就是实例对象了，不再是指针了 
		/* 
		constructor ct = ctr[i];
		cout << ct.value << ' ';
		*/
		cout << ctr[i].value << ' ';
	}
	
	cout << endl;
	//第二种访问方法 
	constructor* end = ctr+5-1;
	cout << end->value << ' ';
	for(;end>=ctr;end--) {
		cout << end->value << ' ';
	}
	
	return 0;
}
