#include <iostream>

template <typename Dtype>
class HeapSort {
public:
	HeapSort() {}
	~HeapSort() {}
	
	static void sort(Dtype *data, int length);
};

template <typename Dtype>
void HeapSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	
}
