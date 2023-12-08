#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!A || !B) return FAILURE;
  if (A->matrix == NULL || B->matrix == NULL) return FAILURE;
  if (A->rows != B->rows || A->columns != B->columns) return FAILURE;
  if ((A->rows < 1 || A->columns < 1) || (A->rows < 1 || A->columns < 1))
    return FAILURE;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if ((A->matrix[i][j] != B->matrix[i][j])) {
        if (((fabs(A->matrix[i][j] - B->matrix[i][j])) > EPSILON))
          return FAILURE;
      }
    }
  }
  return SUCCESS;
}
