#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"




struct matrix create_matrix(int *data, int n_rows, int n_cols){
    struct matrix link;

    link.data = data;
    link.n_rows = n_rows;
    link.n_cols = n_cols;
    link.stride_rows = n_cols;
    link.stride_cols = 1;
    link.offset = 0;
    return link;
}

void print_matrix(struct matrix a_matrix){
    int n_rows = a_matrix.n_rows, n_cols = a_matrix.n_cols;

    int size = n_rows*n_cols;

    int i,j;
        for (i=0; i<n_rows;i++) {
            printf("\n");
            if(a_matrix.offset==size)
            break;
            for (j=0;j<n_cols;j++) {
            printf("%d\t",a_matrix.data[a_matrix.offset]);
            a_matrix.offset++;
    }
    }

}

struct matrix zeros_matrix(int n_rows, int n_cols){
    int size=n_rows * n_cols;
    int *array_zero = malloc(size * sizeof(int));

    for (int i = 0; i<size; i++){
        array_zero[i] = 0;
    }

    return create_matrix(array_zero, n_rows, n_cols);
}

struct matrix random_matrix(int n_rows, int n_cols, int b, int e){
    int size = n_rows * n_cols;
    int *array_random= malloc(size * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size ;i++) {
    array_random[i] = (rand() % (e-b)) + b;
    }

    return create_matrix(array_random, n_rows, n_cols);

}

struct matrix i_matrix(int n){
    int size = n*n;
    int *array_i= malloc(size * sizeof(int));

    array_i[0] = 1;

    int count = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (i==j){
                array_i[count] = 1;
            }
            else{
                array_i[count] = 0;
            }
            count++;
        }

    }
    return create_matrix(array_i, n, n);

}

int get_element(struct matrix a_matrix, int ri, int ci){
    int n_rows = a_matrix.n_rows, n_cols = a_matrix.n_cols;
    int size = n_rows * n_cols;

    int element=2;
    int array[n_rows][n_cols];

    int k = 0;
    int i,j;
        for (i=0; i<n_rows;i++) {
            if(k==size)
            break;
            for (j=0;j<n_cols;j++) {
            array[i][j]=a_matrix.data[k];
            if (i==ri && j==ci){
            }

            k++;
    }
    }
    return array[ri-1][ci-1];

}

void put_element(struct matrix a_matrix, int ri, int ci, int elem){
    int index;
    index = (ri*a_matrix.stride_rows) + (ci*a_matrix.stride_cols);

	a_matrix.data[index] = elem;
}

struct matrix transpose(struct matrix a_matrix){
    int rows, cols;

    rows = a_matrix.n_rows;
    cols = a_matrix.n_cols;

    return create_matrix(a_matrix.data,cols, rows);
}

struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols){
    int rows = a_matrix.n_rows;
    int cols = a_matrix.n_cols;
    int size = rows * cols;
    int size_new = new_n_rows * new_n_cols;

    if (size_new>size || size_new<size){
        printf("DIMENSION NOT VALID");
    }
    else{
        return create_matrix(a_matrix.data, new_n_rows, new_n_cols);
    }
}

struct matrix flatten(struct matrix a_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;

    return create_matrix(a_matrix.data, 1, size);

}

int sum(struct matrix a_matrix){
    int sum = 0;
    int size = a_matrix.n_rows * a_matrix.n_cols;
    for (int i = 0; i<size; i++){
        sum = sum + a_matrix.data[i];
    }
    return sum;
}

float mean(struct matrix a_matrix) {
	float sum = 0;
	float size = (a_matrix.n_cols*a_matrix.n_rows);
	int i;

	for (i=0; i<size; i++) {
		sum += a_matrix.data[i];
	}

	return sum/i;
}

int min(struct matrix a_matrix){
    int min = a_matrix.data[0];
    int size = a_matrix.n_rows * a_matrix.n_cols;

    for (int i = 1; i<size; i++){
        if (a_matrix.data[i] < min){
            min = a_matrix.data[i];
        }
    }
    return min;
}

