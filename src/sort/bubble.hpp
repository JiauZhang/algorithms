#include <iostream>

template <typename Dtype>
class BubbleSort {
public:
	BubbleSort() {}
	~BubbleSort() {}
	
	static void sort(Dtype *data, int length);
};

template <typename Dtype>
void BubbleSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	int end = length;
	for (int i=0; i<length; i++) {
		for (int j=1; j<end; j++) {
			if (data[j-1] > data[j]) {
				Dtype temp = data[j-1];
				data[j-1] = data[j];
				data[j] = temp;
			}
		}
		end--;
	}
}
