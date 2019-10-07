#include <iostream>

using namespace std;

struct BF{
	int use:4;
	int num:4;
};

int main()
{
	BF bf;
	bf.num = 0;
	bf.use = 0;
	
	cout << "sizeof BF: " << sizeof(bf) << endl;
	
	bf.num++;
	bf.use++;
	
	cout << "bf.num: " << bf.num << endl;
	cout << "bf.use: " << bf.use << endl;
	
	bf.num++;
	bf.use++;
	
	cout << "bf.num: " << bf.num << endl;
	cout << "bf.use: " << bf.use << endl;

	bf.num = 0;
	bf.use = 0;
	cout << "OOM test #1" << endl;
	//bf.num += 259;
	bf.use = 15;
	
	cout << "bf.num: " << bf.num << endl;
	cout << "bf.use: " << bf.use << endl;
	
	bf.num = 0;
	bf.use = 0;
	cout << "OOM test #2" << endl;
	bf.num = 8;
	//bf.use++;
	
	cout << "bf.num: " << bf.num << endl;
	cout << "bf.use: " << bf.use << endl;
	
	return 0;
}
