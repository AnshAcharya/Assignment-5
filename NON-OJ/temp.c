#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    char *in1 = (char *)malloc(100); // Adjust the size as needed
    char *in2 = (char *)malloc(100);
    char *out = (char *)malloc(100);

    if (in1 == NULL || in2 == NULL || out == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    printf("Enter the first input file: ");
    scanf("%s", in1);

    printf("Enter the second input file: ");
    scanf("%s", in2);

    printf("Enter the output file: ");
    scanf("%s", out);

    Matrix *A = read_matrix_from_file(in1);
    Matrix *B = read_matrix_from_file(in2);

    if (A == NULL || B == NULL)
    {
        fprintf(stderr, "Error reading matrices from files\n");
        free(in1);
        free(in2);
        free(out);
        return 1;
    }

    Matrix *result = add_matrix(A, B);

    if (result == NULL)
    {
        fprintf(stderr, "Error adding matrices\n");
        destroy_matrix(A);
        destroy_matrix(B);
        free(in1);
        free(in2);
        free(out);
        return 1;
    }

    write_matrix_to_file(out, *result);

    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(result);

    free(in1);
    free(in2);
    free(out);

    return 0;
}
