#include <iostream>
#include <cstdlib>

using namespace std;

// if you want more detail info, open `#define DEBUG`. 
//#define DEBUG

#ifdef DEBUG
#define debug(data, start, end) print(data, start, end)
#else
#define debug(data, start, end)
#endif

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

void print(int data[], int start, int end)
{
	if(start>end) {
		cout << "invalid input" << endl;
	} else {
		while(start<=end) {
			cout << data[start] << ' ';
			start++;
		}
	}
	cout << endl;
}

int partition(int data[], int length, int start, int end)
{
	if(data==NULL || length<=0 || start<0 || end>=length) {
		return false;
	}	
	
	int index = random_in_range(start, end);
	#ifdef DEBUG
	cout << "random data[index]: " << data[index] << endl;
	#endif
	debug(data, start, end);
	swap<int>(&data[index], &data[end]);
	debug(data, start, end);
	// small指针左侧的(包括当前指向的)是小于data[index]的数据
	//右侧的(不包括指针指向的)到index之间的是大于data[index]的数据
	//因此当遇到 < data[index]的数据时，small++，检查两个指针是否相等
	//如果不等说明它们之间有 > data[index]的数据，那么就把小的交换到后方
	//最后把data[index]从末尾置换到所有比它小的数之间，即small++ 
	int small = start-1;
	for(index=start; index<end; ++index) {
		if(data[index]<data[end]) {
			++small;
			#ifdef DEBUG
			cout << "small: " << small << " index: " << index << "--"; 
			#endif
			if(small!=index) {
				swap<int>(&data[index], &data[small]);
			}
			debug(data, start, end); 
		}
	}
	++small;
	swap<int>(&data[small], &data[end]);
	debug(data, start, end);
	
	return small;
}

void quick_sort(int data[], int length, int start, int end)
{
	//原来 void 函数也是可以 return，但是不能带有任何返回参数，否则编译报错 
	if(start==end)
		return;
	//排序的实质性操作是在此函数中完成的 
	int index = partition(data, length, start, end);
	if(index>start)
		quick_sort(data, length, start, index-1);
	if(index<end)
		quick_sort(data, length, index+1, end);
}

int main(int argc, char** argv)
{
	int data[10] = {9, 11, 5, 30, 7 ,13 ,22 ,4, 8, 18};
	
	print(data, 0, 9);
	quick_sort(data, 10, 0, 9);
	print(data, 0, 9);
	
	return 0;
}
