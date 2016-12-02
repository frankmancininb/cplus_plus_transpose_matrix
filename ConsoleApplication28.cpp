// ConsoleApplication28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class m_matrix {
public:
	int **aary, i_size;
	m_matrix(int n) {
		i_size = n;
		aary = new int*[n];
		for (int i = 0; i < n; i++) {
			aary[i] = new int[n];
		}
	}
	~m_matrix() {
		for (int i = 0; i < i_size; i++) {
			delete [] aary[i];
		}
		delete [] aary;
	}
	void print_matrix() {
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				std::cout << aary[row][col];
			}
			std::cout << std::endl;
		}

	}

	void fill_matrix(int n) {
		// fill matrix
		int fill = 0;
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				aary[row][col] = fill;
				fill++;
			}

		}
	}
	void transpose_matrix(int n) {
		// fill matrix
		/*
		1 2 3 4
		5 6 7 8
		9 10 11 12
		13 14 15 16

		yields

		1 5 9 13
		2 6 10 14
		3 7 11 15
		4 8 12 16*/
		// create new matrix
		int **save_matrix = NULL;
		for (int i = 0; i < n; i++) {
			save_matrix = new int *[n];
			for (int j = 0; j < n; j++) {
				save_matrix[j] = new int[n];
			}
		}

		int fill = 0;
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				save_matrix[row][col] = fill;
				fill++;
			}

		}
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				aary[col][row] = save_matrix[row][col];
				
			}

		}
		for (int i = 0; i < n; i++) {
			
				delete []save_matrix[i];
			}
			delete []save_matrix;
	}
	void zero_edges_matrix(int n) {
		//zero the edges
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (row == 0 || row == n - 1)
					aary[row][col] = 0;
				if (col == 0 || col == n - 1)
					aary[row][col] = 0;
			}

		}
	}
};
int main()
{
	/*
	Given a square grid of dimension N, we'd like to do two things:
		- zero the points along the edges
		- transpose it in - place

		eg N = 4 (zeroing function) :

		1 2 3 4
		5 6 7 8
		9 10 11 12
		13 14 15 16

		yields

		0 0 0 0
		0 6 7 0
		0 10 11 0
		0 0 0 0

		eg N = 4 (transpose function) :

		1 2 3 4
		5 6 7 8
		9 10 11 12
		13 14 15 16

		yields

		1 5 9 13
		2 6 10 14
		3 7 11 15
		4 8 12 16*/

	//dynamically allocated matrix

	int n = 4;

	m_matrix mmatrix(n);


	mmatrix.fill_matrix(n);
	
	mmatrix.print_matrix();
	
	mmatrix.zero_edges_matrix(n);

	mmatrix.print_matrix();

	mmatrix.fill_matrix(n);

	mmatrix.transpose_matrix(n);

	mmatrix.print_matrix();

    return 0;
}

