#include "tests.h"

TEST(testCompelementsMatr, Subtest_1) {
  Matrix B;
  Matrix A;
  double arr_a[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  double arr_b[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  Matrix C(A.CalcComplements());
  ASSERT_TRUE(C.EqMatrix(B));
}

TEST(testCompelementsMatr, Subtest_2) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  double arr_a[] = {4, 3, 6, 3};
  double arr_b[] = {3, -6, -3, 4};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  Matrix C(A.CalcComplements());
  ASSERT_TRUE(C.EqMatrix(B));
}

TEST(testCompelementsMatr, Subtest_3) {
  Matrix A(3, 2);
  double arr_a[] = {2, 5, 4, -2, 4, 3, 1, 0, -2};
  A.FillMatrix(arr_a);
  ASSERT_THROW(A.CalcComplements(), logic_error);
}

// TEST(testCompelementsMatr, Subtest_4) {
//     Matrix B;
//     Matrix A;
//     double arr_a[] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
//     double arr_b[] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
//     A.FillMatrix(arr_a);
//     B.FillMatrix(arr_b);
//     Matrix C(A.CalcComplements());
//   ASSERT_TRUE(C.EqMatrix(B));
// }
