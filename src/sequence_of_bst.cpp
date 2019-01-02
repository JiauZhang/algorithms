#include <iostream>

using namespace std;

bool verify_sequence_of_bst(int sequence[], int length)
{
	if (sequence && length > 0) {
		if (length <= 2)
			return true;
		int root_value = sequence[length-1];
		int index_left = 0;
		//找到第一个 ＞ root_value 的值 
		while (sequence[index_left] < root_value && index_left < length-1)
			index_left++;
		
		int index_right = index_left;
		//检查右子树是否全部满足 > root_value	
		while(index_right < length-1) {
			if (sequence[index_right] < root_value)
				return false;
			index_right++;
		}
		
		bool left = true;
		if (index_left > 0) 
			left = verify_sequence_of_bst(sequence, index_left);
		
		bool right = true;
		if (index_left < length - 1)
			right = verify_sequence_of_bst(sequence + index_left, length - 1 - index_left);
		
		return (left && right);
	} else {
		return false;
	}
}

void test(int sequence[], int length)
{
	bool res = verify_sequence_of_bst(sequence, length);
	cout << (res==1?"是":"否") << endl;	
}

int main(int argc, char** argv)
{
	int sequence_test1[7] = {5, 7, 6, 9, 11, 10, 8};
	int sequence_test2[4] = {7, 4, 6, 5};
	
	test(sequence_test1, 7);
	test(sequence_test2, 4);
	
	return 0;
}
