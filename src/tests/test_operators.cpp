#include "tests.h"

TEST(testSumOper, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_b[4] = {1, 2, 3, 4};
  double arr_C[4] = {2, 4, 6, 8};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_TRUE(C == A + B);
}

TEST(testSumOper, Subtest_2) {
  Matrix A(5, 3);
  Matrix B;
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7.1, 0, 0, 0, 0, 0, 0, 0, 0};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_THROW((A + B), logic_error);
}

TEST(testSumOper, Subtest_3) {
  Matrix A(5, 3);
  Matrix B;
  Matrix C;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  double arr_C[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_THROW((A + B), logic_error);
}

TEST(testSubOper, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_b[4] = {1, 2, 3, 4};
  double arr_C[4] = {0, 0, 0, 0};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_TRUE(C == A - B);
}

TEST(testSubOper, Subtest_2) {
  Matrix A(5, 3);
  Matrix B;
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7.1, 0, 0, 0, 0, 0, 0, 0, 0};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_THROW((A - B), logic_error);
}

TEST(testSubOper, Subtest_3) {
  Matrix A(5, 3);
  Matrix B;
  Matrix C;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_THROW((A - B), logic_error);
}

TEST(testMulOper, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_b[4] = {5, 6, 7, 8};
  double arr_C[4] = {19, 22, 43, 50};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_TRUE(C == A * B);
}

TEST(testMulOper, Subtest_2) {
  Matrix A(2, 3);
  Matrix B(3, 2);
  Matrix C(2, 2);
  double arr_a[] = {2, -3, 1, 5, 4, -2};
  double arr_b[] = {-7, 5, 2, -1, 4, 3};
  double arr_C[] = {-16, 16, -35, 15};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_TRUE(C == A * B);
}

TEST(testMulOper, Subtest_3) {
  Matrix A;
  Matrix B;
  Matrix C;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double arr_b[9] = {1, 1, 2, 1, 0, 3, 1, 0, -4};
  double arr_C[9] = {6, 1, -4, 15, 4, -1, 24, 7, 2};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_TRUE(C == A * B);
}

TEST(testMulOper, Subtest_4) {
  Matrix A(2, 3);
  Matrix B(4, 2);
  Matrix C(2, 3);
  double arr_a[] = {2, -3, 1, 5, 4, -2};
  double arr_b[] = {-7, 5, 2, -1, 4, 3};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_THROW((A - B), logic_error);
}

TEST(testEqOper, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(3, 2);
  //     // cout << ans << " eq" << endl;
  ASSERT_FALSE(A == B);
}

TEST(testEqOper, Subtest_2) {
  Matrix A;
  Matrix B(2, 3);
  ASSERT_FALSE(A == B);
}

TEST(testEqOper, Subtest_3) {
  Matrix A;
  Matrix B;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_TRUE(A == B);
}

TEST(testEqOper, Subtest_4) {
  Matrix A;
  Matrix B;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9.00000001};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_TRUE(A == B);
}

TEST(testEqOper, Subtest_5) {
  Matrix A;
  Matrix B;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9.000001};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_FALSE(A == B);
}

TEST(testAssignOper, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_b[4] = {5, 6, 7, 8};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  A = B;
  ASSERT_TRUE(A == B);
}

TEST(testAssignOper, Subtest_2) {
  Matrix A(2, 3);
  Matrix B(3, 2);
  double arr_a[] = {2, -3, 1, 5, 4, -2};
  double arr_b[] = {-7, 5, 2, -1, 4, 3};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  A = B;
  ASSERT_TRUE(A == B);
}

TEST(testAssignOper, Subtest_3) {
  Matrix A;
  Matrix B;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double arr_b[9] = {1, 1, 2, 1, 0, 3, 1, 0, -4};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  A = B;
  ASSERT_TRUE(A == B);
}

TEST(testAssignOper, Subtest_4) {
  Matrix A(2, 3);
  Matrix B(4, 2);
  double arr_a[] = {2, -3, 1, 5, 4, -2};
  double arr_b[] = {-7, 5, 2, -1, 4, 3, 3, 5};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  A = B;
  ASSERT_TRUE(A == B);
}

TEST(testAsSumOper, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_b[4] = {1, 2, 3, 4};
  double arr_C[4] = {2, 4, 6, 8};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A += B;
  ASSERT_TRUE(C == A);
}

TEST(testAsSumOper, Subtest_2) {
  Matrix A(5, 3);
  Matrix B;
  Matrix C(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7.1, 0, 0, 0, 0, 0, 0, 0, 0};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  double arr_C[] = {1, 2, 3, 4, 5, 6, 7.1, 0, 0, 0, 0, 0, 0, 0, 0};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_THROW(A += B;, logic_error);
}

TEST(testAsSumOper, Subtest_3) {
  Matrix A(5, 3);
  Matrix B;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  ASSERT_THROW(A += B;, logic_error);
}

TEST(testAsSubOper, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_b[4] = {1, 2, 3, 4};
  double arr_C[4] = {0, 0, 0, 0};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A -= B;
  ASSERT_TRUE(C == A);
}

TEST(testAsSubOper, Subtest_2) {
  Matrix A(5, 3);
  Matrix B;
  Matrix C(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7.1, 0, 0, 0, 0, 0, 0, 0, 0};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  double arr_C[] = {1, 2, 3, 4, 5, 6, 7.1, 0, 0, 0, 0, 0, 0, 0, 0};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_THROW(A -= B, logic_error);
}

TEST(testAsSubOper, Subtest_3) {
  Matrix A(5, 3);
  Matrix B;
  Matrix C;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7.1};
  double arr_b[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  double arr_C[9] = {1, 2, 3, 4, 5, 6, 7.1, 8, 9};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  ASSERT_THROW(A -= B, logic_error);
}

