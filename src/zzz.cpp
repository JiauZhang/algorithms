#include <iostream>
#include <exception>
#include <vector>

using namespace std;

int find_min(vector<int> &vec, int start, int end) {
    int min = vec[start];
    while (start <= end) {
        if (min>vec[start])
           min = vec[start];
        start++;
    }
    
    return min;
}
int count = 0;
int minNumberInRotateArray(vector<int> &vec) {
    if (vec.size() == 0)
        return 0;
    
    if (vec.size() == 1)
        return vec[0];
    
    int left = 0;
    int right = vec.size() - 1;
    int mid = left;
    
    while (vec[left]>=vec[right]) {
    	cout << "vec[mid]=" << vec[mid] << \
				" vec[left]=" << vec[left]  << \
				" vec[right]=" << vec[right]<< endl;
		
		if (right - left == 1) {
			mid = right;
			break;
		}		
				
        mid = (left + right) / 2;
        if (vec[left] == vec[right] && \
            vec[right] == vec[mid]) {
            cout << "equals" << endl;
            return find_min(vec, left, right);
        }
        
        if (vec[mid] < vec[left]) {
        	cout << "<" << endl;
            right = mid;
        } else if (vec[mid] >= vec[left]) {
        	count++;
        	if (count > 15)
        		break;
        	cout << ">=" << endl;
            left = mid;
        }
    }
    
    return vec[mid];
}   
    


void Test(vector<int> &numbers)
{
	try {
		int minimum = minNumberInRotateArray(numbers);
		cout << "minmum: " << minimum << endl;
	} catch(...) {
		cout << "Invalid parameters" << endl;
	}	
}

int main(int argc, char** argv)
{
	//int test1[9] = {6, 7, 8, 9, 1, 2, 3, 4, 5};// 1
	vector<int> test1;
	test1.push_back(6);test1.push_back(7);test1.push_back(8);
	test1.push_back(9);test1.push_back(1);test1.push_back(2);
	test1.push_back(3);test1.push_back(4);test1.push_back(5);
//	int test2[9] = {1, 1, 1, 1, 0, 1, 1, 1, 1};// 0
//	int test3[9] = {1, 1, 1, 0, 1, 1, 1, 1, 1};// 0
//	int test4[9] = {1, 1, 1, 1, 1, 0, 1, 1, 1};// 0
//	int test5[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};// 1
//	int test6[2] = {3, 2};// 2
	
	Test(test1);
//	Test(test2, 9);
//	Test(test2, 9);
//	Test(test4, 9);
//	Test(test5, 9);
//	Test(NULL, 0);
//	Test(test6, 2);
	
	return 0;
}
