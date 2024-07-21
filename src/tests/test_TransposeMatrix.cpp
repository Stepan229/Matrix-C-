#include "tests.h"

TEST(testTransposeMatr, Subtest_1) {
  Matrix B(2, 3);
  Matrix A(3, 2);
  Matrix C;
  double arr_a[] = {1, 4, 2, 5, 3, 6};
  double arr_b[] = {1, 2, 3, 4, 5, 6};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C = A.Transpose();
  ASSERT_TRUE(C == B);
}

TEST(testTransposeMatr, Subtest_2) {
  Matrix B(2, 3);
  Matrix A(3, 2);
  Matrix C;
  double arr_a[] = {1, 2, 3, 4, 5, 6};
  double arr_b[] = {1, 3, 5, 2, 4, 6};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C = A.Transpose();
  ASSERT_TRUE(C == B);
}

TEST(testTransposeMatr, Subtest_3) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[] = {1, 4, 2, 5};
  double arr_b[] = {1, 2, 4, 5};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C = A.Transpose();
  ASSERT_TRUE(C == B);
}

TEST(testTransposeMatr, Subtest_4) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(1, 1);
  double arr_a[] = {1, 4, 2, 5};
  double arr_b[] = {1, 2, 4, 5};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C = A.Transpose();
  ASSERT_TRUE(C == B);
}
