/* Nome: Artur Luis Brito Gurjão
   Matrícula: 20200024903          */

#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
    int *data;
    int n_rows;
    int n_cols;
    int stride_rows;
    int stride_cols;
    int offset;
}my_matrix;


struct matrix create_matrix(int *data, int n_rows, int n_cols);

void print_matrix(struct matrix a_matrix);

struct matrix zeros_matrix(int n_rows, int n_cols);

struct matrix random_matrix(int n_rows, int n_cols, int b, int e);

struct matrix i_matrix(int n);

int get_element(struct matrix a_matrix, int ri, int ci);

void put_element(struct matrix a_matrix, int ri, int ci, int elem);

struct matrix transpose(struct matrix a_matrix);

struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols);

struct matrix flatten(struct matrix a_matrix);

int sum(struct matrix a_matrix);

float mean(struct matrix a_matrix);

int min(struct matrix a_matrix);

int max(struct matrix a_matrix);

struct matrix add(struct matrix a_matrix, struct matrix b_matrix);

struct matrix sub(struct matrix a_matrix, struct matrix b_matrix);

struct matrix division(struct matrix a_matrix, struct matrix b_matrix);

struct matrix mul(struct matrix a_matrix, struct matrix b_matrix);

struct matrix matmul(struct matrix a_matrix, struct matrix b_matrix);

struct matrix slice(struct matrix a_matrix, int rs, int re, int cs, int ce);



#endif