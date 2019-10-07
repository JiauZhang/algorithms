#include <iostream>
#include <vector>

using namespace std;

/*
	vector<T>::reserve is used to alloc memory
	vector<T>::resize is reset the occpied memory pointer
*/

int main(int argc, char** argv) {
	vector<int> test;
	cout << "test size: " << test.size() << endl;
	cout << "test cap: " << test.capacity() << endl;
	
	test.reserve(10);
	
	cout << "test size: " << test.size() << endl;
	cout << "test cap: " << test.capacity() << endl;
	
	test.push_back(10);
	test.push_back(11);
	
	cout << "test size: " << test.size() << endl;
	cout << "test cap: " << test.capacity() << endl;
	
	test.resize(6);
	test.push_back(66);
	
	cout << "test size: " << test.size() << endl;
	cout << "test cap: " << test.capacity() << endl;
	
	return 0;
}
