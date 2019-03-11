#include <iostream>
#include <cassert>

using namespace std;

void print_string(char *str)
{
	if (str) {
		while (*str != '\0')
			cout << *str++;
		
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	cout << "argc: " << argc << endl;
	
	if (argc == 1) {
		cout << "usage: PATH_TO_EXE param_1 param_2 ... param_n" << endl;
		return 1;
	} 
	
	for (int i=0; i<argc; i++) {
		cout << "arg[" << i+1 << "] = ";
		print_string(*(argv+i));
	}
	
	return 0;
}
