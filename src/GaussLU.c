/*		Gauss Elimination LU Decomposition
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
#include "../headers/Matrix.h"
#include "../headers/GaussLS.h"



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
	
	// Call Gauss LU Elimination Function
	GaussLU(size_m, Matrix_A, Vector);

	// Cleanup
	free(Matrix_A);
	free(Vector);

}
