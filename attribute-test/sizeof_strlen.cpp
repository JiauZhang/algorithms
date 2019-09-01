#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char c1[] = {'a', 'b', '\0', 'd', 'e'};
	char c2[] = {'a', 'b', '\0', 'd', 'e'};
	
	char *c3 = "ab\0decvzvzxv";
	char *c4 = "abcde";
	
	cout << "sizeof(c1): " << sizeof(c1) << endl;
	cout << "strlen(c2): " << strlen(c2) << endl;
	
	cout << "sizeof(c3): " << sizeof(c3) << endl;
	cout << "strlen(c4): " << strlen(c4) << endl;
	
	return 0;
}