TEST(testAsMulOper, Subtest_1) {
  Matrix B(2, 2);
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_b[4] = {5, 6, 7, 8};
  double arr_C[4] = {19, 22, 43, 50};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A *= B;
  ASSERT_TRUE(C == A);
}

TEST(testAsMulOper, Subtest_2) {
  Matrix A(2, 3);
  Matrix B(3, 2);
  Matrix C(2, 2);
  double arr_a[] = {2, -3, 1, 5, 4, -2};
  double arr_b[] = {-7, 5, 2, -1, 4, 3};
  double arr_C[] = {-16, 16, -35, 15};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A *= B;
  ASSERT_TRUE(C == A);
}

TEST(testAsMulOper, Subtest_3) {
  Matrix A;
  Matrix B;
  Matrix C;
  double arr_a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  double arr_b[9] = {1, 1, 2, 1, 0, 3, 1, 0, -4};
  double arr_C[9] = {6, 1, -4, 15, 4, -1, 24, 7, 2};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A *= B;
  ASSERT_TRUE(C == A);
}

TEST(testAsMulOper, Subtest_4) {
  Matrix A(2, 3);
  Matrix B(4, 2);
  Matrix C(2, 3);
  double arr_a[] = {2, -3, 1, 5, 4, -2};
  double arr_b[] = {-7, 5, 2, -1, 4, 3};
  double arr_C[] = {2, -3, 1, 5, 4, -2};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  C.FillMatrix(arr_C);
  A *= B;
  ASSERT_TRUE(C == A);
}

TEST(testMulNumOper, Subtest_1) {
  Matrix A(2, 2);
  Matrix C(2, 2);
  double arr_a[4] = {1, 2, 3, 4};
  double arr_C[4] = {-1, -2, -3, -4};
  A.FillMatrix(arr_a);
  C.FillMatrix(arr_C);
  A *= -1;
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testMulNumOper, Subtest_2) {
  Matrix A(1, 1);
  Matrix C(1, 1);
  double arr_a[1] = {3};
  double arr_C[1] = {1.5};
  A.FillMatrix(arr_a);
  C.FillMatrix(arr_C);
  A *= 0.5;
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testMulNumOper, Subtest_3) {
  Matrix A(5, 3);
  Matrix C(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  double arr_C[] = {10,  20,  30, 40, 50, 60, 70, 100,
                    110, 120, 72, 50, 10, 0,  -30};
  A.FillMatrix(arr_a);
  C.FillMatrix(arr_C);
  A *= 10;
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testAsMulNumOper, Subtest_1) {
  Matrix A(5, 3);
  Matrix C(5, 3);
  Matrix B(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  double arr_C[] = {10,  20,  30, 40, 50, 60, 70, 100,
                    110, 120, 72, 50, 10, 0,  -30};
  A.FillMatrix(arr_a);
  C.FillMatrix(arr_C);
  B = A * 10;
  ASSERT_TRUE(A.EqMatrix(C));
}

TEST(testAsOper, Subtest_1) {
  Matrix A(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  A.FillMatrix(arr_a);

  ASSERT_TRUE(A(0, 0) == 1.);
}

TEST(testAsOper, Subtest_2) {
  Matrix A(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  A.FillMatrix(arr_a);

  ASSERT_TRUE(A(0, 1) == 2.);
}

TEST(testAsOper, Subtest_3) {
  Matrix A(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  A.FillMatrix(arr_a);
  ASSERT_THROW(A(-1, 0), logic_error);
}

TEST(testAsOper, Subtest_4) {
  Matrix A(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  A.FillMatrix(arr_a);
  ASSERT_THROW(A(0, 100), logic_error);
}

// Тест Конструктора копирования
TEST(testAsOper, Subtest_5) {
  Matrix A(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  A.FillMatrix(arr_a);
  Matrix B(A);
  ASSERT_TRUE(A == B);
}

// Конструктор переноса
TEST(testAsOper, Subtest_6) {
  Matrix A(5, 3);
  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  A.FillMatrix(arr_a);
  Matrix C(A);
  Matrix B(std::move(A));
  EXPECT_TRUE(B == C);
}

// Set Cols
TEST(testAsOper, Subtest_7) {
  Matrix A(5, 3);
  Matrix B(5, 4);

  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  double arr_b[] = {1,  2, 3,  0,   4, 5, 6, 0, 7,  10,
                    11, 0, 12, 7.2, 5, 0, 1, 0, -3, 0};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  A.SetCols(4);
  EXPECT_TRUE(A.GetCols() == 4);
  EXPECT_TRUE(B == A);
}

TEST(testAsOper, Subtest_8) {
  Matrix A(5, 3);
  Matrix B(5, 2);

  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  double arr_b[] = {
      1, 2, 4, 5, 7, 10, 12, 7.2, 1, 0,
  };
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  A.SetCols(2);
  EXPECT_TRUE(A.GetCols() == 2);
  EXPECT_TRUE(B == A);
}

// Set Rows
TEST(testAsOper, Subtest_9) {
  Matrix A(5, 3);
  Matrix B(2, 3);

  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  double arr_b[] = {
      1, 2, 3, 4, 5, 6,
  };
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  A.SetRows(2);
  EXPECT_TRUE(A.GetRows() == 2);
  EXPECT_TRUE(B == A);
}

TEST(testAsOper, Subtest_10) {
  Matrix A(5, 3);
  Matrix B(6, 3);

  double arr_a[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3};
  double arr_b[] = {1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 7.2, 5, 1, 0, -3, 0, 0, 0};
  A.FillMatrix(arr_a);
  B.FillMatrix(arr_b);
  A.SetRows(6);
  EXPECT_TRUE(A.GetRows() == 6);
  EXPECT_TRUE(B == A);
}