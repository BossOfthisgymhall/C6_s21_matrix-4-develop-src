#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int err_flag = OK;
  if (result != NULL) {
    result->rows = rows;
    result->columns = columns;
    if (result->rows < 1 || result->columns < 1) {
      err_flag = INCORRECT_MATRIX;
    } else {
      result->matrix = (double **)calloc(rows, sizeof(double *));
      if (result->matrix == NULL) return INCORRECT_MATRIX;
      for (int index_rows = 0; index_rows < rows; index_rows++) {
        result->matrix[index_rows] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[index_rows] == NULL) return INCORRECT_MATRIX;
      }
    }
  } else {
    err_flag = INCORRECT_MATRIX;
  }
  return err_flag;
}