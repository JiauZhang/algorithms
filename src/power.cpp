#include <iostream>

using namespace std;

double power_v1(double base, int exp)
{
	double res = 1.0;
	while(exp) {
		res = res * base;
		exp--;
	}	
	return res;
}
//计算机内表示小数时都有误差，不能直接判断某个小数和某个小数是否相等
//只能通过两个数的差值是否足够小来判断它俩是否相等 
bool equal(double num1, double num2)
{
	if((num1-num2>-0.0000001)&&(num1-num2<0.0000001))
	  return true;
  return false;
}

double power_v2(double base, int exp)
{
	double res = 1.0;
	bool negative = 0;
	if(equal(base, 0.0))
    return base;
	if(base==1.0)
	  return 1.0;
	if(exp<0) {
		exp = -exp;
		negative = 1;
	}
	if(exp==0) {
		return res;
	} else if(exp==1) {
		if(negative)
			return 1/base;
		return base;			
	} else if(exp%2) { //更高效的做法是用 exp&0x01 进行判断 
		res = power_v2(base, (exp-1)/2);
		res = res * res; 
		if(negative)
		  return 1/(res*base);
		return res*base;
	} else {
		res = power_v2(base, exp/2);
		if(negative)
		  return 1/(res*res);
		return res*res;
	}
}

void Test(double base)
{
	cout << power_v2(base, 0) << endl;
	cout << power_v2(base, 1) << endl;
	cout << power_v2(base, 2) << endl;
	cout << power_v2(base, 5) << endl;
	
	cout << power_v2(base, -0) << endl;
	cout << power_v2(base, -1) << endl;
	cout << power_v2(base, -2) << endl;
	cout << power_v2(base, -5) << endl;
}

int main(int argc, char** argv)
{
	double test1 = 5.5;
	double test2 = 1.0;
	double test3 = 0.0;
	
	Test(test1);
	Test(test2);
	Test(test3);
	
	return 0;
}
