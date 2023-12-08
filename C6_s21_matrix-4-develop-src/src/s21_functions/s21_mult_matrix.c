#include "../s21_matrix.h"
void s21_mult(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result) return INCORRECT_MATRIX;
  if ((A->rows < 1 || A->columns < 1) || (B->rows < 1 || B->columns < 1))
    return INCORRECT_MATRIX;
  if (A->matrix == NULL || B->matrix == NULL) return INCORRECT_MATRIX;
  if (B->rows != A->columns) return CALCULATION_ERROR;
  s21_create_matrix(A->rows, B->columns, result);
  s21_mult(A, B, result);

  return OK;
}

void s21_mult(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
}