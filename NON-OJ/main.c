#include <stdio.h>
#include <string.h>
#include "matrix.h"
// #include "matrix.c"

int flag = 0;
int n_is = 0;

void solve(int q)
{
    for (int v = 0; v < q; v++)
    {
        flag = 0;
        char str[20];
        int n;
        scanf("%s %d", str, &n);
        if (n == 0)
        {
            n_is = 0;
            if (strcmp(str, "add_matrix") == 0)
            {
                int r1, c1;
                scanf("%d %d", &r1, &c1);
                Matrix *A = create_matrix(r1, c1);
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c1; j++)
                    {
                        scanf("%lld ", &(A->data[i][j]));
                    }
                }
                int r2, c2;
                scanf("%d %d", &r2, &c2);
                Matrix *B = create_matrix(r2, c2);
                for (int i = 0; i < r2; i++)
                {
                    for (int j = 0; j < c2; j++)
                    {
                        scanf("%lld ", &(B->data[i][j]));
                    }
                }
                print_matrix(add_matrix(A, B));
                destroy_matrix(A);
                destroy_matrix(B);
            }
            else if (strcmp(str, "mult_matrix") == 0)
            {
                int r1, c1;
                scanf("%d %d", &r1, &c1);
                Matrix *A = create_matrix(r1, c1);
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c1; j++)
                    {
                        scanf("%lld ", &(A->data[i][j]));
                    }
                }
                int r2, c2;
                scanf("%d %d", &r2, &c2);
                Matrix *B = create_matrix(r2, c2);
                for (int i = 0; i < r2; i++)
                {
                    for (int j = 0; j < c2; j++)
                    {
                        scanf("%lld ", &(B->data[i][j]));
                    }
                }

                print_matrix(mult_matrix(A, B));

                destroy_matrix(A);
                destroy_matrix(B);
            }
            else if (strcmp(str, "scalar_mult_matrix") == 0)
            {
                long long s;
                scanf("%lld", &s);
                int r1, c1;
                scanf("%d %d", &r1, &c1);
                Matrix *A = create_matrix(r1, c1);
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c1; j++)
                    {
                        scanf("%lld ", &(A->data[i][j]));
                    }
                }
                print_matrix(scalar_mult_matrix(s, A));
                destroy_matrix(A);
            }
            else if (strcmp(str, "transpose_matrix") == 0)
            {
                int r1, c1;
                scanf("%d %d", &r1, &c1);
                Matrix *A = create_matrix(r1, c1);
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c1; j++)
                    {
                        scanf("%lld ", &(A->data[i][j]));
                    }
                }
                print_matrix(transpose_matrix(A));
                destroy_matrix(A);
            }
            else if (strcmp(str, "determinant") == 0)
            {
                flag = 1;
                int r1, c1;
                scanf("%d %d", &r1, &c1);
                Matrix *A = create_matrix(r1, c1);
                for (int i = 0; i < r1; i++)
                {
                    for (int j = 0; j < c1; j++)
                    {
                        scanf("%lld ", &(A->data[i][j]));
                    }
                }
                long long int det = determinant(A);
                if (det == -1)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else
                {
                    printf("%lld\n", det);
                }
                destroy_matrix(A);
            }
        }
        else if (n == 1)
        {
            if (strcmp(str, "add_matrix") == 0)
            {
                char *in1 = (char *)malloc(50);
                char *in2 = (char *)malloc(50);
                char *out = (char *)malloc(50);
                scanf("%s", in1);
                scanf("%s", in2);
                scanf("%s", out);
                Matrix *A = read_matrix_from_file(in1);
                Matrix *B = read_matrix_from_file(in2);
                Matrix *result = add_matrix(A, B);
                if (result == NULL)
                {
                    printf("ERROR: INVALID ARGUMENT");
                    continue;
                }
                else
                {
                    write_matrix_to_file(out, *result);

                    destroy_matrix(A);
                    destroy_matrix(B);
                    destroy_matrix(result);

                    free(in1);
                    free(in2);
                    free(out);
                }
            }
            else if (strcmp(str, "mult_matrix") == 0)
            {
                char *in1 = (char *)malloc(50);
                char *in2 = (char *)malloc(50);
                char *out = (char *)malloc(50);
                scanf("%s", in1);
                scanf("%s", in2);
                scanf("%s", out);
                Matrix *A = read_matrix_from_file(in1);
                Matrix *B = read_matrix_from_file(in2);
                Matrix *result = mult_matrix(A, B);
                if (result == NULL)
                {
                    printf("ERROR: INVALID ARGUMENT");
                    continue;
                }
                else
                {
                    write_matrix_to_file(out, *result);

                    destroy_matrix(A);
                    destroy_matrix(B);
                    destroy_matrix(result);

                    free(in1);
                    free(in2);
                    free(out);
                }
            }
            else if (strcmp(str, "scaler_mult_matrix") == 0)
            {
                char *in = (char *)malloc(50), *out = (char *)malloc(50);
                long long int s;
                scanf("%lld", &s);
                scanf("%s", in);
                scanf("%s", out);
                Matrix *A = read_matrix_from_file(in);
                write_matrix_to_file(out, *scalar_mult_matrix(s, A));
                destroy_matrix(A);
                free(in);
                free(out);
            }
            else if (strcmp(str, "determinant") == 0)
            {
                char *in;
                scanf("%s", in);
                Matrix *A = read_matrix_from_file(in);
                long long int det = determinant(A);
                if (det == -1)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else
                {
                    printf("%lld\n", det);
                }
                destroy_matrix(A);
            }
            else if (strcmp(str, "transpose_matrix") == 0)
            {
                char *in, *out;
                scanf("%s\n%s", in, out);
                Matrix *A = read_matrix_from_file(in);
                write_matrix_to_file(out, *A);
                destroy_matrix(A);
            }
        }
    }
}

int main()
{
    int q;
    scanf("%d", &q);
    solve(q);
    return 0;
}