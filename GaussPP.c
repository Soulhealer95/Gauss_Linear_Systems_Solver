/*		Gauss Elimination Partial Pivoting
 * Uses Gauss Elimination to Solve System of Linear Equations
 * 
 *
 * Author:					Dated				
 * Shivam S.					29-Jan-21
 * Student, McMasterU
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "headers/Matrix.h"
#include "headers/GaussLS.h"



int main(void) {

	int size_m = 0;
	float** Matrix_A;
	float* Vector;

	// Get Matrix Size
	printf("Please enter the size of matrix to process:\n");
	int ret = scanf("%d", &size_m);
	if (ret != 1)
	{
		printf("Invalid Value!\n");
		return -1;
	}

	// Set up Data Structures
	Vector = malloc(sizeof(float)*size_m);
	printf("Values of Vector b\n");
	get_vector(size_m, Vector);
	Matrix_A = get_matrix(size_m, SET_VAL);
	
	// Perform Gauss Elimination Using Partial Pivoting
	GaussPP(size_m, Matrix_A, Vector);

	// Cleanup
	free(Matrix_A);
	free(Vector);

}
