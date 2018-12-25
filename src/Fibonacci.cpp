#include <iostream>
#include <exception>
#include <ctime>

using namespace std;

int Fibonacci_recursive(int n)
{
	if(n<0)
		throw new exception();
	if(n<2)
		return n;
	return Fibonacci_recursive(n-1) + Fibonacci_recursive(n-2);
}

int Fibonacci_iterative(int n)
{
	if(n<0)
		throw new exception();
	if(n<2)
		return n;
	long res = 0;
	long f_n_1 = 1, f_n_2 = 0;
	for(int i=2; i<=n; i++) {
		res = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = res;
	}
	
	return res;
}

struct matrix {
	int mat[4];
};

matrix matrix_multiple(matrix mat1, matrix mat2)
{
	matrix res;
	res.mat[0] = mat1.mat[0]*mat2.mat[0] + mat1.mat[1]*mat2.mat[2];
	res.mat[1] = mat1.mat[0]*mat2.mat[1] + mat1.mat[1]*mat2.mat[3];
	res.mat[2] = mat1.mat[2]*mat2.mat[0] + mat1.mat[3]*mat2.mat[2];
	res.mat[3] = mat1.mat[2]*mat2.mat[1] + mat1.mat[3]*mat2.mat[3];
	return res;
}
matrix matrix_calc(int n)
{
	matrix mat;
	mat.mat[0] = 1;
	mat.mat[1] = 1;
	mat.mat[2] = 1;
	mat.mat[3] = 0;
	if(n==1) {
		return mat;
	}
	// n 为偶数时，直接二分法递归 
	if(!(n%2) && n>1) {
		mat =  matrix_calc(n/2);
		mat = matrix_multiple(mat, mat);
		return mat;
	} else if((n%2) && n>1) { // n 为奇数时，先少乘一个，剩下的直接二分法递归 
		mat =  matrix_calc((n-1)/2);
		mat = matrix_multiple(mat, mat);
		//把少乘的补上 
		matrix mat_;
		mat_.mat[0] = 1;
		mat_.mat[1] = 1;
		mat_.mat[2] = 1;
		mat_.mat[3] = 0;
		mat = matrix_multiple(mat,mat_);
		return mat;
	}
}

int Fibonacci_matrix(int n)
{
	if(n<0)
		throw new exception();
	if(n<2)
		return n;
	matrix mat = matrix_calc(n-1);
	return mat.mat[0];
}

void Test(int n)
{
	try {
		int start, end;
		start = clock();
		cout << "recursive: " << Fibonacci_recursive(n);
		end = clock();
		cout << " time complexity: " << end-start << endl;
		start = clock();
		cout << "iterative: " << Fibonacci_iterative(n);
		end = clock();
		cout << " time complexity: " << end-start << endl;
		start = clock();
		cout << "matrix: " << Fibonacci_matrix(n);
		end = clock();
		cout << " time complexity: " << end-start << endl;
	} catch(...) {
		cout << "capture exception" << endl;
	}
}

int main(int argc, char** argv)
{
	int n[9] = {-1, 0, 1, 2, 3, 4, 5, 10, 35};
	
	Test(n[0]);
	Test(n[1]);
	Test(n[2]);
	Test(n[3]);
	Test(n[4]);
	Test(n[5]);
	Test(n[6]);
	Test(n[7]);
	cout << "\n It will take some time~~~" << endl;
	Test(n[8]);
	
	return 0;
}
