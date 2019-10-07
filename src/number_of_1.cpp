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
#include <cstring>
#include <cstdlib>

using namespace std;

int power_base_10(int n)
{
	int result = 1;
	for(int i = 0; i < n; i++)
		result *= 10;
	
	return result;
}

int number_of_1(char *str_num, int length)
{
	if (length <= 0)
		return 0;
		
	int first = *str_num - '0';
	if (length == 1) {
		if (first == 0)
			return 0;
		else
			return 1;
	}
	
	int first_num = 0;
	int other_num = 0;
	//计算最高位是 1 的情况下的数量 
	if (first == 1) //第一位为 1 的情况 
		first_num = atoi(str_num + 1) + 1;
	else //第一位 >1 的情况，此时最高位为 1 有如下多种情况 
		first_num = power_base_10(length - 1);
	//计算最高位是 2 的情况的数量 
	/* 
	if (first == 2)
		other_num = number_of_1(str_num + 1, length - 1);
	else if (first > 2){
		int other = power_base_10(length - 1) - 1;
		char str_num[20];
		sprintf(str_num, "%d", other);
		int len_other = strlen(str_num);
		other_num = (first - 2) * number_of_1(str_num, len_other);
		other_num += number_of_1(str_num + 1, length - 1);
	}
	
	int other = power_base_10(length - 1) - 1;
	char str_num_[20];
	sprintf(str_num, "%d", other);
	int len_other = strlen(str_num_);
	int recursive_num = number_of_1(str_num_, len_other);
	*/
	
	other_num = first * (length - 1) * power_base_10(length - 2);
	int recursive_num = number_of_1(str_num+1, length-1);
	
	return (first_num + other_num + recursive_num);	
}

int number_of_1_between_1_and_n(int n)
{
	if (n <= 0)
		return 0;
		
	char str_num[20];
	sprintf(str_num, "%d", n);
	int length = strlen(str_num);
	//cout << length;
	return number_of_1(str_num, length);
} 

int stupid_solution(int n)
{
	if (n <= 0)
		return 0;
		
	int result = 0;
	for (int i=1; i<=n; i++) {
		int temp = i;
		while (temp) { //计算某个数中有多少个 1 
			if (temp%10 == 1)
				result++;
			temp = temp / 10;
		}
	}
	
	return result;
}

int my_solution(int n)
{
	if (n <= 0)
		return 0;
		
	int result = 0;
	char str_num[20];
	sprintf(str_num, "%d", n);
	
	int num_len = strlen(str_num);
	//首先是知道十进制数有多少位，然后把它所有的数放在一起看成是矩阵
	//这样就变成了遍历每一列有多少个 1 的问题了 
	//而输入的数值 n 就是它的行数，位数就是它的列数 
	//了统一准则，在最底部不上一行 0 
	//第一列每 10 个数(0-9)出现一个 1 ，重复 1 次，不满一个周期的数量 >1 时必有 1 出现，次数最多不超过 1 
	//第二行每 100 个数出现一次 1 ，但是重复 10 次，不满一个周期的数量 >10 时必有 1 出现，次数最多不超过 10
	//第三行每 1000个数出现一次 1 ，但是重复 100 次，不满一个周期的数量 >100 时必有 1 出现，次数最多不超过 100
	//以此类推，对每一列进行计算 
	for (int i=0; i<num_len; i++) {
		//出现 1 的周期 
		int base = power_base_10(i+1);
		//出现 1 的周期数 
		int quotient = (n+1) / base;
		//不满一个周期的 
		int remainder = (n+1) % base;
		//出现 1 后重复的次数 
		base /= 10;
		//完整周期中出现的总次数 
		result += base * quotient;
		//非完整周期 1 的次数 
		if (remainder > base) { //大于上一列的重复周期时才会出现 1 
			remainder -= base;  //出现 1 的次数 
			if (remainder > base)	//总次数不超过上一列周期长度 
				remainder = base;
		} else {
			remainder = 0; //如果没有出现，则为 0 
		}
		result += remainder;
	}
	
	return result;
}

void Test(int n, int answer)
{
	int number_of_1 = number_of_1_between_1_and_n(n);
	if (number_of_1 == answer)
		cout << "success-->";
	else
		cout << "failed-->" << n << "-->";
	cout << "number_of_1: " << number_of_1 << endl;
	number_of_1 = stupid_solution(n);
	if (number_of_1 == answer)
		cout << "success-->";
	else
		cout << "failed-->" << n << "-->";
	cout << "stupid solution: " << number_of_1 << endl;
	number_of_1 = my_solution(n);
	if (number_of_1 == answer)
		cout << "success-->";
	else
		cout << "failed-->" << n << "-->";
	cout << "my solution: " << number_of_1 << endl;
}

int main(int argc, char** argv)
{
	Test(1, 1);//1
	Test(5, 1);//1
	Test(9, 1);//1
	Test(10, 2);//2
	Test(55, 16);//16
	Test(99, 20);//20
	//这个有问题 
	Test(9999, 4000);//4000
	Test(10000, 4001);//4001
	Test(21345, 18821);//18821
	Test(174396, 164777);//164777
	Test(0, 0);//0
	
	return 0;	
}
