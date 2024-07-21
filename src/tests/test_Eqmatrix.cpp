#include "tests.h"

TEST(testEqMatr, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(3, 2);
  //     // cout << ans << " eq" << endl;
  ASSERT_FALSE(A.EqMatrix(B));
}

TEST(testEqMatr, Subtest_2) {
  Matrix A;
  Matrix B(2, 3);
  ASSERT_FALSE(A.EqMatrix(B));
}

TEST(testEqMatr, Subtest_3) {
  Matrix A;
  Matrix B;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(testEqMatr, Subtest_4) {
  Matrix A;
  Matrix B;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9.00000001};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(testEqMatr, Subtest_5) {
  Matrix A;
  Matrix B;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9.000001};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_FALSE(A.EqMatrix(B));
}