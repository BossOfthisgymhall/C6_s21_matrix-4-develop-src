#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int err_flag = OK;
  if (!A || !B || !result) return INCORRECT_MATRIX;
  if (A->matrix == NULL || B->matrix == NULL) return INCORRECT_MATRIX;
  if (A->rows != B->rows || B->columns != A->columns) return CALCULATION_ERROR;
  if ((A->rows < 1 || A->columns < 1) || (B->rows < 1 || B->columns < 1))
    return INCORRECT_MATRIX;
  err_flag = s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return err_flag;
}