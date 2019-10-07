#include <iostream>
#include <assert.h>

template <class T>
struct point{
	inline point():x(0),y(0) {}
	inline point(T _x, T _y):x(_x),y(_y){}
	T x, y;
};

struct PointAccumulator{
	typedef point<float> FloatPoint;
	typedef point<double> Point;
	/* before 
	PointAccumulator(int i=-1): acc(0,0), n(0), visits(0){assert(i==-1);}
	*/
	/*after begin*/
	PointAccumulator(): acc(0,0), n(0), visits(0){}
	PointAccumulator(int i): acc(0,0), n(0), visits(0){assert(i==-1);}
	/*after end*/
    inline void update(bool value, const Point& p=Point(0,0));
	inline Point mean() const {return Point(1./n*acc.x, 1./n*acc.y);}
	
	// 重载强制类型转换 
	inline operator double() const { return visits?(double)n/(double)visits:-1; }
	
	operator int() const { return visits; } 
	
	inline void add(const PointAccumulator& p) {/*acc=acc+p.acc;*/ n+=p.n; visits+=p.visits; }
	static const PointAccumulator& Unknown();
	static PointAccumulator* unknown_ptr;
	FloatPoint acc;
	int n, visits;
	inline double entropy() const;
};

int main(int argc, char **argv)
{
	PointAccumulator test;
	test.acc.x = 10.101;
	test.acc.y = 11.111;
	test.n = 1.0;
	test.visits = 2.0;
	
	std::cout << (double)test << std::endl;
	std::cout << (int)test << std::endl;
	
	return 0;
}
