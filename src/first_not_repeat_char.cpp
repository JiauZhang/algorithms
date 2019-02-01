#include <iostream>
//#include <string.h>
#include <string>

using namespace std;

int getFirstNotRepeatChar(char *str)
{
	if (!str)
		return -1;

	int chars[256];
	char *pChar = str;

	for (int i=0; i<256; i++)
		chars[i] = 0;
	//这里的index不用减去 'a'，因为字符还可能是数子字符～
	while (*pChar != '0') {
		int index = *pChar - 'a';
		chars[index]++;
		pChar++;
	}

	pChar = str;
	while (*pChar != '0') {
		int index = *pChar - 'a';
		if (chars[index] == 1)
			return *pChar;
		pChar++;
	}
}

int main(int argc, char **argv)
{
	//string *str = "ddbscagds";
	//string str("ddbscagds");
	char str[] = "dd0bscagds";
	
	char firstNotRepeatChar = getFirstNotRepeatChar(str);
	cout << firstNotRepeatChar << endl;

	return 0;
}
