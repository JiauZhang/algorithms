#include <iostream>

using namespace std;

class VoidClass {
	// nothing
};

class OneFuncClass {
	void foo() { cout << "something" << endl; }
}; 

class VirtualClass {
	virtual foo() {}
};

class NormalClass{
	void foo() {}
	virtual vfoo() {}
	int num;
};

int main()
{
	cout << "VoidClass: " << sizeof(VoidClass) << endl;
	cout << "OneFuncClass: " << sizeof(OneFuncClass) << endl;
	cout << "VirtualClass: " << sizeof(VirtualClass) << endl;
	cout << "NormalClass: " << sizeof(NormalClass) << endl;
	
	return 0;
}
