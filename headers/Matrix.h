#ifndef MATRIX_H
#define MATRIX_H
#include <string.h>


/*			Get Matrix
 * Desc: 
 * Allocate Memory for a Square Matrix
 *
 * Args:
 * @int	size_m		Size of Square Matrix
 * @int assin_val 	Whether to get user input or not:
 * 				1 - Set a Value using scanf for each member
 * 				2 - Set each member to 0 
 * Returns:
 * Float** 		A pointer to Matrix allocated on the heap
 * 	Caller is responsible for freeing this memory
 */
float** get_matrix(int size_m, int assign_val) {
	
	float** Matrix_A;
	int ret = 0;
	Matrix_A = malloc(size_m * sizeof(*Matrix_A));
	for (int i = 0; i < size_m; i++) {
		Matrix_A[i] = calloc(size_m, sizeof(*Matrix_A[i]));
	}

	// Get Values for Matrix
	if (assign_val != 0) {
		for(int i = 0; i < size_m; i++) {
			for (int j = 0; j < size_m; j++) {
				printf("Please enter Matrix Value for A[%d][%d]\n",i,j); 
				scanf("%f", &Matrix_A[i][j]);
				// TODO Add more Input Validation
			}
		}
	}
	return Matrix_A;
}

/*			Print A Matrix
 * Desc: 
 * Print a Square Matrix
 *
 * Args:
 * @int	size		Size of Square Matrix
 * @float** A		2-D Matrix
 *
 * Returns:
 * N/A
 */
void print_matrix(int size, float** A) {

	for(int i=0; i < size; i++) {

		printf("[");

		for(int j =0; j < size; j++) {
			printf(" %.2f ",A[i][j]);
		}

		printf("]\n");
	}
	printf("\n");
	return;
}


/*		Row_Oper
 * Desc: 
 * Performs Row Operations on a Square Matrix, namely:
 * - Swap
 * - Add a row to another with a scaler
 *
 * Args:
 * @int	size		Size of Square Matrix
 * @int oper_type	Type of Operation to perform:
 * 				1 - Swap Rows
 *	 			2 - Arithmetic operation on Row2
 * @int row1		The first row number
 * @int row2		The 2nd row number (destination)
 * @float scaler 	Multiplies a scaler with a row for more felixbility 
 * @float** Matrix	2-D Matrix
 *
 * Returns:
 * N/A
 */
void Row_Oper(int size, int oper_type, int row1, int row2, float scaler, float** Matrix) {

	float temp_arr[size];
	// Check what to do
	// 1 - Swap Rows
	// 2 - Arithmetic Operation on Row2 using Row1 
	switch(oper_type) {
		// Row1 <---> Row2 (Swap)
		case 1:
			for(int i=0; i < size; i++) {
				// save row1 contents
				temp_arr[i] = Matrix[row1][i];
			}
			// swap rows
			for(int i=0; i < size; i++) {
				Matrix[row1][i] = Matrix[row2][i];
				Matrix[row2][i] = temp_arr[i];
			}
			break;
		// Row2 --> Row2 + (Scaler * Row1)
		case 2:
			if (scaler == 0) {
				scaler = 1;
			}
			for(int i=0; i < size; i++) {
				Matrix[row2][i] = Matrix[row2][i] + (scaler * Matrix[row1][i]);
			}
		default:
			break;
	}
	
	return;

}



// Same Vector Counterparts

// Get a Vector
void get_vector(int size, float * vector) {
	for(int i=0; i < size; i++) {
		printf("Enter the Vector value for index V[%i]:\n", i);
		scanf("%f", &vector[i]);
		//TODO Input Validation
	}
}

// Print a Vector
void print_vector(int size, float* Vector) {
	for (int i=0; i < size; i++) {
		printf("[ %.2f ]\n", Vector[i]);
	}
	printf("\n");
	return;
}

// Perform Row Operations on Vector
// 1 - Row Swap
// 2 - Arithmetic operations on two rows
void vec_oper(int size, int oper_type, int row1, int row2, int scaler, float* vector) {
	float temp;
	switch(oper_type) {
		case 1:
			temp = vector[row1];
			vector[row1] = vector[row2];
			vector[row2] = temp;
			break;
		case 2:
			if (scaler == 0){
				scaler = 1;
			}
			vector[row2] = vector[row2] + (scaler * vector[row1]);
		default:
			break;
		}
	return;
}



#endif
