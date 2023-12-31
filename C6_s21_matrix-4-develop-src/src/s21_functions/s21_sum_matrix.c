#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result) return INCORRECT_MATRIX;
  if (A->matrix == NULL || B->matrix == NULL) return INCORRECT_MATRIX;
  if (A->rows != B->rows || A->columns != B->columns) return CALCULATION_ERROR;
  if (A->rows < 1 || A->columns < 1) return INCORRECT_MATRIX;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}
