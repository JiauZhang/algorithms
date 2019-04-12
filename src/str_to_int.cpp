#include <iostream>

using namespace std;

bool isNum(char *c)
{
	bool num = false;
	if (*c >= '0' && *c <= '9')
		num = true;
	
	return num;
}

bool error = false;
int str2int(char *str)
{
	if (!str) {
		error = true;
		return 0;
	}
	error = false;
	bool negative = false;
	char *current = str;
	
	if (*current == '-') {
		negative = true;
		current++;
	} else if (*current == '+') {
		current++;
		negative = false;
	}
	
	long long num = 0;
	while (*current != '\0') {
		if (!isNum(current)) {
			error = true;
			return 0;
		}
		num = num * 10 + *current - '0';
		if ((!negative && num>0x7fffffff) || \
		 	(negative && num<(signed int)0x80000000)) {
			error = true;
			return 0;
		}
		current++;
	}	
	
	if (negative)
		num = -num;
	
	return num;
		
} 

void Test(char *str)
{
	int num = str2int(str);
	if (error) {
		cout << "input is illegal!" << endl;
	} else {
		cout << "num: " << num << endl;
	}
}

int main(int argc, char **argv)
{
	char *num1 = "-51624456";
	Test(num1);
	char *num2 = "764428";
	Test(num2);
	char *num3 = "+0697456";
	Test(num3);
	char *num4 = "516-24456";
	Test(num4);
	char *num5 = "456";
	Test(num5);
}
