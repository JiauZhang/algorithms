#include <iostream>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define debug(numbers, length) print_numbers(numbers, length)
#else
#define debug(numbers, length)
#endif

void print_numbers(int numbers[], int length)
{
	int len = 0;
	while(len<length) {
		cout << numbers[len] << ' ';
		len++;
	}
	cout << endl;
	#ifdef DEBUG
	len = 0;
	while(len<length) {
		cout << (numbers[len])%2 << ' ';
		len++;
	}
	cout << endl;
	#endif
}

void reorder(int numbers[], int length)
{
	if(!numbers || length<=0)
		return;
	int* head,* tail;
	head = numbers; 
	tail = numbers+length-1;
	bool odd = false, even = false;
	//int & 0x01 会有问题，不能正确判断奇偶性 
	while(head<tail && head != tail) { //head!=tail用来防止全是奇数和全是偶数是指针超出范围 
		//if((*head)&0x01) { //如果是奇数指针就往尾方向走，偶数就停止 
		if((*head)%2) {
			++head;			
		} else {
			odd = true;
		}
		//if((*tail)&0x01 == 0) { //如果是偶数则往头方向走，奇数就停止 
		if((*tail)%2 == 0) {
			--tail;
		} else {
			even = true;
		}
		if(odd && even) {
			odd = false;
			even = false;
			int temp = *head;
			*head = *tail;
			*tail = temp;
			head++;
			tail--;
			debug(numbers, 15);
		}			
	}
}

int main(int argc, char** argv)
{
	int numbers_test1[15] = {1, 21, 2, 3, 4, 5, 6, 7, 8, 9, 0, 13, 22, 22, 33};
	debug(numbers_test1, 15);
	reorder(numbers_test1, 15);
	print_numbers(numbers_test1, 15);
	
	int numbers_test2[5] = {1, 3, 5, 7, 9};
	reorder(numbers_test2, 5);
	print_numbers(numbers_test2, 5);
	
	int numbers_test3[5] = {0, 2, 4, 6, 8};
	reorder(numbers_test3, 5);
	print_numbers(numbers_test3, 5);
	
	int numbers_test4[10] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
	reorder(numbers_test4, 10);
	print_numbers(numbers_test4, 10);	
	
	int numbers_test5[10] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
	reorder(numbers_test5, 10);
	print_numbers(numbers_test5, 10);
	
	return 0;
} 
