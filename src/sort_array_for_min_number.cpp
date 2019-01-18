#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define DEBUG

#ifdef DEBUG
#define debug(para, str) printf(para, str)
#else
#define debug(para, str)
#endif

const int max_num_len = 10;
char *str_cmb1 = new char[max_num_len * 2 + 1];
char *str_cmb2 = new char[max_num_len * 2 + 1];

int compare(const void *str_num1, const void *str_num2)
{
	strcpy(str_cmb1, *(const char **)str_num1);
	strcat(str_cmb1, *(const char **)str_num2);
	
	strcpy(str_cmb2, *(const char **)str_num2);
	strcat(str_cmb2, *(const char **)str_num1);
	
	debug("%s ", str_cmb1);
	debug("%s ", str_cmb2);
	
	int res = strcmp(str_cmb1, str_cmb2);
	debug("%d\n", res);
	
	return res;
}

void print_min_number(int *numbers, int length)
{
	if (numbers && length>0) {
		char **str_nums = (char **)(new int[length]);
		for (int i=0; i<length; i++) {
			str_nums[i] = new char[max_num_len+1];
			sprintf(str_nums[i], "%d", numbers[i]);
		}
		
		qsort(str_nums, length, sizeof(char *), compare);
		
		for (int i=0; i<length; i++)
			printf("%s", str_nums[i]);
		printf("\n");
			
		for (int i=0; i<length; i++)
			delete[] str_nums[i];
		delete[] str_nums;
	}
}

// ====================²âÊÔ´úÂë====================
void Test(const char* testName, int* numbers, int length, const char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    if(expectedResult != NULL)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    print_min_number(numbers, length);

    printf("\n");
}

void Test()
{
	int numbers_1[] = {3, 5, 1, 4, 2};
    Test("Test1", numbers_1, sizeof(numbers_1)/sizeof(int), "12345");
    
    int numbers_2[] = {3, 32, 321};
    Test("Test2", numbers_2, sizeof(numbers_2)/sizeof(int), "321323");
    
    int numbers_3[] = {3, 323, 32123};
    Test("Test3", numbers_3, sizeof(numbers_3)/sizeof(int), "321233233");
    
    int numbers_4[] = {1, 11, 111};
    Test("Test4", numbers_4, sizeof(numbers_4)/sizeof(int), "111111");
    
    int numbers_5[] = {321};
    Test("Test5", numbers_5, sizeof(numbers_5)/sizeof(int), "321");
    
    Test("Test6", NULL, 0, "Don't print anything.");
    
    int numbers_7[] = {1, 10, 100, 230};
    Test("Test4", numbers_7, sizeof(numbers_7)/sizeof(int), "100101230");
}

int main(int argc, char **argv)
{
    Test();

    return 0;
}
