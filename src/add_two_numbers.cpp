/*
* Copyright(c) 2019 Jiau Zhang
* For more information see <https://github.com/JiauZhang/algorithms>
* 
* This repo is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation
*
* It is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with THIS repo. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>

using namespace std;
//加法可以分解为二进制的 (异或，不进位加) + (位与，进位) 
int add_ops(int num1, int num2)
{
	int carry = 0;
	int sum = 0;
	
	do {
		//不进位加 
		sum = num1 ^ num2;
		//进位位
		carry = (num1 & num2) << 1;
		//进入下一个循环，如果有仅为则将进位与和相加 
		num1 = sum;
		num2 = carry; 
	} while (carry);
	
	return sum; 
}

void swap_ops(int a, int b)
{
	a = a + b; // a = a^b;
	b = a - b; // b = a^b;
	a = a - b; // a = a^b;
} 

int main(int argc, char **argv)
{
	cout << add_ops(10, 15) << endl;
	cout << add_ops(15, 13) << endl;
	cout << add_ops(66, 99) << endl;
	cout << add_ops(0, -99) << endl;
	cout << add_ops(-66, 99) << endl;
} 
