#include "tests.h"

TEST(testMulMatr, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_b[4] = {5, 6, 7, 8};
  double arr_C[4] = {19, 22, 43, 50};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A.MulMatrix(B);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testMulMatr, Subtest_2) {
  Matrix A(2, 3);
  Matrix B(3, 2);
  Matrix C(2, 2);
  double arr_a[] = {2, -3, 1, 5, 4, -2};
  double arr_b[] = {-7, 5, 2, -1, 4, 3};
  double arr_C[] = {-16, 16, -35, 15};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A.MulMatrix(B);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testMulMatr, Subtest_3) {
  Matrix A;
  Matrix B;
  Matrix C;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double arr_b[9] = {1, 1, 2, 1, 0, 3, 1, 0, -4};
  double arr_C[9] = {6, 1, -4, 15, 4, -1, 24, 7, 2};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A.MulMatrix(B);
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testMulMatr, Subtest_4) {
  Matrix A(2, 3);
  Matrix B(4, 2);
  Matrix C(2, 3);
  double arr_a[] = {2, -3, 1, 5, 4, -2};
  double arr_b[] = {-7, 5, 2, -1, 4, 3};
  double arr_C[] = {2, -3, 1, 5, 4, -2};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A.MulMatrix(B);

  ASSERT_TRUE(A.EqMatrix(C));
}
