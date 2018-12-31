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
