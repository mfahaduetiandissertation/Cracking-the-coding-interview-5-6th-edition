#include <iostream>
using namespace std;

void nullifyMatrix( int ** matrix, int M, int N ) {
	bool firstRow = false;
	bool *r,*c;
	r = new bool[M];
	fill_n(r, M, 0);
	c = new bool[N];
	fill_n(c, N, 0);

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (matrix[i][j] == 0) {
				r[i] = 1;
				c[j] = 1;
			}
		}
	}
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (r[i] == 1) {
				matrix[i][j] = 0;
			}
			if (c[j] == 1) {
				matrix[i][j] = 0;
			}
		}
	}
}

void printMatrix( int ** matrix, int M, int N ) {
	for ( int i = 0; i < M; ++i ) {
		for ( int j = 0; j < N; ++j ) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main()
{
	int M, N;
	std::cout << "Enter number of rows:";
	std::cin >> M;
	std::cout << "Enter number of cols:";
	std::cin >> N;
	int ** matrix = new int*[M];
	for ( int i =0; i < M; ++i ) {
		matrix[i] = new int[N];
	}
	std::cout << "Provide M x N matrix \n";
	for ( int i = 0; i < M; ++i ) {
		for ( int j = 0; j < N; ++j ) {
			matrix[i][j]=(int)(rand() % 10);// populate matrix with random ints between 1 and 10
		}
	}

	std::cout << "Matrix Before:\n";
	printMatrix(matrix, M, N);
	nullifyMatrix(matrix, M, N);
	std::cout << "Matrix After:\n";
	printMatrix(matrix, M, N);
	return 0;
}
