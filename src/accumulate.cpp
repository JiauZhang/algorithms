#include <iostream>
#include <list>

using namespace std;
/************************* soulution-1 **************************/ 
class add {
public:
	add() { sum = sum + n; n++; }
	//a static data member that can only be initialized at its definition
	static int sum;
	static int n;
	static int getSum() { return sum; }
}; 

int add::sum = 0;
int add::n = 1;

int accumulate_1(int n)
{	
	add *sum = new add[n];
	delete[] sum;
	sum = NULL;
	
	return add::getSum();	
}
/************************* soulution-2 **************************/ 
class End;
End *end_start[2];

class End {
public:
	virtual int sum(int n) {
		return 0;
	}
};

class Start: public End {
	virtual int sum(int n) {
		// n 非零时执行当前函数递归，
		// 为零时实行父类函数，其直接返回，扮演终止条件 
		return end_start[!!n]->sum(n-1) + n;
	}
};

int accumulate_2(int n)
{
	if (n<1)
		return -1;
	End e;
	Start s;
	end_start[0] = &e;
	end_start[1] = &s;
	
	return end_start[!!n]->sum(n);
}
/************************* soulution-3 **************************/ 
typedef int (*func)(int n);
int Stop(int n)
{
	return 0;
}

int Begin(int n)
{
	static func f[2] = {Stop, Begin};
	return f[!!n](n-1) + n;
}

int accumulate_3(int n)
{
	return Begin(n);
}
/************************* soulution-4 **************************/
template <int n>
struct solution4 {
	enum Value {
		sum = solution4<n-1>::sum + n
	};
};

template <>
struct solution4<1> {
	enum Value {
		sum = 1
	};
};

int accumulate_4(int n)
{
	const int m = 10;
	struct solution4<m> s;
	return s.sum;
}

int main(int argc, char **argv)
{
	cout << accumulate_1(10) << endl;
	cout << accumulate_2(10) << endl;
	cout << accumulate_3(10) << endl;
	cout << accumulate_4(10) << endl;
} 
