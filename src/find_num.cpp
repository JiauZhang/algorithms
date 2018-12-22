#include <iostream>

using namespace std;

bool find_num(int* matrix, int rows, int cols, int find)
{
	int steps = 0;
	if(matrix && cols>0 && rows>0) {
		for(int i=0; i<rows; i++) {
			for(int j=0; j<cols; j++) {
				steps++;
				if(matrix[cols*i+j] == find) {
					cout << "steps: " << steps << endl; 
					return true;					
				}					
			}
		}
	}
	cout << "steps: " << steps << endl;
	return false;
}

bool find_num_top_right(int* matrix, int rows, int cols, int find)
{
	int steps = 0;
	if(matrix && cols>0 && rows>0) {
		int col = cols - 1;
		int row = 0;
		while(col>=0 && row<rows) {
			steps++;
			if(matrix[row*cols+col]>find)
				col--;
			else if(matrix[row*cols+col]<find)
				row++;
			else {
				cout << "steps: " << steps << endl;
				return true;				
			}
		}
	}
	cout << "steps: " << steps << endl;	
	return false;
}

bool find_num_bottom_left(int* matrix, int rows, int cols, int find)
{
	int steps = 0;
	if(matrix && cols>0 && rows>0) {
		int col = 0;
		int row = rows - 1;
		while(col<cols && row>=0) {
			steps++;
			if(matrix[row*cols+col]>find)
				row--;
			else if(matrix[row*cols+col]<find)
				col++;
			else {
				cout << "steps: " << steps << endl;
				return true;				
			}
		}
	}
	cout << "steps: " << steps << endl;
	return false;
}

void Test(int* matrix, int rows, int cols, int num)
{
	bool result = find_num(matrix, rows, cols, num);
	cout << (result?"true":"false") << endl;

	result = find_num_top_right(matrix, rows, cols, num);
	cout << (result?"true":"false") << endl;
	
	result = find_num_bottom_left(matrix, rows, cols, num);
	cout << (result?"true":"false") << endl;
}

int main(int argc, char** argv)
{
	int array_test[5][5] = {1, 2, 3, 4, 5, \
							6, 7, 8, 9, 10, \
							11, 12, 13, 14, 15, \
							16, 17, 18, 19, 20, \
							21, 22, 23, 24, 25};
	
	Test(&array_test[0][0], 5, 5, 1);
	Test(&array_test[0][0], 5, 5, 5);
	Test(&array_test[0][0], 5, 5, 11);
	Test(&array_test[0][0], 5, 5, 13);
	Test(&array_test[0][0], 5, 5, 15);
	Test(&array_test[0][0], 5, 5, 21);
	Test(&array_test[0][0], 5, 5, 25);
	Test(&array_test[0][0], 5, 5, 0);
	
	return 0;
}
