#include <iostream>
#include <cstring>

using namespace std;

bool replace_blank_head(char* src, char* des, int length)
{
	if(src && des) {
		int len = 0;
		while((*src)!='\0' && len<length) {
			if((*src)==' ') {
				*(des++) = '%';
				*(des++) = '2';
				*(des++) = '0';
				//这里切不可忘记将 src 的指针 ++，否则程序就只复制到了这里就死了，如果没有 len<length 
				src++;
			} else {
				*(des++) = *(src++);
			}
			len++;
		}
		*des = '\0';
		return true;
	}
	
	cout << "invalid string" << endl;
	return false;
}

bool replace_blank_tail(char* src, char* des, int length)
{
	if(src && des) {
		int len = 0;
		src = src + length -1;
		*(des+1) = '\0';
		while(len<length) {
			if((*src)==' ') {
				*(des--) = '0';
				*(des--) = '2';
				*(des--) = '%';
				src--;
			} else {
				*(des--) = *(src--);
			}
			len++;
		}
		return true;
	}
	
	cout << "invalid string" << endl;
	return false;
}

void Print(char* str)
{
	if(str) {
		while(*str!='\0') {
			cout << *str++;
		}
		cout << endl;
	} else {
		cout << endl;
	}
}

int main(int argc, char** argv)
{
	char* src = "  hello  string world!  ";
	char* des = new char[50];
	
	bool res = replace_blank_head(src, des, strlen(src));
	Print(des);
	
	int len = strlen(des);
	cout << "des length: " << len << endl;
	
	res = replace_blank_tail(src, (des+len-1), strlen(src));
	Print(des);
	
	return 0;
}
