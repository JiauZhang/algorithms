#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class CQueue {
public:
	CQueue();
	~CQueue();	
	void appendTail(const T& value);
	T& deleteHead();
	void printQueue();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue()
{
	while(!stack1.empty())
		stack1.pop();
	while(!stack2.empty())
		stack2.pop();
}

template <typename T>
CQueue<T>::~CQueue()
{
	while(!stack1.empty())
		stack1.pop();
	while(!stack2.empty())
		stack2.pop();
}

template <typename T>
void CQueue<T>::appendTail(const T& value)
{
	stack1.push(value);
}

template <typename T>
T& CQueue<T>::deleteHead()
{
	if(!stack2.empty()) {
		// top 返回的是栈顶的引用 
		T& res = stack2.top();
		stack2.pop();
		return res;
	} else if(!stack1.empty()) {
		while(!stack1.empty()) {
			T& res = stack1.top();
			stack2.push(res);
			stack1.pop();
		}
		T& res = stack2.top();
		stack2.pop();
		return res;
	}
}

template <typename T>
void CQueue<T>::printQueue()
{
	if(!stack2.empty()) {
		T& ref = stack2.top();
		size_t stack_size = stack2.size();
		T* top = &ref;
		while(stack_size) {
			cout << *top << ' ';
			stack_size--;
			//windows中的栈是从低地址向高地址增长的 
			top--;
		}
	}
	if(!stack1.empty()) {
		size_t stack_size = stack1.size();
		T& ref = stack1.top();
		//引用可以看作是别名，对某一内存的直接使用，通过&提取地址 
		T* bottom = &ref;
		//栈低需要在通过栈顶指针减去(stack_size-1) 
		bottom = bottom - stack_size + 1;
		while(stack_size) {
			stack_size--;
			cout << *(bottom++) << ' ';
			//cout << bottom++ << ' ';
		}
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	CQueue<int> queue;
	queue.appendTail(1);
	queue.appendTail(2);
	queue.appendTail(3);
	queue.appendTail(4);
	queue.appendTail(5);
	
	queue.deleteHead();
	queue.deleteHead();
	
	queue.printQueue();
	
	queue.appendTail(6);
	queue.appendTail(7);
	queue.appendTail(8);
	queue.appendTail(9);
	
	queue.printQueue();
	
	queue.deleteHead();
	
	queue.printQueue();
	
	queue.deleteHead();
	queue.deleteHead();
	queue.deleteHead();
	queue.deleteHead();
	
	queue.printQueue();
	
	return 0;
}
