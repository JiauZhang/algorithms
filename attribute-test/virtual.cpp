#include <iostream>

class CVirtual {
public:
	//virtual void show_something() = 0;
	/*virtual*/ void show_something() {
		std::cout << "CVirtual" << std::endl;
	}
};

class CInstance: public CVirtual {
public:
	explicit CInstance(int var): var(var) {}
	virtual void show_something();
	int var;
};

void CInstance::show_something()
{
	std::cout << "CInstance variable: " << var << std::endl;
}

class CIns: public CInstance {
public:
	explicit CIns(int test): CInstance(233), test(test) {}
	virtual void show_something();
	int test;
};

void CIns::show_something()
{
	std::cout << "CIns variable: " << test << std::endl;
}

/*
	虚函数的作用是实现多态性，即将子类实例指针赋值给父类
	父类调用同名函数时，执行的是子类中的实现
	而纯虚数除了上述功能外，就是约束子类必须实现父类函数才可实例化
	即起到预留接口的作用
	而非虚函数父类调用同名函数时，执行自己的实现 
*/

int main(int argc, char **argv)
{
	CVirtual *cvirtual = new CInstance(20);
	cvirtual->show_something();
	CInstance *cinstance = new CIns(666);
	cinstance->show_something();
		
	return 0;	
} 
