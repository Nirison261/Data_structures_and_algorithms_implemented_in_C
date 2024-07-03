/**
 * @file matrix.h
 */

#ifndef MATRIX_H_
#define MATRIX_H_

/**
 * @brief  Allocate a new matrix in memory.
 * 
 * Ensure that this function is executed atomically on a multithreaded program so that the allocated rows (array of int array) and the allocated columns (int arrays) are contigous in memory, ensuring that it behaves exactly like a normal 2D array, even if it is stored on heap.
 * 
 * @param  rows number of rows of the new matrix
 * @param  cols number of columns of the new matrix
 * @return returns the new allocated matrix.
 */
int **allocateMatrix(int rows, int cols);

/**
 * @brief  Free previously allocated matrix in memory.
 * 
 * Rows are freed one by one (one row -> one int array) and columns are freed only one time because it is just an array of int pointer
 * 
 * @param  matrix the matrix to be freed.
 * @param  rows the number of rows of the matrix.
 * @return none.
 */
void freeMatrix(int **matrix, int rows);

/**
 * @brief  Perform [A] x [B] = [C] matrix multiplication
 * 
 * Allocate an array of pointer of int pointer, and after, affect allocated array of int pointer to each pointer of pointer.
 * So, the returned matrix behave exactly like normal 2D array in memory.
 * Normal 2D array behave in memory like this -> [0,0] [0,1] [0,2] ... [1,0] [1,1] [1,2]....
 * All elements of a row are contiguous per column and each set of row elements are also contiguous in memory for normal 2D array
 * 
 * @param[in]  matrixA matrix A
 * @param[in]  matrixB matrix B
 * @param[out]  matrixC matrix C
 * @return none.
 */
void multiplyMatrices(int** matrixA, int** matrixB, int** matrixC, int rowA, int colA, int colB);

#endif