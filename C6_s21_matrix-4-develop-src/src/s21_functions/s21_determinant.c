#include "../s21_matrix.h"
// void print_matrix(matrix_t *A);

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  *result = 0;
  if (!A || !result) return INCORRECT_MATRIX;
  if (A->matrix == NULL) return INCORRECT_MATRIX;
  if (A->columns < 1 || A->rows < 1) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALCULATION_ERROR;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (A->rows == 2) {
    double a = A->matrix[0][0];
    double b = A->matrix[0][1];
    double c = A->matrix[1][0];
    double d = A->matrix[1][1];
    *result = (a * d) - (b * c);
  } else if (A->rows > 2) {
    for (int index_col = 0; index_col < A->columns; index_col++) {
      matrix_t minor = {0};
      res = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      res = s21_minor(A, &minor, 0, index_col);
      double tmp_determ = 0;
      res = s21_determinant(&minor, &tmp_determ);
      *result += A->matrix[0][index_col] * tmp_determ * pow(-1, (index_col));
      s21_remove_matrix(&minor);
    }
  }
  return res;
}
