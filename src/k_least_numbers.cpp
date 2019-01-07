#include <iostream>
#include <cstdlib>

#include <functional>
#include <set>
#include <vector>

using namespace std;

int random_in_range(int start, int end)
{
	if(start==end) {
		return start;
	} else {
		int index = rand()%(end-start) + start;	
		return index;	
	}
}

template <typename T>
void swap(T* v1, T* v2)
{
	T temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

int partition(int data[], int length, int start, int end)
{
	if(data==NULL || length<=0 || start<0 || end>=length) {
		return false;
	}	
	
	int index = random_in_range(start, end);
	swap<int>(&data[index], &data[end]);
	int small = start-1;
	for(index=start; index<end; ++index) {
		if(data[index]<data[end]) {
			++small;
			if(small!=index) {
				swap<int>(&data[index], &data[small]);
			}
		}
	}
	++small;
	swap<int>(&data[small], &data[end]);
	
	return small;
}

bool inline check_input(int *numbers, int length, int k, int *output)
{
	if (!numbers || length < 1 || k < 1 || !output)
		return false;
	return true;
}

void k_least_numbers(int *numbers, int length, int k, int *output)
{
	if (check_input(numbers, length, k, output)) {
		int start = 0;
		int end = length - 1;
		int index = partition(numbers, length, start, end);
		while (index != (k-1)) {
			if (index < (k-1)) {
				start = index + 1;
				index = partition(numbers, length, start, end);
			} else {
				end = index - 1;
				index = partition(numbers, length, start, end);
			}
		}
		for (int i=0; i<k; i++) {
			output[i] = numbers[i];
		}
	}
}

void print_output(int *output, int k)
{
	for (int i=0; i<k; i++)
		cout << output[i];
	cout << endl;
}

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void k_least_numbers_set(int *numbers, int length, int k, intSet &output)
{
	if (numbers && length>0 && k>0) {
		output.clear();
		for (int i=0; i<length; i++) {
			if (output.size() < k)
				output.insert(numbers[i]);
			else {
				setIterator it = output.begin();
				if (numbers[i] < *it) {
					output.erase(it);
					output.insert(numbers[i]);
				}
			}
		}
	}
}

void print_output_set(intSet &output_set)
{
	setIterator it_begin = output_set.begin();
	setIterator it_end = output_set.end(); 
	//cout << output_set.size() << endl;
	for (; it_begin != it_end; it_begin++)
		cout << (*it_begin);
	cout << endl;
}

int main(int argc, char** argv)
{
	int  numbers_test1[7] = {6, 8, 4, 7, 9, 1, 3};
	int  numbers_test2[7] = {6, 8, 5, 5, 5, 5, 3};
	int *output = new int[4];
	k_least_numbers(numbers_test1, 7, 4, output);
	print_output(output, 4);
	k_least_numbers(numbers_test2, 7, 4, output);
	print_output(output, 4);
	
	intSet output_set;
	k_least_numbers_set(numbers_test1, 7, 4, output_set);
	print_output_set(output_set);
	k_least_numbers_set(numbers_test2, 7, 4, output_set);
	print_output_set(output_set);
	
	return 0;	
}
