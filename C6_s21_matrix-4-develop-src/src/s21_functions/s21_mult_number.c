#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int err_flag = OK;
  if (!A || !result) return INCORRECT_MATRIX;
  if (A->matrix == NULL) {
    return INCORRECT_MATRIX;
  } else {
    err_flag = s21_create_matrix(A->rows, A->columns, result);
    if (A->rows < 1 || A->columns < 1) return INCORRECT_MATRIX;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return err_flag;
}