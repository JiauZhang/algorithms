#include <iostream>

using namespace std;

int kmp_bs(string &tpl, string &str)
{
	if (!tpl.size() || !str.size())
		return -1;
		
	int i = 0, j = 0;
	while (i<str.size() && j<tpl.size()) {
		if (str[i] == tpl[j]) {
			i++;
			j++;
		} else {
			i = i - j + 1;
			j = 0;
		}
	}
	
	if (j == tpl.size())
		return i - j;
	
	return -1;
}

int main()
{
	string tpl = "template";
	string str = "string tme plate template tt";
	
	cout << kmp_bs(tpl, str);	
	
	return 0;
} 
