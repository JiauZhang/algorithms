#include <iostream>

using namespace std;

void static_test()
{
	static int count = 0;
	cout << count++ << endl;
}

int main(int argc, char** argv)
{
	static_test();
	static_test();
	static_test();
	static_test();
	
	return 0;
} 
