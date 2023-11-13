#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix *create_matrix(int r, int c) // Given
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int **)calloc(r, sizeof(long long int *));
    for (int i = 0; i < r; i++)
    {
        m->data[i] = (long long int *)calloc(c, sizeof(long long int));
    }
    return m;
}

// AQ1: Code to free all memory used by the matrix stored in m
void destroy_matrix(Matrix *m)
{
    for (int i = 0; i < m->num_rows; i++)
    {
        free(m->data[i]);
    }
    free(m->data);
}

// AQ2: Code to add the matrices A and B and return a new matrix with the results.
Matrix *add_matrix(Matrix *A, Matrix *B)
{
    if (((A->num_rows) != (B->num_rows)) || ((A->num_cols) != (B->num_cols)))
    {
        return NULL;
    }

    Matrix *R = create_matrix(A->num_rows, A->num_cols);
    for (int i = 0; i < R->num_rows; i++)
    {
        for (int j = 0; j < R->num_cols; j++)
        {
            (R->data[i][j]) = (A->data[i][j]) + (B->data[i][j]);
        }
    }
    return R;
}

// AQ3: Code to multiply the matrices A and B and return a new matrix with the results.
Matrix *mult_matrix(Matrix *A, Matrix *B)
{
    if (A->num_cols != B->num_rows)
    {
        printf("hello");
        return NULL;
    }

    Matrix *R = create_matrix(A->num_rows, B->num_cols);

    for (int i = 0; i < R->num_rows; i++)
    {
        for (int j = 0; j < R->num_cols; j++)
        {
            R->data[i][j] = 0;
            for (int k = 0; k < A->num_cols; k++)
            {
                R->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }

    return R;
}

// AQ4: Code to multiply the matrix A with a scalar s and return a new matrix with the results.
Matrix *scalar_mult_matrix(long long int s, Matrix *M)
{
    Matrix *A = create_matrix(M->num_rows, M->num_cols);
    for (int i = 0; i < A->num_rows; i++)
    {
        for (int j = 0; j < A->num_cols; j++)
        {
            (A->data[i][j]) = s * (M->data[i][j]);
        }
    }
    return A;
}

// AQ5: write code here to find the transpose of given matrix A and return a new matrix with the results.
Matrix *transpose_matrix(Matrix *A)
{
    Matrix *R = create_matrix(A->num_cols, A->num_rows);
    for (int i = 0; i < R->num_rows; i++)
    {
        for (int j = 0; j < R->num_cols; j++)
        {
            R->data[i][j] = A->data[j][i];
        }
    }
    return R;
}

// For AQ6: Code to create a sub-matrix from a given matrixx by deleting a particular row and col
Matrix *create_submatrix(Matrix *M, int removed_row, int removed_col)
{
    Matrix *sub = create_matrix((M->num_rows - 1), (M->num_cols) - 1);

    int r = 0;
    for (int i = 0; i < M->num_rows; i++)
    {
        if (i == removed_row)
        {
            continue;
        }

        int c = 0;
        for (int j = 0; j < M->num_cols; j++)
        {
            if (i == removed_col)
            {
                continue;
            }
            sub->data[r][c] = M->data[i][j];
            c++;
        }
        r++;
    }

    return sub;
}

// AQ6: Code to calculate the determinant of the given matrix M
long long int determinant(Matrix *M)
{
    if (M->num_cols != M->num_rows)
    {
        return -1;
    }
    if (M->num_cols == 1 && M->num_rows == 1)
    {
        return M->data[0][0];
    }
    if (M->num_cols == 2 && M->num_rows == 2)
    {
        return ((M->data[0][0]) * (M->data[1][1])) - ((M->data[0][1]) * (M->data[1][0]));
    }

    long long detM = 0;
    int sign = 1;
    for (int i = 0; i < M->num_cols; i++)
    {
        Matrix *sub = create_submatrix(M, 0, i);
        detM += sign * M->data[0][i] * determinant(sub);
        sign = -sign;
        destroy_matrix(sub);
    }
    return detM;
}

// Given
void print_matrix(Matrix *m)
{
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix *read_matrix_from_file(char *name)
{
    char buffer[100], **check;
    FILE *fptr = fopen(name, "r");
    if (fptr == NULL)
    {
        // printf("ERROR: INVALID ARGUMENT");
        return NULL;
    }
    long long int r, c;

    if (fscanf(fptr, "%s", buffer) == 1)
    {
        r = strtoll(buffer, check, 10);
    }
    if (fscanf(fptr, "%s", buffer) == 1)
    {
        c = strtoll(buffer, check, 10);
    }
    Matrix *A = create_matrix(r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            fscanf(fptr, "%s", buffer);
            A->data[i][j] = strtoll(buffer, check, 10);
        }
    }
    fclose(fptr);
    return A;
}

void write_matrix_to_file(char *name, Matrix A)
{
    FILE *fptr = fopen(name, "w");
    if (fptr == NULL)
    {
        printf("ERROR: INVALID ARGUMENT");
    }
    fprintf(fptr, "%d %d\n", A.num_rows, A.num_cols);
    for (int i = 0; i < A.num_rows; i++)
    {
        for (int j = 0; j < A.num_cols; j++)
        {
            fprintf(fptr, "%lld ", A.data[i][j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}