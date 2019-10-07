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

void print_string_num(char* str)
{
	bool zero = false;
	if(str) {
		while(*str!='\0') {
			if(*str!='0' || zero) {
				cout << *str;
				zero = true;
			}
			str++;
		}
		cout << ' ';
	}
}
/*
void print_hex(char num)
{
	char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', 
	               '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  cout << hex[num&0x0f];
  num = num >> 4;
  cout << hex[num&0x0f];
  cout << ' ';
}
*/
void add_string_num(char* str, int length)
{
	if(str) {
		//cout << "length: " << length << endl;
		bool carry = true;
		while(carry && length>0) {
			carry = false;
			if(*(str+length-1) == '9') {
				carry = true;
				//又是语法错误！！！ 
				//*(str+length-1) == '0';
				*(str+length-1) = '0';
				/*
				cout << *(str+length-1) << " hex: ";
				print_hex(*(str+length-1)); 
				cout << endl;
				*/
				length = length - 1;
				if(length==0) 
				  str[0] = 'F';
			} else {
				/*
				char temp = *(str+length-1) + 1;
				cout << temp << " hex: ";
				print_hex(temp);
				cout << endl;
				cout << "length: " << length << endl;
				*(str+length-1) = temp;
				*/
				*(str+length-1) += 1;
			}
		}
	}
}

void print_num_1_to_max(int n)
{
	char num[n+1];
	for(char i=0; i<n; i++) {
		num[i] = '0';
	}
	num[n] = '\0';
	//判断是否达到了最大数，这里是在 add_string_num 把num[0] 设置为 'F'来标识的
	//也可以通过返回值的方式完成，也可以申请num[n+2]个字符空间，当num[0]为'1'时
	//就表明进位了，即已经达到了最大数，不过这样浪费了一个字符空间 
	while(num[0] !='F') {
		print_string_num(num);
		add_string_num(num, n);
	}
}

int main(int argc, char** argv)
{
	//严重语法错误！！！ 
	//char* num = "009";
	/*
	char num[4] = "008";
	print_string_num(num);
	add_string_num(num, 3);
	print_string_num(num);
	add_string_num(num, 3);
	print_string_num(num);
	add_string_num(num, 3);
	print_string_num(num);
	*/
	
	print_num_1_to_max(3);
	
	return 0;
}
