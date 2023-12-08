#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int err_flag = OK;
  if (!A || !result) return INCORRECT_MATRIX;
  if (A->matrix == NULL) return INCORRECT_MATRIX;
  if (A->rows < 1 || A->columns < 1) return INCORRECT_MATRIX;
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return err_flag;
}
