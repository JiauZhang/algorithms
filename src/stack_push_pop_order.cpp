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
#include <stack>

using namespace std;

bool stack_push_pop_order(int *push_order, int *pop_order, int length)
{
	stack<int> push_stack;
	int *pop_origin = pop_order, len = length;
	
	while(length>=0) {
		if (!push_stack.empty()) {
			if (push_stack.top() == *pop_order) {
				push_stack.pop();
				pop_order++;
			} else if (length != 0) {
				push_stack.push(*push_order);
				push_order++;
				length--;
			} else if (length == 0) {
				break;
			}
		} else { //第一次运行时先 push 
			//cout << "stack is empty--stack.top()" << push_stack.top() << endl;
			//当 stack 为空时，访问stack.top()会导致程序运行错误！ 
			push_stack.push(*push_order);
			push_order++;
			length--;
		}
	}
	 
	if (pop_order - pop_origin == len)
		return true;
	else
		return false;
}

bool Test(int *push_order, int *pop_order, int length)
{
	bool res = stack_push_pop_order(push_order, pop_order, length);
	cout << ((res == 1) ? "匹配成功":"匹配失败") << endl;
}

int main(int argc, char** argv)
{
	int pop_order_test1[5] = {4, 5, 3, 2, 1};
	int push_order_test1[5] = {1, 2, 3, 4, 5};
	int pop_order_test2[5] = {4, 3, 5, 1, 2};
	int push_order_test2[5] = {1, 2, 3, 4, 5};
	int pop_order_test3[1] = {4};
	int push_order_test3[1] = {1};
	int pop_order_test4[2] = {4, 3};
	int push_order_test4[2] = {4, 3};
	int pop_order_test5[1] = {4};
	int push_order_test5[1] = {4};	
	
	Test(push_order_test1, pop_order_test1, 5);
	Test(push_order_test2, pop_order_test2, 5);
	Test(push_order_test3, pop_order_test3, 1);
	Test(push_order_test4, pop_order_test4, 2);
	Test(push_order_test5, pop_order_test5, 1);
	
	return 0;
}
