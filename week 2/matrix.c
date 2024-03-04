#include <stdio.h>
#include <stdlib.h>

struct Matrix {
    int rows;
    int cols;
    int **values;
};

struct Matrix *alloc_matrix(int rows, int cols) {
    struct Matrix *matrix = NULL;
    matrix = malloc(sizeof(struct Matrix));

    matrix->rows = rows;
    matrix->cols = cols;

    matrix->values = (int**)malloc(matrix->rows * sizeof(int*));

    int i;
    for (i = 0; i < matrix->rows; i++)
        matrix->values[i] = (int*)malloc(matrix->cols * sizeof(int));

    return matrix;
}

struct Matrix *read_matrix() {
    int rows, cols;

    printf("Enter number of rows:\n");
    scanf("%d", &rows);
    printf("\n");

    printf("Enter number of cols:\n");
    scanf("%d", &cols);
    printf("\n");

    struct Matrix *matrix = alloc_matrix(rows, cols);

    printf("Enter your matrix values:\n");
    int i, j;
    for (i = 0; i < matrix->rows; i++){
        for (j = 0; j < matrix->cols; j++){
            scanf("%d", &matrix->values[i][j]);
        }
    }
    printf("\n");

    return matrix;
}

void print_matrix(struct Matrix *m){
    printf("Your matrix:\n");
    int i, j;
    for (i = 0; i < m->rows; i++){
        for (j = 0; j < m->cols; j++){
            printf("%d", m->values[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

struct Matrix *multiply_matrix(struct Matrix *M1, struct Matrix *M2) {
    if(M1->cols != M2->rows)
        return NULL;

    struct Matrix *result = alloc_matrix(M1->rows, M2->cols);

    int i, j, k, sum;

    for(i = 0; i < M1->rows; i++){
        for(j = 0; j < M2->cols; j++){
            sum = 0;
            for(k = 0; k < M2->rows; k++){
                sum += (M1->values[i][k] * M2->values[k][j]);
            }
            result->values[i][j] = sum;
        }
    }

    return result;
}

int main() {
    struct Matrix *matrix1 = read_matrix();
    print_matrix(matrix1);

    struct Matrix *matrix2 = read_matrix();
    print_matrix(matrix2);

    struct Matrix *multiplyMatrix = multiply_matrix(matrix1, matrix2);

    if(multiplyMatrix == NULL)
        printf("Cannot multiply specified matrices");

    print_matrix(multiplyMatrix);

    free(matrix1);
    free(matrix2);
    free(multiplyMatrix);

    return 0;
}