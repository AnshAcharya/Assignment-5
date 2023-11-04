#ifndef MATRIX_H
#define MATRIX_H

typedef struct Matrix Matrix; // Given

Matrix *create_matrix(int r, int c); // Given

void destroy_matrix(Matrix *m); // Q1

Matrix *add_matrix(Matrix *A, Matrix *B);// Q2

Matrix *mult_matrix(Matrix *A, Matrix *B);// Q3

Matrix *scalar_mult_matrix(long long int s, Matrix *M);// Q4

Matrix *transpose_matrix(Matrix *A); // Q5

long long int determinant(Matrix *M); //Q6

Matrix *create_submatrix(Matrix *M, int removed_row, int removed_col); // For question 6

void print_matrix(Matrix *m);

#endif
