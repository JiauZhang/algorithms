#include <iostream>

using namespace std;

void reverse(char *start, char *end)
{
	if (!start || !end)
		return;
		
	while (start < end) {
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

void left_rotate(char *data, int offset)
{
	if (!data || offset <=0)
		return;
	
	int length = 0;		
	char *start = data;
	//cout << "step 1" << endl;
	while (*start != '\0') {
		length++;
		start++;
	}
	
	if (offset >= length || length < offset)
		return;
	
	start = data;
	char *end = data + offset - 1;
	//cout << "step 2" << endl;
	reverse(start, end);
	//cout << "step 3" << endl;
	start = end + 1;
	end = data + length -1;
	reverse(start, end);
	//cout << "step 4" << endl;
	start = data;
	reverse(start, end);
}

int main(int argc, char **argv)
{
	char sentence[] = "sentence";
	left_rotate(sentence, 3);
	cout << sentence << endl;
	
	return 0;
}
