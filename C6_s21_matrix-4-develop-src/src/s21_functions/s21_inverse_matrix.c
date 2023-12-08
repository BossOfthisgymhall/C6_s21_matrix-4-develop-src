#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int err_flag = OK;
  if (A->matrix == NULL) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALCULATION_ERROR;
  if (A->columns < 1 || A->rows < 1) return INCORRECT_MATRIX;
  matrix_t tmp_matrix = {0};
  matrix_t trans_result = {0};
  double deter = 0;
  err_flag = s21_determinant(A, &deter);
  if (deter == 0) {
    err_flag = CALCULATION_ERROR;
  } else if (A->columns == 1) {
    err_flag = s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1 / A->matrix[0][0];
  } else {
    err_flag = s21_calc_complements(A, &tmp_matrix);
    err_flag = s21_transpose(&tmp_matrix, &trans_result);

    err_flag = s21_mult_number(&trans_result, 1 / deter, result);
  }
  s21_remove_matrix(&tmp_matrix);
  s21_remove_matrix(&trans_result);
  return err_flag;
}
