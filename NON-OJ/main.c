#include <stdio.h>
#include <string.h>
#include "matrix.h"
// #include "matrix.c"

int flag = 0;

void solve(int q, Matrix *M[q])
{
    for (int v = 0; v < q; v++)
    {
        flag = 0; 
        char str[20];
        int n;
        scanf("%s %d", str, &n);
        if (n == 0)
        {
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
                if (r1 != r2 || c1 != c2)
                {
                    M[v] = NULL;
                }
                else
                {
                    M[v] = add_matrix(A, B);
                }
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
                if (r1 != r2 || c1 != c2)
                {
                    M[v] = NULL;
                }
                else
                {
                    M[v] = mult_matrix(A, B);
                }
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
                M[v] = scalar_mult_matrix(s, A);
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
                M[v] = transpose_matrix(A);
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
                M[v] = create_matrix(1, 1); 
                M[v]->data[0][0] = determinant(A);
                destroy_matrix(A);
            }
        }
    }
}

int main()
{
    int q;
    scanf("%d", &q);
    Matrix *M[q];

    solve(q, M);

    for (int i = 0; i < q; i++)
    {
        if (M[i] == NULL)
        {
            printf("ERROR: INVALID ARGUMENT\n"); 
        }
        else
        {
            if (flag == 1)
            {
                if (M[i]->data[0][0] == -1)
                {
                    printf("ERROR: INVALID ARGUMENT\n");
                }
                else
                {
                    printf("%lld\n", M[i]->data[0][0]); 
                }
            }
            else
            {
                print_matrix(M[i]);
                destroy_matrix(M[i]);
            }
        }
    }

    return 0;
}
