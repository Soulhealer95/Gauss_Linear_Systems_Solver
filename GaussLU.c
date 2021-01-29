#include <stdio.h>
#include <stdlib.h>
#include "headers/Matrix.h"
#include "headers/GaussLS.h"



int main(void) {

	int size_m, ret = 0;
	float** Matrix_A;
	float* Vector;

	// Get Matrix Size
	printf("Please enter the size of matrix to process:\n");
	ret = scanf("%d", &size_m);
	if (ret != 1)
	{
		printf("Invalid Value, Please enter an integer value for size of matrix\n");
	}

	// Set up Data Structures
	Vector = malloc(sizeof(float)*size_m);
	get_vector(size_m, Vector);
	Matrix_A = get_matrix(size_m, SET_VAL);
/*
	// Print the Matrix
	print_matrix(size_m, Matrix_A);
	print_vector(size_m, Vector);


	// Swap 2 rows
	Row_Oper(size_m, ROW_SWAP, 0, 1, 0, Matrix_A);
	print_matrix(size_m, Matrix_A);
	
	// Do a R2 -> R2 - 4R1
	Row_Oper(size_m, ROW_OPER, 0, 1, -4, Matrix_A);
	print_matrix(size_m, Matrix_A);
	vec_oper(size_m, ROW_OPER, 0, 1, -4, Vector);
	print_vector(size_m, Vector);
*/

	GaussLU(size_m, Matrix_A, Vector);

	// Cleanup
	free(Matrix_A);
	free(Vector);

}
