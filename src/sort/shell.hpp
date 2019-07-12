#include <iostream>

#define DEBUG

#ifdef DEBUG
#define debug(data, length) showme_(data, length)
#else
#define debug(data, length)
#endif

void showme_(int *data, int length)
{
	for (int i=0; i<length; i++) {
		std::cout << data[i] << ' ';
	}
	std::cout << std::endl;
}

template <typename Dtype>
class ShellSort {
public:
	ShellSort() {}
	~ShellSort() {}
	
	static void sort(Dtype *data, int length);
};

template <typename Dtype>
void ShellSort<Dtype>::sort(Dtype *data, int length)
{
	if (data == NULL || length <=0)
		return;
	int d = length>>1;
	for (; d>0; d=d>>1) {
		// 分组中的第一个数据0，第二个数据为 d，第三个为2d，... 
		// 因为这是原始的shell二分，so i<length, 
		// 上一句的解释是错误的看法！ 并不是因为这个 
		// 遍历每个段的元素 
		std::cout << "d = " << d << std::endl;
		for (int i=d; i<length; i++) {
			// 段中某个元素出现需要重排的情况 
			if (data[i] < data[i-d]) {
				Dtype temp = data[i];
				std::cout << "data[" << i << "] = " << temp << std::endl;
				int j=i;
				for (; j>=d; j -=d) {
					if (temp < data[j-d]) {
						debug(data, length);
						data[j] = data[j-d];
						debug(data, length);
					} else {
						debug(data, length);
						//data[j] = temp;
						std::cout << "break" << std::endl;
						debug(data, length);
						break;
					}
				}
				data[j] = temp;				
			}
		}	
	}
}
