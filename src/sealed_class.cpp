#include <iostream>

using namespace std;
//把构造函数私有化 
class sealedClass1 {
public:
	static sealedClass1 *getInstance() {
		return new sealedClass1();
	}
	
	static void deleteInstance(sealedClass1 *pInstance) {
		delete pInstance;
	}
private:
	sealedClass1() {cout << "sealedClass1" << endl;}
	~sealedClass1() {cout << "~sealedClass1" << endl;}
};
//利用虚拟继承
template <typename T>
class makeSealed {
	friend T;
private:
	makeSealed() { cout << "makeSealed" << endl;}
	~makeSealed() {cout << "~makeSealed" << endl;}
}; 

class sealedClass2: virtual public makeSealed<sealedClass2> {
public:
	sealedClass2() {cout << "sealedClass2" << endl;}
	~sealedClass2() {cout << "~sealedClass2" << endl;}
};
//由于sealedClass2是虚继承makeSealed的
//所以当Try继承sealedClass2时会直接跳过它
//直接执行makeSealed的构造函数，所以编译器会报错！
/* 
class Try: public sealedClass2 {
public:
	Try() {cout << "Try" << endl;}
	~Try() {cout << "~Try" << endl;}
};
*/
int main(int argc, char **argv)
{
	sealedClass1 *test1 = sealedClass1::getInstance();
	sealedClass1::deleteInstance(test1);
	sealedClass2 test2;
}
