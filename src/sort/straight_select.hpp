#include <iostream>

template <typename Dtype>
class StraightSelectSort {
public:
	StraightSelectSort() {}
	~StraightSelectSort() {}
	
	static void sort(Dtype *data, int length);
};

template <typename Dtype>
void StraightSelectSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	
	Dtype min;
	int start = 0, min_index;
	while (start < length) {
		min = data[start];
		min_index = start;
		for (int i=start; i<length; i++) {
			if (min > data[i]) {
				min = data[i];
				min_index = i;
			}
		}
		if (start != min_index) {
			Dtype temp = data[start];
			data[start] = min;
			data[min_index] = temp;
		}
		start++;
	}	
}
