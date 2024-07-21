#include "tests.h"

TEST(testInverseMatr, Subtest_1) {
  Matrix B;
  Matrix A;
  double arr_a[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  double arr_b[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  Matrix C(A.InverseMatrix());
  ASSERT_TRUE(C.EqMatrix(B));
}

TEST(testInverseMatr, Subtest_2) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  double arr_a[] = {4, 3, 6, 3};
  double arr_b[] = {-0.5, 0.5, 1, -0.6666666666666666};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  Matrix C(A.InverseMatrix());
  ASSERT_TRUE(C.EqMatrix(B));
}

TEST(testInverseMatr, Subtest_3) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  double arr_a[] = {1, 2, 3, 4};
  double arr_b[] = {-2, 1, 1.5, -0.5};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  Matrix C(A.InverseMatrix());
  ASSERT_TRUE(C.EqMatrix(B));
}

TEST(testInverseMatr, Subtest_4) {
  Matrix A(3, 2);
  double arr_a[] = {2, 5, 4, -2, 4, 3, 1, 0, -2};
  A.FillMatrix(arr_a);
  ASSERT_THROW(A.InverseMatrix(), logic_error);
}

// Determinant = 0
TEST(testInverseMatr, Subtest_5) {
  Matrix A(3, 3);
  double arr_a[] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9};
  A.FillMatrix(arr_a);
  ASSERT_THROW(A.InverseMatrix(), logic_error);
}
