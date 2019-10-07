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

template <typename T>
class min_in_stack {
public:
	T min();
	void push(T value);
	void pop();
//private: 为了能够打印数据，暂设为 public 
	stack<T> m_min;
	stack<T> m_stack;
};

template <typename T>
void min_in_stack<T>::push(T value)
{
	m_stack.push(value);
	if(m_min.size()==0 || m_min.top()>value)
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T>
void min_in_stack<T>::pop()
{
	if(m_min.size()>0 && m_stack.size()>0) {
		m_min.pop();
		m_stack.pop();
	}
}

template <typename T>
T min_in_stack<T>::min()
{
	return m_min.top();
}

void print(int* stack, int size)
{
	while(size>0) {
		cout << *stack << ' ';
		stack--;
		size--;
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	min_in_stack<int> min_stack;
	min_stack.push(10);
	min_stack.push(11);
	min_stack.push(8);
	min_stack.push(9);
	min_stack.push(2);
	min_stack.push(7);
	
	print(&min_stack.m_min.top(), min_stack.m_min.size());
	print(&min_stack.m_stack.top(), min_stack.m_stack.size()); 
	
	min_stack.pop();
	print(&min_stack.m_min.top(), min_stack.m_min.size());
	print(&min_stack.m_stack.top(), min_stack.m_stack.size());
	
	min_stack.pop();
	print(&min_stack.m_min.top(), min_stack.m_min.size());
	print(&min_stack.m_stack.top(), min_stack.m_stack.size());
	
	return 0;
}
