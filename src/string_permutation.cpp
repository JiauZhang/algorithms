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

//#define DEBUG

#ifdef DEBUG
#define debug(str) print_string(str)
#else
#define debug(str)
#endif

void print_string(char *str)
{
	while (*str != '\0') {
		cout << *str;
		str++;
	}
	cout << ' ';
}

void permutation(char *str, char *next)
{
	if (*next == '\0') { //当next指向最后一个字符时，说明一个排列产生了 
		print_string(str);
	} else {
		//此循环的作用是把 next 指针指向的字符与此字符之后的进行逐一交换 
		for (char *next_next=next; *next_next!='\0'; next_next++) {
			//进行交换，第一次交换为自身 
			char temp = *next;
			*next = *next_next;
			*next_next = temp;
			permutation(str, next+1);
			//交换之后恢复原始顺序，这样递归的上一级才可正常使用 
			temp = *next;
			*next = *next_next;
			*next_next = temp;
		}
	}
}

void permutation(char *str)
{
	if (str) {
		permutation(str, str);
	}
}

int main(int argc, char** argv)
{
	char str[4] = {'a', 'b', 'c', '\0'};
	permutation(str);

	return 0;	
}
