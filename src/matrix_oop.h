#include <string.h>

#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

class Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated

  void create_matrix(int rows, int cols);
  void RemoveMatrix();

 public:
  // Destructor
  ~Matrix();

  // Default constructor
  Matrix();
  // Default constructor with editable rows, cols
  Matrix(int rows, int cols);
  // Конструктор копирования
  Matrix(const Matrix& other);
  // Конструктор переноса
  Matrix(Matrix&& other);
  int GetRows() const;
  int GetCols() const;
  // Добавить проверку на элемент
  double GetNum(int row, int col) const;
  int SetNum(int row, int col, double value);
  void Print();

  bool EqMatrix(const Matrix& other);
  void SumMatrix(const Matrix& other);
  void SubMatrix(const Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const Matrix& other);
  // Заполнение матрицы с помощью массива
  void FillMatrix(double* value);
  // Вывод всех элементов матрицы
  void PrintAllElements();

  Matrix Transpose();
  double Determinant();
  Matrix findMinor(int row, int col) const;
  Matrix CalcComplements();
  Matrix InverseMatrix();

  Matrix& operator=(const Matrix& other);
  Matrix operator+(const Matrix& other);
  Matrix operator-(const Matrix& other);
  double& operator()(int row, int col);
  Matrix operator*(const Matrix& other);
  Matrix operator*(const double num);
  bool operator==(const Matrix& other);
  void operator+=(const Matrix& other);
  void operator-=(const Matrix& other);
  void operator*=(const Matrix& other);
  void operator*=(const double num);
  void SetCols(int num);
  void SetRows(int newRows);
};