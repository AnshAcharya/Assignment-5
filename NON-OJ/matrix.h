
typedef struct Matrix // Given
{
    int num_rows;
    int num_cols;
    long long int **data;
} Matrix;

Matrix *create_matrix(int r, int c); // Given

void destroy_matrix(Matrix *m); // AQ1

Matrix *add_matrix(Matrix *A, Matrix *B);// AQ2

Matrix *mult_matrix(Matrix *A, Matrix *B);// AQ3

Matrix *scalar_mult_matrix(long long int s, Matrix *M);// AQ4

Matrix *transpose_matrix(Matrix *A); // AQ5

long long int determinant(Matrix *M); //AQ6

Matrix *create_submatrix(Matrix *M, int removed_row, int removed_col); // For AQuestion 6

void print_matrix(Matrix *m);

Matrix * read_matrix_from_file(char *name);

void write_matrix_to_file(char *name, Matrix A);