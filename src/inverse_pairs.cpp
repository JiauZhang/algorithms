#include <iostream>

using namespace std;

int inverse_pairs(int *data, int *copy, int start, int end);
//留给用户调用 
int inverse_pairs(int *data, int length)
{
	if (!data || length <= 0)
		return 0;
	
	//cout << "12" << endl;	
	int *copy = new int[length];
	for (int i=0; i<length; i++) {
		copy[i] = data[i];
	}
	int count = inverse_pairs(data, copy, 0, length - 1);
	
	//copy里最后存放的为从小到大的排序，这就是归并排序！！ 
	cout << "copy data: " << endl;
	for (int i=0; i<length; i++) {
		cout << copy[i] << ' ';
	}
	cout << endl;
	
	delete[] copy;
	
	return count;
}

//真正的实现操作
//start、end表示在原始数组中的偏移
int inverse_pairs(int *data, int *copy, int start, int end)
{
	//安全检查 
	if (!copy || start<0 || end<0 || start>end)
		return 0;
	//递归终止条件	
	//if (start=end)
	if (start == end)
		return 0;
	
	//cout << "30" << endl;
	int length_ = (end - start) / 2;	
//	int left = inverse_pairs(data, copy, start, start+length_);	
//	int right = inverse_pairs(data, copy, start+length_+1, end);
	//这里必须要交换使用，因为当前分支需要使用排好序的数据，当前分支使用的又是data
	//而当前分支修改的是copy，所以下一个分支就要修改data，即，把data放在copy位置上传入递归 
	int left = inverse_pairs(copy, data, start, start+length_);	
	int right = inverse_pairs(copy, data, start+length_+1, end);
	//为了每次比较都能把数据排序到copy内存中，应该从两组中最大的开始
	//比较，即指针都指向末尾 
	int *p1 = data + start + length_;
	int *p2 = data + end;
	//int *p3 = copy + end;
	int copyIndex = end; //该两组数据的存储末尾地址为end，因为它是和data对应的长度的 
	int count = 0;
	for(int i=start; i<=end; i++) {
		cout << *(data+i) << ' ';
	}
	cout << endl;
	while (p1 >= (data + start) && p2 >= (data + start + length_ + 1)) {
		if (*p1 > *p2) {
			//cout << "find" << endl;
			cout << *p1 << " > " << *p2 << endl; 
			//count += (end - start - length_); 这里应该是 + p2到起点包含的个数
			//因为p2是在移动的 
			count += (p2 - data - start - length_);
			copy[copyIndex--] = *p1; 
			p1--;
		} else {
			//cout << "empty" << endl;
			copy[copyIndex--] = *p2;
			p2--;
		}
	}
	
	//处理剩余的没有复制到copy的
	while (p1 >= (data + start)) {
		//cout << "p1" << endl;
		copy[copyIndex--] = *(p1--);
	} 
	while (p2 >= (data + start + length_ + 1)) {
		//cout << "p2" << endl;
		copy[copyIndex--] = *(p2--);
	}
	
	return left + right + count;
} 

int main(int argc, char **argv)
{
	int array[5] = {7, 5, 6, 4, 9};
	int count = inverse_pairs(array, 5);
	cout << "count: " << count << endl;
	
	for (int i=0; i<5; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
	
	int arr[4] = {7, 5, 6, 9};
	count = inverse_pairs(arr, 4);
	cout << "count: " << count << endl;
	
	for (int i=0; i<4; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
