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

int find_number_of_k(int *data, int len, int num)
{
	if (!data || len <=0) {
		cout << "invalid param!" << endl;
		return 0;
	}
	
	if (len == 1) {
		cout << "len == 1" << endl;
		return (*data==num);
	}		
	
	if (len == 2) {
		cout << "len == 2" << endl;
		return (*data==num) + (*(data+1)==num);
	}
	//以下程序数组长度不小于 3 
	int length = len / 2;
	int middle = data[length];
	
	if (middle == num) {
		//这样操作不妥，如果数组长度为1，left错误，如果为2，right错误
		/* 
		int left = data[length-1];
		int right = data[length+1];
		*/
		cout << "middle = num" << endl;
		int left;
		if (length>0) {
			left = data[length-1];
			if (left != middle) {
				cout << "left != middle" << endl;
				return find_number_of_k(data+length, len-length, num);
			} else {
				cout << "left = middle" << endl;
				return find_number_of_k(data, length-1, num) \
					 // + find_number_of_k(data+length+1, length-length-1, num)
					 //以后尽量不要用相似的名字，容易出错 
					 + find_number_of_k(data+length+1, len-length-1, num) \
					 + 2; 
			}
		}
		cout << "length !> 0" << endl;	
	} else if (middle > num) {
		cout << "middle > num" << endl;
		return find_number_of_k(data, length, num);
	} else if (middle < num) {
		cout << "middle < num" << endl;
		return find_number_of_k(data+length+1, len-length-1, num);
	}
}

void showNums(int *data, int length)
{
	int i = 0;
	while (length) {
		cout << *(data+i) << ' ';
		i++;
		length--;
	}
	cout << endl;
}


int solution(int *data, int length, int num)
{
	/*
		用二分法寻找数组中的第一个num和最后一个num的index 
		根据坐标差算出长度 
	*/
} 

int main(int argc, char **argv)
{
	int data1[] = {1, 2, 3, 3, 4, 6, 7};	
	showNums(data1, 7);
	cout << "find = " << 4 << endl;
	cout << find_number_of_k(data1, 7, 4) << endl;

	int data2[] = {1, 2, 3, 3, 4, 6, 7};
	showNums(data2, 7);	
	cout << "find = " << 3 << endl;
	cout << find_number_of_k(data2, 7, 3) << endl;
	
	int data3[] = {1, 2, 3, 3, 3, 6, 7};	
	showNums(data3, 7);
	cout << "find = " << 7 << endl;
	cout << find_number_of_k(data3, 7, 7) << endl;
	cout << "find = " << 3 << endl;
	cout << find_number_of_k(data3, 7, 3) << endl;
	
	int data4[] = {1, 2, 3, 3, 3, 6, 7, 7, 7, 7, 8, 9, 9, 9, 9};
	showNums(data4, 15);
	cout << "find = " << 7 << endl;	
	cout << find_number_of_k(data4, 15, 7) << endl;
	
	int data5[] = {2,2};
	showNums(data5, 2);	
	cout << "find = " << 2 << endl;
	cout << find_number_of_k(data5, 2, 2) << endl;

	int data6[] = {2, 3, 4};
	showNums(data6, 3);	
	cout << "find = " << 2 << endl;
	cout << find_number_of_k(data6, 3, 2) << endl;
	cout << "find = " << 3 << endl;
	cout << find_number_of_k(data6, 3, 3) << endl;
	cout << "find = " << 4 << endl;
	cout << find_number_of_k(data6, 3, 4) << endl;
		
	return 0;
}
