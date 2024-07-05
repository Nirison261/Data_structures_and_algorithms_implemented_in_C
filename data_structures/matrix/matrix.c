#include "matrix.h"
#include <stdlib.h>

int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    int i;
    for (i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int rows) {
    int i;
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void transposeMatrix(int** A, int** B, int rowA, int colA) {
    int i, j; 
    for (i = 0; i < colA; i++)
        for (j = 0; j < rowA; j++) 
            B[i][j] = A[j][i]; 
}

void addMatrices(int** A, int** B, int** C, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int** A, int** B, int** C, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int** A, int** B, int** C, int rowA, int colA, int colB) {
    int i, j, k;
    for (i = 0; i < rowA; i++) {
        for (j = 0; j < colB; j++) {
            C[i][j] = 0; // Initialize the result matrix element to 0
            for (k = 0; k < colA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}