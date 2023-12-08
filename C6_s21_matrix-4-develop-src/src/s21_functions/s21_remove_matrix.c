#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int index_rows = 0; index_rows < A->rows; index_rows++) {
      if (A->matrix[index_rows] != NULL) {
        free(A->matrix[index_rows]);
      }
    }
    free(A->matrix);
  }
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}