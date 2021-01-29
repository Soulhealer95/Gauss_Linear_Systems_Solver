#ifndef GAUSLS_H
#define GAUSLS_H

#define ROW_SWAP 1
#define ROW_OPER 2
#define SET_VAL 1
#define SET_ZERO 0



/*			Upper_TLS
 * Desc: 
 * Solve Upper Triangular Linear Systems Equation
 * 		Ax = b
 *
 * Args:
 * @int		size		Size of Square Matrix
 * @float**	Matrix  	Square Matrix (A)
 * @float*	Vector		Array with (b) Values
 *
 * Returns:
 * N/A
 */
void Upper_TLS(int size, float** Matrix, float* Vector) {
	
	// Temp on Stack
	float temp_arr[size];

	// Loop backwards to compute x
	for(int i = size-1; i >= 0; i--) {
		if(Matrix[i][i] == 0) {
			printf("Matrix is Singular! Exiting!\n");
			return;
		}
		temp_arr[i] = Vector[i]/Matrix[i][i];
		for(int j = i-1; j >= 0; j--) {
			Vector[j] = Vector[j] - (Matrix[j][i] * temp_arr[i]);
			printf("Upper_TLS(): After Elimination at %i, b:\n", j);
			print_vector(size, Vector);
		}
	}
	
	// Print results
	printf("Final Result:\n");
	printf("A:\n");
	print_matrix(size, Matrix);
	printf("b:\n");
	print_vector(size, Vector);
	printf("x:\n");
	print_vector(size, (float*) temp_arr);

	return;
}



/*			GaussPP
 * Desc: 
 * Solves Linear System Equation with Gauss Elimination
 * Using Partial Pivoting and Upper_TLS function
 * Prints the result
 * 		
 * Args:
 * @int		size		Size of Square Matrix
 * @float**	Matrix  	Square Matrix
 * @float*	Vector		Array with (b) Values
 *
 * Returns:
 * N/A
 */

void GaussPP(int size, float** Matrix, float* Vector) {

	float** temp_arr = get_matrix(size, SET_ZERO);
	int temp_num1, temp_num2 = 0;
	
	// Print Original Matrix
	printf("Starting Values:\n");
	printf("A:\n");
	print_matrix(size, Matrix);
	printf("b:\n");
	print_vector(size, Vector);



	for(int k =0; k < size; k++) {
		// reset high_r to 0 for each column
		int high_r = k;

		// Find biggest value row in current column
		for(int j=k+1; j < size; j++) {
			if(abs(Matrix[high_r][k]) < abs(Matrix[j][k])) {
			       high_r = j;
			}	       
		}

		// if highest val row isn't the same as current, swap rows
		if (high_r != k) {
			printf("Swapping rows %i and %i\n", k, high_r);
			Row_Oper(size, ROW_SWAP, k, high_r, 0, Matrix);
			Row_Oper(size, ROW_SWAP, k, high_r, 0, temp_arr);
			vec_oper(size, ROW_SWAP, k, high_r, 0, Vector);

			// Print status of matrix after each pivot swap
			printf("After Row Swap:\n");
			printf("A:\n");
			print_matrix(size, Matrix);
			printf("L:\n");
			print_matrix(size, temp_arr);
			printf("b:\n");
			print_vector(size, Vector);
			
		}

		// skip current column if zero
		if (Matrix[k][k] == 0){
			continue;
		}

		// Compute Multipliers for current column
		for(int i = k+1; i < size; i++) {
			temp_arr[i][k] = Matrix[i][k]/Matrix[k][k];
			Matrix[i][k] = 0;
		}

		// Apply Transformation to submatrix remaining
		for(int j = k+1; j < size; j++) {
			for(int i = k+1; i < size; i++) {
				Matrix[i][j] = Matrix[i][j] - (temp_arr[i][k] * Matrix[k][j]);
				printf("After Elimination at %i, A:\n", j);
				print_matrix(size, Matrix);
			}
			Vector[j] = Vector[j] - (temp_arr[j][k] * Vector[k]);
			printf("After Elimination, b:\n");
			print_vector(size, Vector);
		}

	}

	// Print Result from Gauss Partial Pivot
	printf("Pre Result\n");
	printf("A:\n");
	print_matrix(size, Matrix);
	printf("L:\n");
	print_matrix(size, temp_arr);
	printf("b:\n");
	print_vector(size, Vector);

	// Solve the resulting Upper Triangular Linear System Equations
	Upper_TLS(size, Matrix, Vector);

	// Cleanup
	free(temp_arr);



}




/*			GaussLU
 * Desc: 
 * Solves Linear System Equation with Gauss Elimination
 * Can not be used if first term of Matrix is 0
 *
 * Prints the Matrix and Result
 * Relies on Upper_TLS()
 * 		
 * Args:
 * @int		size		Size of Square Matrix
 * @float**	Matrix  	Square Matrix
 * @float*	Vector		Array with (b) Values
 *
 * Returns:
 * N/A
 */
void GaussLU(int size, float** Matrix, float* Vector) {

	float** temp_arr = get_matrix(size, SET_ZERO);

	// Print Original Matrix
	printf("Starting Values:\n");
	printf("A:\n");
	print_matrix(size, Matrix);
	printf("b:\n");
	print_vector(size, Vector);


	// Sanity Check
	if(Matrix[0][0] == 0) {
		printf("A[0][0] = 0! LU Factorization can't be done!\n");
		return;
	}

	// Calculate
	for (int k = 0; k < size-1; k++) {
		// Compute Multipliers
		for(int i = k+1; i < size; i++)
		{
			temp_arr[i][k] = Matrix[i][k] / Matrix[k][k];
			Matrix[i][k] = 0;
		}


		for(int j = k+1; j < size; j++) {
			for(int l = k+1; l < size; l++) {
				Matrix[l][j] = Matrix[l][j] - (temp_arr[l][k] * Matrix[k][j]);
				printf("After Elimination at %i, A:\n", l);
				print_matrix(size, Matrix);
			}
			Vector[j] = Vector[j] - (temp_arr[j][k] * Vector[k]);
			printf("After Elimination, b:\n");
			print_vector(size, Vector);
		}
	}

	// Print Results
	printf("Pre Result:\n");
	printf("A:\n");
	print_matrix(size, Matrix);
	printf("L:\n");
	print_matrix(size, temp_arr);
	printf("b:\n");
	print_vector(size, Vector);

	// Solve the Linear System Equation
	Upper_TLS(size, Matrix, Vector);

	// Cleanup
	free(temp_arr);

}



#endif
