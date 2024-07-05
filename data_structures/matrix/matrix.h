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
 * @return the new allocated matrix.
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
 * @brief perform [A]T = [B]
 * 
 * @param[in] A matrix A
 * @param[out] B matrix B
 * @param row number of rows
 * @param col number of columns
 * @return none.
 */
void transposeMatrix(int** A, int** B, int rowA, int colA);

/**
 * @brief perform [A] + [B] = [C]
 * 
 * @param[in] A matrix A
 * @param[in] B matrix B
 * @param rowA number of rows
 * @param colA number of columns
 * @return none.
 */
void addMatrices(int** A, int** B, int** C, int row, int col);

/**
 * @brief perform [A] - [B] = [C]
 * 
 * @param A matrix A
 * @param B matrix B
 * @param C matrix C
 * @param row number of rows
 * @param col number of columns
 * @return none.
 */
void subtractMatrices(int** A, int** B, int** C, int row, int col);

/**
 * @brief  Perform [A] x [B] = [C] matrix multiplication
 * 
 * Allocate an array of pointer of int pointer, and after, affect allocated array of int pointer to each pointer of pointer.
 * So, the returned matrix behave exactly like normal 2D array in memory.
 * Normal 2D array behave in memory like this -> [0,0] [0,1] [0,2] ... [1,0] [1,1] [1,2]....
 * All elements of a row are contiguous per column and each set of row elements are also contiguous in memory for normal 2D array.
 * 
 * The algorithm used here have O(n^3) time complexity. There are other more efficient algorithm like the Strassen's Algorithm (O(n^2.81))
 * or the Coppersmith-Winograd Algorithm (O(n^2.376)).
 * 
 * The Strassen's Algorithm is more efficient for large algorithm and the Coppersmith-Winograd Algorithm is more complex to implement but faster for very large matrices.
 * 
 * @param[in]  A matrix A
 * @param[in]  B matrix B
 * @param[out]  C matrix C
 * @param rowA number of rows of the matrix A
 * @param colA number of columns of the matrix A
 * @param colB number of columns of the matrix B
 * @return none.
 */
void multiplyMatrices(int** A, int** B, int** C, int rowA, int colA, int colB);

#endif