int max(struct matrix a_matrix){
    int max = a_matrix.data[0];
    int size = a_matrix.n_rows * a_matrix.n_cols;

    for (int i = 1; i<size; i++){
        if (a_matrix.data[i] > max){
            max = a_matrix.data[i];
        }
    }
    return max;
}

struct matrix add(struct matrix a_matrix, struct matrix b_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int *sum = malloc(size * sizeof(int));

    for (int i = 0; i<size; i++){
        sum[i] = a_matrix.data[i] + b_matrix.data[i];
    }
    return create_matrix(sum, a_matrix.n_rows, a_matrix.n_cols);
}

struct matrix sub(struct matrix a_matrix, struct matrix b_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int *sum = malloc(size * sizeof(int));

    for (int i = 0; i<size; i++){
        sum[i] = a_matrix.data[i] - b_matrix.data[i];
    }
    return create_matrix(sum, a_matrix.n_rows, a_matrix.n_cols);
}

struct matrix division(struct matrix a_matrix, struct matrix b_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int *sum = malloc(size * sizeof(int));

    for (int i = 0; i<size; i++){
        sum[i] = a_matrix.data[i] / b_matrix.data[i];
    }
    return create_matrix(sum, a_matrix.n_rows, a_matrix.n_cols);
}

struct matrix mul(struct matrix a_matrix, struct matrix b_matrix){
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int *sum = malloc(size * sizeof(int));

    for (int i = 0; i<size; i++){
        sum[i] = a_matrix.data[i] * b_matrix.data[i];
    }
    return create_matrix(sum, a_matrix.n_rows, a_matrix.n_cols);
}

struct matrix matmul(struct matrix a_matrix, struct matrix b_matrix){
    if (a_matrix.n_cols != b_matrix.n_rows){
        printf("DIMENSION NOT VALID: MATRIX 1 N_COLS SHOULD BE EQUAL MATRIX 2 N_ROWS!");
    }
    else{
        int size = a_matrix.n_rows * b_matrix.n_cols;
        int *mul = malloc(size * sizeof(int));

        for (int i = 0; i<size; i++){
            mul[i] = 0;
        }

        int matrix_a[a_matrix.n_rows][a_matrix.n_cols];
        int matrix_b[b_matrix.n_rows][b_matrix.n_cols];

        int k = 0;
        int i,j,f;
        for (i=0; i<a_matrix.n_rows;i++) {
            if(k==a_matrix.n_rows * a_matrix.n_cols)
            break;
            for (j=0;j<a_matrix.n_cols;j++) {
            matrix_a[i][j]=a_matrix.data[k];
            k++;
            }
    }
        k=0;
        for (i=0; i<b_matrix.n_rows;i++) {
            if(k==b_matrix.n_rows * b_matrix.n_cols)
            break;
            for (j=0;j<b_matrix.n_cols;j++) {
            matrix_b[i][j]=b_matrix.data[k];
            k++;

    }}  k=0;
        for (i=0; i<a_matrix.n_rows; i++){
            for (j=0; j<b_matrix.n_cols; j++){
                for (f=0; f<b_matrix.n_rows; f++){
                    mul[k]= mul[k] + matrix_a[i][f] * matrix_b[f][j];
                }
                k++;
            }
        }

    return create_matrix(mul, a_matrix.n_rows, b_matrix.n_cols);
        }
}

struct matrix slice(struct matrix a_matrix, int rs, int re, int cs, int ce){
    /*[rs][cs] > [re-1][ce-1]*/
    int size = a_matrix.n_rows * a_matrix.n_cols;
    int slice[a_matrix.n_rows][a_matrix.n_cols];
    int *prov = malloc(size * sizeof(int));

    int x=0;
    int k = 0;
    int i,j;
    for (i=0; i<a_matrix.n_rows;i++) {
        if(k==a_matrix.n_rows * a_matrix.n_cols)
        break;
        for (j=0;j<a_matrix.n_cols;j++) {
            slice[i][j]=a_matrix.data[k];
            if (i >= rs && i < re && j >= cs && j < ce){
                x++;
                prov[k] = a_matrix.data[k];
            }
            k++;
            }
    }
    return create_matrix(prov, a_matrix.n_rows, a_matrix.n_cols);


}
