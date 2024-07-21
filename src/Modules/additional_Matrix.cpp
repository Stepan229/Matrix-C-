#include "../matrix_oop.h"

// void Matrix::PrintAllElements(){
//     for (int row = 0; row < rows_; row++){
//         for (int col = 0; col < cols_; col++){
//             cout << matrix_[row][col] << "\t" << ends;
//         }
//         cout << " " << endl;
//     }
//     cout << " " << endl;
// }

void Matrix::FillMatrix(double *value) {
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[0][i] = value[i];
  }
}

int Matrix::GetRows() const { return rows_; }

int Matrix::GetCols() const { return cols_; }

void Matrix::SetCols(int newCols) {
  if (newCols <= 0) throw logic_error("different matrix dimensions.");
  Matrix newMatrix(rows_, newCols);
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < newCols; col++) {
      if (col >= cols_)
        newMatrix(row, col) = 0;
      else
        newMatrix(row, col) = matrix_[row][col];
    }
  }
  *this = newMatrix;
}

void Matrix::SetRows(int newRows) {
  if (newRows <= 0) throw logic_error("different matrix dimensions.");
  Matrix newMatrix(newRows, cols_);
  for (int row = 0; row < newRows; row++) {
    for (int col = 0; col < cols_; col++) {
      if (row >= rows_)
        newMatrix(row, col) = 0;
      else
        newMatrix(row, col) = matrix_[row][col];
    }
  }
  *this = newMatrix;
}

// Добавить проверку на элемент
double Matrix::GetNum(int row, int col) const { return matrix_[row][col]; }

// int Matrix::SetNum(int row, int col, double value){
//     if (row > rows_ || col > cols_ || row < 0 || col < 0)
//         return -1;
//     matrix_[row][col] = value;
//     return 0;
// }
