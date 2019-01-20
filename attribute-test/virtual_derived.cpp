#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define DEBUG

#ifdef DEBUG
#define debug(para, str) printf(para, str)
#else
#define debug(para, str)
#endif

class abstract_class
{
public:
	int ac_int;
	virtual void virtual_func(int add1, int add2, int &sum) = 0;
};

class imp_class: public abstract_class
{
public:
	int imp_int;
	void virtual_func(int add1, int add2, int &sum)
	{
		sum = add1 + add2;
	}
};

int main(int argc, char **argv)
{
    imp_class imp;
    imp.ac_int = 1;
    imp.imp_int = 2;
    abstract_class *ac = &imp;
    int sum;
    //通过传入子类指针给父类指针，来实现访问子类对父类纯虚函数的实例 
    ac->virtual_func(imp.ac_int, imp.imp_int, sum);
    cout << "sum: " << sum;

    return 0;
}
