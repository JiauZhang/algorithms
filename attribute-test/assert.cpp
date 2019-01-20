#include <iostream>
#include <cassert>

using namespace std;

bool assert_test(bool bl)
{
	cout << "assert_test: " << bl << endl;
	
	return bl;
}

int main(int argc, char **argv)
{
	//assert中如果放的是函数，那么它会先执行函数，然后根据返回值
	//判断是否assert成功了 
	assert(assert_test(true));
	assert(assert_test(false));
	
	return 0;
}
