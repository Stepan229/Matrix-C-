
#include "../matrix_oop.h"

void Matrix::create_matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = (double**)new double*[rows_];
  matrix_[0] = new double[rows_ * cols_];
  for (int i = 1; i < rows_; i++) matrix_[i] = matrix_[0] + i * cols_;
  for (int i = 0; i < cols_ * rows_; i++) matrix_[0][i] = 0;
}

// Destructor
Matrix::~Matrix() { RemoveMatrix(); }

// Default constructor
Matrix::Matrix() { create_matrix(3, 3); }

Matrix::Matrix(int rows, int cols) {
  if (rows > 0 && cols > 0) create_matrix(rows, cols);
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  create_matrix(rows_, cols_);
  for (int i = 0; i < rows_ * cols_; i++) matrix_[0][i] = other.GetNum(0, i);
}

// Конструктор переноса
Matrix::Matrix(Matrix&& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;

  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

void Matrix::RemoveMatrix() {
  if (matrix_) {
    delete[] matrix_[0];
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
  }
}
bool Matrix::EqMatrix(const Matrix& other) {
  int eq = true;
  if (rows_ != other.rows_ || cols_ != other.cols_)
    eq = false;
  else {
    for (int i = 0; i < cols_ * rows_; i++) {
      if (fabs(matrix_[0][i] - other.matrix_[0][i]) > 1e-7) {
        eq = false;
        break;
      }
    }
  }
  return eq;
}

void Matrix::SumMatrix(const Matrix& other) {
  if (other.cols_ != cols_ || other.rows_ != rows_)
    throw logic_error("different matrix dimensions.");
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[0][i] += other.matrix_[0][i];
  }
}

void Matrix::SubMatrix(const Matrix& other) {
  if (other.cols_ != cols_ || other.rows_ != rows_)
    throw logic_error("different matrix dimensions.");
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[0][i] -= other.matrix_[0][i];
  }
}

void Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_ * cols_; i++) matrix_[0][i] *= num;
}
// Возможно надо удалить newMatrix
void Matrix::MulMatrix(const Matrix& other) {
  if (cols_ == other.rows_) {
    Matrix newMatrix(rows_, other.cols_);
    for (int row = 0; row < rows_; row++) {
      for (int col = 0; col < other.cols_; col++) {
        for (int k = 0; k < cols_; k++)
          newMatrix.matrix_[row][col] +=
              matrix_[row][k] * other.matrix_[k][col];
      }
    }
    *this = newMatrix;
  }
}

Matrix Matrix::Transpose() {
  Matrix newMatrix(cols_, rows_);
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      newMatrix.matrix_[col][row] = matrix_[row][col];
    }
  }
  return newMatrix;
}
double Matrix::Determinant() {
  double result = 0;
  if (rows_ != cols_) throw logic_error("rows != columns");
  if (cols_ == 2)
    result = (matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0]);
  else if (cols_ == 1)
    result = matrix_[0][0];
  else {
    for (int col = 0; col < cols_; col++) {
      Matrix tmp(findMinor(0, col));
      result += powf64(-1, col) * tmp.Determinant() * matrix_[0][col];
    }
  }

  return result;
}

Matrix Matrix::findMinor(int delRow, int delCol) const {
  Matrix M((rows_ - 1), (cols_ - 1));
  // Флаги показывающие прошли ли решающую строку и столбец
  int flagDelRow = 0, flagDelCol = 0;
  for (int row = 0; row < rows_; row++) {
    flagDelCol = 0;
    if (row != delRow) {
      for (int col = 0; col < cols_; col++) {
        if (col != delCol)
          M.matrix_[row - flagDelRow][col - flagDelCol] = matrix_[row][col];
        else
          flagDelCol = 1;
      }
    } else
      flagDelRow = 1;
  }
  return M;
}

Matrix Matrix::CalcComplements() {
  if (rows_ != cols_) throw logic_error("rows != columns");
  Matrix newMatrix(rows_, cols_);
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      Matrix Minor(findMinor(row, col));
      double determinant = Minor.Determinant();
      newMatrix.matrix_[row][col] = powf64(-1, row + col) * determinant;
    }
  }
  return newMatrix;
}

Matrix Matrix::InverseMatrix() {
  if (rows_ != cols_) throw logic_error("rows != columns");
  double determinant = Determinant();
  if (determinant < 1e-7 && determinant > -1e-7)
    throw logic_error("determinant = 0");
  Matrix newMatrix(Transpose().CalcComplements());
  newMatrix.MulNumber(1.0 / determinant);
  return newMatrix;
}

Matrix& Matrix::operator=(const Matrix& other) {
  if (this != &other) {
    RemoveMatrix();
    create_matrix(other.rows_, other.cols_);
    for (int i = 0; i < other.cols_ * other.rows_; i++)
      matrix_[0][i] = other.matrix_[0][i];
  }
  return *this;
}

Matrix Matrix::operator+(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw logic_error("Different matrix dimensions.");
  Matrix newMatrix(cols_, rows_);
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      newMatrix.matrix_[row][col] = matrix_[row][col] + other.matrix_[row][col];
    }
  }
  return newMatrix;
}

Matrix Matrix::operator-(const Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw logic_error("Different matrix dimensions.");
  Matrix newMatrix(cols_, rows_);
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < cols_; col++) {
      newMatrix.matrix_[row][col] = matrix_[row][col] - other.matrix_[row][col];
    }
  }
  return newMatrix;
}

Matrix Matrix::operator*(const Matrix& other) {
  if (cols_ != other.rows_) throw logic_error("Different matrix dimensions.");
  Matrix newMatrix(rows_, other.cols_);
  for (int row = 0; row < rows_; row++) {
    for (int col = 0; col < other.cols_; col++) {
      for (int k = 0; k < cols_; k++)
        newMatrix.matrix_[row][col] += matrix_[row][k] * other.matrix_[k][col];
    }
  }

  return newMatrix;
}

Matrix Matrix::operator*(const double num) {
  Matrix newMatrix(rows_, cols_);
  for (int i = 0; i < rows_ * cols_; i++) matrix_[0][i] *= num;
  return newMatrix;
}

bool Matrix::operator==(const Matrix& other) {
  bool eq = true;
  if (rows_ != other.rows_ || cols_ != other.cols_)
    eq = false;
  else {
    for (int i = 0; i < cols_ * rows_; i++) {
      if (fabs(matrix_[0][i] - other.matrix_[0][i]) > 1e-7) {
        eq = false;
        break;
      }
    }
  }
  return eq;
}

void Matrix::operator+=(const Matrix& other) { SumMatrix(other); }

void Matrix::operator-=(const Matrix& other) { SubMatrix(other); }

void Matrix::operator*=(const double num) { MulNumber(num); }

void Matrix::operator*=(const Matrix& other) { MulMatrix(other); }

double& Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || row > rows_ || col > cols_)
    throw logic_error("Index is outside the matrix.");

  return matrix_[row][col];
}

// int main() {
//     Matrix A(5,3);
//     Matrix B(5,4);
//     double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
//     double arr_b[] = {1, 2, 3,0, 4, 5, 6,0, 7, 10, 11,0, 12, 7.2, 5,0, 1, 0,
//     -3,0}; A.FillMatrix(arr_a); B.FillMatrix(arr_b); A.PrintAllElements();
//     A.SetRows(0);
//     A.PrintAllElements();
// }