#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
	int random_num;
	// rand 函数产生 0-INT_MAX之间的随机数 
	for(int i=0; i<20; i++) {
		random_num = rand()%10;
		cout << random_num << ' '; 
	} 
		
	return 0;
}
