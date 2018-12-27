#include <iostream>

using namespace std;

class singleton_v1
{
public:
	int data_test;
	static singleton_v1& getInstance() {
		static singleton_v1 singleton;
		return singleton;
	}
private:	
	singleton_v1() {}
};

int main(int argc, char** argv)
{
	//使用返回值得引用才会发生使用的是同一个类实例 
	cout << "mysingleton1: ";
	singleton_v1& mysingleton1 = singleton_v1::getInstance();
	mysingleton1.data_test = 0;
	cout << mysingleton1.data_test << ' ';
	mysingleton1.data_test++;
	cout << mysingleton1.data_test << '\n';
	
	cout << "mysingleton2: ";
	singleton_v1& mysingleton2 = singleton_v1::getInstance();
	cout << mysingleton2.data_test << ' ';
	mysingleton2.data_test++;
	cout << mysingleton2.data_test << '\n';
	
	//直接将返回值赋值给声明的类变量，并不会使用同一个类的实例 
	cout << "mysingleton3: ";
	singleton_v1 mysingleton3 = singleton_v1::getInstance();
	cout << mysingleton3.data_test << ' ';
	mysingleton3.data_test++;
	cout << mysingleton3.data_test << '\n';
	
	cout << "mysingleton4: ";
	singleton_v1 mysingleton4 = singleton_v1::getInstance();
	cout << mysingleton4.data_test << ' ';
	mysingleton4.data_test++;
	cout << mysingleton4.data_test << ' ';
	cout << mysingleton4.data_test << ' ';
	mysingleton4.data_test++;
	cout << mysingleton4.data_test << '\n';

	cout << "mysingleton1: " << mysingleton1.data_test << '\n';
	cout << "mysingleton2: " << mysingleton2.data_test << '\n';	
	cout << "mysingleton3: " << mysingleton3.data_test << '\n';
	cout << "mysingleton4: " << mysingleton4.data_test << '\n';
	
	//从输出可以看出，实例1和实例2操作的是同一个实例
	//而实例3和实例4是实例1和实例2共同指向的实例的副本，并且各自有自己的数据
	//所以，只有使用类返回的引用才可以使用同一个类实例 
	
	return 0;
}
