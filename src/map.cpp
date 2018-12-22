#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {
	
	map<int, float> test_map;
	
	test_map[1] = 1.0;
	test_map[3] = 3.0;
	test_map[7] = 7.0;
	test_map[2] = 2.0;
	test_map[10] = 10.0;
	test_map[8] = 8.0;
	test_map[22] = 22.0;
	test_map[15] = 15.0;
	test_map[13] = 11.0;
	
	cout << test_map.size() << endl;
	//从输出可以看出，map 迭代器是按照 key 值从小到大依次访问其中的元素的 
	for(map<int, float>::iterator it = test_map.begin(), itend = test_map.end();it!=itend;it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}
	
	map<int, float> test_map_;
	
	test_map_[5] = 1.0;
	test_map_[9] = 3.0;
	test_map_[12] = 7.0;
	test_map_[2] = 2.0;
	test_map_[10] = 10.0;
	test_map_[13] = 8.0;
	test_map_[8] = 22.0;
	test_map_[15] = 15.0;	
	
	cout << test_map_.size() << endl;
	
	for(map<int, float>::iterator it = test_map_.begin(), itend = test_map_.end();it!=itend;it++) {
		cout << "key: " << it->first << " value: " << it->second << endl;
	}
	
	map<int, float>::iterator it1 = test_map.begin();
	map<int, float>::iterator it2 = test_map_.begin();
	map<int, float>::iterator it1end = test_map.end();
	map<int, float>::iterator it2end = test_map_.end();
	
	vector<pair<int, int> > process; 
	typedef pair<int, int> make_pair;
	process.push_back(make_pair(it1->first, it2->first));
	
	//这段程序的作用是寻找出两个 map 结构中 key 相等的元素 
	while(it1!=it1end && it2!=it2end) {
		if(it1->first == it2->first)
        {
        	cout << "the same key" << it1->first << endl;        	
            it1++;
            it2++;
            process.push_back(make_pair(it1->first, it2->first));
        }
        else if(it1->first < it2->first)
        {
            //返回一个不小于it2-first的迭代器指针 
            it1 = test_map.lower_bound(it2->first);
            process.push_back(make_pair(it1->first, it2->first));
        }
        else
        {
            it2 = test_map_.lower_bound(it1->first);
            process.push_back(make_pair(it1->first, it2->first));
        }
	}
	//结束while循环时，有一个指向end，所以最后一组 push_back 的是越界的数据 
	process.pop_back();
	
	vector<make_pair>::iterator it = process.begin(), itend = process.end();
	while(it!=itend) {
		cout << it->first << ' ' << it->second << endl;
		it++;
	}
	
	return 0;
}
