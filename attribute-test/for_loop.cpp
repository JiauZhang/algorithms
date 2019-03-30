#include <iostream>

using namespace std;

//#define DEBUG

int main(int argc, char **argv)
{
	int i;
	for (i=0; i<10; i++) {
		#ifdef DEBUG
		if (i>5) {
			cout << "for loop i = " << i << endl;
			break;
		}
		#else
		//不会执行到这里 
		if (!(i<10))
			cout << "for loop end" << endl;
		#endif
	}
	
	cout << "main i = " << i << endl;
	
	return 0;
}
