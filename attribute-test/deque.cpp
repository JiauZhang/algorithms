#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char** argv)
{
	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	dq.push_back(5);
	
	deque<int> dq_test;
	for (int i=0; i<dq.size(); i++) {
		dq_test.push_back(dq[i]);
		cout << dq[i] << " ";
	}
	cout << endl;
	
	for (int i=0; i<dq_test.size(); i++) {
		cout << dq_test[i] << " ";
	}
	
	return 0;	
}
