#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(void){
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	struct matrix matrix_base = create_matrix(data, 3, 3);
	struct matrix matrix_z = zeros_matrix(5, 4);
	struct matrix matrix_rand = random_matrix(4, 3, 1, 10);
	struct matrix matrix_i = i_matrix(3);

	printf("Matriz base: \n");
	print_matrix(matrix_base);
	printf("\nMatriz de zeros: \n");
	print_matrix(matrix_z);
	printf("\nMatriz random: \n");   /*matriz_cm = matrix_base*/
	print_matrix(matrix_rand);
	printf("\nMatriz identidade: \n");
	print_matrix(matrix_i);

	printf("\nPegar o elemento (0,1) da matriz identidade: %d\n", get_element(matrix_i, 0, 1));
	printf("\nColocar o elemento 9 em (0,1) na matriz identidade: \n");
	put_element(matrix_i, 0, 1, 9);
	print_matrix(matrix_i);

	printf("\nMatriz random transposta: \n");
	print_matrix(transpose(matrix_rand));
	printf("\nReshape matriz de zeros: \n");
	print_matrix(reshape(matrix_z, 10, 2));
	printf("\nFlatten matriz identidade: \n");
	print_matrix(flatten(matrix_i));
	printf("\nSlice matriz base: \n");
	print_matrix(slice(matrix_base, 0, 1, 0, 3));

	printf("\nSoma da matriz identidade: %d\n", sum(matrix_i));
	printf("\nMédia da matriz base: %f\n", mean(matrix_base));
	printf("\nMínimo da matriz random: %d\n", min(matrix_rand));
	printf("\nMáximo da matriz random: %d\n", max(matrix_rand));

	printf("\nAdição matriz identidade e matriz base: \n");
	print_matrix(add(matrix_i, matrix_base));
	printf("\nSubtração matriz identidade e matriz base: \n");
	print_matrix(sub(matrix_base, matrix_i));
	printf("\nDivisão matriz identidade e matriz base: \n");
	print_matrix(division(matrix_i, matrix_base));
	printf("\nMultiplicação matriz identidade e matriz base: \n");
	print_matrix(mul(matrix_i, matrix_base));
	printf("\nMultiplicação de matriz entre matriz identidade e matriz base: \n");
	print_matrix(matmul(matrix_i, matrix_base));

	return 0;
}
