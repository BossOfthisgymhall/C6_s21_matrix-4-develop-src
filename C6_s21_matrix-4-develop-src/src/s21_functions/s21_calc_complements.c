#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int err_flag = OK;
  if (!A) return INCORRECT_MATRIX;
  if ((A->matrix == NULL)) return INCORRECT_MATRIX;
  if ((A->columns < 1 || A->rows < 1)) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALCULATION_ERROR;
  matrix_t minor_tmp = {0};
  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1 && A->columns == 1)
    result->matrix[0][0] = 1;
  else {
    s21_create_matrix(A->rows - 1, A->columns - 1, &minor_tmp);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double deter_res = 0;
        err_flag = s21_minor(A, &minor_tmp, i, j);
        err_flag = s21_determinant(&minor_tmp, &deter_res);
        result->matrix[i][j] = deter_res * powf(-1, (i + j));
      }
    }
    s21_remove_matrix(&minor_tmp);
  }
  return err_flag;
}

int s21_minor(matrix_t *A, matrix_t *result, int ignore_row, int ignore_col) {
  int minor_col = 0, minor_row = 0;
  if (A->rows == 1 && A->columns == 1) return result->matrix[0][0] = 1;
  for (int i = 0; i < A->rows; i++) {
    if (i == ignore_row) continue;
    minor_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == ignore_col) continue;
      result->matrix[minor_row][minor_col] = A->matrix[i][j];
      minor_col++;
    }
    minor_row++;
  }
  return OK;
}
