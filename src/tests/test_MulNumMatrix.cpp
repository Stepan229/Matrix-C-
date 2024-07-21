#include "tests.h"

TEST(testMulNumMatr, Subtest_1) {
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_C[4] = {-1, -2, -3, -4};
  A.FillMatrix(arr_a);
  C.FillMatrix(arr_C);
  A.MulNumber(-1);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testMulNumMatr, Subtest_2) {
  Matrix A(1, 1);
  Matrix C(1, 1);
  double arr_a[1] = {3};
  double arr_C[1] = {1.5};
  A.FillMatrix(arr_a);
  C.FillMatrix(arr_C);
  A.MulNumber(0.5);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testMulNumMatr, Subtest_3) {
  Matrix A(5, 3);
  Matrix C(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  double arr_C[] = {10,  20,  30, 40, 50, 60, 70, 100,
                    110, 120, 72, 50, 10, 0,  -30};
  A.FillMatrix(arr_a);
  C.FillMatrix(arr_C);
  A.MulNumber(10);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testMulNumMatr, Subtest_4) {
  Matrix A(3, 5);
  Matrix C(3, 5);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  double arr_C[] = {10,  20,  30, 40, 50, 60, 70, 100,
                    110, 120, 72, 50, 10, 0,  -30};
  A.FillMatrix(arr_a);
  C.FillMatrix(arr_C);
  A.MulNumber(10);
  ASSERT_TRUE(A.EqMatrix(C));
}