#include "tests.h"

TEST(testDeterminantMatr, Subtest_1) {
  Matrix A;
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  A.FillMatrix(arr_a);
  ASSERT_EQ(A.Determinant(), 0);
}

TEST(testDeterminantMatr, Subtest_2) {
  Matrix A(4, 4);
  double arr_a[] = {18, 6, 13, 14, 8, 12, 12, 0, 8, 110, 1, 5, 5, 16, 7, 0};
  A.FillMatrix(arr_a);
  ASSERT_EQ(A.Determinant(), 196);
}

TEST(testDeterminantMatr, Subtest_3) {
  Matrix A;
  double arr_a[] = {2, 5, 4, -2, 4, 3, 1, 0, -2};
  A.FillMatrix(arr_a);
  ASSERT_EQ(A.Determinant(), -37);
}

TEST(testDeterminantMatr, Subtest_4) {
  Matrix A;
  double arr_a[] = {0, 0, 0, -2, 4, 3, 1, 0, -2};
  A.FillMatrix(arr_a);
  ASSERT_EQ(A.Determinant(), 0);
}

TEST(testDeterminantMatr, Subtest_5) {
  Matrix A(3, 2);
  double arr_a[] = {2, 5, 4, -2, 4, 3, 1, 0, -2};
  A.FillMatrix(arr_a);
  ASSERT_THROW(A.Determinant(), logic_error);
}

TEST(testDeterminantMatr, Subtest_6) {
  Matrix A(2, 2);
  double arr_a[] = {2, 5, 4, -2};
  A.FillMatrix(arr_a);
  ASSERT_EQ(A.Determinant(), -24);
}

TEST(testDeterminantMatr, Subtest_7) {
  Matrix A(2, 2);
  double arr_a[] = {2, 5, 4, -2};
  A.FillMatrix(arr_a);
  ASSERT_EQ(A.Determinant(), -24);
}